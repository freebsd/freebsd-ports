--- extensions/curl/interface.c.orig	Tue Mar  1 19:38:05 2005
+++ extensions/curl/interface.c	Tue Mar  1 19:47:08 2005
@@ -18,7 +18,7 @@
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 NTLIBS: libcurl.lib ws2_32.lib
-UXLIBS: -lcurl -lssl -lcrypto -ldl -lc
+UXLIBS: -lcurl -lssl -lcrypto -lc
 
 */
 #include <stdio.h>
@@ -1352,10 +1352,10 @@
     if( Argument == NULL )return COMMAND_ERROR_ARGUMENT_RANGE;
     Argument = besCONVERT2STRING(Argument);
     if( STRLEN(Argument) == 10 && memcmp(STRINGVALUE(Argument),"IFMODSINCE",10) == 0 ){
-      value = TIMECOND_IFMODSINCE;
+      value = CURL_TIMECOND_IFMODSINCE;
       }else
     if( STRLEN(Argument) == 12 && memcmp(STRINGVALUE(Argument),"IFUNMODSINCE",12) == 0 ){
-      value = TIMECOND_IFUNMODSINCE;
+      value = CURL_TIMECOND_IFUNMODSINCE;
       }else return COMMAND_ERROR_ARGUMENT_RANGE;
     res = curl_easy_setopt(pCon->myConnection,CURLOPT_TIMECONDITION,value);
     if( res == CURLE_OK ) return COMMAND_ERROR_SUCCESS;
