--- ./conserver/master.c.orig	2013-02-15 18:35:06.000000000 -0500
+++ ./conserver/master.c	2013-02-15 18:36:30.000000000 -0500
@@ -571,9 +571,14 @@
 			    FileWrite(pCLServing->fd, FLAGFALSE, "ok\r\n",
 				      4);
 			} else {
+#if HAVE_GSSAPI
+			    FileWrite(pCLServing->fd, FLAGFALSE,
+				      "kerberos/gssapi required, use kinit\r\n", -1);
+#else
 			    FilePrint(pCLServing->fd, FLAGFALSE,
 				      "passwd? %s\r\n", myHostname);
 			    pCLServing->iState = S_PASSWD;
+#endif
 			}
 		    }
 #if HAVE_OPENSSL
