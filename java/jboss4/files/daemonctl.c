/*
 * -*- mode: Fundamental; tab-width: 4; -*-
 * ex:ts=4
 *
 * Daemon control program, with Java Startup options.
 *
 *	Original by Ernst de Haan <znerd@freebsd.org>
 *	www/jakarta-tomcat4/files/daemonctl.c
 *
 * $FreeBSD: /tmp/pcvs/ports/java/jboss4/files/Attic/daemonctl.c,v 1.3 2004-12-22 20:44:23 hq Exp $
 */

#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>

#define	TRUE	1
#define	FALSE	0

/* The interval in seconds between the checks to make sure the process
   died after a kill */
#define STOP_TIME_INTERVAL		1

#define ERR_ILLEGAL_ARGUMENT				1
#define ERR_PID_FILE_NOT_FOUND				2
#define ERR_KILL_FAILED						5
#define ERR_ALREADY_RUNNING					6
#define ERR_NOT_RUNNING						7
#define ERR_CHDIR_TO_APP_HOME				8
#define ERR_ACCESS_JAR_FILE					17
#define ERR_STDOUT_LOGFILE_OPEN				9
#define ERR_STDERR_LOGFILE_OPEN				10
#define ERR_FORK_FAILED						11
#define ERR_STAT_JAVA_HOME					12
#define ERR_JAVA_HOME_NOT_DIR				13
#define ERR_STAT_JAVA_CMD					14
#define ERR_JAVA_CMD_NOT_FILE				15
#define ERR_JAVA_CMD_NOT_EXECUTABLE			16

/*
	Function declarations.
 */
static void printUsage (void);
static int readPID (void);
static void writePID (int pid);
static void clearPID (void);
static void start (int javaOpt, char * javaArgs [], int jbossOpt, char * jbossArgs []);
static void stop (void);
static void restart (int javaOpt, char * javaArgs [], int jbossOpt, char * jbossArgs []);
static void logOutput (char *);

/*
	Globals
 */
static int isQuiet = FALSE;
static char * optQuiet = "-q",			/* quiet option */
			* optConfig = "-config";	/* jboss configuration option */

/**
 * Main function. This function is called when this program is executed.
 *
 * @param argc
 *    the number of arguments plus one, so always greater than 0.
 *
 * @param argv
 *    the arguments in an array of character pointers, where the last argument
 *    element is followed by a NULL element.
 */
int
main (
 int argc,
 char *argv [])
{
	/* Declare variables, like all other good ANSI C programs do :) */
	int i, javaOpt, jbossOpt;
	char *argument, **javaArgs, **jbossArgs;

	/* Parse the arguments */
	if (argc < 2)
	{
		printUsage ();
		return 0;
	}

	/* XXX: Fix for setting up the environment for the java wrapper script */
	setuid (geteuid ());
	setgid (getegid ());

	/*
		Build up java and jboss option blocks.
	 */
	javaOpt = jbossOpt = 0;
	for (i = 1; i < argc; i++)
	{
		if (strcmp (argv [i], optQuiet) == 0)
		{
			isQuiet = TRUE;

		} else if (strcmp (argv [i], optConfig) == 0)
		{
			jbossOpt += 2;
			if (++i >= argc)
			{
				printUsage ();
				return ERR_ILLEGAL_ARGUMENT;
			}

		} else if (*argv [i] == '-')
		{
			javaOpt++;
		}
	}
	if (javaOpt == 0)
		javaArgs = NULL;
	else
	{
		int j = 0;
		javaArgs = malloc (sizeof (char *) * javaOpt);
		for (i = 0; i < argc; i++)
		{
			if (strcmp (argv [i], optQuiet) &&
				strcmp (argv [i], optConfig) &&
				*argv [i] == '-')
			{
				javaArgs [j++] = argv [i];
			}
		}
	}
	if (jbossOpt == 0)
		jbossArgs = NULL;
	else
	{
		int j = 0;
		jbossArgs = malloc (sizeof (char *) * jbossOpt);
		for (i = 0; i < argc; i++)
		{
			if (strcmp (argv [i], optConfig) == 0)
			{
				jbossArgs [j++] = "-c";
				jbossArgs [j++] = argv [++i];
			}
		}
	}

	/*
		Decide on just what to call.
	 */
	argument = argv [argc - 1];
	if (strcmp ("start", argument) == 0)
	{
		start (javaOpt, javaArgs, jbossOpt, jbossArgs);

	} else if (strcmp ("stop", argument) == 0)
	{
		stop ();

	} else if (strcmp ("restart", argument) == 0)
	{
		restart (javaOpt, javaArgs, jbossOpt, jbossArgs);

	} else {
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Illegal argument \"%s\".\n", argument);
		printUsage ();
		exit (ERR_ILLEGAL_ARGUMENT);
	}

	return EXIT_SUCCESS;
}

/**
 * Prints usage information to stdout.
 */
