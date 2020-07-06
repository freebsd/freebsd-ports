# Description: 3.2.1 fails to build with clang 3.5.0 on arm
# Issue ID: https://github.com/atgreen/libffi/issues/162
# Submitted by: sbruno

--- src/arm/sysv.S.orig	2015-01-01 10:47:51 UTC
+++ src/arm/sysv.S
@@ -360,7 +360,7 @@ ARM_FUNC_START(ffi_call_VFP)
 	cmp	r0, #3
 	sub	ip, fp, #64
 	flddle	d0, [ip]
-	fldmiadgt	ip, {d0-d7}
+	vldmiagt	ip, {d0-d7}
 
 LSYM(Lbase_args):
 	@ move first 4 parameters in registers
@@ -396,7 +396,7 @@ LSYM(Lbase_args):
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_SINT64
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_FLOAT
@@ -409,7 +409,7 @@ LSYM(Lbase_args):
 
 	cmp	r3, #FFI_TYPE_STRUCT_VFP_FLOAT
 	cmpne	r3, #FFI_TYPE_STRUCT_VFP_DOUBLE
-	fstmiadeq	r2, {d0-d3}
+	vstmiaeq	r2, {d0-d3}
 
 LSYM(Lepilogue_vfp):
 	RETLDM	"r0-r3,fp"
@@ -420,7 +420,7 @@ LSYM(Lepilogue_vfp):
 
 
 ARM_FUNC_START(ffi_closure_VFP)
-	fstmfdd	sp!, {d0-d7}
+	vstmdb	sp!, {d0-d7}
 	@ r0-r3, then d0-d7
 	UNWIND .pad #80
 	add	ip, sp, #80
@@ -470,10 +470,10 @@ ARM_FUNC_START(ffi_closure_VFP)
 	ldmia	sp, {r0, r1}
 	b	.Lclosure_epilogue_vfp
 .Lretfloat_struct_vfp:
-	fldmiad	sp, {d0-d1}
+	vldmia	sp, {d0-d1}
 	b	.Lclosure_epilogue_vfp
 .Lretdouble_struct_vfp:
-	fldmiad	sp, {d0-d3}
+	vldmia	sp, {d0-d3}
 	b	.Lclosure_epilogue_vfp
 
 .ffi_closure_VFP_end:
