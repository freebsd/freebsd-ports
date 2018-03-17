--- sysui/desktop/share/create_tree.sh.orig	2018-03-16 00:33:44.202900000 +0800
+++ sysui/desktop/share/create_tree.sh	2018-03-16 01:10:52.600520000 +0800
@@ -58,7 +58,7 @@
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API boostrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
+ln -sf "../lib/libreoffice/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} -a "${PREFIX}" != libreofficedev${PRODUCTVERSION}  ; then
     # compat symlinks
@@ -74,7 +74,7 @@
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/applications"
 for i in `cat launcherlist`; do
-  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
+  ln -sf "../../lib/libreoffice/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
 done
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/appdata"
