--- ./rubysdl_rwops.c.orig	2012-04-07 17:50:01.000000000 +0200
+++ ./rubysdl_rwops.c	2013-10-16 09:54:34.000000000 +0200
@@ -70,6 +70,9 @@
   return 0;
 }
 
+#ifdef close
+#undef close
+#endif
 /* WARNING: +obj+ is not marked when GC starts,
    so you should use `volatile' when this function is used
    and you should not take out this RWops pointer to ruby's world.
