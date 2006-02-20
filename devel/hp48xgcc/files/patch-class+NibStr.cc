--- class/NibStr.cc	3 Nov 2004 06:57:51 -0000	1.1
+++ class/NibStr.cc	3 Nov 2004 12:49:26 -0000	1.2
@@ -84,8 +84,8 @@
 }
 
 
-NibStr NibStr::operator+ (const NibStr & rv) const
-                         return res(length()+rv.length()) {
+NibStr NibStr::operator+ (const NibStr & rv) const {
+	NibStr res(length()+rv.length());
 
 	if (!res.fail) {
 		bcopy ( adr, res.adr, len );
