--- sysui/desktop/share/create_tree.sh.orig	2019-01-24 03:35:25.000000000 +0800
+++ sysui/desktop/share/create_tree.sh	2019-02-04 10:04:10.186856000 +0800
@@ -58,7 +58,7 @@
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API bootstrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/${BINDIR}/${PREFIX}"
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
