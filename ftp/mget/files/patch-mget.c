--- mget.c.orig	Mon Aug  4 13:23:05 2003
+++ mget.c	Mon Aug  4 13:28:01 2003
@@ -41,36 +41,36 @@
 void print_usage(void){
 	fprintf( \
 	stderr,
-	"Usage: mget %s 
-		[-n number_segments{1}] 
+	"Usage: mget %s\n\
+		[-n number_segments{1}]\n\
 		-f file_name\n" 
 #ifdef HAVE_GETOPT_LONG
-"		[--use_ftp_proxy[=<ftp_proxy_name:ftp_proxy_port{80}>]]
+"		[--use_ftp_proxy[=<ftp_proxy_name:ftp_proxy_port{80}>]]\n\
 		[--use_http_proxy[=<http_proxy_name:http_proxy_port{80}>]]\n"
 #elif HAVE_GETOPT_GETOPT_H
-"		[--use_ftp_proxy[=<ftp_proxy_name:ftp_proxy_port{80}>]]
+"		[--use_ftp_proxy[=<ftp_proxy_name:ftp_proxy_port{80}>]]\n\
 		[--use_http_proxy[=<http_proxy_name:http_proxy_port{80}>]]\n"
 #endif
-"		[-F<ftp_proxy_name:ftp_proxy_port{80}>]
-		[-x<ftp_proxy_name:ftp_proxy_port{80}>]
-		[-H<http_proxy_name:http_proxy_port{80}>]
-		[-h<http_proxy_name:http_proxy_port{80}>]
-		[-p port{80}] 
-		[-O Output_file_name]
+"		[-F<ftp_proxy_name:ftp_proxy_port{80}>]\n\
+		[-x<ftp_proxy_name:ftp_proxy_port{80}>]\n\
+		[-H<http_proxy_name:http_proxy_port{80}>]\n\
+		[-h<http_proxy_name:http_proxy_port{80}>]\n\
+		[-p port{80}]\n\
+		[-O Output_file_name]\n\
 		[-C]\n"
 #ifdef TRY_SIGNAL		
 "		[-l {log_file}]\n"
 #endif
-"		[-t timeout_seconds{60}]
-		[-R referrer]
-		[-r rollback{0} bytes]
-		[-v]
-		[-V]
--------------------------------------------------------------------------
-proxy option can be given as -H(F) proxyhost:proxyport or 
-as --use_http(or ftp)_proxy=proxyhost:proxyport. If port is not given, 
-port is assumed to be 80. [Works differently in Solaris, refer manpage].
-	On some machines getopt doesnot allow '-H <proxy_name>' i.e. the space is not allowed between H and hostname.
+"		[-t timeout_seconds{60}]\n\
+		[-R referrer]\n\
+		[-r rollback{0} bytes]\n\
+		[-v]\n\
+		[-V]\n\
+-------------------------------------------------------------------------\n\
+proxy option can be given as -H(F) proxyhost:proxyport or\n\
+as --use_http(or ftp)_proxy=proxyhost:proxyport. If port is not given,\n\
+port is assumed to be 80. [Works differently in Solaris, refer manpage].\n\
+On some machines getopt doesnot allow '-H <proxy_name>' i.e. the space is not allowed between H and hostname.\n\
 		   \n", VERSION);
 	exit(1);
 }
@@ -308,7 +308,7 @@
 	if(PROTO_HTTP==FALSE)
 		port=21;
 
-	VERBOSEPRINT(fprintf(outfile,"
+	VERBOSEPRINT(fprintf(outfile,"\
 		%sDocument %s requested from %s,with address %s in %d segments,\n,proxy:%s:%d\n%s",
 		sep,save_file_name,host_name,file_name,num_segment,proxy,proxy_port,sep))
 }
