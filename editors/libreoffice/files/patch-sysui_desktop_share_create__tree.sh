--- sysui/desktop/share/create_tree.sh.orig	2022-01-26 14:35:29 UTC
+++ sysui/desktop/share/create_tree.sh
@@ -37,7 +37,7 @@ test -n "${OFFICE_PREFIX}" && office_prefix="${OFFICE_
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API bootstrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/${BINDIR}/${PREFIX}"
+ln -sf "../lib/libreoffice/program/soffice" "${DESTDIR}/${PREFIXDIR}/bin/${PREFIX}"
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} -a "${PREFIX}" != libreofficedev${PRODUCTVERSION}  ; then
     # compat symlinks
@@ -53,7 +53,7 @@ chmod 0644 "${DESTDIR}/${PREFIXDIR}/share/mime/package
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/applications"
 for i in `cat launcherlist`; do
-  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
+  ln -sf "../../lib/libreoffice/share/xdg/${i}" "${DESTDIR}/${PREFIXDIR}/share/applications/${PREFIX}-${i}"
 done
 
 mkdir -p "${DESTDIR}/${PREFIXDIR}/share/metainfo"
