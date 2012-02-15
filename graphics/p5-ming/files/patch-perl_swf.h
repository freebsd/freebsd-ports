--- perl_swf.h.orig	2011-10-26 14:33:18.000000000 +0800
+++ perl_swf.h	2011-11-20 18:01:38.397227987 +0800
@@ -66,5 +66,9 @@
 void swf_stash_refcnt_inc(SV *sv_key, SV *sv_value);
 void swf_stash_refcnt_dec(SV *sv_key);
 
+#ifndef GvCV_set
+#define GvCV_set(gv, cv) (GvCV(gv) = cv)
+#endif
+
 #endif /* PERL_SWF_H_INCLUDED */
 
