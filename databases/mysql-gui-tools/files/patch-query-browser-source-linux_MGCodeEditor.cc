--- query-browser/source/linux/MGCodeEditor.cc.orig	2009-07-08 11:17:31.000000000 +0200
+++ query-browser/source/linux/MGCodeEditor.cc	2009-07-08 11:22:58.000000000 +0200
@@ -39,6 +39,7 @@
   _wrapper->show();
   
   gtk_source_view_set_show_line_markers(GTK_SOURCE_VIEW(_srcv), TRUE);
+#if 0
   gtk_source_view_set_compose_line_markers(GTK_SOURCE_VIEW(_srcv), FALSE);
   
   bg_color= Gdk::Color("#ffa6a6");
@@ -54,6 +55,7 @@
   _wrapper->get_colormap()->alloc_color(fg_color);
   gtk_source_view_set_marker_highlight_colors(GTK_SOURCE_VIEW(_srcv), "pc",
                                               fg_color.gobj(), bg_color.gobj());
+#endif
 }
 
 
@@ -157,7 +159,9 @@
     {
       _pc_marker= gtk_source_buffer_create_marker(_buffer, "pc", "pc",
                                                   iter.gobj());
+#if 0
       gtk_source_marker_set_priority(_pc_marker, 100);
+#endif
     }
     else
       gtk_source_buffer_move_marker(_buffer, _pc_marker, iter.gobj());
@@ -264,7 +268,9 @@
     {
       marker= gtk_source_buffer_create_marker(_buffer, NULL, "breakpoint",
                                               iter.gobj());
+#if 0
       gtk_source_marker_set_priority(marker, 10);
+#endif
     }
   }
   _wrapper->queue_draw();
