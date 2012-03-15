--- libs/core/api/ri.cpp.orig	2012-03-02 09:03:48.000000000 +0100
+++ libs/core/api/ri.cpp	2012-03-15 11:58:30.000000000 +0100
@@ -4220,6 +4220,11 @@
 	Aqsis::log() << warning << "RiDeformation not supported" << std::endl;
 }
 
+RtVoid RiDeformationV(RtToken name, RtInt n, RtToken tokens[], RtPointer parms[])
+{
+	Aqsis::log() << warning << "RiDeformationV not supported" << std::endl;
+}
+
 RtVoid RiMakeBump(RtString imagefile, RtString bumpfile, RtToken swrap, RtToken twrap, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, PARAMETERLIST)
 {
 	Aqsis::log() << warning << "RiMakeBump not supported" << std::endl;
