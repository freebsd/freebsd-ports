--- ttcp.c.orig	Thu Oct 18 12:26:35 2001
+++ ttcp.c	Thu Oct 18 12:31:00 2001
@@ -55,6 +55,9 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <sys/time.h>		/* struct timeval */
+#include <unistd.h>
+#include <string.h>
+#include <stdlib.h>
 
 #if defined(SYSV)
 #include <sys/times.h>
@@ -133,7 +136,7 @@
 
 void err();
 void mes();
-int pattern();
+void pattern();
 void prep_timer();
 double read_timer();
 int Nread();
@@ -147,6 +150,7 @@
 {
 }
 
+int
 main(argc,argv)
 int argc;
 char **argv;
@@ -249,6 +253,7 @@
 #endif /* cray */
 		}
 		sinhim.sin_port = htons(port);
+		sinme.sin_family = AF_INET;     /* Solaris needs this */
 		sinme.sin_port = 0;		/* free choice */
 	} else {
 		/* rcvr */
@@ -263,29 +268,31 @@
 	if ( (buf = (char *)malloc(buflen+bufalign)) == (char *)NULL)
 		err("malloc");
 	if (bufalign != 0)
-		buf +=(bufalign - ((int)buf % bufalign) + bufoffset) % bufalign;
+		buf += (bufalign
+			-((unsigned long)buf % bufalign)
+			+ bufoffset) % bufalign;
 
 	if (trans) {
-	    fprintf(stdout,
+	    fprintf(stderr,
 	    "ttcp-t: buflen=%d, nbuf=%d, align=%d/%d, port=%d",
 		buflen, nbuf, bufalign, bufoffset, port);
  	    if (sockbufsize)
- 		fprintf(stdout, ", sockbufsize=%d", sockbufsize);
- 	    fprintf(stdout, "  %s  -> %s\n", udp?"udp":"tcp", host);
+ 		fprintf(stderr, ", sockbufsize=%d", sockbufsize);
+ 	    fprintf(stderr, "  %s  -> %s\n", udp?"udp":"tcp", host);
 	} else {
-	    fprintf(stdout,
+	    fprintf(stderr,
  	    "ttcp-r: buflen=%d, nbuf=%d, align=%d/%d, port=%d",
  		buflen, nbuf, bufalign, bufoffset, port);
  	    if (sockbufsize)
- 		fprintf(stdout, ", sockbufsize=%d", sockbufsize);
- 	    fprintf(stdout, "  %s\n", udp?"udp":"tcp");
+ 		fprintf(stderr, ", sockbufsize=%d", sockbufsize);
+ 	    fprintf(stderr, "  %s\n", udp?"udp":"tcp");
 	}
 
 	if ((fd = socket(AF_INET, udp?SOCK_DGRAM:SOCK_STREAM, 0)) < 0)
 		err("socket");
 	mes("socket");
 
-	if (bind(fd, &sinme, sizeof(sinme)) < 0)
+	if (bind(fd, (struct sockaddr *) &sinme, sizeof(sinme)) < 0)
 		err("bind");
 
 #if defined(SO_SNDBUF) || defined(SO_RCVBUF)
@@ -326,7 +333,7 @@
 			mes("nodelay");
 		}
 #endif
-		if(connect(fd, &sinhim, sizeof(sinhim) ) < 0)
+		if(connect(fd, (struct sockaddr*)&sinhim, sizeof(sinhim) ) < 0)
 			err("connect");
 		mes("connect");
 	    } else {
@@ -348,11 +355,11 @@
 		}
 		fromlen = sizeof(frominet);
 		domain = AF_INET;
-		if((fd=accept(fd, &frominet, &fromlen) ) < 0)
+		if((fd=accept(fd, (struct sockaddr*)&frominet, &fromlen) ) < 0)
 			err("accept");
 		{ struct sockaddr_in peer;
 		  int peerlen = sizeof(peer);
-		  if (getpeername(fd, (struct sockaddr_in *) &peer, 
+		  if (getpeername(fd, (struct sockaddr*) &peer, 
 				&peerlen) < 0) {
 			err("getpeername");
 		  }
@@ -412,25 +419,25 @@
 	}
 	if( cput <= 0.0 )  cput = 0.001;
 	if( realt <= 0.0 )  realt = 0.001;
-	fprintf(stdout,
+	fprintf(stderr,
 		"ttcp%s: %.0f bytes in %.2f real seconds = %s/sec +++\n",
 		trans?"-t":"-r",
 		nbytes, realt, outfmt(nbytes/realt));
 	if (verbose) {
-	    fprintf(stdout,
+	    fprintf(stderr,
 		"ttcp%s: %.0f bytes in %.2f CPU seconds = %s/cpu sec\n",
 		trans?"-t":"-r",
 		nbytes, cput, outfmt(nbytes/cput));
 	}
-	fprintf(stdout,
+	fprintf(stderr,
 		"ttcp%s: %d I/O calls, msec/call = %.2f, calls/sec = %.2f\n",
 		trans?"-t":"-r",
 		numCalls,
 		1024.0 * realt/((double)numCalls),
 		((double)numCalls)/realt);
-	fprintf(stdout,"ttcp%s: %s\n", trans?"-t":"-r", stats);
+	fprintf(stderr,"ttcp%s: %s\n", trans?"-t":"-r", stats);
 	if (verbose) {
-	    fprintf(stdout,
+	    fprintf(stderr,
 		"ttcp%s: buffer address %#x\n",
 		trans?"-t":"-r",
 		buf);
@@ -459,6 +466,7 @@
 	fprintf(stderr,"ttcp%s: %s\n", trans?"-t":"-r", s);
 }
 
+void
 pattern( cp, cnt )
 register char *cp;
 register int cnt;
@@ -614,13 +622,13 @@
 
 		case 'U':
 			tvsub(&tdiff, &r1->ru_utime, &r0->ru_utime);
-			sprintf(outp,"%d.%01d", tdiff.tv_sec, tdiff.tv_usec/100000);
+			sprintf(outp,"%ld.%01ld", tdiff.tv_sec, tdiff.tv_usec/100000);
 			END(outp);
 			break;
 
 		case 'S':
 			tvsub(&tdiff, &r1->ru_stime, &r0->ru_stime);
-			sprintf(outp,"%d.%01d", tdiff.tv_sec, tdiff.tv_usec/100000);
+			sprintf(outp,"%ld.%01ld", tdiff.tv_sec, tdiff.tv_usec/100000);
 			END(outp);
 			break;
 
@@ -642,49 +650,49 @@
 			break;
 
 		case 'X':
-			sprintf(outp,"%d", t == 0 ? 0 : (r1->ru_ixrss-r0->ru_ixrss)/t);
+			sprintf(outp,"%ld", t == 0 ? 0 : (r1->ru_ixrss-r0->ru_ixrss)/t);
 			END(outp);
 			break;
 
 		case 'D':
-			sprintf(outp,"%d", t == 0 ? 0 :
+			sprintf(outp,"%ld", t == 0 ? 0 :
 			    (r1->ru_idrss+r1->ru_isrss-(r0->ru_idrss+r0->ru_isrss))/t);
 			END(outp);
 			break;
 
 		case 'K':
-			sprintf(outp,"%d", t == 0 ? 0 :
+			sprintf(outp,"%ld", t == 0 ? 0 :
 			    ((r1->ru_ixrss+r1->ru_isrss+r1->ru_idrss) -
 			    (r0->ru_ixrss+r0->ru_idrss+r0->ru_isrss))/t);
 			END(outp);
 			break;
 
 		case 'M':
-			sprintf(outp,"%d", r1->ru_maxrss/2);
+			sprintf(outp,"%ld", r1->ru_maxrss/2);
 			END(outp);
 			break;
 
 		case 'F':
-			sprintf(outp,"%d", r1->ru_majflt-r0->ru_majflt);
+			sprintf(outp,"%ld", r1->ru_majflt-r0->ru_majflt);
 			END(outp);
 			break;
 
 		case 'R':
-			sprintf(outp,"%d", r1->ru_minflt-r0->ru_minflt);
+			sprintf(outp,"%ld", r1->ru_minflt-r0->ru_minflt);
 			END(outp);
 			break;
 
 		case 'I':
-			sprintf(outp,"%d", r1->ru_inblock-r0->ru_inblock);
+			sprintf(outp,"%ld", r1->ru_inblock-r0->ru_inblock);
 			END(outp);
 			break;
 
 		case 'O':
-			sprintf(outp,"%d", r1->ru_oublock-r0->ru_oublock);
+			sprintf(outp,"%ld", r1->ru_oublock-r0->ru_oublock);
 			END(outp);
 			break;
 		case 'C':
-			sprintf(outp,"%d+%d", r1->ru_nvcsw-r0->ru_nvcsw,
+			sprintf(outp,"%ld+%ld", r1->ru_nvcsw-r0->ru_nvcsw,
 				r1->ru_nivcsw-r0->ru_nivcsw );
 			END(outp);
 			break;
@@ -743,6 +751,7 @@
 /*
  *			N R E A D
  */
+int
 Nread( fd, buf, count )
 int fd;
 void *buf;
@@ -752,7 +761,7 @@
 	int len = sizeof(from);
 	register int cnt;
 	if( udp )  {
-		cnt = recvfrom( fd, buf, count, 0, &from, &len );
+		cnt = recvfrom( fd, buf, count, 0, (struct sockaddr *)&from, &len );
 		numCalls++;
 	} else {
 		if( b_flag )
@@ -774,6 +783,7 @@
 /*
  *			N W R I T E
  */
+int
 Nwrite( fd, buf, count )
 int fd;
 void *buf;
@@ -782,7 +792,7 @@
 	register int cnt;
 	if( udp )  {
 again:
-		cnt = sendto( fd, buf, count, 0, &sinhim, sizeof(sinhim) );
+		cnt = sendto( fd, buf, count, 0, (struct sockaddr *)&sinhim, sizeof(sinhim) );
 		numCalls++;
 		if( cnt<0 && errno == ENOBUFS )  {
 			delay(18000);
@@ -803,7 +813,7 @@
 
 	tv.tv_sec = 0;
 	tv.tv_usec = us;
-	(void)select( 1, (char *)0, (char *)0, (char *)0, &tv );
+	(void)select( 1, NULL, NULL, NULL, &tv );
 }
 
 /*
