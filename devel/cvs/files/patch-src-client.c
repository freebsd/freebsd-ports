From 9c448da8bb5f592ddcd2d980d01d81305f920f78 Mon Sep 17 00:00:00 2001
From: Fabian Keil <fk@fabiankeil.de>
Date: Mon, 21 Aug 2017 10:49:05 +0200
Subject: [PATCH] Add fix for CVE-2017-12836

Based on a patch by Thorsten Glaser:
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=871810#10

The patched file had to be changed and in the first
chunk the size of rsh_argv has been extended to 16
to match Debian's upstream version.
---
 cvs/src/client.c | 12 +++++++++---
 1 file changed, 9 insertions(+), 3 deletions(-)

diff --git cvs/src/client.c cvs/src/client.c
index c9fe170..09771ce 100644
--- src/client.c
+++ src/client.c
@@ -4736,9 +4736,10 @@ start_rsh_server (root, to_server, from_server)
     char *cvs_rsh;
     char *cvs_server = getenv ("CVS_SERVER");
     int i = 0;
-    /* This needs to fit "rsh", "-b", "-l", "USER", "host",
-       "cmd (w/ args)", and NULL.  We leave some room to grow. */
-    char *rsh_argv[10];
+    /* This needs to fit "rsh", "-b", "-l", "USER", "-p", port,
+       "--", "host", "cvs", "-R", "server", and NULL.
+       We leave some room to grow. */
+    char *rsh_argv[16];
 
     if (root->method == extssh_method)
 	cvs_rsh = env_cvs_ssh ? env_cvs_ssh : SSH_DFLT;
@@ -4763,6 +4764,9 @@ start_rsh_server (root, to_server, from_server)
 	rsh_argv[i++] = root->username;
     }
 
+    /* Only non-option arguments from here. (CVE-2017-12836) */
+    rsh_argv[i++] = "--";
+
     rsh_argv[i++] = root->hostname;
     rsh_argv[i++] = cvs_server;
     rsh_argv[i++] = "server";
@@ -4841,6 +4845,8 @@ start_rsh_server (root, to_server, from_server)
 	    *p++ = root->username;
 	}
 
+	*p++ = "--";
+
 	*p++ = root->hostname;
 	*p++ = command;
 	*p++ = NULL;
-- 
2.14.1

