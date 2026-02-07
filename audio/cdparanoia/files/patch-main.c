--- main.c.orig	2019-07-23 18:12:13 UTC
+++ main.c
@@ -588,10 +588,10 @@ static void callback(long inpos, int function){
 	    buffer[aheadposition+19]='>';
 	}
    
-	fprintf(stderr,buffer);
+	fprintf(stderr,"%s",buffer);
        
 	if (logfile != NULL && function==-1) {
-	  fprintf(logfile,buffer+1);
+	  fprintf(logfile,"%s",buffer+1);
 	  fprintf(logfile,"\n\n");
 	  fflush(logfile);
 	}
