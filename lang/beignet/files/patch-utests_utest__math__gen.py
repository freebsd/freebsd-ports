--- utests/utest_math_gen.py.orig	2017-01-20 10:40:51 UTC
+++ utests/utest_math_gen.py
@@ -241,10 +241,11 @@ static float atan2pi(float y, float x){
   exp2Utests = func('exp2','exp2',[exp2_input_type],exp2_output_type,[exp2_input_values],'4 * FLT_ULP')
   
   ##### gentype exp10(gentype)
-  exp10_input_values = base_input_values
-  exp10_input_type = ['float','float2','float4','float8','float16']
-  exp10_output_type = ['float','float2','float4','float8','float16']
-  exp10Utests = func('exp10','exp10',[exp10_input_type],exp10_output_type,[exp10_input_values],'4 * FLT_ULP')
+#  exp10_input_values = base_input_values
+#  exp10_input_type = ['float','float2','float4','float8','float16']
+#  exp10_output_type = ['float','float2','float4','float8','float16']
+#  exp10Utests = func('exp10','exp10',[exp10_input_type],exp10_output_type,[exp10_input_values],'4 * FLT_ULP')
+# FreeBSD does not have a exp10() function
   
   ##### gentype expm1(gentype x)
   expm1_input_values = base_input_values
