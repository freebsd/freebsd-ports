===================================================================
RCS file: /usr/repos/kde/kdegraphics/ksvg/impl/SVGList.h,v
retrieving revision 1.22
retrieving revision 1.22.2.1
diff -u -p -r1.22 -r1.22.2.1
--- ksvg/impl/SVGList.h	2003/12/09 13:42:26	1.22
+++ ksvg/impl/SVGList.h	2004/06/04 16:46:27	1.22.2.1
@@ -48,7 +48,7 @@ class SVGList : public DOM::DomShared
 {
 public:
 	SVGList() { m_impl.setAutoDelete(false); }
-	SVGList(const SVGList &) { *this = other; }
+	SVGList(const SVGList &other) { *this = other; }
 	~SVGList() { clear(); }
 
 	SVGList<T> &operator=(const SVGList<T> &other)
