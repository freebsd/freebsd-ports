--- netio.c.orig	2015-03-22 18:03:25.739744000 +0100
+++ netio.c	2015-03-22 18:03:36.459543000 +0100
@@ -1,1505 +1,1618 @@
-/* netio.c
- *
- * Author:  Kai-Uwe Rommel <rommel@ars.de>
- * Created: Wed Sep 25 1996
- */
-
-static char *rcsid =
-"$Id: netio.c,v 1.32 2012/11/22 16:47:24 Rommel Exp Rommel $";
-static char *rcsrev = "$Revision: 1.32 $";
-
-/*
- * $Log: netio.c,v $
- * Revision 1.32  2012/11/22 16:47:24  Rommel
- * added binding to client sockets, too
- *
- * Revision 1.31  2010/10/14 16:44:38  Rommel
- * fixed sleep calls
- *
- * Revision 1.30  2010/10/14 14:32:41  Rommel
- * removed NetBIOS code
- * added server side result printing
- * fixed packet loss calculation (data type bug)
- *
- * Revision 1.29  2010/10/14 11:28:19  Rommel
- * central printing routine
- *
- * Revision 1.28  2009/09/07 14:09:39  Rommel
- * changed number output from bytes/KB to bytes/KB/MB
- *
- * Revision 1.27  2008/02/11 09:00:22  Rommel
- * re-randomize buffer data for each loop run
- *
- * Revision 1.26  2005/08/30 14:45:51  Rommel
- * minor fixes
- *
- * Revision 1.25  2004/05/26 07:23:04  Rommel
- * some more corrections from Oliver Lau and Frank Schnell
- *
- * Revision 1.24  2004/05/17 16:01:03  Rommel
- * fix for _send/_recv from Thomas Jahns
- *
- * Revision 1.23  2003/09/30 09:32:22  Rommel
- * corrections from Matthias Scheler for error handling
- * added socket buffer size setting
- * added htonl/ntohl code (hint from Oliver Lau)
- * restructured send/recv error/result checking
- * more verbose server side messages
- * other minor changes
- *
- * Revision 1.22  2003/09/22 14:58:33  Rommel
- * added server side progress messages
- *
- * Revision 1.21  2003/08/28 12:44:11  Rommel
- * fixed display of non-k-multiple packet sizes
- *
- * Revision 1.20  2003/08/27 11:05:48  Rommel
- * allow block size specifikation in bytes or k bytes
- *
- * Revision 1.19  2003/08/17 16:53:45  Rommel
- * added Unix/Linux pthreads support (required for UDP)
- *
- * Revision 1.18  2003/08/17 14:46:17  Rommel
- * added UDP benchmark
- * several minor changes (cleanup)
- * configurable binding address
- *
- * Revision 1.17  2003/07/12 17:25:00  Rommel
- * made block size selectable
- *
- * Revision 1.16  2003/02/10 09:06:59  Rommel
- * fixed sender algorithm
- *
- * Revision 1.15  2001/09/17 13:56:40  Rommel
- * changed to perform bidirectional benchmarks
- *
- * Revision 1.14  2001/04/19 12:20:55  Rommel
- * added fixes for Unix systems
- *
- * Revision 1.13  2001/03/26 11:37:41  Rommel
- * avoid integer overflows during throughput calculation
- *
- * Revision 1.12  2000/12/01 15:57:57  Rommel
- * *** empty log message ***
- *
- * Revision 1.11  2000/03/01 12:21:47  rommel
- * fixed _INTEGRAL_MAX_BITS problem for WIN32
- *
- * Revision 1.10  1999/10/28 17:36:57  rommel
- * fixed OS/2 timer code
- *
- * Revision 1.9  1999/10/28 17:04:12  rommel
- * fixed timer code
- *
- * Revision 1.8  1999/10/24 19:08:20  rommel
- * imported DOS support from G. Vanem <giva@bgnett.no>
- *
- *
- * Revision 1.8  1999/10/12 11:02:00  giva
- * added Watt-32 with djgpp support. Added debug mode.
- * G. Vanem <giva@bgnett.no>
- *
- * Revision 1.7  1999/06/13 18:42:25  rommel
- * added Linux port with patches from Detlef Plotzky <plo@bvu.de>
- *
- * Revision 1.6  1998/10/12 11:14:58  rommel
- * change to malloc'ed (and tiled) memory for transfer buffers
- * (hint from Guenter Kukkukk <kukuk@berlin.snafu.de>)
- * for increased performance
- *
- * Revision 1.5  1998/07/31 14:15:03  rommel
- * added random buffer data
- * fixed bugs
- *
- * Revision 1.4  1997/09/12 17:35:04  rommel
- * termination bug fixes
- *
- * Revision 1.3  1997/09/12 12:00:15  rommel
- * added Win32 port
- * (tested for Windows NT only)
- *
- * Revision 1.2  1997/09/12 10:44:22  rommel
- * added TCP/IP and a command line interface
- *
- * Revision 1.1  1996/09/25 08:42:29  rommel
- * Initial revision
- *
- */
-
-#ifdef WIN32
-#define _INTEGRAL_MAX_BITS 64
-#endif
-
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <ctype.h>
-#include <signal.h>
-#if defined(UNIX) || defined(DJGPP)
-#include <sys/time.h>
-#include <unistd.h>
-#include <errno.h>
-#else
-#include <process.h>
-#include "getopt.h"
-#endif
-
-#define DEFAULTPORT 0x494F /* "IO" */
-#define DEFAULTNBSRV "NETIOSRV"
-#define DEFAULTNBCLT "NETIOCLT"
-#define THREADSTACK 65536
-
-/* TCP/IP system specific details */
-
-#ifdef OS2
-
-#define BSD_SELECT
-#include <types.h>
-#include <netinet/in.h>
-#include <sys/select.h>
-#include <sys/socket.h>
-#include <sys/time.h>
-#include <netdb.h>
-
-#ifdef __IBMC__
-#define newthread(entry) (_beginthread(entry, 0, THREADSTACK, 0) == -1)
-#else
-#define newthread(entry) (_beginthread(entry, THREADSTACK, 0) == -1)
-#endif
-#define THREAD void
-#define THREADRESULT 
-
-#endif /* OS2 */
-
-#ifdef WATT32
-
-#include <tcp.h>       /* sock_init() etc. */
-#include <netinet/in.h>
-#include <sys/socket.h>
-#include <netdb.h>
-#define soclose     close_s
-#define select      select_s
-#define psock_errno perror
-
-#endif /* WATT32 */
-
-#ifdef WIN32
-
-#include <windows.h>
-#include <winsock.h>
-#define soclose closesocket
-
-int sock_init(void)
-{
-  WSADATA wsaData;
-  return WSAStartup(MAKEWORD(1, 1), &wsaData);
-}
-
-void psock_errno(char *text)
-{
-  int rc = WSAGetLastError();
-  printf("%s: error code %d\n", text, rc);
-}
-
-#ifdef __IBMC__
-#define newthread(entry) (_beginthread(entry, 0, THREADSTACK, 0) == -1)
-#else
-#define newthread(entry) (_beginthread(entry, THREADSTACK, 0) == -1)
-#endif
-#define THREAD void
-#define THREADRESULT 
-
-#endif /* WIN32 */
-
-#ifdef UNIX
-
-#include <sys/types.h>
-#include <sys/socket.h>
-#include <sys/time.h>
-#include <time.h>
-#include <netinet/in.h>
-#include <netdb.h>
-
-#define psock_errno(x) perror(x)
-#define soclose(x) close(x)
-
-int sock_init(void)
-{
-  return 0;
-}
-
-#include <pthread.h>
-pthread_t thread;
-#define newthread(entry) (pthread_create(&thread, 0, entry, 0) != 0)
-#define THREAD void*
-#define THREADRESULT ((void*)0)
-
-#endif /* UNIX */
-
-#ifdef SOCKLEN_T
-typedef socklen_t socklen_type;
-#else
-typedef size_t socklen_type;
-#endif
-
-/* global data */
-
-#ifndef max
-#define max(x, y) ((x) > (y) ? (x) : (y))
-#endif
-
-#ifndef min
-#define min(x, y) ((x) < (y) ? (x) : (y))
-#endif
-
-#ifndef EINTR
-#define EINTR 0
-#endif
-
-int nSizes[] = {1024, 2048, 4096, 8192, 16384, 32768};
-size_t nnSizes = sizeof(nSizes) / sizeof(int);
-#define NMAXSIZE 65536
-
-int tSizes[] = {1024, 2048, 4096, 8192, 16384, 32767};
-size_t ntSizes = sizeof(tSizes) / sizeof(int);
-#define TMAXSIZE 65536
-
-#define INTERVAL 6
-
-/* you may need to adapt this to your platform/compiler */
-typedef unsigned int uint32;
-
-typedef struct
-{
-  uint32 cmd;
-  uint32 data;
-}
-CONTROL;
-
-#define CMD_QUIT  0
-#define CMD_C2S   1
-#define CMD_S2C   2
-#define CMD_RES   3
-
-#define CTLSIZE sizeof(CONTROL)
-
-/* timer code */
-
-int bTimeOver;
-
-#ifdef OS2
-
-#define INCL_DOS
-#define INCL_NOPM
-#include <os2.h>
-
-typedef QWORD TIMER;
-
-void APIENTRY TimerThread(ULONG nSeconds)
-{
-  HEV hSem;
-  HTIMER hTimer;
-
-  DosCreateEventSem(0, &hSem, DC_SEM_SHARED, 0);
-
-  DosAsyncTimer(nSeconds * 1000, (HSEM) hSem, &hTimer);
-  DosWaitEventSem(hSem, SEM_INDEFINITE_WAIT);
-  DosStopTimer(hTimer);
-
-  DosCloseEventSem(hSem);
-
-  bTimeOver = 1;
-
-  DosExit(EXIT_THREAD, 0);
-}
-
-int StartAlarm(long nSeconds)
-{
-  TID ttid;
-
-  bTimeOver = 0;
-
-  if (DosCreateThread(&ttid, TimerThread, nSeconds, 0, THREADSTACK))
-    return printf("Cannot create timer thread.\n"), -1;
-
-  return 0;
-}
-
-int StartTimer(TIMER *nStart)
-{
-  if (DosTmrQueryTime(nStart))
-    return printf("Timer error.\n"), -1;
-
-  return 0;
-}
-
-long StopTimer(TIMER *nStart, int nAccuracy)
-{
-  TIMER nStop;
-  ULONG nFreq;
-
-  if (DosTmrQueryTime(&nStop))
-    return printf("Timer error.\n"), -1;
-  if (DosTmrQueryFreq(&nFreq))
-    return printf("Timer error.\n"), -1;
-
-  nFreq = (nFreq + nAccuracy / 2) / nAccuracy;
-
-  return (* (long long *) &nStop - * (long long *) nStart) / nFreq;
-}
-
-#endif /* OS2 */
-
-#ifdef WIN32
-
-typedef LARGE_INTEGER TIMER;
-
-#define sleep(x) Sleep((x) * 1000);
-
-DWORD CALLBACK TimerThread(void *pArg)
-{
-  long nSeconds = * (long *) pArg;
-
-  Sleep(nSeconds * 1000);
-  bTimeOver = 1;
-
-  return 0;
-}
-
-int StartAlarm(long nSeconds)
-{
-  static long sSeconds;
-  DWORD ttid;
-
-  sSeconds = nSeconds;
-
-  bTimeOver = 0;
-
-  if (CreateThread(0, THREADSTACK, TimerThread, (void *) &sSeconds, 0, &ttid) == NULL)
-    return printf("Cannot create timer thread.\n"), -1;
-
-  return 0;
-}
-
-int StartTimer(TIMER *nStart)
-{
-  if (!QueryPerformanceCounter(nStart))
-    return printf("Timer error.\n"), -1;
-
-  return 0;
-}
-
-long StopTimer(TIMER *nStart, int nAccuracy)
-{
-  TIMER nStop, nFreq;
-
-  if (!QueryPerformanceCounter(&nStop))
-    return printf("Timer error.\n"), -1;
-  if (!QueryPerformanceFrequency(&nFreq))
-    return printf("Timer error.\n"), -1;
-
-  nFreq.QuadPart = (nFreq.QuadPart + nAccuracy / 2) / nAccuracy;
-
-  return (nStop.QuadPart - nStart->QuadPart) / nFreq.QuadPart;
-}
-
-#endif /* WIN32 */
-
-#if defined(UNIX) || defined(DJGPP)
-
-typedef struct timeval TIMER;
-
-void on_alarm(int signum)
-{
-  alarm(0);
-  bTimeOver = 1;
-}
-
-int StartAlarm(long nSeconds)
-{
-  bTimeOver = 0;
-  signal(SIGALRM, on_alarm);
-  alarm(nSeconds);
-  return 0;
-}
-
-int StartTimer(TIMER *nStart)
-{
-  struct timezone tz = {0, 0};
-
-  gettimeofday(nStart, &tz);
-
-  return 0;
-}
-
-long StopTimer(TIMER *nStart, int nAccuracy)
-{
-  struct timezone tz = {0, 0};
-  TIMER nStop;
-
-  gettimeofday(&nStop, &tz);
-
-  return (nStop.tv_sec - nStart->tv_sec) * nAccuracy
-       + (nStop.tv_usec - nStart->tv_usec) * nAccuracy / 1000000;
-}
-
-#endif /* UNIX || DJGPP */
-
-/* initialize data to transfer */
-
-void GenerateRandomData(char *cBuffer, size_t nSize)
-{
-  if (cBuffer != NULL)
-  {
-    size_t i;
- 
-    cBuffer[0] = 0;
-    srand(time(NULL));
- 
-    for (i = 1; i < nSize; i++)
-      cBuffer[i] = (char) rand();
-  }
-}
- 
-char *InitBuffer(size_t nSize)
-{
- char *cBuffer = malloc(nSize); 
- GenerateRandomData(cBuffer, nSize); 
- return cBuffer;
-}
-
-char *PacketSize(int nSize)
-{
-  static char szBuffer[64];
-
-  if ((nSize % 1024) == 0 || (nSize % 1024) == 1023)
-    sprintf(szBuffer, "%2dk", (nSize + 512) / 1024);
-  else
-    sprintf(szBuffer, "%d", nSize);
-
-  return szBuffer;
-}
-
-/* print results */
-
-typedef enum {nf_auto, nf_bytes, nf_kbytes, nf_mbytes, nf_gbytes} numberformat;
-numberformat nFormat = nf_auto;
-
-void print_result(long long nData, long nTime)
-{
-  numberformat nThisFormat = nFormat;
-  double nResult;
-  
-  if (nThisFormat == nf_auto)
-  {
-    if (nData < 10 * 1024 * INTERVAL)
-      nThisFormat = nf_bytes;
-    else if (nData < 10 * 1024 * 1024 * INTERVAL)
-      nThisFormat = nf_kbytes;
-    else if (nData < (long long) 1024 * 1024 * 1024 * INTERVAL)
-      nThisFormat = nf_mbytes;
-    else
-      nThisFormat = nf_gbytes;
-  }
-
-  switch(nThisFormat)
-  {
-  case nf_bytes:
-    nResult = (double) nData * 1024 / nTime;
-    printf(" %0.0f Byte/s", nResult);
-    break;
-
-  case nf_kbytes:
-    nResult = (double) nData / nTime;
-    printf(" %0.2f KByte/s", nResult);
-    break;
-
-  case nf_mbytes:
-    nResult = (double) nData / nTime / 1024;
-    printf(" %0.2f MByte/s", nResult);
-    break;
-
-  case nf_gbytes:
-    nResult = (double) nData / nTime / 1024 / 1024;
-    printf(" %0.3f GByte/s", nResult);
-    break;
-  }
-}
-
-/* TCP/IP code */
-
-int send_data(int socket, void *buffer, size_t size, int flags)
-{
-  int rc = send(socket, buffer, size, flags);
-
-  if (rc < 0)
-  {
-    psock_errno("send()");
-    return -1;
-  }
-
-  if (rc != size)
-    return 1;
-
-  return 0;
-}
-
-int recv_data(int socket, void *buffer, size_t size, int flags)
-{
-  size_t rc = recv(socket, buffer, size, flags);
-
-  if (rc < 0)
-  {
-    psock_errno("recv()");
-    return -1;
-  }
-
-  if (rc != size)
-    return 1;
-
-  return 0;
-}
-
-const int sobufsize = 131072;
-int nPort = DEFAULTPORT;
-int nAuxPort = DEFAULTPORT + 1;
-struct in_addr addr_server;
-struct in_addr addr_local;
-
-int udpsocket, udpd;
-unsigned long nUDPCount;
-long long nUDPData;
-
-THREAD TCP_Server(void *arg)
-{
-  char *cBuffer;
-  CONTROL ctl;
-  TIMER nTimer;
-  long nTime;
-  long long nData;
-  struct sockaddr_in sa_server, sa_client;
-  int server, client;
-  socklen_type length;
-  struct timeval tv;
-  fd_set fds;
-  int rc;
-  int nByte;
-
-  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
-  {
-    perror("malloc()");
-    return THREADRESULT;
-  }
-
-  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-  {
-    psock_errno("socket()");
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nPort);
-  sa_server.sin_addr = addr_local;
-
-  if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
-  {
-    psock_errno("bind()");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  if (listen(server, 2) != 0)
-  {
-    psock_errno("listen()");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  for (;;)
-  {
-    printf("TCP server listening.\n");
-
-    FD_ZERO(&fds);
-    FD_SET(server, &fds);
-    tv.tv_sec  = 3600;
-    tv.tv_usec = 0;
-
-    if ((rc = select(FD_SETSIZE, &fds, 0, 0, &tv)) < 0)
-    {
-      psock_errno("select()");
-      break;
-    }
-
-    if (rc == 0 || FD_ISSET(server, &fds) == 0)
-      continue;
-
-    length = sizeof(sa_client);
-    if ((client = accept(server, (struct sockaddr *) &sa_client, &length)) == -1)
-      continue;
-
-    setsockopt(client, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-    setsockopt(client, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-    printf("TCP connection established ... ");
-    fflush(stdout);
-
-    for (;;)
-    {
-      if (recv_data(client, (void *) &ctl, CTLSIZE, 0))
-	break;
-
-      ctl.cmd = ntohl(ctl.cmd);
-      ctl.data = ntohl(ctl.data);
-
-      if (ctl.cmd == CMD_C2S)
-      {
-	StartTimer(&nTimer);
-
-	printf("\nReceiving from client, packet size %s ... ", PacketSize(ctl.data));
-	nData = 0;
-
-	do
-	{
-	  for (nByte = 0; nByte < ctl.data; )
-	  {
-	    rc = recv(client, cBuffer + nByte, ctl.data - nByte, 0);
-
-	    if (rc < 0 && errno != EINTR)
-	    {
-	      psock_errno("recv()");
-	      break;
-	    }
-	    
-	    if (rc > 0)
-	      nByte += rc;
-	  }
-
-	  nData += ctl.data;
-	}
-	while (cBuffer[0] == 0 && rc > 0);
-
-	if ((nTime = StopTimer(&nTimer, 1024)) != -1)
-	  print_result(nData, nTime);
-      }
-      else if (ctl.cmd == CMD_S2C)
-      {
-	if (StartAlarm(INTERVAL) == 0)
-	{
-	  StartTimer(&nTimer);
-
-	  printf("\nSending to client, packet size %s ... ", PacketSize(ctl.data));
-	  cBuffer[0] = 0;
-	  nData = 0;
-
-	  while (!bTimeOver)
-	  {
-	    //GenerateRandomData(cBuffer, ctl.data);
-
-	    for (nByte = 0; nByte < ctl.data; )
-	    {
-	      rc = send(client, cBuffer + nByte, ctl.data - nByte, 0);
-
-	      if (rc < 0 && errno != EINTR)
-	      {
-		psock_errno("send()");
-		break;
-	      }
-
-	      if (rc > 0)
-		nByte += rc;
-	    }
-
-	    nData += ctl.data;
-	  }
-
-	  cBuffer[0] = 1;
-
-	  if (send_data(client, cBuffer, ctl.data, 0))
-	    break;
-
-	  if ((nTime = StopTimer(&nTimer, 1024)) != -1)
-	    print_result(nData, nTime);
-	}
-      }
-      else /* quit */
-	break;
-    }
-
-    printf("\nDone.\n");
-
-    soclose(client);
-
-    if (rc < 0)
-      break;
-  }
-
-  soclose(server);
-  free(cBuffer);
-
-  return THREADRESULT;
-}
-
-void TCP_Bench(void *arg)
-{
-  char *cBuffer;
-  CONTROL ctl;
-  TIMER nTimer;
-  long nTime;
-  long long nData;
-  int i;
-  struct sockaddr_in sa_server, sa_client;
-  int server;
-  int rc;
-  int nByte;
-
-  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
-  {
-    perror("malloc()");
-    return;
-  }
-
-  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-  {
-    psock_errno("socket()");
-    free(cBuffer);
-    return;
-  }
-
-  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-  sa_client.sin_family = AF_INET;
-  sa_client.sin_port = htons(0);
-  sa_client.sin_addr = addr_local;
-
-  if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
-  {
-    psock_errno("bind()");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nPort);
-  sa_server.sin_addr = addr_server;
-
-  if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
-  {
-    psock_errno("connect()");
-    soclose(server);
-    free(cBuffer);
-    return;
-  }
-
-  printf("\nTCP connection established.\n");
-
-  for (i = 0; i < ntSizes; i++)
-  {
-    printf("Packet size %s bytes: ", PacketSize(tSizes[i]));
-    fflush(stdout);
-
-    /* tell the server we will send it data now */
-
-    ctl.cmd = htonl(CMD_C2S);
-    ctl.data = htonl(tSizes[i]);
-
-    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    /* 1 - Tx test */
-
-    if (StartAlarm(INTERVAL) == 0)
-    {
-      StartTimer(&nTimer);
-      nData = 0;
-      cBuffer[0] = 0;
-
-      while (!bTimeOver)
-      {
-	//GenerateRandomData(cBuffer, tSizes[i]);
-
-	for (nByte = 0; nByte < tSizes[i]; )
-	{
-	  rc = send(server, cBuffer + nByte, tSizes[i] - nByte, 0);
-
-	  if (rc < 0 && errno != EINTR)
-	  {
-	    psock_errno("send()");
-	    break;
-	  }
-	  
-	  if (rc > 0)
-	    nByte += rc;
-	}
-
-	nData += tSizes[i];
-      }
-
-      if ((nTime = StopTimer(&nTimer, 1024)) == -1)
-	printf(" (failed)");
-      else
-	print_result(nData, nTime);
-
-      printf(" Tx, ");
-      fflush(stdout);
-
-      cBuffer[0] = 1;
-
-      if (send_data(server, cBuffer, tSizes[i], 0))
-	break;
-    }
-
-    /* tell the server we expect him to send us data now */
-
-    ctl.cmd = htonl(CMD_S2C);
-    ctl.data = htonl(tSizes[i]);
-
-    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    /* 2 - Rx test */
-
-    StartTimer(&nTimer);
-    nData = 0;
-
-    do
-    {
-      for (nByte = 0; nByte < tSizes[i]; )
-      {
-	rc = recv(server, cBuffer + nByte, tSizes[i] - nByte, 0);
-
-	if (rc < 0 && errno != EINTR)
-	{
-	  psock_errno("recv()");
-	  break;
-	}
-	  
-	if (rc > 0)
-	  nByte += rc;
-      }
-
-      nData += tSizes[i];
-    }
-    while (cBuffer[0] == 0 && rc > 0);
-
-    if ((nTime = StopTimer(&nTimer, 1024)) == -1)
-      printf(" (failed)");
-    else
-      print_result(nData, nTime);
-
-    printf(" Rx.\n");
-  }
-
-  ctl.cmd = htonl(CMD_QUIT);
-  ctl.data = 0;
-
-  send_data(server, (void *) &ctl, CTLSIZE, 0);
-
-  printf("Done.\n");
-
-  soclose(server);
-  free(cBuffer);
-}
-
-THREAD UDP_Receiver(void *arg)
-{
-  char *cBuffer;
-  struct sockaddr_in sa_server, sa_client;
-  int rc;
-  socklen_type nBytes;
-
-  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
-  {
-    perror("malloc()");
-    return THREADRESULT;
-  }
-
-  if ((udpsocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
-  {
-    psock_errno("socket(DGRAM)");
-    free(cBuffer);
-    return THREADRESULT;
-  }
-  
-  setsockopt(udpsocket, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-  setsockopt(udpsocket, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nAuxPort);
-  sa_server.sin_addr = addr_local;
-
-  if (bind(udpsocket, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
-  {
-    psock_errno("bind(DGRAM)");
-    soclose(udpsocket);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  udpd = 1;
-
-  for (;;)
-  {
-    nBytes = sizeof(sa_client);
-    rc = recvfrom(udpsocket, cBuffer, TMAXSIZE, 0, (struct sockaddr *) &sa_client, &nBytes);
-
-    if (rc < 0 && errno != EINTR)
-      psock_errno("recvfrom()");
-
-    if (rc > 0)
-    {
-      nUDPCount++;
-      nUDPData += rc;
-    }
-  }
-
-  soclose(udpsocket);
-  free(cBuffer);
-
-  return THREADRESULT;
-}
-
-THREAD UDP_Server(void *arg)
-{
-  char *cBuffer;
-  CONTROL ctl;
-  TIMER nTimer;
-  long nTime;
-  long long nData;
-  struct sockaddr_in sa_server, sa_client;
-  int server, client;
-  struct timeval tv;
-  fd_set fds;
-  int rc, nByte;
-  socklen_type nLength;
-
-  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
-  {
-    perror("malloc()");
-    return THREADRESULT;
-  }
-
-  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-  {
-    psock_errno("socket(STREAM)");
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nAuxPort);
-  sa_server.sin_addr = addr_local;
-
-  if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
-  {
-    psock_errno("bind(STREAM)");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  if (listen(server, 2) != 0)
-  {
-    psock_errno("listen()");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  for (;;)
-  {
-    printf("UDP server listening.\n");
-
-    FD_ZERO(&fds);
-    FD_SET(server, &fds);
-    tv.tv_sec  = 3600;
-    tv.tv_usec = 0;
-
-    if ((rc = select(FD_SETSIZE, &fds, 0, 0, &tv)) < 0)
-    {
-      psock_errno("select()");
-      break;
-    }
-
-    if (rc == 0 || FD_ISSET(server, &fds) == 0)
-      continue;
-
-    nLength = sizeof(sa_client);
-    if ((client = accept(server, (struct sockaddr *) &sa_client, &nLength)) == -1)
-      continue;
-
-    setsockopt(client, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-    setsockopt(client, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-    printf("UDP connection established ... ");
-    fflush(stdout);
-
-    sa_client.sin_port = htons(nAuxPort);
-
-    for (;;)
-    {
-      if (recv_data(client, (void *) &ctl, CTLSIZE, 0))
-	break;
-
-      ctl.cmd = ntohl(ctl.cmd);
-      ctl.data = ntohl(ctl.data);
-
-      if (ctl.cmd == CMD_C2S)
-      {
-	StartTimer(&nTimer);
-	nUDPCount = 0;
-	nUDPData = 0;
-
-	printf("\nReceiving from client, packet size %s ... ", PacketSize(ctl.data));
-
-	ctl.cmd = htonl(ctl.cmd);
-	ctl.data = htonl(ctl.data);
-
-	if (send_data(client, (void *) &ctl, CTLSIZE, 0))
-	  break;
-      }
-      else if (ctl.cmd == CMD_RES)
-      {
-	ctl.cmd = htonl(ctl.cmd);
-	ctl.data = htonl(nUDPCount);
-
-	if (send_data(client, (void *) &ctl, CTLSIZE, 0))
-	  break;
-
-	if ((nTime = StopTimer(&nTimer, 1024)) != -1)
-	  print_result(nUDPData, nTime);
-      }
-      else if (ctl.cmd == CMD_S2C)
-      {
-	if (StartAlarm(INTERVAL) == 0)
-	{
-	  StartTimer(&nTimer);
-	  nData = 0;
-
-	  printf("\nSending to client, packet size %s ... ", PacketSize(ctl.data));
-	  cBuffer[0] = 0;
-	  nLength = ctl.data;
-
-	  ctl.cmd = htonl(CMD_RES);
-	  ctl.data = 0;
-
-	  while (!bTimeOver)
-	  {
-	    //GenerateRandomData(cBuffer, nLength);
-
-	    for (nByte = 0; nByte < nLength; )
-	    {
-	      do
-	      {
-	        rc = sendto(udpsocket, cBuffer + nByte, nLength - nByte, 0, 
-			    (struct sockaddr *) &sa_client, sizeof(sa_client));
-	      }
-#ifdef ENOBUFS
-	      while (rc < 0 && errno == ENOBUFS);
-#else
-	      while (0);
-#endif
-
-	      if (rc < 0 && errno != EINTR)
-	      {
-		psock_errno("sendto()");
-		break;
-	      }
-	      
-	      if (rc > 0)
-		nByte += rc;
-	    }
-
-	    ctl.data++;
-	    nData += nLength;
-	  }
-
-	  ctl.data = htonl(ctl.data);
-
-	  if (send_data(client, (void *) &ctl, CTLSIZE, 0))
-	    break;
-
-	  if ((nTime = StopTimer(&nTimer, 1024)) != -1)
-	    print_result(nData, nTime);
-	}
-      }
-      else /* quit */
-	break;
-    }
-
-    printf("\nDone.\n");
-
-    soclose(client);
-
-    if (rc < 0)
-      break;
-  }
-
-  soclose(server);
-  free(cBuffer);
-
-  return THREADRESULT;
-}
-
-void UDP_Bench(void *arg)
-{
-  char *cBuffer;
-  CONTROL ctl;
-  TIMER nTimer;
-  long nTime, nCount;
-  long nResult;
-  long long nData;
-  int i;
-  struct sockaddr_in sa_server, sa_client;
-  int server;
-  int rc, nByte;
-
-  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
-  {
-    perror("malloc()");
-    return;
-  }
-
-  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-  {
-    psock_errno("socket()");
-    free(cBuffer);
-    return;
-  }
-
-  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
-  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
-
-  sa_client.sin_family = AF_INET;
-  sa_client.sin_port = htons(0);
-  sa_client.sin_addr = addr_local;
-
-  if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
-  {
-    psock_errno("bind(STREAM)");
-    soclose(server);
-    free(cBuffer);
-    return THREADRESULT;
-  }
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nAuxPort);
-  sa_server.sin_addr = addr_server;
-
-  if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
-  {
-    psock_errno("connect()");
-    soclose(server);
-    free(cBuffer);
-    return;
-  }
-
-  printf("\nUDP connection established.\n");
-
-  for (i = 0; i < ntSizes; i++)
-  {
-    printf("Packet size %s bytes: ", PacketSize(tSizes[i]));
-    fflush(stdout);
-
-    /* tell the server we will send it data now */
-
-    ctl.cmd = htonl(CMD_C2S);
-    ctl.data = htonl(tSizes[i]);
-
-    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    /* 1 - Tx test */
-
-    if (StartAlarm(INTERVAL) == 0)
-    {
-      StartTimer(&nTimer);
-      nData = 0;
-      nCount = 0;
-      cBuffer[0] = 0;
-
-      while (!bTimeOver)
-      {
-	//GenerateRandomData(cBuffer, tSizes[i]);
-
-	for (nByte = 0; nByte < tSizes[i]; )
-	{
-	  rc = sendto(udpsocket, cBuffer + nByte, tSizes[i] - nByte, 0, 
-		      (struct sockaddr *) &sa_server, sizeof(sa_server));
-
-	  if (rc < 0)
-	  {
-	    if (errno != EINTR)
-	    {
-	      psock_errno("sendto()");
-	      break;
-	    }
-	  }
-	  else
-	    nByte += rc;
-	}
-
-	nData += tSizes[i];
-	nCount++;
-      }
-      
-      if ((nTime = StopTimer(&nTimer, 1024)) == -1)
-	printf(" (failed)");
-
-      ctl.cmd = htonl(CMD_RES);
-
-      if (send_data(server, (void *) &ctl, CTLSIZE, 0))
-	break;
-
-      if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
-	break;
-
-      ctl.data = ntohl(ctl.data);
-      nData = (long long) tSizes[i] * ctl.data;
-
-      print_result(nData, nTime);
-      nResult = (nCount - ctl.data) * 100 / nCount;
-      printf(" (%ld%%) Tx, ", nResult);
-      fflush(stdout);
-    }
-
-    /* tell the server we expect him to send us data now */
-
-    ctl.cmd = htonl(CMD_S2C);
-    ctl.data = htonl(tSizes[i]);
-
-    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    /* 2 - Rx test */
-
-    StartTimer(&nTimer);
-    nUDPCount = 0;
-    nUDPData = 0;
-
-    if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
-      break;
-
-    if ((nTime = StopTimer(&nTimer, 1024)) == -1)
-      printf(" (failed)");
-
-    ctl.data = ntohl(ctl.data);
-
-    print_result(nUDPData, nTime);
-    nResult = (ctl.data - nUDPCount) * 100 / ctl.data;
-    printf(" (%ld%%) Rx.\n", nResult);
-  }
-
-  ctl.cmd = htonl(CMD_QUIT);
-  ctl.data = 0;
-
-  send_data(server, (void *) &ctl, CTLSIZE, 0);
-
-  printf("Done.\n");
-
-  soclose(server);
-  free(cBuffer);
-}
-
-/* main / user interface */
-
-int bSRV, bTCP, bUDP;
-
-void handler(int sig)
-{
-  _exit(0);
-}
-
-void usage(void)
-{
-  printf(
-	 "\nUsage: netio [options] [<server>]\n"
-	 "\n  -s              run server side of benchmark (otherwise run client)"
-	 "\n  -b <size>[k]    use this block size (otherwise run with 1,2,4,8,16 and 32k)"
-	 "\n  -B -K -M -G     force number formatting to Bytes, K, M or G Bytes\n"
-
-	 "\n  -t              use TCP protocol for benchmark"
-	 "\n  -u              use UDP protocol for benchmark"
-	 "\n  -h <addr/name>  bind TCP and UDP sockets to this local host address/name"
-	 "\n                  defaults to all (server) or unspecified (client)"
-	 "\n  -p <port>       bind TCP and UDP servers to this port (default is %d)\n"
-
-         "\n  <server>        If the client side of the benchmark is running,"
-	 "\n                  a server name or address is required.\n"
-
-	 "\nThe server side can run either TCP (-t) or UDP (-u) protocol or both"
-	 "\n(default, if neither -t or -u is specified). The client runs one of"
-	 "\nthese protocols only (must specify -t or -u).\n"
-	 "\n", nPort);
-  exit(1);
-}
-
-int main(int argc, char **argv)
-{
-  char szVersion[32], *szName = 0, *szLocal = 0, *szEnd;
-  int option;
-  struct hostent *host;
-  long nSize;
-
-  strcpy(szVersion, rcsrev + sizeof("$Revision: ") - 1);
-  *strchr(szVersion, ' ') = 0;
-
-  printf("\nNETIO - Network Throughput Benchmark, Version %s"
-	 "\n(C) 1997-2012 Kai Uwe Rommel\n", szVersion);
-
-  if (argc == 1)
-    usage();
-
-  /* check arguments */
-
-  while ((option = getopt(argc, argv, "?stup:h:b:dBKMG")) !=  -1)
-    switch (option)
-    {
-    case 's':
-      bSRV = 1;
-      break;
-    case 't':
-      bTCP = 1;
-      break;
-    case 'u':
-      bUDP = 1;
-      break;
-    case 'p':
-      nPort = atoi(optarg);
-      nAuxPort = nPort + 1;
-      break;
-    case 'h':
-      szLocal = optarg;
-      break;
-    case 'b':
-      nSize = strtol(optarg, &szEnd, 10);
-      if (*szEnd == 'k')
-	nSize *= 1024;
-      nSizes[0] = min(max(nSize, 1), NMAXSIZE);
-      tSizes[0] = min(max(nSize, 1), TMAXSIZE);
-      nnSizes = ntSizes = 1;
-      break;
-#ifdef WATT32
-    case 'd':
-      dbug_init();
-      break;
-#endif
-    case 'B':
-      nFormat = nf_bytes;
-      break;
-    case 'K':
-      nFormat = nf_kbytes;
-      break;
-    case 'M':
-      nFormat = nf_mbytes;
-      break;
-    case 'G':
-      nFormat = nf_gbytes;
-      break;
-    default:
-      usage();
-      break;
-    }
-
-  if (bSRV == 1 && bTCP == 0 && bUDP == 0)
-    bTCP = bUDP = 1;
-
-  /* initialize TCP/IP */
-
-  if (bTCP || bUDP)
-  {
-    if (sock_init())
-      return psock_errno("sock_init()"), 1;
-
-    if (szLocal == 0)
-      addr_local.s_addr = INADDR_ANY;
-    else
-    {
-      if (isdigit(*szLocal))
-	addr_local.s_addr = inet_addr(szLocal);
-      else
-      {
-	if ((host = gethostbyname(szLocal)) == NULL)
-	  return psock_errno("gethostbyname()"), 1;
-
-	addr_local = * (struct in_addr *) (host->h_addr);
-      }
-    }
-
-    if (!bSRV)
-    {
-      if (optind == argc)
-	usage();
-
-      if (isdigit(*argv[optind]))
-	addr_server.s_addr = inet_addr(argv[optind]);
-      else
-      {
-	if ((host = gethostbyname(argv[optind])) == NULL)
-	  return psock_errno("gethostbyname()"), 1;
-
-	addr_server = * (struct in_addr *) (host->h_addr);
-      }
-    }
-  }
-
-  /* do work */
-
-  signal(SIGINT, handler);
-
-  if (bSRV)
-  {
-    printf("\n");
-
-    if (bTCP)
-    {
-      if (newthread(TCP_Server))
-	return printf("Cannot create additional thread.\n"), 2;
-    }
-    if (bUDP)
-    {
-      if (newthread(UDP_Receiver))
-	return printf("Cannot create additional thread.\n"), 2;
-      if (newthread(UDP_Server))
-	return printf("Cannot create additional thread.\n"), 2;
-    }
-
-    for (;;) sleep(86400);
-  }
-  else
-  {
-    if (bTCP + bUDP > 1) /* exactly one only */
-      usage();
-
-    if (bTCP)
-      TCP_Bench(0);
-    else if (bUDP)
-    {
-      if (newthread(UDP_Receiver))
-	return printf("Cannot create additional thread.\n"), 2;
-      while (udpd == 0)	sleep(1);
-      UDP_Bench(0);
-    }
-  }
-
-  /* terminate */
-
-  printf("\n");
-
-  return 0;
-}
-
-/* end of netio.c */
+/* netio.c
+ *
+ * Author:  Kai-Uwe Rommel <rommel@ars.de>
+ * Created: Wed Sep 25 1996
+ */
+
+static char *rcsid =
+"$Id: netio.c,v 1.32 2012/11/22 16:47:24 Rommel Exp Rommel $";
+static char *rcsrev = "$Revision: 1.32 $";
+
+/*
+ * $Log: netio.c,v $
+ * Revision 1.32  2012/11/22 16:47:24  Rommel
+ * added binding to client sockets, too
+ *
+ * Revision 1.31  2010/10/14 16:44:38  Rommel
+ * fixed sleep calls
+ *
+ * Revision 1.30  2010/10/14 14:32:41  Rommel
+ * removed NetBIOS code
+ * added server side result printing
+ * fixed packet loss calculation (data type bug)
+ *
+ * Revision 1.29  2010/10/14 11:28:19  Rommel
+ * central printing routine
+ *
+ * Revision 1.28  2009/09/07 14:09:39  Rommel
+ * changed number output from bytes/KB to bytes/KB/MB
+ *
+ * Revision 1.27  2008/02/11 09:00:22  Rommel
+ * re-randomize buffer data for each loop run
+ *
+ * Revision 1.26  2005/08/30 14:45:51  Rommel
+ * minor fixes
+ *
+ * Revision 1.25  2004/05/26 07:23:04  Rommel
+ * some more corrections from Oliver Lau and Frank Schnell
+ *
+ * Revision 1.24  2004/05/17 16:01:03  Rommel
+ * fix for _send/_recv from Thomas Jahns
+ *
+ * Revision 1.23  2003/09/30 09:32:22  Rommel
+ * corrections from Matthias Scheler for error handling
+ * added socket buffer size setting
+ * added htonl/ntohl code (hint from Oliver Lau)
+ * restructured send/recv error/result checking
+ * more verbose server side messages
+ * other minor changes
+ *
+ * Revision 1.22  2003/09/22 14:58:33  Rommel
+ * added server side progress messages
+ *
+ * Revision 1.21  2003/08/28 12:44:11  Rommel
+ * fixed display of non-k-multiple packet sizes
+ *
+ * Revision 1.20  2003/08/27 11:05:48  Rommel
+ * allow block size specifikation in bytes or k bytes
+ *
+ * Revision 1.19  2003/08/17 16:53:45  Rommel
+ * added Unix/Linux pthreads support (required for UDP)
+ *
+ * Revision 1.18  2003/08/17 14:46:17  Rommel
+ * added UDP benchmark
+ * several minor changes (cleanup)
+ * configurable binding address
+ *
+ * Revision 1.17  2003/07/12 17:25:00  Rommel
+ * made block size selectable
+ *
+ * Revision 1.16  2003/02/10 09:06:59  Rommel
+ * fixed sender algorithm
+ *
+ * Revision 1.15  2001/09/17 13:56:40  Rommel
+ * changed to perform bidirectional benchmarks
+ *
+ * Revision 1.14  2001/04/19 12:20:55  Rommel
+ * added fixes for Unix systems
+ *
+ * Revision 1.13  2001/03/26 11:37:41  Rommel
+ * avoid integer overflows during throughput calculation
+ *
+ * Revision 1.12  2000/12/01 15:57:57  Rommel
+ * *** empty log message ***
+ *
+ * Revision 1.11  2000/03/01 12:21:47  rommel
+ * fixed _INTEGRAL_MAX_BITS problem for WIN32
+ *
+ * Revision 1.10  1999/10/28 17:36:57  rommel
+ * fixed OS/2 timer code
+ *
+ * Revision 1.9  1999/10/28 17:04:12  rommel
+ * fixed timer code
+ *
+ * Revision 1.8  1999/10/24 19:08:20  rommel
+ * imported DOS support from G. Vanem <giva@bgnett.no>
+ *
+ *
+ * Revision 1.8  1999/10/12 11:02:00  giva
+ * added Watt-32 with djgpp support. Added debug mode.
+ * G. Vanem <giva@bgnett.no>
+ *
+ * Revision 1.7  1999/06/13 18:42:25  rommel
+ * added Linux port with patches from Detlef Plotzky <plo@bvu.de>
+ *
+ * Revision 1.6  1998/10/12 11:14:58  rommel
+ * change to malloc'ed (and tiled) memory for transfer buffers
+ * (hint from Guenter Kukkukk <kukuk@berlin.snafu.de>)
+ * for increased performance
+ *
+ * Revision 1.5  1998/07/31 14:15:03  rommel
+ * added random buffer data
+ * fixed bugs
+ *
+ * Revision 1.4  1997/09/12 17:35:04  rommel
+ * termination bug fixes
+ *
+ * Revision 1.3  1997/09/12 12:00:15  rommel
+ * added Win32 port
+ * (tested for Windows NT only)
+ *
+ * Revision 1.2  1997/09/12 10:44:22  rommel
+ * added TCP/IP and a command line interface
+ *
+ * Revision 1.1  1996/09/25 08:42:29  rommel
+ * Initial revision
+ *
+ */
+
+#ifdef WIN32
+#define _INTEGRAL_MAX_BITS 64
+#endif
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
+#include <signal.h>
+#if defined(UNIX) || defined(DJGPP)
+#include <arpa/inet.h>
+#include <sys/time.h>
+#include <unistd.h>
+#include <errno.h>
+#else
+#include <process.h>
+#include "getopt.h"
+#endif
+
+#define DEFAULTPORT 0x494F /* "IO" */
+#define DEFAULTNBSRV "NETIOSRV"
+#define DEFAULTNBCLT "NETIOCLT"
+#define THREADSTACK 65536
+
+/* TCP/IP system specific details */
+
+#ifdef OS2
+
+#define BSD_SELECT
+#include <types.h>
+#include <netinet/in.h>
+#include <sys/select.h>
+#include <sys/socket.h>
+#include <sys/time.h>
+#include <netdb.h>
+
+#ifdef __IBMC__
+#define newthread(entry) (_beginthread(entry, 0, THREADSTACK, 0) == -1)
+#else
+#define newthread(entry) (_beginthread(entry, THREADSTACK, 0) == -1)
+#endif
+#define THREAD void
+#define THREADRESULT 
+
+#endif /* OS2 */
+
+#ifdef WATT32
+
+#include <tcp.h>       /* sock_init() etc. */
+#include <netinet/in.h>
+#include <sys/socket.h>
+#include <netdb.h>
+#define soclose     close_s
+#define select      select_s
+#define psock_errno perror
+
+#endif /* WATT32 */
+
+#ifdef WIN32
+
+#include <windows.h>
+#include <winsock.h>
+#define soclose closesocket
+
+int sock_init(void)
+{
+  WSADATA wsaData;
+  return WSAStartup(MAKEWORD(1, 1), &wsaData);
+}
+
+void psock_errno(char *text)
+{
+  int rc = WSAGetLastError();
+  printf("%s: error code %d\n", text, rc);
+}
+
+#ifdef __IBMC__
+#define newthread(entry) (_beginthread(entry, 0, THREADSTACK, 0) == -1)
+#else
+#define newthread(entry) (_beginthread(entry, THREADSTACK, 0) == -1)
+#endif
+#define THREAD void
+#define THREADRESULT 
+
+#endif /* WIN32 */
+
+#ifdef UNIX
+
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/time.h>
+#include <time.h>
+#include <netinet/in.h>
+#include <netdb.h>
+
+#define psock_errno(x) perror(x)
+#define soclose(x) close(x)
+
+int sock_init(void)
+{
+  return 0;
+}
+
+#include <pthread.h>
+pthread_t thread;
+#define newthread(entry) (pthread_create(&thread, 0, entry, 0) != 0)
+#define THREAD void*
+#define THREADRESULT ((void*)0)
+
+#endif /* UNIX */
+
+#ifdef SOCKLEN_T
+typedef socklen_t socklen_type;
+#else
+typedef size_t socklen_type;
+#endif
+
+/* global data */
+
+#ifndef max
+#define max(x, y) ((x) > (y) ? (x) : (y))
+#endif
+
+#ifndef min
+#define min(x, y) ((x) < (y) ? (x) : (y))
+#endif
+
+#ifndef EINTR
+#define EINTR 0
+#endif
+
+int nSizes[] = {1024, 2048, 4096, 8192, 16384, 32768};
+size_t nnSizes = sizeof(nSizes) / sizeof(int);
+#define NMAXSIZE 65536
+
+int tSizes[] = {1024, 2048, 4096, 8192, 16384, 32767};
+size_t ntSizes = sizeof(tSizes) / sizeof(int);
+#define TMAXSIZE 65536
+
+#define INTERVAL 6
+
+/* you may need to adapt this to your platform/compiler */
+typedef unsigned int uint32;
+
+typedef struct
+{
+  uint32 cmd;
+  uint32 data;
+}
+CONTROL;
+
+#define CMD_QUIT  0
+#define CMD_C2S   1
+#define CMD_S2C   2
+#define CMD_RES   3
+
+#define CTLSIZE sizeof(CONTROL)
+
+/* timer code */
+
+int bTimeOver;
+
+#ifdef OS2
+
+#define INCL_DOS
+#define INCL_NOPM
+#include <os2.h>
+
+typedef QWORD TIMER;
+
+void APIENTRY TimerThread(ULONG nSeconds)
+{
+  HEV hSem;
+  HTIMER hTimer;
+
+  DosCreateEventSem(0, &hSem, DC_SEM_SHARED, 0);
+
+  DosAsyncTimer(nSeconds * 1000, (HSEM) hSem, &hTimer);
+  DosWaitEventSem(hSem, SEM_INDEFINITE_WAIT);
+  DosStopTimer(hTimer);
+
+  DosCloseEventSem(hSem);
+
+  bTimeOver = 1;
+
+  DosExit(EXIT_THREAD, 0);
+}
+
+int StartAlarm(long nSeconds)
+{
+  TID ttid;
+
+  bTimeOver = 0;
+
+  if (DosCreateThread(&ttid, TimerThread, nSeconds, 0, THREADSTACK))
+    return printf("Cannot create timer thread.\n"), -1;
+
+  return 0;
+}
+
+int StartTimer(TIMER *nStart)
+{
+  if (DosTmrQueryTime(nStart))
+    return printf("Timer error.\n"), -1;
+
+  return 0;
+}
+
+long StopTimer(TIMER *nStart, int nAccuracy)
+{
+  TIMER nStop;
+  ULONG nFreq;
+
+  if (DosTmrQueryTime(&nStop))
+    return printf("Timer error.\n"), -1;
+  if (DosTmrQueryFreq(&nFreq))
+    return printf("Timer error.\n"), -1;
+
+  nFreq = (nFreq + nAccuracy / 2) / nAccuracy;
+
+  return (* (long long *) &nStop - * (long long *) nStart) / nFreq;
+}
+
+#endif /* OS2 */
+
+#ifdef WIN32
+
+typedef LARGE_INTEGER TIMER;
+
+#define sleep(x) Sleep((x) * 1000);
+
+DWORD CALLBACK TimerThread(void *pArg)
+{
+  long nSeconds = * (long *) pArg;
+
+  Sleep(nSeconds * 1000);
+  bTimeOver = 1;
+
+  return 0;
+}
+
+int StartAlarm(long nSeconds)
+{
+  static long sSeconds;
+  DWORD ttid;
+
+  sSeconds = nSeconds;
+
+  bTimeOver = 0;
+
+  if (CreateThread(0, THREADSTACK, TimerThread, (void *) &sSeconds, 0, &ttid) == NULL)
+    return printf("Cannot create timer thread.\n"), -1;
+
+  return 0;
+}
+
+int StartTimer(TIMER *nStart)
+{
+  if (!QueryPerformanceCounter(nStart))
+    return printf("Timer error.\n"), -1;
+
+  return 0;
+}
+
+long StopTimer(TIMER *nStart, int nAccuracy)
+{
+  TIMER nStop, nFreq;
+
+  if (!QueryPerformanceCounter(&nStop))
+    return printf("Timer error.\n"), -1;
+  if (!QueryPerformanceFrequency(&nFreq))
+    return printf("Timer error.\n"), -1;
+
+  nFreq.QuadPart = (nFreq.QuadPart + nAccuracy / 2) / nAccuracy;
+
+  return (nStop.QuadPart - nStart->QuadPart) / nFreq.QuadPart;
+}
+
+#endif /* WIN32 */
+
+#if defined(UNIX) || defined(DJGPP)
+
+typedef struct timeval TIMER;
+
+void on_alarm(int signum)
+{
+  alarm(0);
+  bTimeOver = 1;
+}
+
+int StartAlarm(long nSeconds)
+{
+  bTimeOver = 0;
+  signal(SIGALRM, on_alarm);
+  alarm(nSeconds);
+  return 0;
+}
+
+int StartTimer(TIMER *nStart)
+{
+  struct timezone tz = {0, 0};
+
+  gettimeofday(nStart, &tz);
+
+  return 0;
+}
+
+long StopTimer(TIMER *nStart, int nAccuracy)
+{
+  struct timezone tz = {0, 0};
+  TIMER nStop;
+
+  gettimeofday(&nStop, &tz);
+
+  return (nStop.tv_sec - nStart->tv_sec) * nAccuracy
+       + (nStop.tv_usec - nStart->tv_usec) * nAccuracy / 1000000;
+}
+
+#endif /* UNIX || DJGPP */
+
+/* initialize data to transfer */
+
+void GenerateRandomData(char *cBuffer, size_t nSize)
+{
+  if (cBuffer != NULL)
+  {
+    size_t i;
+ 
+    cBuffer[0] = 0;
+    srand(time(NULL));
+ 
+    for (i = 1; i < nSize; i++)
+      cBuffer[i] = (char) rand();
+  }
+}
+ 
+char *InitBuffer(size_t nSize)
+{
+ char *cBuffer = malloc(nSize); 
+ GenerateRandomData(cBuffer, nSize); 
+ return cBuffer;
+}
+
+char *PacketSize(int nSize)
+{
+  static char szBuffer[64];
+
+  if ((nSize % 1024) == 0 || (nSize % 1024) == 1023)
+    sprintf(szBuffer, "%2dk", (nSize + 512) / 1024);
+  else
+    sprintf(szBuffer, "%d", nSize);
+
+  return szBuffer;
+}
+
+/* print results */
+
+typedef enum {nf_auto, nf_bytes, nf_kbytes, nf_mbytes, nf_gbytes} numberformat;
+numberformat nFormat = nf_auto;
+
+void print_result(long long nData, long nTime)
+{
+  numberformat nThisFormat = nFormat;
+  double nResult;
+  
+  if (nThisFormat == nf_auto)
+  {
+    if (nData < 10 * 1024 * INTERVAL)
+      nThisFormat = nf_bytes;
+    else if (nData < 10 * 1024 * 1024 * INTERVAL)
+      nThisFormat = nf_kbytes;
+    else if (nData < (long long) 1024 * 1024 * 1024 * INTERVAL)
+      nThisFormat = nf_mbytes;
+    else
+      nThisFormat = nf_gbytes;
+  }
+
+  switch(nThisFormat)
+  {
+  case nf_bytes:
+    nResult = (double) nData * 1024 / nTime;
+    printf(" %0.0f Byte/s", nResult);
+    break;
+
+  case nf_kbytes:
+    nResult = (double) nData / nTime;
+    printf(" %0.2f KByte/s", nResult);
+    break;
+
+  case nf_mbytes:
+    nResult = (double) nData / nTime / 1024;
+    printf(" %0.2f MByte/s", nResult);
+    break;
+
+  case nf_gbytes:
+    nResult = (double) nData / nTime / 1024 / 1024;
+    printf(" %0.3f GByte/s", nResult);
+    break;
+  }
+}
+
+/* TCP/IP code */
+
+int send_data(int socket, void *buffer, size_t size, int flags)
+{
+  int rc = send(socket, buffer, size, flags);
+
+  if (rc < 0)
+  {
+    psock_errno("send()");
+    return -1;
+  }
+
+  if (rc != size)
+    return 1;
+
+  return 0;
+}
+
+int recv_data(int socket, void *buffer, size_t size, int flags)
+{
+  ssize_t rc = recv(socket, buffer, size, flags);
+
+  if (rc < 0)
+  {
+    psock_errno("recv()");
+    return -1;
+  }
+
+  if (rc != size)
+    return 1;
+
+  return 0;
+}
+
+const int sobufsize = 131072;
+int nPort = DEFAULTPORT;
+int nAuxPort = DEFAULTPORT + 1;
+#ifdef USE_IPV6
+struct in6_addr addr_server;
+struct in6_addr addr_local;
+#else
+struct in_addr addr_server;
+struct in_addr addr_local;
+#endif
+
+int udpsocket, udpd;
+unsigned long nUDPCount;
+long long nUDPData;
+
+THREAD TCP_Server(void *arg)
+{
+  char *cBuffer;
+  CONTROL ctl;
+  TIMER nTimer;
+  long nTime;
+  long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
+  int server, client;
+  socklen_type length;
+  struct timeval tv;
+  fd_set fds;
+  int rc;
+  int nByte;
+
+  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
+  {
+    perror("malloc()");
+    return THREADRESULT;
+  }
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
+  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
+  {
+    psock_errno("socket()");
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_local;
+#else
+  sa_server.sin_family = AF_INET;
+  sa_server.sin_port = htons(nPort);
+  sa_server.sin_addr = addr_local;
+#endif
+
+  if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  {
+    psock_errno("bind()");
+    soclose(server);
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  if (listen(server, 2) != 0)
+  {
+    psock_errno("listen()");
+    soclose(server);
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  for (;;)
+  {
+    printf("TCP server listening.\n");
+
+    FD_ZERO(&fds);
+    FD_SET(server, &fds);
+    tv.tv_sec  = 3600;
+    tv.tv_usec = 0;
+
+    if ((rc = select(FD_SETSIZE, &fds, 0, 0, &tv)) < 0)
+    {
+      psock_errno("select()");
+      break;
+    }
+
+    if (rc == 0 || FD_ISSET(server, &fds) == 0)
+      continue;
+
+    length = sizeof(sa_client);
+    if ((client = accept(server, (struct sockaddr *) &sa_client, &length)) == -1)
+      continue;
+
+    setsockopt(client, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+    setsockopt(client, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+    printf("TCP connection established ... ");
+    fflush(stdout);
+
+    for (;;)
+    {
+      if (recv_data(client, (void *) &ctl, CTLSIZE, 0))
+	break;
+
+      ctl.cmd = ntohl(ctl.cmd);
+      ctl.data = ntohl(ctl.data);
+
+      if (ctl.cmd == CMD_C2S)
+      {
+	StartTimer(&nTimer);
+
+	printf("\nReceiving from client, packet size %s ... ", PacketSize(ctl.data));
+	nData = 0;
+
+	do
+	{
+	  for (nByte = 0; nByte < ctl.data; )
+	  {
+	    rc = recv(client, cBuffer + nByte, ctl.data - nByte, 0);
+
+	    if (rc < 0 && errno != EINTR)
+	    {
+	      psock_errno("recv()");
+	      break;
+	    }
+	    
+	    if (rc > 0)
+	      nByte += rc;
+	  }
+
+	  nData += ctl.data;
+	}
+	while (cBuffer[0] == 0 && rc > 0);
+
+	if ((nTime = StopTimer(&nTimer, 1024)) != -1)
+	  print_result(nData, nTime);
+      }
+      else if (ctl.cmd == CMD_S2C)
+      {
+	if (StartAlarm(INTERVAL) == 0)
+	{
+	  StartTimer(&nTimer);
+
+	  printf("\nSending to client, packet size %s ... ", PacketSize(ctl.data));
+	  cBuffer[0] = 0;
+	  nData = 0;
+
+	  while (!bTimeOver)
+	  {
+	    //GenerateRandomData(cBuffer, ctl.data);
+
+	    for (nByte = 0; nByte < ctl.data; )
+	    {
+	      rc = send(client, cBuffer + nByte, ctl.data - nByte, 0);
+
+	      if (rc < 0 && errno != EINTR)
+	      {
+		psock_errno("send()");
+		break;
+	      }
+
+	      if (rc > 0)
+		nByte += rc;
+	    }
+
+	    nData += ctl.data;
+	  }
+
+	  cBuffer[0] = 1;
+
+	  if (send_data(client, cBuffer, ctl.data, 0))
+	    break;
+
+	  if ((nTime = StopTimer(&nTimer, 1024)) != -1)
+	    print_result(nData, nTime);
+	}
+      }
+      else /* quit */
+	break;
+    }
+
+    printf("\nDone.\n");
+
+    soclose(client);
+
+    if (rc < 0)
+      break;
+  }
+
+  soclose(server);
+  free(cBuffer);
+
+  return THREADRESULT;
+}
+
+void TCP_Bench(void *arg)
+{
+  char *cBuffer;
+  CONTROL ctl;
+  TIMER nTimer;
+  long nTime;
+  long long nData;
+  int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
+  int server;
+  int rc;
+  int nByte;
+
+  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
+  {
+    perror("malloc()");
+    return;
+  }
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
+  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
+  {
+    psock_errno("socket()");
+    free(cBuffer);
+    return;
+  }
+
+  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+#ifdef USE_IPV6
+  sa_client.sin6_family = AF_INET6;
+  sa_client.sin6_port = htons(0);
+  sa_client.sin6_addr = addr_local;
+#else
+  sa_client.sin_family = AF_INET;
+  sa_client.sin_port = htons(0);
+  sa_client.sin_addr = addr_local;
+#endif
+
+  if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
+  {
+    psock_errno("bind()");
+    soclose(server);
+    free(cBuffer);
+    return;
+  }
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_server;
+#else
+  sa_server.sin_family = AF_INET;
+  sa_server.sin_port = htons(nPort);
+  sa_server.sin_addr = addr_server;
+#endif
+
+  if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  {
+    psock_errno("connect()");
+    soclose(server);
+    free(cBuffer);
+    return;
+  }
+
+  printf("\nTCP connection established.\n");
+
+  for (i = 0; i < ntSizes; i++)
+  {
+    printf("Packet size %s bytes: ", PacketSize(tSizes[i]));
+    fflush(stdout);
+
+    /* tell the server we will send it data now */
+
+    ctl.cmd = htonl(CMD_C2S);
+    ctl.data = htonl(tSizes[i]);
+
+    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    /* 1 - Tx test */
+
+    if (StartAlarm(INTERVAL) == 0)
+    {
+      StartTimer(&nTimer);
+      nData = 0;
+      cBuffer[0] = 0;
+
+      while (!bTimeOver)
+      {
+	//GenerateRandomData(cBuffer, tSizes[i]);
+
+	for (nByte = 0; nByte < tSizes[i]; )
+	{
+	  rc = send(server, cBuffer + nByte, tSizes[i] - nByte, 0);
+
+	  if (rc < 0 && errno != EINTR)
+	  {
+	    psock_errno("send()");
+	    break;
+	  }
+	  
+	  if (rc > 0)
+	    nByte += rc;
+	}
+
+	nData += tSizes[i];
+      }
+
+      if ((nTime = StopTimer(&nTimer, 1024)) == -1)
+	printf(" (failed)");
+      else
+	print_result(nData, nTime);
+
+      printf(" Tx, ");
+      fflush(stdout);
+
+      cBuffer[0] = 1;
+
+      if (send_data(server, cBuffer, tSizes[i], 0))
+	break;
+    }
+
+    /* tell the server we expect him to send us data now */
+
+    ctl.cmd = htonl(CMD_S2C);
+    ctl.data = htonl(tSizes[i]);
+
+    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    /* 2 - Rx test */
+
+    StartTimer(&nTimer);
+    nData = 0;
+
+    do
+    {
+      for (nByte = 0; nByte < tSizes[i]; )
+      {
+	rc = recv(server, cBuffer + nByte, tSizes[i] - nByte, 0);
+
+	if (rc < 0 && errno != EINTR)
+	{
+	  psock_errno("recv()");
+	  break;
+	}
+	  
+	if (rc > 0)
+	  nByte += rc;
+      }
+
+      nData += tSizes[i];
+    }
+    while (cBuffer[0] == 0 && rc > 0);
+
+    if ((nTime = StopTimer(&nTimer, 1024)) == -1)
+      printf(" (failed)");
+    else
+      print_result(nData, nTime);
+
+    printf(" Rx.\n");
+  }
+
+  ctl.cmd = htonl(CMD_QUIT);
+  ctl.data = 0;
+
+  send_data(server, (void *) &ctl, CTLSIZE, 0);
+
+  printf("Done.\n");
+
+  soclose(server);
+  free(cBuffer);
+}
+
+THREAD UDP_Receiver(void *arg)
+{
+  char *cBuffer;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
+  int rc;
+  socklen_type nBytes;
+
+  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
+  {
+    perror("malloc()");
+    return THREADRESULT;
+  }
+
+#ifdef USE_IPV6
+  if ((udpsocket = socket(PF_INET6, SOCK_DGRAM, 0)) < 0)
+#else
+  if ((udpsocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
+#endif
+  {
+    psock_errno("socket(DGRAM)");
+    free(cBuffer);
+    return THREADRESULT;
+  }
+  
+  setsockopt(udpsocket, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+  setsockopt(udpsocket, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_local;
+#else
+  sa_server.sin_family = AF_INET;
+  sa_server.sin_port = htons(nAuxPort);
+  sa_server.sin_addr = addr_local;
+#endif
+
+  if (bind(udpsocket, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  {
+    psock_errno("bind(DGRAM)");
+    soclose(udpsocket);
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  udpd = 1;
+
+  for (;;)
+  {
+    nBytes = sizeof(sa_client);
+    rc = recvfrom(udpsocket, cBuffer, TMAXSIZE, 0, (struct sockaddr *) &sa_client, &nBytes);
+
+    if (rc < 0 && errno != EINTR)
+      psock_errno("recvfrom()");
+
+    if (rc > 0)
+    {
+      nUDPCount++;
+      nUDPData += rc;
+    }
+  }
+
+  soclose(udpsocket);
+  free(cBuffer);
+
+  return THREADRESULT;
+}
+
+THREAD UDP_Server(void *arg)
+{
+  char *cBuffer;
+  CONTROL ctl;
+  TIMER nTimer;
+  long nTime;
+  long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
+  int server, client;
+  struct timeval tv;
+  fd_set fds;
+  int rc, nByte;
+  socklen_type nLength;
+
+  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
+  {
+    perror("malloc()");
+    return THREADRESULT;
+  }
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
+  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
+  {
+    psock_errno("socket(STREAM)");
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_local;
+#else
+  sa_server.sin_family = AF_INET;
+  sa_server.sin_port = htons(nAuxPort);
+  sa_server.sin_addr = addr_local;
+#endif
+
+  if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  {
+    psock_errno("bind(STREAM)");
+    soclose(server);
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  if (listen(server, 2) != 0)
+  {
+    psock_errno("listen()");
+    soclose(server);
+    free(cBuffer);
+    return THREADRESULT;
+  }
+
+  for (;;)
+  {
+    printf("UDP server listening.\n");
+
+    FD_ZERO(&fds);
+    FD_SET(server, &fds);
+    tv.tv_sec  = 3600;
+    tv.tv_usec = 0;
+
+    if ((rc = select(FD_SETSIZE, &fds, 0, 0, &tv)) < 0)
+    {
+      psock_errno("select()");
+      break;
+    }
+
+    if (rc == 0 || FD_ISSET(server, &fds) == 0)
+      continue;
+
+    nLength = sizeof(sa_client);
+    if ((client = accept(server, (struct sockaddr *) &sa_client, &nLength)) == -1)
+      continue;
+
+    setsockopt(client, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+    setsockopt(client, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+    printf("UDP connection established ... ");
+    fflush(stdout);
+
+#ifdef USE_IPV6
+	sa_client.sin6_port = htons(nAuxPort);
+#else
+    sa_client.sin_port = htons(nAuxPort);
+#endif
+
+    for (;;)
+    {
+      if (recv_data(client, (void *) &ctl, CTLSIZE, 0))
+	break;
+
+      ctl.cmd = ntohl(ctl.cmd);
+      ctl.data = ntohl(ctl.data);
+
+      if (ctl.cmd == CMD_C2S)
+      {
+	StartTimer(&nTimer);
+	nUDPCount = 0;
+	nUDPData = 0;
+
+	printf("\nReceiving from client, packet size %s ... ", PacketSize(ctl.data));
+
+	ctl.cmd = htonl(ctl.cmd);
+	ctl.data = htonl(ctl.data);
+
+	if (send_data(client, (void *) &ctl, CTLSIZE, 0))
+	  break;
+      }
+      else if (ctl.cmd == CMD_RES)
+      {
+	ctl.cmd = htonl(ctl.cmd);
+	ctl.data = htonl(nUDPCount);
+
+	if (send_data(client, (void *) &ctl, CTLSIZE, 0))
+	  break;
+
+	if ((nTime = StopTimer(&nTimer, 1024)) != -1)
+	  print_result(nUDPData, nTime);
+      }
+      else if (ctl.cmd == CMD_S2C)
+      {
+	if (StartAlarm(INTERVAL) == 0)
+	{
+	  StartTimer(&nTimer);
+	  nData = 0;
+
+	  printf("\nSending to client, packet size %s ... ", PacketSize(ctl.data));
+	  cBuffer[0] = 0;
+	  nLength = ctl.data;
+
+	  ctl.cmd = htonl(CMD_RES);
+	  ctl.data = 0;
+
+	  while (!bTimeOver)
+	  {
+	    //GenerateRandomData(cBuffer, nLength);
+
+	    for (nByte = 0; nByte < nLength; )
+	    {
+	      do
+	      {
+	        rc = sendto(udpsocket, cBuffer + nByte, nLength - nByte, 0, 
+			    (struct sockaddr *) &sa_client, sizeof(sa_client));
+	      }
+#ifdef ENOBUFS
+	      while (rc < 0 && errno == ENOBUFS);
+#else
+	      while (0);
+#endif
+
+	      if (rc < 0 && errno != EINTR)
+	      {
+		psock_errno("sendto()");
+		break;
+	      }
+	      
+	      if (rc > 0)
+		nByte += rc;
+	    }
+
+	    ctl.data++;
+	    nData += nLength;
+	  }
+
+	  ctl.data = htonl(ctl.data);
+
+	  if (send_data(client, (void *) &ctl, CTLSIZE, 0))
+	    break;
+
+	  if ((nTime = StopTimer(&nTimer, 1024)) != -1)
+	    print_result(nData, nTime);
+	}
+      }
+      else /* quit */
+	break;
+    }
+
+    printf("\nDone.\n");
+
+    soclose(client);
+
+    if (rc < 0)
+      break;
+  }
+
+  soclose(server);
+  free(cBuffer);
+
+  return THREADRESULT;
+}
+
+void UDP_Bench(void *arg)
+{
+  char *cBuffer;
+  CONTROL ctl;
+  TIMER nTimer;
+  long nTime, nCount;
+  long nResult;
+  long long nData;
+  int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
+  int server;
+  int rc, nByte;
+
+  if ((cBuffer = InitBuffer(TMAXSIZE)) == NULL)
+  {
+    perror("malloc()");
+    return;
+  }
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
+  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
+  {
+    psock_errno("socket()");
+    free(cBuffer);
+    return;
+  }
+
+  setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
+  setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
+
+#ifdef USE_IPV6
+  sa_client.sin6_family = AF_INET6;
+  sa_client.sin6_port = htons(0);
+  sa_client.sin6_addr = addr_local;
+#else
+  sa_client.sin_family = AF_INET;
+  sa_client.sin_port = htons(0);
+  sa_client.sin_addr = addr_local;
+#endif
+
+  if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
+  {
+    psock_errno("bind(STREAM)");
+    soclose(server);
+    free(cBuffer);
+    return;
+  }
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_server;
+#else
+  sa_server.sin_family = AF_INET;
+  sa_server.sin_port = htons(nAuxPort);
+  sa_server.sin_addr = addr_server;
+#endif
+
+  if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  {
+    psock_errno("connect()");
+    soclose(server);
+    free(cBuffer);
+    return;
+  }
+
+  printf("\nUDP connection established.\n");
+
+  for (i = 0; i < ntSizes; i++)
+  {
+    printf("Packet size %s bytes: ", PacketSize(tSizes[i]));
+    fflush(stdout);
+
+    /* tell the server we will send it data now */
+
+    ctl.cmd = htonl(CMD_C2S);
+    ctl.data = htonl(tSizes[i]);
+
+    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    /* 1 - Tx test */
+
+    if (StartAlarm(INTERVAL) == 0)
+    {
+      StartTimer(&nTimer);
+      nData = 0;
+      nCount = 0;
+      cBuffer[0] = 0;
+
+      while (!bTimeOver)
+      {
+	//GenerateRandomData(cBuffer, tSizes[i]);
+
+	for (nByte = 0; nByte < tSizes[i]; )
+	{
+	  rc = sendto(udpsocket, cBuffer + nByte, tSizes[i] - nByte, 0, 
+		      (struct sockaddr *) &sa_server, sizeof(sa_server));
+
+	  if (rc < 0)
+	  {
+	    if (errno != EINTR)
+	    {
+	      psock_errno("sendto()");
+	      break;
+	    }
+	  }
+	  else
+	    nByte += rc;
+	}
+
+	nData += tSizes[i];
+	nCount++;
+      }
+      
+      if ((nTime = StopTimer(&nTimer, 1024)) == -1)
+	printf(" (failed)");
+
+      ctl.cmd = htonl(CMD_RES);
+
+      if (send_data(server, (void *) &ctl, CTLSIZE, 0))
+	break;
+
+      if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
+	break;
+
+      ctl.data = ntohl(ctl.data);
+      nData = (long long) tSizes[i] * ctl.data;
+
+      print_result(nData, nTime);
+      nResult = (nCount - ctl.data) * 100 / nCount;
+      printf(" (%ld%%) Tx, ", nResult);
+      fflush(stdout);
+    }
+
+    /* tell the server we expect him to send us data now */
+
+    ctl.cmd = htonl(CMD_S2C);
+    ctl.data = htonl(tSizes[i]);
+
+    if (send_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    /* 2 - Rx test */
+
+    StartTimer(&nTimer);
+    nUDPCount = 0;
+    nUDPData = 0;
+
+    if (recv_data(server, (void *) &ctl, CTLSIZE, 0))
+      break;
+
+    if ((nTime = StopTimer(&nTimer, 1024)) == -1)
+      printf(" (failed)");
+
+    ctl.data = ntohl(ctl.data);
+
+    print_result(nUDPData, nTime);
+    nResult = (ctl.data - nUDPCount) * 100 / ctl.data;
+    printf(" (%ld%%) Rx.\n", nResult);
+  }
+
+  ctl.cmd = htonl(CMD_QUIT);
+  ctl.data = 0;
+
+  send_data(server, (void *) &ctl, CTLSIZE, 0);
+
+  printf("Done.\n");
+
+  soclose(server);
+  free(cBuffer);
+}
+
+/* main / user interface */
+
+int bSRV, bTCP, bUDP;
+
+void handler(int sig)
+{
+  _exit(0);
+}
+
+void usage(void)
+{
+  printf(
+	 "\nUsage: netio [options] [<server>]\n"
+	 "\n  -s              run server side of benchmark (otherwise run client)"
+	 "\n  -b <size>[k]    use this block size (otherwise run with 1,2,4,8,16 and 32k)"
+	 "\n  -B -K -M -G     force number formatting to Bytes, K, M or G Bytes\n"
+
+	 "\n  -t              use TCP protocol for benchmark"
+	 "\n  -u              use UDP protocol for benchmark"
+	 "\n  -h <addr/name>  bind TCP and UDP sockets to this local host address/name"
+	 "\n                  defaults to all (server) or unspecified (client)"
+	 "\n  -p <port>       bind TCP and UDP servers to this port (default is %d)\n"
+
+         "\n  <server>        If the client side of the benchmark is running,"
+	 "\n                  a server name or address is required.\n"
+
+	 "\nThe server side can run either TCP (-t) or UDP (-u) protocol or both"
+	 "\n(default, if neither -t or -u is specified). The client runs one of"
+	 "\nthese protocols only (must specify -t or -u).\n"
+	 "\n", nPort);
+  exit(1);
+}
+
+int main(int argc, char **argv)
+{
+  char szVersion[32], *szName = 0, *szLocal = 0, *szEnd;
+  int option;
+  struct hostent *host;
+  long nSize;
+
+  strcpy(szVersion, rcsrev + sizeof("$Revision: ") - 1);
+  *strchr(szVersion, ' ') = 0;
+
+  printf("\nNETIO - Network Throughput Benchmark, Version %s"
+	 "\n(C) 1997-2012 Kai Uwe Rommel\n", szVersion);
+
+  if (argc == 1)
+    usage();
+
+  /* check arguments */
+
+  while ((option = getopt(argc, argv, "?stup:h:b:dBKMG")) !=  -1)
+    switch (option)
+    {
+    case 's':
+      bSRV = 1;
+      break;
+    case 't':
+      bTCP = 1;
+      break;
+    case 'u':
+      bUDP = 1;
+      break;
+    case 'p':
+      nPort = atoi(optarg);
+      nAuxPort = nPort + 1;
+      break;
+    case 'h':
+      szLocal = optarg;
+      break;
+    case 'b':
+      nSize = strtol(optarg, &szEnd, 10);
+      if (*szEnd == 'k')
+	nSize *= 1024;
+      nSizes[0] = min(max(nSize, 1), NMAXSIZE);
+      tSizes[0] = min(max(nSize, 1), TMAXSIZE);
+      nnSizes = ntSizes = 1;
+      break;
+#ifdef WATT32
+    case 'd':
+      dbug_init();
+      break;
+#endif
+    case 'B':
+      nFormat = nf_bytes;
+      break;
+    case 'K':
+      nFormat = nf_kbytes;
+      break;
+    case 'M':
+      nFormat = nf_mbytes;
+      break;
+    case 'G':
+      nFormat = nf_gbytes;
+      break;
+    default:
+      usage();
+      break;
+    }
+
+  if (bSRV == 1 && bTCP == 0 && bUDP == 0)
+    bTCP = bUDP = 1;
+
+  /* initialize TCP/IP */
+
+  if (bTCP || bUDP)
+  {
+    if (sock_init())
+      return psock_errno("sock_init()"), 1;
+
+    if (szLocal == 0)
+#ifdef USE_IPV6
+	  addr_local = in6addr_any;
+#else
+      addr_local.s_addr = INADDR_ANY;
+#endif
+    else
+    {
+      if (isdigit(*szLocal))
+#ifdef USE_IPV6
+	inet_pton(AF_INET6, szLocal, &addr_local);
+#else
+	addr_local.s_addr = inet_addr(szLocal);
+#endif
+      else
+      {
+	if ((host = gethostbyname(szLocal)) == NULL)
+	  return psock_errno("gethostbyname()"), 1;
+
+#ifdef USE_IPV6
+	addr_local = * (struct in6_addr *) (host->h_addr);
+#else
+	addr_local = * (struct in_addr *) (host->h_addr);
+#endif
+      }
+    }
+
+    if (!bSRV)
+    {
+      if (optind == argc)
+	usage();
+
+      if (isdigit(*argv[optind]))
+#ifdef USE_IPV6
+	inet_pton(AF_INET6, argv[optind], &addr_server);
+#else
+	addr_server.s_addr = inet_addr(argv[optind]);
+#endif
+      else
+      {
+	if ((host = gethostbyname(argv[optind])) == NULL)
+	  return psock_errno("gethostbyname()"), 1;
+
+#ifdef USE_IPV6
+	addr_server = * (struct in6_addr *) (host->h_addr);
+#else
+	addr_server = * (struct in_addr *) (host->h_addr);
+#endif
+      }
+    }
+  }
+
+  /* do work */
+
+  signal(SIGINT, handler);
+
+  if (bSRV)
+  {
+    printf("\n");
+
+    if (bTCP)
+    {
+      if (newthread(TCP_Server))
+	return printf("Cannot create additional thread.\n"), 2;
+    }
+    if (bUDP)
+    {
+      if (newthread(UDP_Receiver))
+	return printf("Cannot create additional thread.\n"), 2;
+      if (newthread(UDP_Server))
+	return printf("Cannot create additional thread.\n"), 2;
+    }
+
+    for (;;) sleep(86400);
+  }
+  else
+  {
+    if (bTCP + bUDP > 1) /* exactly one only */
+      usage();
+
+    if (bTCP)
+      TCP_Bench(0);
+    else if (bUDP)
+    {
+      if (newthread(UDP_Receiver))
+	return printf("Cannot create additional thread.\n"), 2;
+      while (udpd == 0)	sleep(1);
+      UDP_Bench(0);
+    }
+  }
+
+  /* terminate */
+
+  printf("\n");
+
+  return 0;
+}
+
+/* end of netio.c */
+
