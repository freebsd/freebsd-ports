--- ghc/rts/Profiling.c.orig	Tue May 24 23:15:46 2005
+++ ghc/rts/Profiling.c	Tue May 24 23:15:56 2005
@@ -713,6 +713,7 @@ reportCCSProfiling( void )
       gen_XML_logfile();
       return;
     default:
+      /* do nothing */;
     }
 
     fprintf(prof_file, "\t%s Time and Allocation Profiling Report  (%s)\n", 
