--- eeschema/sim/sim_plot_frame.cpp.orig	2023-01-25 22:50:55.894239000 +0100
+++ eeschema/sim/sim_plot_frame.cpp	2023-01-27 00:25:46.086158000 +0100
@@ -27,6 +27,8 @@
 #include <wx/debug.h>
 #include <wx/stc/stc.h>
 
+#undef WXWIN_COMPATIBILITY_2_8
+
 // For some obscure reason, needed on msys2 with some wxWidgets versions (3.0) to avoid
 // undefined symbol at link stage (due to use of #include <pegtl.hpp>)
 // Should not create issues on other platforms
