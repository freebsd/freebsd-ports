--- src/code_editor_dialog.cpp.orig	2018-06-16 12:59:49.843741000 +0300
+++ src/code_editor_dialog.cpp	2018-06-16 13:01:13.695918000 +0300
@@ -55,7 +55,7 @@
 
 	//std::cerr << "CED: " << x() << "," << y() << "; " << width() << "," << height() << std::endl;
 	drag_widget* dragger = new drag_widget(x(), y(), width(), height(),
-		drag_widget::DRAG_HORIZONTAL, NULL, 
+		drag_widget::DRAG_HORIZONTAL, [](int, int){}, 
 		boost::bind(&code_editor_dialog::on_drag_end, this, _1, _2), 
 		boost::bind(&code_editor_dialog::on_drag, this, _1, _2));
 
