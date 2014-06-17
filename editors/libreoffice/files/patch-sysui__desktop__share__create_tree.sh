--- sysui/desktop/share/create_tree.sh.orig	2014-04-30 15:49:45.000000000 -0400
+++ sysui/desktop/share/create_tree.sh	2014-06-16 19:55:56.000000000 -0400
@@ -57,37 +57,37 @@
   chmod 0644 "${DESTDIR}/${GNOMEDIR}/share/application-registry/${PREFIX}".*
 fi
 
-mkdir -p "${DESTDIR}/usr/bin"
+mkdir -p "${DESTDIR}/${PREFIXDIR}/bin"
 
 test -n "${OFFICE_PREFIX}" && office_prefix="${OFFICE_PREFIX}" || office_prefix=/opt
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API boostrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/usr/bin/${PREFIX}"
+ln -sf "${office_root}/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
 
-cp printeradmin.sh "${DESTDIR}/usr/bin/${PREFIX}-printeradmin"
-chmod 0755 "${DESTDIR}/usr/bin/${PREFIX}-printeradmin"
+cp printeradmin.sh "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}-printeradmin"
+chmod 0755 "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}-printeradmin"
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} -a "${PREFIX}" != libreofficedev${PRODUCTVERSION}  ; then
     # compat symlinks
     mkdir -p "${DESTDIR}${office_prefix}"
     ln -sf libreoffice${PRODUCTVERSION} "${DESTDIR}${office_root}"
-    ln -sf /usr/bin/${PREFIX} "${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}"
-    ln -sf /usr/bin/${PREFIX}-printeradmin "${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}-printeradmin"
+    ln -sf /${PREFIXDIR}/bin/${PREFIX} "${DESTDIR}/${PREFIXDIR}/bin/libreoffice${PRODUCTVERSION}"
+    ln -sf /${PREFIXDIR}/bin/${PREFIX}-printeradmin "${DESTDIR}/${PREFIXDIR}/bin/libreoffice${PRODUCTVERSION}-printeradmin"
 fi
 
 test "${PREFIX}" = libreofficedev${PRODUCTVERSION} && mime_def_file="libreofficedev${PRODUCTVERSION}.xml" || mime_def_file="libreoffice${PRODUCTVERSION}.xml"
-mkdir -p "${DESTDIR}/usr/share/mime/packages"
-cp openoffice.org.xml "${DESTDIR}/usr/share/mime/packages/$mime_def_file"
-chmod 0644 "${DESTDIR}/usr/share/mime/packages/$mime_def_file"
+mkdir -p "${DESTDIR}/${PREFIXDIR}/share/mime/packages"
+cp openoffice.org.xml "${DESTDIR}/${PREFIXDIR}/share/mime/packages/$mime_def_file"
+chmod 0644 "${DESTDIR}/${PREFIXDIR}/share/mime/packages/$mime_def_file"
 
-mkdir -p "${DESTDIR}/usr/share/applications"
+mkdir -p "${DESTDIR}/${PREFIXDIR}/share/applications"
 for i in `cat launcherlist`; do
-  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/usr/share/applications/${PREFIX}-${i}"
+  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
 done
 
-mkdir -p "${DESTDIR}/usr/share/appdata"
-for i in base calc draw impress writer; do
-    cp "${APPDATA_SOURCE_DIR}/libreoffice-${i}.appdata.xml" "${DESTDIR}/usr/share/appdata/${PREFIX}-${i}.appdata.xml"
-done
+#mkdir -p "${DESTDIR}/${PREFIXDIR}/share/appdata"
+#for i in base calc draw impress writer; do
+#    cp "${APPDATA_SOURCE_DIR}/libreoffice-${i}.appdata.xml" "${DESTDIR}/${PREFIXDIR}/share/appdata/${PREFIX}-${i}.appdata.xml"
+#done
 
