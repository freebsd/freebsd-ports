--- server/setup.c.orig	2008-10-26 23:37:54.000000000 +0900
+++ server/setup.c	2008-10-26 23:38:10.000000000 +0900
@@ -71,6 +71,7 @@
 char	*error_file	= NULL;			
 char	*log_file	= NULL;
 char	*port_name	= NULL;
+char	*server_name	= NULL;
 #ifdef TLI
 char	*port_number	= NULL;
 #else
@@ -232,6 +233,8 @@
 	"ProtoName",    get_opt_str,        &proto_name,
 	"protoname",    get_opt_str,        &proto_name,
 #else
+	"ServerName",	get_opt_str,	&server_name,
+	"servername",	get_opt_str,	&server_name,
 	"PortNumber",	get_opt_int,	&port_number,
 	"portnumber",	get_opt_int,	&port_number,
 #endif
@@ -409,6 +412,7 @@
 	set_defstr(&dict_dir,		DictRootDir);
 	set_defstr(&log_file,		LogOutFile);
 	set_defstr(&port_name,		PortName);
+	set_defstr(&server_name,	ServerName);
 	set_defstr(&socket_name,	SocketName);
 #ifdef	LOCK_FILE
 	set_defstr(&lock_file,		LockFile);
