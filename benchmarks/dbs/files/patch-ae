--- src/sendrecv.c--	Mon Oct 13 03:27:19 1997
+++ src/sendrecv.c	Sat Aug  1 19:37:02 1998
@@ -70,12 +70,12 @@
 #define INIT_RECORD()  (rdp = rd->d, rd->n=0)
 #define INIT_RECORD2() (rdp2 = rd2->d, rd2->n=0)
 
-#define RECORD(NO,SIZE) (gettimeofday(&(rdp->tv), &tzp),\
+#define RECORD(NO,SIZE) (gettimeofday(&(rdp->tv), (struct timezone *)&tzp),\
 			 rdp->packet_no   = (NO),\
 			 rdp->packet_size = (SIZE),\
 			 rdp++, rd->n++)
 
-#define RECORD2(NO,SIZE) (gettimeofday(&(rdp2->tv), &tzp),\
+#define RECORD2(NO,SIZE) (gettimeofday(&(rdp2->tv), (struct timezone *)&tzp),\
 			  rdp2->packet_no   = (NO),\
 			  rdp2->packet_size = (SIZE),\
 			  rdp2++, rd2->n++)
@@ -87,7 +87,7 @@
 				    _TP1.tv_usec %= 1000000;\
 				}
 
-#define GETTIMEOFDAY(_TPP) gettimeofday(&tp, &tzp);\
+#define GETTIMEOFDAY(_TPP) gettimeofday(&tp, (struct timezone *)&tzp);\
                            tp.tv_sec  = _TPP.tv_sec  - tp.tv_sec;\
                            tp.tv_usec = _TPP.tv_usec - tp.tv_usec;\
                            if (tp.tv_usec < 0) {\
@@ -108,7 +108,7 @@
 	              USLEEP(tp);
 
 /* before 0.00001s */
-#define WAIT_BEFORE(_TPP) gettimeofday(&tp, &tzp);\
+#define WAIT_BEFORE(_TPP) gettimeofday(&tp, (struct timezone *) &tzp);\
                           tp.tv_sec  = _TPP.tv_sec  - tp.tv_sec;\
                           tp.tv_usec = _TPP.tv_usec - tp.tv_usec - 1000;\
                           if (tp.tv_usec < 0) {\
