/* pnohang: executes command ($4-) with output in file ($3)
 * kills command if no output with $1 seconds with message in $2
 * usage: pnohang timeout file command args ...
 */

#include <sys/param.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    	int timeout, status, i, result, ofd;
	char *command, *outfile, *message, args[MAXPATHLEN + 1];
	char logstr[BUFSIZ + 1];
	pid_t pid, pid1, pid2, child;
	time_t now;
	struct stat st;
	struct sigaction sv;

	if (argc < 3) {
	    	printf("usage: %s timeout outfile message command [args...]\n",
			argv[0]);
		exit(1);
	}

	timeout = atoi(argv[1]);
	outfile = argv[2];
	message = argv[3];
	command = argv[4];

	bzero(args, MAXPATHLEN + 1);
	for (i = 4; i < argc; i++) {
	    	strlcat(args, argv[i], MAXPATHLEN - strlen(args));
		strlcat(args, " ", MAXPATHLEN - strlen(args));
	}

	pid = getpid();

	/*printf("timeout is %d\n", timeout);
	printf("outfile is %s\n", outfile);
	printf("message is %s\n", message);
	printf("arguments are %s", args);*/

	if ((ofd = open(outfile, O_CREAT|O_TRUNC|O_WRONLY, 0600)) == -1)
		err(1, "open");

	if (dup2(ofd, STDOUT_FILENO) == -1)
		err(1, "dup2 stdout");
	if (dup2(ofd, STDERR_FILENO) == -1)
		err(1, "dup2 stderr");

	if ((pid1 = fork()) > 0) {
	    	if ((pid2 = fork()) > 0) {
		    sv.sa_handler = SIG_IGN;
		    sigemptyset(&sv.sa_mask);
		    sv.sa_flags = 0;
		    sigaction(SIGTERM, &sv, 0);

		    /* parent */
		    child = wait(&status);
		    /*printf("exited child is %d, status is %d\n", child, status);*/

		    if (pid1 = child) {
			/*printf("killing process %d (second child)\n", pid2);*/
			kill(pid2, SIGTERM);
		    } else {
			/*printf("killing process %d (first child)\n", pid1);*/
			kill(pid1, SIGTERM);
		    }
		    /* exit status in upper 8 bits, killed signal (if any) in
		     * lower 8 bits
		     */
		    exit((status >> 8) | (status & 0xff));
		} else {
		    /* second child */
		    for (;;) {
			sleep(timeout/10);
			now = time(NULL);
			stat(outfile, &st);
			if ((now - st.st_mtime) > timeout) {
			    /*snprintf(logstr, BUFSIZ, "logger -t %s killing %s %s, pid %d since no output in %d seconds", argv[0], args, message, pid, timeout);
			    system(logstr);*/
			    printf("%s: killing %s (%s, pid %d and %d) since no output in %d seconds since %s", argv[0], args, message, pid1, pid, timeout, ctime(&now));
			    printf("ps jgx before the singal\n");
			    system("ps jgxww");
			    sleep(1); /* give it a chance to output the message */
			    kill(pid1, SIGTERM);
			    sleep(1);
			    kill(pid, SIGTERM);
			    sleep(1);
			    system("ps jgxww");
			    exit(1);
			}
		    }
		}
	} else {
	    	/* first child */
		/*printf("executing %s\n", args);*/
		result = execvp(command, argv + 4);
		if (result < 0) {
		    printf("Failed to exec %s: %s\n", args, strerror(errno));
		    exit(1);
		}
	}

	return 0;
}