static void
printUsage (void)
{
	printf ("Usage: %%CONTROL_SCRIPT_NAME%% [java-options] [-config jbossconfig] {start|stop|restart}\n");
}

/**
 * Reads a PID from the PID file.
 *
 * @return
 *    the PID, or -1 if the file was empty.
 */
static int
readPID (void)
{
	FILE * file;
	int pid;

	logOutput (">> Reading PID file (%%PID_FILE%%)...");
	file = fopen ("%%PID_FILE%%", "r");
	if (!file)
	{
		logOutput (" [ FAILED ]\n");
		perror ("%%CONTROL_SCRIPT_NAME%%: Unable to open %%PID_FILE%% for reading: ");
		exit (ERR_PID_FILE_NOT_FOUND);
	}
	if (fscanf (file, "%d", &pid) < 1)
		pid = -1;
	fclose (file);

	logOutput (" [ DONE ]\n");
	return pid;
}

/**
 * Writes a process ID to the specified file. The file is identified by a file
 * handle.
 *
 * @param pid
 *    the PID to store, always greater than 0.
 */
static void
writePID (
 int pid)
{
	FILE * file;

	logOutput (">> Writing PID file...");
	file = fopen ("%%PID_FILE%%", "w");
	if (!file)
	{
		logOutput (" [ FAILED ]\n");
		perror ("%%CONTROL_SCRIPT_NAME%%: Unable to open %%PID_FILE%% for writing: ");
		exit (ERR_PID_FILE_NOT_FOUND);
	}
	fprintf (file, "%d\n", pid);
	fclose (file);

	logOutput (" [ DONE ]\n");
}

/**
	Truncate the PID file.
 */
static void
clearPID (void)
{
	if (truncate ("%%PID_FILE%%", 0) != 0)
	{
		perror ("%%CONTROL_SCRIPT_NAME%%: Unable to clear %%PID_FILE%%: ");
		exit (ERR_PID_FILE_NOT_FOUND);
	}
}

/**
 * Checks if the specified process is running.
 *
 * @param pid
 *    the process id, greater than 0.
 *
 * @return
 *    0 if the specified process is not running, a different value otherwise.
 */
static int
existsProcess (
 int pid)
{
	int result;

	/* Check preconditions */
	assert (pid > 0);

	/* See if the process exists */
   	result = kill (pid, 0);

	/* If the result is 0, then the process exists */
	return result == 0;
}

/**
 * Kills the process identified by the specified ID.
 *
 * @param pid
 *    the process id, greater than 0.
 */
static void
killProcess (
 int pid)
{
	int result;
	unsigned int waited;
	unsigned int forced;
	unsigned int interval = STOP_TIME_INTERVAL;
	unsigned int timeout  = %%STOP_TIMEOUT%%;

	/* Check preconditions */
	assert (pid > 0);

	if (!isQuiet)
		printf (">> Terminating process %d...", pid);
	result = kill (pid, SIGTERM);
	if (result < 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to kill process %d: ", pid);
		perror (NULL);
		exit (ERR_KILL_FAILED);
	}

	/* Wait until the process is actually killed */
    result = existsProcess (pid);
	for (waited=0; result == 1 && waited < timeout; waited += interval)
	{
		logOutput (".");
		fflush (stdout);
		sleep (interval);
    	result = existsProcess (pid);
	}

	/* If the process still exists, then have no mercy and kill it */
	forced = 0;
	if (result == 1)
	{
		/* Force the process to die */
		result = kill (pid, SIGKILL);
		if (result == 0) {
			forced = 1;
			logOutput (" [ KILLED ]\n");
			fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Process %d did not terminate within %%STOP_TIMEOUT%% sec. Killed.\n", pid);
		} else if (result != ESRCH) {
			logOutput (" [ FAILED ]\n");
			fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to kill process %d: ", pid);
			perror (NULL);
			exit (ERR_KILL_FAILED);
		}
	}

	if (forced == 0) {
		logOutput (" [ DONE ]\n");
	}
}

/**
 * Starts the daemon.
 */
