Index: src/netpipe.c
===================================================================
RCS file: /cvs/gnn/Personal/Code/Networking/NetPIPE/src/netpipe.c,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- src/netpipe.c	9 Sep 2004 08:29:38 -0000	1.1
+++ src/netpipe.c	27 Sep 2004 11:26:17 -0000	1.2
@@ -84,7 +84,7 @@
     args.soffset=0; /* default to no offsets */
     args.roffset=0; 
     args.syncflag=0; /* use normal mpi_send */
-
+    args.port = DEFPORT; /* just in case the user doesn't set this. */
 
     /* TCGMSG launches NPtcgmsg with a -master master_hostname
      * argument, so ignore all arguments and set them manually 
@@ -94,7 +94,7 @@
 #if ! defined(TCGMSG)
 
     /* Parse the arguments. See Usage for description */
-    while ((c = getopt(argc, argv, "SO:rIiPszgfaB2h:p:o:l:u:b:m:n:t:c:d:D:")) != -1)
+    while ((c = getopt(argc, argv, "SO:rIiszgfaB2h:p:o:l:u:b:m:n:t:c:d:D:P:")) != -1)
     {
         switch(c)
         {
@@ -322,6 +322,9 @@
                       printf("Resetting connection after every trial\n");
                       break;
 #endif
+	    case 'P': 
+		      args.port = atoi(optarg);
+		      break;
 
             default: 
                      PrintUsage(); 
@@ -369,7 +372,6 @@
        exit(420132);
    }
    args.nbuff = TRIALS;
-   args.port = DEFPORT;
 
    Setup(&args);
 
@@ -994,7 +996,7 @@
     printf("a: asynchronous receive (a.k.a. preposted receive)\n");
 #endif
     printf("B: burst all preposts before measuring performance\n");
-#if defined(TCP) && ! defined(INFINIBAND)
+#if (defined(TCP) || defined(TCP6)) && ! defined(INFINIBAND)
     printf("b: specify TCP send/receive socket buffer sizes\n");
 #endif
 
@@ -1010,7 +1012,7 @@
     printf("   all MPI-2 implementations\n");
 #endif
 
-#if defined(TCP) || defined(INFINIBAND)
+#if defined(TCP) || defined(TCP6) || defined(INFINIBAND)
     printf("h: specify hostname of the receiver <-h host>\n");
 #endif
 
@@ -1030,7 +1032,7 @@
     printf("p: set the perturbation number <-p 1>\n"
            "   (default = 3 Bytes, set to 0 for no perturbations)\n");
 
-#if defined(TCP) && ! defined(INFINIBAND)
+#if (defined(TCP) || defined(TCP6)) && ! defined(INFINIBAND)
     printf("r: reset sockets for every trial\n");
 #endif
 
@@ -1053,10 +1055,11 @@
 #endif
 
     printf("2: Send data in both directions at the same time.\n");
+    printf("P: Set the port number to one other than the default.\n");
 #if defined(MPI)
     printf("   May need to use -a to choose asynchronous communications for MPI/n");
 #endif
-#if defined(TCP) && !defined(INFINIBAND)
+#if (defined(TCP) || defined(TCP6)) && !defined(INFINIBAND)
     printf("   The maximum test size is limited by the TCP buffer size/n");
 #endif
     printf("\n");
