--- sal/osl/unx/uunxapi.cxx.bak	2019-03-23 22:42:30.703590000 -0500
+++ sal/osl/unx/uunxapi.cxx	2019-03-23 22:46:37.905090000 -0500
@@ -563,14 +563,22 @@
         case EBFONT:
             return "EBFONT";
 #endif
+#ifdef ENOSTR
         case ENOSTR:
             return "ENOSTR";
+#endif
+#ifdef ENODATA
         case ENODATA:
             return "ENODATA";
+#endif
+#if defined(ETIME) && (!defined(ETIMEDOUT) || ETIME != ETIMEDOUT)
         case ETIME:
             return "ETIME";
+#endif
+#ifdef ENOSR
         case ENOSR:
             return "ENOSR";
+#endif
 #ifdef ENONET
         case ENONET:
             return "ENONET";
