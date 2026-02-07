--- nsping.c.orig	Wed Jul 20 15:23:29 2005
+++ nsping.c	Wed Feb 16 10:41:04 2005
@@ -14,6 +14,9 @@
 #include <stdarg.h>
 #include <assert.h>
 
+
+#define MAX_ID	65536
+
 /* store state on sent queries */
 
 struct nsq {
@@ -26,8 +29,17 @@
  * too much stuff through globals. Sorry.
  */
 
+#if 0
 u_int32_t Target_Address 	= INADDR_NONE;
+#endif
+struct in_addr 		sin_addr; /* XXX = INADDR_NONE; */
+struct in6_addr 	sin6_addr; /* XXX = ; IN6ADDR_ANY_INIT */
+#if 0
 u_int16_t Target_Port 	= DNS_PORT;
+#endif
+char *Target_Port	= NULL;
+char addr_string[255];
+struct addrinfo		*ainfo;
 char *Zone 		= NULL;
 char *Hostname 		= NULL;
 
@@ -55,7 +67,7 @@
 	struct timeval *tvp;
 	struct itimerval itv;
 	u_int32_t address = INADDR_ANY;
-	u_int32_t port = getpid() + 1024;
+	char Local_Port[6]; 
 	char *timearg = NULL;
 	char c;
 	int i;
@@ -65,6 +77,10 @@
 		Queries[i].found = 1;
 	}
 
