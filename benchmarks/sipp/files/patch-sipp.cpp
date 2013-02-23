--- sipp.cpp.orig	2013-02-09 20:03:03.000000000 +0000
+++ sipp.cpp	2013-02-09 20:10:27.000000000 +0000
@@ -4622,7 +4622,7 @@
 	  }
 	  exit(EXIT_OTHER);
 	case SIPP_OPTION_VERSION:
-	  printf("\n SIPp v3.3-beta2"
+	  printf("\n SIPp v3.3"
 #ifdef _USE_OPENSSL
 	      "-TLS"
 #endif
@@ -4632,8 +4632,8 @@
 #ifdef PCAPPLAY
 	      "-PCAP"
 #endif
-	      ", version %s, built %s, %s.\n\n",
-	      SIPP_VERSION, __DATE__, __TIME__); 
+	      ", built %s, %s.\n\n",
+	      __DATE__, __TIME__);
 
 	  printf
 	    (" This program is free software; you can redistribute it and/or\n"
