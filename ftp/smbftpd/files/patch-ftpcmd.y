--- ftpcmd.y.orig	2009-01-07 09:13:19 UTC
+++ ftpcmd.y
@@ -77,6 +77,8 @@ static const char rcsid[] =
 #include "cmd.h"
 #include "ssl.h"
 
+#define	yylex	ftpcmd_yylex
+
 extern	smbftpd_session_t smbftpd_session;
 extern	smbftpd_conf_t smbftpd_conf;
 extern	union sockunion data_dest, his_addr;
