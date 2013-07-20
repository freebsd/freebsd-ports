--- ./scripts/postprocess-unix.sh.orig	2012-12-30 05:13:26.000000000 +0000
+++ ./scripts/postprocess-unix.sh	2013-07-19 19:52:16.249098376 +0000
@@ -6,7 +6,7 @@
 DOCDIR="${THISDIR}/support/doc"
 
 # Generate Help Files
-cd "{$DOCDIR}"
+cd "${DOCDIR}"
 qcollectiongenerator LibreCADdoc.qhcp
 
 cd "${THISDIR}"
@@ -18,19 +18,8 @@
 cp support/patterns/*.dxf "${RESOURCEDIR}"/patterns
 #cp support/fonts/*.cxf "${RESOURCEDIR}"/fonts
 cp support/fonts/*.lff* "${RESOURCEDIR}"/fonts
-#cp support/doc/*.qhc "${RESOURCEDIR}"/doc
-#cp support/doc/*.qch "${RESOURCEDIR}"/doc
+cp support/doc/*.qhc "${RESOURCEDIR}"/doc
+cp support/doc/*.qch "${RESOURCEDIR}"/doc
 find support/library -type d | sed s/support// | xargs -IFILES  mkdir "${RESOURCEDIR}"/FILES
 find support/library -type f -iname *.dxf | sed s/support// | xargs -IFILES  cp support/FILES "${RESOURCEDIR}"/FILES
 
-# Generate translations
-lrelease librecad.pro
-mkdir -p "${RESOURCEDIR}"/qm
- 
-# Go into translations directory
-cd "${TSDIR}"
-for tf in *.qm
-do
-		cp "${tf}" "${RESOURCEDIR}/qm/${tf}"
-done
-
