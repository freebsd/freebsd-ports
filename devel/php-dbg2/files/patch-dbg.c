--- ./dbg.c.orig	2010-04-13 09:40:15.000000000 -0400
+++ ./dbg.c	2010-04-13 09:41:12.000000000 -0400
@@ -563,7 +563,7 @@
 	}
 	DBG(is_extension_activated) = 1;
 	if (DBG(cfgprm_enabled)) {
-		CG(extended_info) = 1;
+		CG(compiler_options) |= ZEND_COMPILE_EXTENDED_INFO;
 	}
 }
 
@@ -571,7 +571,7 @@
 	TSRMLS_FETCH1(C);
 
 	DBG_TRACE(("dbg_deactivate Zend extension\n"));
-	CG(extended_info) = 0;
+	CG(compiler_options) = 0;
 
 /*	TS_ALLOC_DTOR_CALL(DBG); */
 }
