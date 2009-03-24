--- src/gui/widgets/window_builder.cpp.orig	2008-11-02 17:31:45.000000000 +0100
+++ src/gui/widgets/window_builder.cpp	2008-11-02 17:32:43.000000000 +0100
@@ -199,6 +199,10 @@
 		std::cerr << cfg;
 		assert(false);
 	}
+
+	// Appease the compiler on FreeBSD
+	// Unreachable
+	return NULL;
 }
 
 } // namespace
