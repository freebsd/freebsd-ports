#include <stdio.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

/*
 * adjust_priority
 *
 * sets realtime priority
 */

#ifdef HAVE_REALTIME_SCHED
#include <sched.h>

void adjust_priority()
{
	int sched = sched_getscheduler(0);
	if(sched == SCHED_FIFO || sched == SCHED_RR)
	{
		printf(">> since the scheduling policy is not standard, I assume\n");
		printf("   it has been adjusted to fit the needs of realtime audio\n");
	}
	else
	{
		struct sched_param sp;
		long priority = (sched_get_priority_max(SCHED_FIFO) +
			             sched_get_priority_min(SCHED_FIFO))/2;
		
		sp.sched_priority = priority;

		if(sched_setscheduler(0, SCHED_FIFO, &sp) != -1)
		{
			printf(">> running as realtime process now (priority %ld)\n",
																	priority);
			putenv("STARTED_THROUGH_ARTSWRAPPER=1");
		}
		else
		{
			/* can't set realtime priority */
			putenv("STARTED_THROUGH_ARTSWRAPPER=2");
		}
	}
}
#else
void adjust_priority()
{
	int prio;

	prio = getpriority(PRIO_PROCESS,getpid());
	if(prio > -10)
	{
		setpriority(PRIO_PROCESS,getpid(),-17);
		prio = getpriority(PRIO_PROCESS,getpid());
	}

	/* no system support for realtime priority */
	putenv("STARTED_THROUGH_ARTSWRAPPER=3");

	if(prio > -10) {
		printf(">> synthesizer priority is %d (which is unacceptable,",prio);
		printf(" try running as root)\n");
	}
	else {
		printf(">> synthesizer priority is %d (which is the best\n",prio);
		printf("   we can get out of a non realtime system)\n");
	}
}
#endif

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		if(strcmp(argv[1],"check") == 0)
		{
			/* backward compatibility with old artswrapper */
			printf("okay\n");
			return 0;
		}
	}

	adjust_priority();

	/* drop root privileges if running setuid root
	   (due to realtime priority stuff) */
	if (geteuid() != getuid()) 
	{
#if defined (HAVE_SETEUID) && !defined (HAVE_SETEUID_FAKE) 
		seteuid(getuid());
#else
		setreuid(-1, getuid());
#endif
	}

	if(argc == 0)
		return 1;

/*
 * Real-time status is passed to artsd via the environment variable
 * STARTED_THROUGH_ARTSWRAPPER. It has one of the following values:
 *
 * unset - not running as real-time
 * 1     - running as real-time
 * 2     - no privileges to set real-time scheduling
 * 3     - no support for real-time scheduling
 */
	argv[0] = EXECUTE;
	execv(EXECUTE,argv);
	perror(EXECUTE);
	return 1;
}
