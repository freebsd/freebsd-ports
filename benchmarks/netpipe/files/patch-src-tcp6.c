Index: src/tcp6.c
===================================================================
RCS file: src/tcp6.c
diff -N src/tcp6.c
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ src/tcp6.c	9 Sep 2004 08:35:07 -0000	1.1
@@ -0,0 +1,444 @@
+/*****************************************************************************/
+/* "NetPIPE" -- Network Protocol Independent Performance Evaluator.          */
+/* Copyright 1997, 1998 Iowa State University Research Foundation, Inc.      */
+/*                                                                           */
+/* This program is free software; you can redistribute it and/or modify      */
+/* it under the terms of the GNU General Public License as published by      */
+/* the Free Software Foundation.  You should have received a copy of the     */
+/* GNU General Public License along with this program; if not, write to the  */
+/* Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.   */
+/*                                                                           */
+/* TCP6 extension Copyright 2004 George V. Neville-Neil and Neville-Neil     */
+/* Consulting                                                                */
+/*                                                                           */
+/*     * tcp6.c         ---- TCP over IPv6 calls source                      */
+/*     * tcp.h          ---- Include file for TCP6 calls and data structs    */
+/*****************************************************************************/
+#include    "netpipe.h"
+
+#if defined (MPLITE)
+#include "mplite.h"
+#endif
+
+
+int doing_reset = 0;
+
+void Init(ArgStruct *p, int* pargc, char*** pargv)
+{
+    p->reset_conn = 0; /* Default to not resetting connection */
+    p->prot.sndbufsz = p->prot.rcvbufsz = 0;
+    /* The transmitter will be set using the -h host flag. */
+    p->tr = 0;
+    p->rcv = 1;
+}
+
+void Setup(ArgStruct *p)
+{
+    int one = 1;
+    int sockfd = -1;
+    /* ptr to sockaddr_in in ArgStruct */
+    struct sockaddr_in6 *lsin1, *lsin2;      
+    
+    char *host;
+    struct hostent *hp;
+    struct protoent *proto;
+    int send_size, recv_size, sizeofint = sizeof(int);
+	
+    host = p->host;                           /* copy ptr to hostname */ 
+	
+    lsin1 = &(p->prot.sin1);
+    lsin2 = &(p->prot.sin2);
+	
+    bzero((char *) lsin1, sizeof(*lsin1));
+    bzero((char *) lsin2, sizeof(*lsin2));
+
+    if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0){
+	printf("NetPIPE: can't open stream socket! errno=%d\n", errno);
+	exit(-4);
+    }
+
+    if(!(proto = getprotobyname("tcp"))){
+	printf("NetPIPE: protocol 'tcp' unknown!\n");
+	exit(555);
+    }
+
+    /* Attempt to set TCP_NODELAY */
+
+    if(setsockopt(sockfd, proto->p_proto, TCP_NODELAY, &one, sizeof(one)) < 0)
+    {
+	printf("NetPIPE: setsockopt: TCP_NODELAY failed! errno=%d\n", errno);
+	exit(556);
+    }
+
+    /* If requested, set the send and receive buffer sizes */
+
+    if(p->prot.sndbufsz > 0)
+    {
+	if(setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &(p->prot.sndbufsz), 
+		      sizeof(p->prot.sndbufsz)) < 0)
+	{
+	    printf("NetPIPE: setsockopt: SO_SNDBUF failed! errno=%d\n", errno);
+	    printf("You may have asked for a buffer larger than the system can handle\n");
+	    exit(556);
+	}
+	if(setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &(p->prot.rcvbufsz), 
+		      sizeof(p->prot.rcvbufsz)) < 0)
+	{
+	    printf("NetPIPE: setsockopt: SO_RCVBUF failed! errno=%d\n", errno);
+	    printf("You may have asked for a buffer larger than the system can handle\n");
+	    exit(556);
+	}
+    }
+    getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF,
+	       (char *) &send_size, (void *) &sizeofint);
+    getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF,
+	       (char *) &recv_size, (void *) &sizeofint);
+ 
+    if(!doing_reset) {
+	fprintf(stderr,"Send and receive buffers are %d and %d bytes\n",
+		send_size, recv_size);
+	fprintf(stderr, "(A bug in Linux doubles the requested buffer sizes)\n");
+    }
+
+    if( p->tr ) {                             /* Primary transmitter */
+
+	lsin1->sin6_family = AF_INET6;
+
+	/* First attempt to convert the string to an IPv6 */
+	/* address. */
+	/* If the user supplied a real host name this will fail and */
+  	/* we'll then do a name lookup. */
+
+	if (inet_pton(AF_INET6, host, &lsin1->sin6_addr) == 0)
+	{
+	    if ((hp = gethostbyname2(host, AF_INET6)) == NULL)
+	    {
+		printf("NetPIPE: invalid hostname '%s'\n", host);
+		exit(-5);
+	    }
+
+	    if (hp->h_addrtype != AF_INET6) 
+	    {
+		printf("NetPIPE: invalid hostname '%s'\n", host);
+		exit(-5);
+	    }
+	    bcopy(hp->h_addr, (char*) &(lsin1->sin6_addr), 
+		  hp->h_length);
+	}
+
+	lsin1->sin6_port = htons(p->port);
+	
+	p->commfd = sockfd;
+	
+    } else if( p->rcv ) {                     /* we are the receiver */
+	bzero((char *) lsin1, sizeof(*lsin1));
+	lsin1->sin6_family  = AF_INET6;
+	lsin1->sin6_len     = sizeof(*lsin1);
+	lsin1->sin6_port    = htons(p->port);
+	/* Setting this to all 0 is the "ANY" address. */
+	bzero(&lsin1->sin6_addr, sizeof(lsin1->sin6_addr));
+   
+	if (bind(sockfd, (struct sockaddr *) lsin1, sizeof(*lsin1)) < 0){
+	    printf("NetPIPE: server: bind on local address failed! errno=%d", errno);
+	    exit(-6);
+	}
+
+	p->servicefd = sockfd;
+    }
+    p->upper = send_size + recv_size;
+
+    establish(p);                               /* Establish connections */
+
+}   
+
+static int
+readFully(int fd, void *obuf, int len)
+{
+    int bytesLeft = len;
+    char *buf = (char *) obuf;
+    int bytesRead = 0;
+
+    while (bytesLeft > 0 &&
+	   (bytesRead = read(fd, (void *) buf, bytesLeft)) > 0)
+    {
+	bytesLeft -= bytesRead;
+	buf += bytesRead;
+    }
+    if (bytesRead <= 0) return bytesRead;
+    return len;
+}
+
+void Sync(ArgStruct *p)
+{
+    char s[] = "SyncMe", response[] = "      ";
+
+    if (write(p->commfd, s, strlen(s)) < 0 ||           /* Write to nbor */
+	readFully(p->commfd, response, strlen(s)) < 0)  /* Read from nbor */
+    {
+	perror("NetPIPE: error writing or reading synchronization string");
+	exit(3);
+    }
+    if (strncmp(s, response, strlen(s)))
+    {
+	fprintf(stderr, "NetPIPE: Synchronization string incorrect! |%s|\n", response);
+	exit(3);
+    }
+}
+
+void PrepareToReceive(ArgStruct *p)
+{
+    /*
+      The Berkeley sockets interface doesn't have a method to pre-post
+      a buffer for reception of data.
+    */
+}
+
+void SendData(ArgStruct *p)
+{
+    int bytesWritten, bytesLeft;
+    char *q;
+
+    bytesLeft = p->bufflen;
+    bytesWritten = 0;
+    q = p->s_ptr;
+    while (bytesLeft > 0 &&
+	   (bytesWritten = write(p->commfd, q, bytesLeft)) > 0)
+    {
+	bytesLeft -= bytesWritten;
+	q += bytesWritten;
+    }
+    if (bytesWritten == -1)
+    {
+	printf("NetPIPE: write: error encountered, errno=%d\n", errno);
+	exit(401);
+    }
+}
+
+void RecvData(ArgStruct *p)
+{
+    int bytesLeft;
+    int bytesRead;
+    char *q;
+
+    bytesLeft = p->bufflen;
+    bytesRead = 0;
+    q = p->r_ptr;
+    while (bytesLeft > 0 &&
+	   (bytesRead = read(p->commfd, q, bytesLeft)) > 0)
+    {
+	bytesLeft -= bytesRead;
+	q += bytesRead;
+    }
+    if (bytesLeft > 0 && bytesRead == 0)
+    {
+	printf("NetPIPE: \"end of file\" encountered on reading from socket\n");
+    }
+    else if (bytesRead == -1)
+    {
+	printf("NetPIPE: read: error encountered, errno=%d\n", errno);
+	exit(401);
+    }
+}
+
+/* uint32_t is used to insure that the integer size is the same even in tests 
+ * between 64-bit and 32-bit architectures. */
+
+void SendTime(ArgStruct *p, double *t)
+{
+    uint32_t ltime, ntime;
+
+    /*
+      Multiply the number of seconds by 1e8 to get time in 0.01 microseconds
+      and convert value to an unsigned 32-bit integer.
+    */
+    ltime = (uint32_t)(*t * 1.e8);
+
+    /* Send time in network order */
+    ntime = htonl(ltime);
+    if (write(p->commfd, (char *)&ntime, sizeof(uint32_t)) < 0)
+    {
+	printf("NetPIPE: write failed in SendTime: errno=%d\n", errno);
+	exit(301);
+    }
+}
+
+void RecvTime(ArgStruct *p, double *t)
+{
+    uint32_t ltime, ntime;
+    int bytesRead;
+
+    bytesRead = readFully(p->commfd, (void *)&ntime, sizeof(uint32_t));
+    if (bytesRead < 0)
+    {
+	printf("NetPIPE: read failed in RecvTime: errno=%d\n", errno);
+	exit(302);
+    }
+    else if (bytesRead != sizeof(uint32_t))
+    {
+	fprintf(stderr, "NetPIPE: partial read in RecvTime of %d bytes\n",
+		bytesRead);
+	exit(303);
+    }
+    ltime = ntohl(ntime);
+
+    /* Result is ltime (in microseconds) divided by 1.0e8 to get seconds */
+
+    *t = (double)ltime / 1.0e8;
+}
+
+void SendRepeat(ArgStruct *p, int rpt)
+{
+    uint32_t lrpt, nrpt;
+
+    lrpt = rpt;
+    /* Send repeat count as a long in network order */
+    nrpt = htonl(lrpt);
+    if (write(p->commfd, (void *) &nrpt, sizeof(uint32_t)) < 0)
+    {
+	printf("NetPIPE: write failed in SendRepeat: errno=%d\n", errno);
+	exit(304);
+    }
+}
+
+void RecvRepeat(ArgStruct *p, int *rpt)
+{
+    uint32_t lrpt, nrpt;
+    int bytesRead;
+
+    bytesRead = readFully(p->commfd, (void *)&nrpt, sizeof(uint32_t));
+    if (bytesRead < 0)
+    {
+	printf("NetPIPE: read failed in RecvRepeat: errno=%d\n", errno);
+	exit(305);
+    }
+    else if (bytesRead != sizeof(uint32_t))
+    {
+	fprintf(stderr, "NetPIPE: partial read in RecvRepeat of %d bytes\n",
+		bytesRead);
+	exit(306);
+    }
+    lrpt = ntohl(nrpt);
+
+    *rpt = lrpt;
+}
+
+void establish(ArgStruct *p)
+{
+    int one = 1;
+    socklen_t clen;
+    struct protoent *proto;
+
+    clen = (socklen_t) sizeof(p->prot.sin2);
+
+    if( p->tr ){
+
+	while( connect(p->commfd, (struct sockaddr *) &(p->prot.sin1),
+		       sizeof(p->prot.sin1)) < 0 ) {
+
+	    /* If we are doing a reset and we get a connection refused from
+	     * the connect() call, assume that the other node has not yet
+	     * gotten to its corresponding accept() call and keep trying until
+	     * we have success.
+	     */
+	    if(!doing_reset || errno != ECONNREFUSED) {
+		printf("Client: Cannot Connect! errno=%d\n",errno);
+		exit(-10);
+	    } 
+        
+	}
+
+    } else if( p->rcv ) {
+
+	/* SERVER */
+	listen(p->servicefd, 5);
+	p->commfd = accept(p->servicefd, (struct sockaddr *) &(p->prot.sin2), &clen);
+
+	if(p->commfd < 0){
+	    printf("Server: Accept Failed! errno=%d\n",errno);
+	    exit(-12);
+	}
+
+	/*
+	  Attempt to set TCP_NODELAY. TCP_NODELAY may or may not be propagated
+	  to accepted sockets.
+	*/
+	if(!(proto = getprotobyname("tcp"))){
+	    printf("unknown protocol!\n");
+	    exit(555);
+	}
+
+	if(setsockopt(p->commfd, proto->p_proto, TCP_NODELAY,
+		      &one, sizeof(one)) < 0)
+	{
+	    printf("setsockopt: TCP_NODELAY failed! errno=%d\n", errno);
+	    exit(556);
+	}
+
+	/* If requested, set the send and receive buffer sizes */
+	if(p->prot.sndbufsz > 0)
+	{
+/*      printf("Send and Receive Buffers on accepted socket set to %d bytes\n",*/
+/*           p->prot.sndbufsz);*/
+	    if(setsockopt(p->commfd, SOL_SOCKET, SO_SNDBUF, &(p->prot.sndbufsz), 
+			  sizeof(p->prot.sndbufsz)) < 0)
+	    {
+		printf("setsockopt: SO_SNDBUF failed! errno=%d\n", errno);
+		exit(556);
+	    }
+	    if(setsockopt(p->commfd, SOL_SOCKET, SO_RCVBUF, &(p->prot.rcvbufsz), 
+			  sizeof(p->prot.rcvbufsz)) < 0)
+	    {
+		printf("setsockopt: SO_RCVBUF failed! errno=%d\n", errno);
+		exit(556);
+	    }
+	}
+    }
+}
+
+void CleanUp(ArgStruct *p)
+{
+    char *quit="QUIT";
+
+    if (p->tr) {
+
+	write(p->commfd,quit, 5);
+	read(p->commfd, quit, 5);
+	close(p->commfd);
+
+    } else if( p->rcv ) {
+
+	read(p->commfd,quit, 5);
+	write(p->commfd,quit,5);
+	close(p->commfd);
+	close(p->servicefd);
+
+    }
+}
+
+
+void Reset(ArgStruct *p)
+{
+  
+    /* Reset sockets */
+
+    if(p->reset_conn) {
+
+	doing_reset = 1;
+
+	/* Close the sockets */
+
+	CleanUp(p);
+
+	/* Now open and connect new sockets */
+
+	Setup(p);
+
+    }
+
+}
+
+void AfterAlignmentInit(ArgStruct *p)
+{
+
+}
+


