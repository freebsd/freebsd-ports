--- ui/gtkmm/icongroup.cpp.orig	Sun Aug 21 15:51:54 2005
+++ ui/gtkmm/icongroup.cpp	Fri Sep 16 07:37:05 2005
@@ -218,6 +218,7 @@
 	  << endl;
 	}
 #endif
+#if 0
 	if (icon.is_null()
 	    && ::setting(Setting::SHOW_AI_INFORMATION_TEAMS)
 	    && (game.humanno() == 1)
@@ -228,6 +229,7 @@
 	  icon->saturate_and_pixelate(copy, 5, true);
 	  icon = copy;
 	} // if (icon.is_null())
+#endif
 
 	if (icon)
 	  possible_icons.push_back(icon);
