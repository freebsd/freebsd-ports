/*
 *	tcpblast - test and estimate TCP thruput
 *
 *	Daniel Karrenberg   <dfk@nic.eu.net>
 */

#include <sys/types.h>
#include <machine/endian.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/time.h>

#include <netinet/in.h>

#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLKSIZE 1024

struct	sockaddr_in sock_in;
struct	servent *sp;
struct	hostent *host;

long starts, startms, stops, stopms, expms;
struct timeval ti; 
struct timezone tiz;

char 	greet[BLKSIZE] = "Hi!";
int 	nblocks;
int	f;

int main(argc, argv)
int argc; char **argv;
{
	struct addrinfo hints, *res, *res0;
	char *cause = NULL;
	int ch, proto, error;
	register int i;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	while ((ch = getopt(argc, argv, "46")) != -1) {
		switch (ch) {
		case '4':
			hints.ai_family = PF_INET;
			break;
		case '6':
			hints.ai_family = PF_INET6;
			break;
		}
	}
	argc -= optind;
	argv += optind;
	if (argc != 2) {
		fprintf(stderr,
			"usage: tcpblast [-4] [-6] destination nblkocks\n"
			"blocksize: %d bytes %d\n", BLKSIZE, argc);
		exit(1);
	}

	nblocks = atoi(argv[1]);
	if (nblocks<=1 || nblocks>10000) {
		fprintf(stderr, "tcpblast: 1 < nblocks <= 10000 \n");
		exit(1);
	}

	error = getaddrinfo(argv[0], "discard", &hints, &res0);
	if (error)
		errx(1, "%s", gai_strerror(error));
	f = -1;
	cause = "no addresses";
	errno = EADDRNOTAVAIL;
	for (res = res0; res; res = res->ai_next) {
		f = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (f < 0) {
			cause = "socket";
			continue;
		}
		if (connect(f, res->ai_addr, res->ai_addrlen) < 0) {
			cause = "connect";
			close(f);
			f = -1;
			continue;
		}
		break;
	}
	if (f < 0)
		err(1, cause);
	freeaddrinfo(res);

	if (gettimeofday(&ti, &tiz) < 0)
	{
		perror("tcpblast time:");
		exit(1);
	}
	starts =  ti.tv_sec;
	startms = ti.tv_usec / 1000L;


	for (i=0; i<nblocks; i++)
	{
		if (write(f, greet, BLKSIZE) != BLKSIZE)
			perror("tcpblast send:");
		write(1, ".", 1);
	}

	if (gettimeofday(&ti, &tiz) < 0)
	{
		perror("tcpblast time:");
		exit(1);
	}
	stops =  ti.tv_sec;
	stopms = ti.tv_usec / 1000L;

	expms = (stops-starts)*1000 + (stopms-startms);
	printf("\n%d %d-byte blocks in %ld msec.\n", nblocks, BLKSIZE, expms);
	printf("Throughput  =  %.1f kbit/s", (double) (nblocks*BLKSIZE) / expms * 8.0);
	printf("  =  %.1f kByte/s", (double) (nblocks*BLKSIZE) / expms);
	printf("  =  %.1f MByte/s\n", (double) (nblocks*BLKSIZE) / (double)(expms*1024.0));
return(0);
}
