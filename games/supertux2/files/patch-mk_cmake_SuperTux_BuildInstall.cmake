--- mk/cmake/SuperTux/BuildInstall.cmake.orig	2026-03-15 05:38:51 UTC
+++ mk/cmake/SuperTux/BuildInstall.cmake
@@ -36,7 +36,8 @@ else()
     # HACK: Flatpak is dumb right now and still uses nightly icons, so ignore that case
     if(IS_SUPERTUX_RELEASE AND NOT FLATPAK)
       set(LINUX_DESKTOP_ICON "supertux2")
-      install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux.png ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux.xpm DESTINATION "share/pixmaps/")
+      install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux.png DESTINATION "share/pixmaps/" RENAME supertux2.png)
+      install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux.xpm DESTINATION "share/pixmaps/" RENAME supertux2.xpm)
     else()
       set(LINUX_DESKTOP_ICON "supertux-nightly")
       install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux-nightly.png ${CMAKE_CURRENT_SOURCE_DIR}/data/images/engine/icons/supertux.xpm DESTINATION "share/pixmaps/")
