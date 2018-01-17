sig2fv_main.cc:190:18: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
         "    default: "DEFAULT_WINDOW"\n\n"
                        ^

--- speech_tools/main/sig2fv_main.cc.orig	2010-11-05 14:12:43 UTC
+++ speech_tools/main/sig2fv_main.cc
@@ -187,7 +187,7 @@ int main(int argc, char *argv[])
 	 "-window_type <string> Type of window used on waveform. \n"
 	 "    Permissable types are: \n" +
 	 EST_Window::options_supported() + 
-	 "    default: "DEFAULT_WINDOW"\n\n"
+	 "    default: " DEFAULT_WINDOW "\n\n"
 	 "-lpc_order <int>      Order of lpc analysis. \n\n"
 	 "-ref_order <int>      Order of lpc reflection coefficient analysis. \n\n"
 	 "-cep_order <int>      Order of lpc cepstral analysis.\n\n"
