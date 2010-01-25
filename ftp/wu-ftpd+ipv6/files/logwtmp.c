#include "config.h"
#include "proto.h"

#include <utmpx.h>

void
wu_logwtmp(char *line, char *name, char *host, int login)
{
	struct utmpx utx;

	memset(&utx, 0, sizeof(utx));
	utx.ut_pid = getpid();
	snprintf(utx.ut_id, sizeof utx.ut_id, "%xftp", utx.ut_pid);
	gettimeofday(&utx.ut_tv, NULL);
	if (login) {
		utx.ut_type = USER_PROCESS;
		strncpy(utx.ut_user, name, sizeof(utx.ut_user));
		strncpy(utx.ut_host, host, sizeof(utx.ut_host));
		strncpy(utx.ut_line, line, sizeof(utx.ut_line));
	} else {
		utx.ut_type = DEAD_PROCESS;
	}
	pututxline(&utx);
}
