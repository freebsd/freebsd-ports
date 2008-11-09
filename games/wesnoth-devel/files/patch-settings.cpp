--- src/gui/widgets/settings.cpp.orig	2008-09-07 18:11:27.000000000 -0700
+++ src/gui/widgets/settings.cpp	2008-09-07 18:12:15.000000000 -0700
@@ -1100,6 +1100,10 @@
 	}
 
 	assert(false);
+
+	// Appease the compiler on FreeBSD
+	// Unreachable
+	return NULL;
 }
 
 std::vector<twindow_builder::tresolution>::const_iterator get_window_builder(const std::string& type)
@@ -1131,6 +1135,10 @@
 	}
 
 	assert(false);
+
+	// Appease the compiler on FreeBSD
+	// Unreachable
+	return window->second.resolutions.begin();
 }
 
 } // namespace gui2
