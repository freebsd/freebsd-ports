--- src/ftp.c.orig	Mon Jul  5 21:26:46 2004
+++ src/ftp.c	Mon Jul  5 21:39:05 2004
@@ -798,15 +798,30 @@
 
 int get_msg(int csock, char * msg, int buflen){
   int res = 0;
+  char *s;
   
   do {
 	  memset(msg, 0, buflen);
 	  res = recv(csock, msg, buflen-1, 0);
 	  printout(vDEBUG, "%s", msg);
+	  /*
+	   * Multiline responses should of course only check on the last line.
+	   * If there are two \n's from the end of the string in the string,
+	   * the check at the start of second last one.
+	   */
+	  if ((s=strrchr(msg,'\n'))!=NULL) {
+		  if ((s=strrchr(s-1,'\n'))!=NULL) {
+			s++;
+			if (*s=='\r') s++;
+		  } else
+			s=msg;
+	  } else {
+		s=msg;
+	  }
   /* multiline messages are required by rfc to have a hiphen
    * after the command-code (e.g. 250-).
    * this counts for all but the last one, so look out for it. */
-  } while(msg[3] == '-');
+  } while(s[3] == '-');
   
   return res;
 }
