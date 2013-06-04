--- tools/qslim/qslim.cxx.orig
+++ tools/qslim/qslim.cxx
@@ -32,7 +32,7 @@
     output_preamble();
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     double input_time, init_time, slim_time, output_time;
 
