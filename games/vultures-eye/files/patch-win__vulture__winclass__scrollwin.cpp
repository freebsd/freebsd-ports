--- win/vulture/winclass/scrollwin.cpp.orig
+++ win/vulture/winclass/scrollwin.cpp
@@ -122,13 +122,12 @@
 void scrollwin::layout(void)
 {
 	window *winelem, *coltxt;
-	int i, elem_maxwidth, saved_scrollpos, height;
+	int i, elem_maxwidth, height;
 	int colwidths[8] = {0, 0, 0, 0, 0, 0, 0, 0};
 	int colstart[8] = {0, 0, 0, 0, 0, 0, 0, 0};
-  std::string txt, orig_caption;
+	std::string txt, orig_caption;
 	bool done = false;
 	elem_maxwidth = height = 0;
-	saved_scrollpos = scrollpos;
 	size_t prevpos, pos;
 
 	/* must not re-layout an already layouted scrollarea, as that would mangle
