--- ghc/rts/RtsFlags.c.orig	Thu Dec 11 15:13:07 2003
+++ ghc/rts/RtsFlags.c	Thu Dec 11 15:13:17 2003
@@ -1383,8 +1383,7 @@
 	      } else if (RtsFlags.GranFlags.proc > MAX_PROC || 
 			 RtsFlags.GranFlags.proc < 1)
 		{
-		  fprintf(stderr,"setupRtsFlags: no more than %u processors
-allowed\n", 
+		  fprintf(stderr,"setupRtsFlags: no more than %u processors allowed\n", 
 			  MAX_PROC);
 		  *error = rtsTrue;
 		}
