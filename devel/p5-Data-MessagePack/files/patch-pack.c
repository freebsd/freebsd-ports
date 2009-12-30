--- pack.c.orig	2009-07-30 16:42:06.000000000 +0900
+++ pack.c	2009-12-30 13:35:08.000000000 +0900
@@ -159,7 +159,15 @@
     } else if (SvIOK_UV(sv)) {
         msgpack_pack_uint32(enc, SvUV(sv));
     } else if (SvIOKp(sv)) {
-        PACK_WRAPPER(IVTYPE)(enc, SvIV(sv));
+	if (sizeof(IVTYPE) == 8) {
+	    msgpack_pack_int64(enc, SvIV(sv));
+	} else if (sizeof(IVTYPE) == 4) {
+	    msgpack_pack_int32(enc, SvIV(sv));
+	} else if (sizeof(IVTYPE) == 2) {
+	    msgpack_pack_int16(enc, SvIV(sv));
+	} else {
+	    Perl_croak(aTHX_ "msgpack cannot support sizeof(IVTYPE)==%d\n", sizeof(IVTYPE));
+	}
     } else if (SvROK(sv)) {
         _msgpack_pack_rv(enc, SvRV(sv));
     } else if (!SvOK(sv)) {