+	Target_Port = xstrdup(DNS_PORT);
+	/* XXX check for result */
+ 	snprintf(Local_Port, sizeof(Local_Port), "%d", getpid() + 1024);
+
 #define OPTS "z:h:t:p:dP:a:c:T:rR"
 
 	while((c = getopt(argc, argv, OPTS)) != EOF) {
@@ -105,15 +121,17 @@
 			break;			
 
 		case 'p':
-			Target_Port = atoi(optarg);
+			Target_Port = xstrdup(optarg);
 			break;
 
 		case 'P':
-			port = atoi(optarg);
+			strncpy(Local_Port, optarg, sizeof(Local_Port));
 			break;
 
 		case 'a':
-			address = resolve(optarg);
+#if 0
+			address = resolve(optarg, port);
+#endif
 			if(address == INADDR_NONE) {
 				fprintf(stderr, "Unable to resolve local address.\n");
 				exit(1);
@@ -135,7 +153,7 @@
 		exit(1);
 	}
 
-	if((Target_Address = resolve(*argv)) == INADDR_NONE) {
+	if ((ainfo = resolve(*argv, Target_Port)) == 0) {
 		fprintf(stderr, "Unable to resolve target server address.\n");
 		fprintf(stderr, "Fatal error, exiting.\n");
 		exit(1);
@@ -147,7 +165,7 @@
 	       	exit(1);
 	}
 
-	if((Sockfd = bind_udp_socket(address, port)) < 0) {
+	if((Sockfd = bind_udp_socket(Local_Port)) < 0) {
 		fprintf(stderr, "Fatal error, exiting.\n");
 		exit(1);
 	}
@@ -167,7 +185,7 @@
 	/* start the fun */
 
 	printf("NSPING %s (%s): %s = \"%s\", Type = \"IN %s\"\n",
-			*argv, addr_string(Target_Address), 
+			*argv, addr_string,
 			Hostname ? "Hostname" : "Domain",
 			Hostname ? Hostname : Zone,
 			type_int2string(Type));
@@ -189,10 +207,14 @@
 
 int guess_zone() {
 	char lhn[MAXDNAME];
+	struct hostent *hp;
 	char *cp;
 
 	if(gethostname(lhn, MAXDNAME) < 0) 
 		return(0);
+	if((hp = gethostbyname(lhn)) == NULL)
+		return(0);
+	strlcpy(lhn, hp->h_name, sizeof(lhn));
 
 	cp = strchr(lhn, '.');
 	if(!cp || !(*(++cp)))
@@ -261,15 +283,19 @@
 	static int Start = 0;
 	static int Pos    = 0;      
 
-	struct sockaddr_in si;
+#if 0
+	struct sockaddr_storage si;
+#endif
 	int l;
 	int id;
 	u_char *qp;
 
 	signal(SIGALRM, probe);
 
-	if(!Start)
-		Start = getpid();
+	if(!Start) {
+		Start = getpid() % MAX_ID;
+	  	dprintf("Start = %d\n", Start);
+	}
 
 	/* we're overwriting state from a query we never got a response
 	 * to, so at least note that we missed it.
@@ -278,18 +304,16 @@
 	if(!Queries[Pos].found)
 		Missed++;
 
-	memset(&si, 0, sizeof(si));
-	si.sin_addr.s_addr = Target_Address;
-	si.sin_port = htons(Target_Port);
-	si.sin_family = AF_INET;
-
 	/* get the DNS request */
 
-	l = dns_packet(&qp, Start + Sent);
+	dprintf("sending with id = %d\n", (Start + Sent) % MAX_ID);
+	l = dns_packet(&qp, (Start + Sent) % MAX_ID); 
 
 	do {
 		if(sendto(Sockfd, qp, l, 0, 
-			(struct sockaddr *)&si, sizeof(si)) < 0) {
+			(struct sockaddr *)ainfo->ai_addr, 
+			ainfo->ai_addrlen) < 0) {
+
 			if(errno != EINTR) {		
 				perror("sendto");
 				return;
@@ -299,7 +323,7 @@
 
 	/* if it was sent successfully, update state */
 
-	Queries[Pos].id = Start + Sent;
+	Queries[Pos].id = (Start + Sent) % MAX_ID;
 	gettimeofday(&Queries[Pos].sent, NULL);
 	Queries[Pos].found = 0;
 
@@ -361,7 +385,10 @@
 
 void handle_incoming() {
 	u_char buffer[1024];
+#if 0
 	struct sockaddr_in si;
+#endif
+	struct sockaddr_storage si;
 	int sil = sizeof(si);
 	int l;
 
@@ -378,6 +405,7 @@
 
 		/* descriminate real responses from spurious crud */
 
+#if 0
 		if(si.sin_addr.s_addr != Target_Address) {
 			dprintf("Received packet from unexpected address %s.\n",
 				inet_ntoa(si.sin_addr));
@@ -389,6 +417,7 @@
 				ntohs(si.sin_port));
 			continue;
 		}
+#endif
 
 		if(l < sizeof(HEADER)) {
 			dprintf("Short packet.\n");
@@ -420,7 +449,7 @@
 	double triptime;
 
 	if(!Start)
-		Start = getpid();
+		Start = getpid() % MAX_ID;
 
 	gettimeofday(&tv, NULL);
 
@@ -437,8 +466,9 @@
 		Queries[i].found = 1;	
 
 	/* figure out which query this was, using the DNS query ID */
-
+	dprintf("received with id = %d\n", ntohs(hp->id));
 	delta = ntohs(hp->id) - Start;
+	dprintf("delta = %d - %d = %d\n", ntohs(hp->id), Start, delta);
 	
 	/* figure out how long it took */
 
@@ -494,7 +524,7 @@
 	       hp->rcode == NOERROR ? "+" : "-",
 	       delta,
 	       l, 
-	       addr_string(Target_Address),
+	       addr_string,
 	       triptime,
 	       delta ? Ave : 0.0);
 
@@ -512,6 +542,9 @@
 	       "Ave/Max/Min: %8.3f / %8.3f / %8.3f\n",
 	       Sent, Count, Missed ? Missed : Sent - Count, Lagged, Ave, Max, Min);
 
+#if 0
+	freeaddrinfo();
+#endif
 	exit(0);
 }
 
@@ -555,18 +588,6 @@
 
 /* -------------------------------------------------------------------------- */
 
-/* binary address -> dotted quad string */
-
-char *addr_string(u_int32_t address) {
-	static char as[20];
-	u_char *cp = (u_char *) &address;
-
-	sprintf(as, "%d.%d.%d.%d", cp[0], cp[1], cp[2], cp[3]);
-	return(as);
-}
-
-/* -------------------------------------------------------------------------- */
-
 /* map integer type codes to names, v/vrsa. Add new types here if you must. */
 
 struct type2str {
@@ -625,22 +646,40 @@
 
 /* return a bound UDP socket */
 
-int bind_udp_socket(u_int32_t address, u_int16_t port) {
-	struct sockaddr_in si;
+int bind_udp_socket(char *port) {
 	int sockfd;
-	
-	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
-	if(sockfd < 0) {
+	char str[255];
+
+	struct sockaddr_storage sss;
+	struct in6_addr anyaddr = IN6ADDR_ANY_INIT;
+	socklen_t               addrlen;
+
+	sockfd = socket(ainfo->ai_family, ainfo->ai_socktype,
+	                ainfo->ai_protocol);
+	if (sockfd < 0) {
 		perror("socket");
 		return(-1);
 	}
 
-	memset(&si, 0, sizeof(si));
-	si.sin_addr.s_addr = address;
-	si.sin_port = htons(port);
-	si.sin_family = AF_INET;
+	memset(&sss, 0, sizeof(sss));
+	switch (ainfo->ai_family) {
+	    case AF_INET:
+		(((struct sockaddr_in *)(&sss))->sin_addr).s_addr = INADDR_ANY;
+		((struct sockaddr_in *)(&sss))->sin_port = htons(atoi(port));
+		((struct sockaddr_in *)(&sss))->sin_family = AF_INET;
+		addrlen = sizeof(struct sockaddr_in);
+	    	break;
+
+	    case AF_INET6:
+		((struct sockaddr_in6 *)(&sss))->sin6_addr = anyaddr;
+		((struct sockaddr_in6 *)(&sss))->sin6_port = htons(atoi(port)); 
+		((struct sockaddr_in6 *)(&sss))->sin6_family = AF_INET6;
+		addrlen = sizeof(struct sockaddr_in6);
+	    	break;
+	}
 
-	if(bind(sockfd, (struct sockaddr *)&si, sizeof(si)) < 0) {
+	if(bind(sockfd, (struct sockaddr *)&sss, addrlen) < 0) 
+	{
 		perror("bind");
 		return(-1);
 	}
@@ -652,19 +691,45 @@
 
 /* wrap hostname resolution */
 
-u_int32_t resolve(char *name) {
-	u_long addr;
-
-	addr = inet_addr(name);
-	if(addr == INADDR_NONE) {
-		struct hostent *hp = gethostbyname(name);
-		if(!hp)
-			return(INADDR_NONE);
-
-		memcpy(&addr, hp->h_addr, 4);
+struct addrinfo* resolve(char *name, char *port) { 
+	struct addrinfo hints, *res, *res0;
+    	int error;
+        const char *cause = NULL;
+
+	memset(&hints, 0, sizeof(hints));
+    	hints.ai_family = PF_UNSPEC;
+      	hints.ai_socktype = SOCK_DGRAM;
+        error = getaddrinfo(name, port, &hints, &res0);
+	if (error) {
+	  errx(1, "%s", gai_strerror(error));
+	  return(NULL);
+	}
+
+	res = res0;
+	switch (res->ai_family) {
+	    case AF_INET:
+#if 0
+		sin_addr = (struct 
+#endif
+		inet_ntop(res->ai_family, 
+			&(((struct sockaddr_in *)(res->ai_addr))->sin_addr),
+			addr_string, sizeof(addr_string));
+		printf("%s\n", addr_string);
+	    	break;
+	    case AF_INET6:
+#if 0
+		sin6_addr = 
+#endif
+		inet_ntop(res->ai_family, 
+			&(((struct sockaddr_in6 *)(res->ai_addr))->sin6_addr),
+			addr_string, sizeof(addr_string));
+	    	break;
+	    default:
+	    	return(NULL);
+		break;
 	}
 
-	return(addr);
+	return(res);
 }
 
 
@@ -679,9 +744,7 @@
 /* -------------------------------------------------------------------------- */
 
  void usage() {
-	 fprintf(stderr, "nsping [ -z <zone> | -h <hostname> ] -p <port> -t <timeout>\n"
-		   "\t\t-a <local address> -P <local port>\n"
-		   "\t\t-T <type> <-r | -R, recurse?>\n");
+	 fprintf(stderr, "Usage: nsping [-dR] [-c count] [-z zone | -h hostname] [-t timeout] [-p dport] [-P sport] [-a saddr] [-T querytype]\n");
 	 return;
  }
 
