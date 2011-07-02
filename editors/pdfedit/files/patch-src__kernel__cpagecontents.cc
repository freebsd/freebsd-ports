--- src/kernel/cpagecontents.cc.orig	2010-04-30 21:44:30.000000000 +0900
+++ src/kernel/cpagecontents.cc	2011-03-21 20:39:56.000000000 +0900
@@ -379,6 +379,12 @@
 
 	// Get the text
 	libs::Rectangle rec = (rc)? *rc : _page->display()->getPageRect();
+	// if we use rotation 90,270 then we must change the rectangle from which we want the text
+	// accordingly (TODO - verify for all rotations)
+	int rot = _page->getRotation ();
+	if (90 == rot || 270 == rot)
+		std::swap (rec.xright, rec.yright);
+
 	scoped_ptr<GString> gtxt (textDev->getText(rec.xleft, rec.yleft, rec.xright, rec.yright));
 	text = gtxt->getCString();
 }
@@ -540,10 +546,14 @@
 
 
 	CDict image_dict;
-	image_dict.addProperty ("W", CInt (image_size.x));
-	image_dict.addProperty ("H", CInt (image_size.y));
-	image_dict.addProperty ("CS", CName ("RGB"));
-	image_dict.addProperty ("BPC", CInt (8));
+	CInt x (image_size.x);
+	image_dict.addProperty ("W", x);
+	CInt y (image_size.y);
+	image_dict.addProperty ("H", y);
+	CName n ("RGB");
+	image_dict.addProperty ("CS", n);
+	CInt i (8);
+	image_dict.addProperty ("BPC", i);
 	CInlineImage img (image_dict, what);
 	shared_ptr<CInlineImage> inline_image (new CInlineImage (image_dict, what));
 	shared_ptr<InlineImageCompositePdfOperator> BI(new InlineImageCompositePdfOperator (inline_image));
