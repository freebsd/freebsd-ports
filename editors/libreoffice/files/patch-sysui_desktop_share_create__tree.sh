--- sysui/desktop/share/create_tree.sh.orig	2015-08-22 06:41:35 UTC
+++ sysui/desktop/share/create_tree.sh
@@ -82,8 +82,8 @@ for i in `cat launcherlist`; do
   ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
 done
 
-mkdir -p "${DESTDIR}/${PREFIXDIR}/share/appdata"
-for i in base calc draw impress writer; do
-    cp "${APPDATA_SOURCE_DIR}/libreoffice-${i}.appdata.xml" "${DESTDIR}/${PREFIXDIR}/share/appdata/${PREFIX}-${i}.appdata.xml"
-done
+#mkdir -p "${DESTDIR}/${PREFIXDIR}/share/appdata"
+#for i in base calc draw impress writer; do
+#    cp "${APPDATA_SOURCE_DIR}/libreoffice-${i}.appdata.xml" "${DESTDIR}/${PREFIXDIR}/share/appdata/${PREFIX}-${i}.appdata.xml"
+#done
 
