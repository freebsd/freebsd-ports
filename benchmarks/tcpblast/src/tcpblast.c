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
	register int i;

	if (argc!=3)
	{
		fprintf(stderr, "usage: tcpblast destination nblkocks\n");
		fprintf(stderr, "blocksize: %d bytes\n", BLKSIZE);
		exit(1);
	}

	nblocks = atoi(argv[2]);
	if (nblocks<=1 || nblocks>=10000)
	{
		fprintf(stderr, "tcpblast: 1 < nblocks <= 10000 \n");
		exit(1);
	}

	bzero((char *)&sock_in, sizeof (sock_in));
	sock_in.sin_family = AF_INET;
	f = socket(AF_INET, SOCK_STREAM, 0);
	if (f < 0) {
		perror("tcpblast: socket");
		exit(3);
	}
	if (bind(f, (struct sockaddr*) &sock_in, sizeof (sock_in)) < 0) {
		perror("tcpblast: bind");
		exit(1);
	}

	host = gethostbyname(argv[1]);
	if (host) {
		sock_in.sin_family = host->h_addrtype;
		bcopy(host->h_addr, &sock_in.sin_addr, host->h_length);
	} else {
		sock_in.sin_family = AF_INET;
		sock_in.sin_addr.s_addr = inet_addr(argv[1]);
		if (sock_in.sin_addr.s_addr == -1) {
			fprintf(stderr, "tcpblast: %s unknown host\n", argv[1]);
			exit(1);
		}
	}
	sock_in.sin_port = htons(9);

	if (connect(f, (struct sockaddr*) &sock_in, sizeof(sock_in)) <0)
	{
		perror("tcpblast connect:");
		exit(1);
	}

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
	printf("\n%d KB in %ld msec", nblocks, expms);
	printf("  =  %.1f kbit/s", (double) (nblocks*BLKSIZE) / expms * 8000.0);
	printf("  =  %.1f kByte/s", (double) (nblocks*BLKSIZE) / expms * 1000);
	printf("  =  %.1f MByte/s\n", (double) (nblocks*BLKSIZE) / (double)(expms*1024.0));
return(0);
}
