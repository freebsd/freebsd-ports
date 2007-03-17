--- mcs/class/System.Web/System.Web.Compilation/AspParser.cs.orig	Fri Dec 29 22:13:43 2006
+++ mcs/class/System.Web/System.Web.Compilation/AspParser.cs	Fri Dec 29 22:14:41 2006
@@ -454,8 +454,12 @@
 			tokenizer.Verbatim = false;
 			id = inside_tags;
 			attributes = null;
-			tagtype = (databinding ? TagType.DataBinding :
-				  (varname ? TagType.CodeRenderExpression : TagType.CodeRender));
+			if (databinding)
+				tagtype = TagType.DataBinding;
+			else if (varname)
+				tagtype = TagType.CodeRenderExpression;
+			else
+				tagtype = TagType.CodeRender;
 		}
 
 		public event ParseErrorHandler Error;
