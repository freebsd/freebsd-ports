--- giscanner/scannerlexer.l.orig	2017-04-17 10:01:31 UTC
+++ giscanner/scannerlexer.l
@@ -164,6 +164,8 @@ stringtext				([^\\\"])|(\\.)
 "__inline__"                            { return INLINE; }
 "__inline"				{ return INLINE; }
 "__nonnull" 			        { if (!parse_ignored_macro()) REJECT; }
+"_Nonnull" 			        { /* Ignore */ }
+"_Nullable" 			        { /* Ignore */ }
 "_Noreturn" 			        { /* Ignore */ }
 "__signed"                              { return SIGNED; }
 "__signed__"				{ return SIGNED; }
