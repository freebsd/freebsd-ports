--- daapd.cc.orig	Tue Jun 15 22:54:30 2004
+++ daapd.cc	Tue Jun 29 20:37:49 2004
@@ -787,7 +787,7 @@
 		}
 	}
 	
-	conf = fopen( "/etc/daapd.conf", "r" );
+	conf = fopen( "/usr/local/etc/daapd.conf", "r" );
 	if( conf != NULL ) {
 		return( parseConfig( conf, initParams ) );
 	}
@@ -1041,6 +1041,10 @@
 		perror ( "Couldn't create HTTP server" );	
 		exit(1);
 	}
+
+	// unbuffer stdout if redirected
+	if (!isatty(fileno(stdout)))
+		setvbuf(stdout, NULL, _IONBF, 0);
 
 	httpdSetAccessLog( server, stdout );
 	httpdSetErrorLog( server, stderr ); 
