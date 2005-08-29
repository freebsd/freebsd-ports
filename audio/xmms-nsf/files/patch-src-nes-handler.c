--- src/nes/handler.c.orig	Sun Jan  7 05:17:57 2001
+++ src/nes/handler.c	Thu Aug 18 16:47:01 2005
@@ -10,9 +10,9 @@
 static NES_READ_HANDLER  *(nprh[0x10]) = { 0, };
 static NES_WRITE_HANDLER *(npwh[0x10]) = { 0, };
 #define EXTREADWRITE(p) \
-static Uint __fastcall ExtRd##p##(Uint A) \
+static Uint __fastcall ExtRd##p (Uint A) \
 { \
-	NES_READ_HANDLER *ph = nprh[0x##p##]; \
+	NES_READ_HANDLER *ph = nprh[0x##p ]; \
 	do \
 	{ \
 		if (ph->min <= A && A <= ph->max) \
@@ -22,9 +22,9 @@
 	} while ((ph = ph->next) != 0); \
 	return 0; \
 } \
-static void __fastcall ExtWr##p##(Uint A, Uint V) \
+static void __fastcall ExtWr##p (Uint A, Uint V) \
 { \
-	NES_WRITE_HANDLER *ph = npwh[0x##p##]; \
+	NES_WRITE_HANDLER *ph = npwh[0x##p ]; \
 	do \
 	{ \
 		if (ph->min <= A && A <= ph->max) \
