# Description: 3.2.1 fails to build with clang 3.5.0 on arm
# Issue ID: https://github.com/atgreen/libffi/issues/162
# Submitted by: sbruno

--- src/arm/sysv.S.orig	2015-01-01 10:47:51 UTC
+++ src/arm/sysv.S
@@ -396,7 +396,7 @@ LSYM(Lbase_args):
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_SINT64
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_FLOAT
