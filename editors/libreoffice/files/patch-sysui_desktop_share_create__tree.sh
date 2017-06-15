--- sysui/desktop/share/create_tree.sh.orig	2016-10-28 14:50:26 UTC
+++ sysui/desktop/share/create_tree.sh
@@ -82,10 +82,10 @@ for i in `cat launcherlist`; do
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
 
 # Generate gobject-introspection files
 if [ -n "$INTROSPECTION_SCANNER" ]; then
