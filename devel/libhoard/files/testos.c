#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	static int level;

	level = pthread_getconcurrency();
	(void)pthread_setconcurrency(level++);

	printf("LIBC_R TEST PASSED: All ok\n");

	exit(0);
}
