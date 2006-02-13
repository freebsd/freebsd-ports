Index: src/netpipe.h
===================================================================
RCS file: /cvs/gnn/Personal/Code/Networking/NetPIPE/src/netpipe.h,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -r1.1.1.1 -r1.2
--- src/netpipe.h	9 Sep 2004 08:29:38 -0000	1.1.1.1
+++ src/netpipe.h	9 Sep 2004 08:35:07 -0000	1.2
@@ -23,6 +23,11 @@
 #include <stdlib.h>         /* malloc(3) */
 #include <unistd.h>         /* getopt, read, write, ... */
 
+/* Handle the case of building on MacOS X */
+#if defined(__APPLE__)
+#include <stdint.h>
+#endif 
+
 #ifdef INFINIBAND
 #include <ib_defs.h> /* ib_mtu_t */
 #endif
@@ -89,6 +94,24 @@
 };
 #endif
 
+#elif defined(TCP6)
+  #include <netdb.h>
+  #include <sys/socket.h>
+  #include <netinet/in.h>
+  #include <netinet/tcp.h>
+  #include <arpa/inet.h>
+  
+  typedef struct protocolstruct ProtocolStruct;
+  struct protocolstruct
+  {
+      struct sockaddr_in6     sin1;   /* socket structure #1              */
+      struct sockaddr_in6     sin2;   /* socket structure #2              */
+      int                     nodelay;  /* Flag for TCP nodelay           */
+      struct hostent          *addr;    /* Address of host                */
+      int                     sndbufsz; /* Size of TCP send buffer        */
+      int                     rcvbufsz; /* Size of TCP receive buffer     */
+  };
+
 #elif defined(MPI)
   typedef struct protocolstruct ProtocolStruct;
   struct protocolstruct 
@@ -197,7 +220,7 @@
   };
 
 #else
-  #error "One of TCP, MPI, PVM, TCGMSG, LAPI, SHMEM, ATOLL, MEMCPY, DISK must be defined during compilation"
+  #error "One of TCP, TCP6, MPI, PVM, TCGMSG, LAPI, SHMEM, ATOLL, MEMCPY, DISK must be defined during compilation"
 
 #endif
 
