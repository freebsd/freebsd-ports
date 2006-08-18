--- ../compiler/resource/buildenv/postambl.mak.orig	Wed Jul 26 22:54:14 2006
+++ ../compiler/resource/buildenv/postambl.mak	Wed Jul 26 22:54:50 2006
@@ -17,8 +17,8 @@
 	if [ ! -d $(INSTALL_DIR) ] ; then mkdir -p $(INSTALL_DIR) ; fi
 	(cd install ; \
 	 find . \! \( -name CVS -prune \) -print) > .install.list
-	cat .install.list | (cd install ; cpio -oc) \
-			  | (cd ${INSTALL_DIR} ; cpio -idc)
+	cat .install.list | tar -cf- -C install -T- \
+			  | tar -xf- -C ${INSTALL_DIR}
 
 clean::
 	for i in $(SUBDIRS) ; do (cd $$i && $(MAKE) clean) ; done
