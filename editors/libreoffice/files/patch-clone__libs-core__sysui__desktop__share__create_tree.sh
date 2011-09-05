--- clone/libs-core/sysui/desktop/share/create_tree.sh.orig	2011-09-04 16:44:43.591133517 +0000
+++ clone/libs-core/sysui/desktop/share/create_tree.sh	2011-09-04 17:05:55.429128701 +0000
@@ -41,31 +41,31 @@
   chmod 0644 ${DESTDIR}/${GNOMEDIR}/share/application-registry/${PREFIX}.*
 fi
 
-mkdir -p ${DESTDIR}/usr/bin
+mkdir -p ${DESTDIR}${PREFIXDIR}/bin
 
 test -n "$OFFICE_PREFIX" && office_prefix="$OFFICE_PREFIX" || office_prefix=/opt
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API boostrap functions running right
-ln -sf ${office_root}/program/soffice ${DESTDIR}/usr/bin/${PREFIX}
+ln -sf ${office_root}/program/soffice ${DESTDIR}${PREFIXDIR}/bin/${PREFIX}
 
-cp printeradmin.sh ${DESTDIR}/usr/bin/${PREFIX}-printeradmin
-chmod 0755 ${DESTDIR}/usr/bin/${PREFIX} ${DESTDIR}/usr/bin/${PREFIX}-printeradmin
+cp printeradmin.sh ${DESTDIR}${PREFIXDIR}/bin/${PREFIX}-printeradmin
+chmod 0755 ${DESTDIR}${PREFIXDIR}/bin/${PREFIX} ${DESTDIR}${PREFIXDIR}/bin/${PREFIX}-printeradmin
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} ; then
     # compat symlinks
     mkdir -p ${DESTDIR}${office_prefix}
     ln -sf libreoffice${PRODUCTVERSION} ${DESTDIR}${office_root}
-    ln -sf /usr/bin/${PREFIX} ${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}
-    ln -sf /usr/bin/${PREFIX}-printeradmin ${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}-printeradmin
+    ln -sf ${PREFIXDIR}/bin/${PREFIX} ${DESTDIR}${PREFIXDIR}/bin/libreoffice${PRODUCTVERSION}
+    ln -sf ${PREFIXDIR}/bin/${PREFIX}-printeradmin ${DESTDIR}${PREFIXDIR}/bin/libreoffice${PRODUCTVERSION}-printeradmin
 fi
 
-mkdir -p ${DESTDIR}/usr/share/mime/packages
-cp openoffice.org.xml ${DESTDIR}/usr/share/mime/packages/libreoffice${PRODUCTVERSION}.xml
-chmod 0644 ${DESTDIR}/usr/share/mime/packages/libreoffice${PRODUCTVERSION}.xml
+mkdir -p ${DESTDIR}${PREFIXDIR}/share/mime/packages
+cp openoffice.org.xml ${DESTDIR}${PREFIXDIR}/share/mime/packages/libreoffice${PRODUCTVERSION}.xml
+chmod 0644 ${DESTDIR}${PREFIXDIR}/share/mime/packages/libreoffice${PRODUCTVERSION}.xml
 
-mkdir -p ${DESTDIR}/usr/share/applications
+mkdir -p ${DESTDIR}${PREFIXDIR}/share/applications
 for i in `cat launcherlist`; do
-  ln -sf ${office_root}/share/xdg/$i ${DESTDIR}/usr/share/applications/${PREFIX}-$i
+  ln -sf ${office_root}/share/xdg/$i ${DESTDIR}${PREFIXDIR}/share/applications/${PREFIX}-$i
 done
 
