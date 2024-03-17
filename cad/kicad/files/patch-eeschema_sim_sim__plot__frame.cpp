--- eeschema/sim/sim_plot_frame.cpp.orig	2023-04-13 20:27:39 UTC
+++ eeschema/sim/sim_plot_frame.cpp
@@ -27,6 +27,8 @@
 #include <wx/debug.h>
 #include <wx/stc/stc.h>
 
+#undef WXWIN_COMPATIBILITY_2_8
+
 // For some obscure reason, needed on msys2 with some wxWidgets versions (3.0) to avoid
 // undefined symbol at link stage (due to use of #include <pegtl.hpp>)
 // Should not create issues on other platforms
