--- ./src/cfg.c.orig	2008-08-08 07:51:20.000000000 +0000
+++ ./src/cfg.c	2008-08-08 07:52:05.000000000 +0000
@@ -37,7 +37,7 @@
 	if (SLang_load_file (DATADIR "/lpe/init.sl") == -1)
 	{
 	    SLang_restart (1);
-	    SLang_Error = 0;
+	    SLang_set_error(0);
 	}
     }
 }