static void
start (
 int javaOpt,
 char * javaArgs [],
 int jbossOpt,
 char * jbossArgs [])
{
	int i, argc;
	char ** argv;
	int pid;
	int result;
	int stdoutLogFile;
	int stderrLogFile;
	struct stat sb;

	pid = readPID ();

	logOutput (">> Starting %%APP_TITLE%% %%PORTVERSION%%...");
	if (pid != -1)
	{
		/* Check if the process actually exists */
		result = existsProcess (pid);
		if (result == 1)
		{
			logOutput (" [ FAILED ]\n");
			fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: %%APP_TITLE%% %%PORTVERSION%% is already running, PID is %d.\n", pid);
			exit (ERR_ALREADY_RUNNING);
		}
	}

	/* Check if the JDK home directory is actually a directory */
	result = stat ("%%JAVA_HOME%%", &sb);
	if (result != 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to stat %%JAVA_HOME%%: ");
		perror (NULL);
		exit (ERR_STAT_JAVA_HOME);
	}
	if (!S_ISDIR (sb.st_mode)) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Java home directory %%JAVA_HOME%% is not a directory.\n");
		exit (ERR_JAVA_HOME_NOT_DIR);
	}

	/* Check if the Java command is actually an executable regular file */
	result = stat ("%%JAVA%%", &sb);
	if (result != 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to stat %%JAVA%%: ");
		perror (NULL);
		exit (ERR_STAT_JAVA_CMD);
	}
	if (!S_ISREG (sb.st_mode)) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Java command %%JAVA%% is not a regular file.\n");
		exit (ERR_JAVA_CMD_NOT_FILE);
	}
	result = access ("%%JAVA%%", X_OK);
	if (result != 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Java command %%JAVA%% is not executable: ");
		perror (NULL);
		exit (ERR_JAVA_CMD_NOT_EXECUTABLE);
	}

	/* Change directory */
	result = chdir ("%%APP_HOME%%");
	if (result < 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to access directory %%APP_HOME%%: ");
		perror (NULL);
		exit (ERR_CHDIR_TO_APP_HOME);
	}

	/* See if the JAR file exists */
	result = access ("%%APP_HOME%%/%%JAR_FILE%%", R_OK);
	if (result < 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to access JAR file %%APP_HOME%%/%%JAR_FILE%%: ");
		perror (NULL);
		exit (ERR_ACCESS_JAR_FILE);
	}

	/* Open the stdout log file */
	stdoutLogFile = open ("%%STDOUT_LOG%%", O_WRONLY);
	if (stdoutLogFile < 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to open %%STDOUT_LOG%% for writing: ");
		perror (NULL);
		exit (ERR_STDOUT_LOGFILE_OPEN);
	}
	lseek (stdoutLogFile, (off_t) 0, SEEK_END);

	/* Open the stderr log file */
	stderrLogFile = open ("%%STDERR_LOG%%", O_WRONLY);
	if (stderrLogFile < 0) {
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to open %%STDERR_LOG%% for writing: ");
		perror (NULL);
		exit (ERR_STDERR_LOGFILE_OPEN);
	}
	lseek (stderrLogFile, (off_t) 0, SEEK_END);

	/* Split this process in two */
	switch (pid = fork ())
	{
	case -1:
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: Unable to fork: ");
		perror (NULL);
		exit (ERR_FORK_FAILED);
		break;

	case 0:
		/* Redirect stdout to log file */
		dup2 (stdoutLogFile, STDOUT_FILENO);

		/* Redirect stderr to log file */
		dup2 (stderrLogFile, STDERR_FILENO);

		/* TODO: Support redirection of both stdout and stderr to the same
				 file using pipe (2) */

		/*
			Build the argument vector, with the java/jboss options if any.
		 */
		argv = malloc (sizeof (char *) * (javaOpt + jbossOpt + 5));
		argc = 0;
		argv [argc++] = "%%JAVA%%";
		for (i = 0; i < javaOpt; i++)
			argv [argc++] = javaArgs [i];
		argv [argc++] = "-cp";
		argv [argc++] = "%%JAVA_CP%%";
		argv [argc++] = "%%JAVA_MAIN%%";
		for (i = 0; i < jbossOpt; i++)
			argv [argc++] = jbossArgs [i];
		argv [argc++] = NULL;

		/* Execute the command */
		execv (argv [0], argv);
		perror (NULL);
		break;

	default:
		logOutput (" [ DONE ]\n");
		writePID (pid);
	}
}

/**
 * Stops the daemon.
 */
static void
stop (void)
{
	int pid;

	pid = readPID ();

	logOutput (">> Checking if %%APP_TITLE%% %%PORTVERSION%% is running...");

	/* If there is a PID, see if the process still exists */
	if (pid != -1)
	{
		int result = kill (pid, 0);
		if (result != 0 && errno == ESRCH)
		{
			clearPID ();
			pid = -1;
		}
	}

	/* If there is no running process, produce an error */
	if (pid == -1)
	{
		logOutput (" [ FAILED ]\n");
		fprintf (stderr, "%%CONTROL_SCRIPT_NAME%%: %%APP_TITLE%% %%PORTVERSION%% is currently not running.\n");
		exit (ERR_NOT_RUNNING);
	}
	logOutput (" [ DONE ]\n");

	/* Terminate the process */
	killProcess (pid);
	clearPID ();
}


/**
 * Restarts the process. If it not currently running, then it will fail.
 */
static void
restart (
 int javaOpt,
 char * javaArgs [],
 int jbossOpt,
 char * jbossArgs [])
{
	stop ();
	start (javaOpt, javaArgs, jbossOpt, jbossArgs);
}

/**
	Output log to stdout.
 */
static void
logOutput (
 char * string)
{
	if (!isQuiet)
		printf (string);
}
