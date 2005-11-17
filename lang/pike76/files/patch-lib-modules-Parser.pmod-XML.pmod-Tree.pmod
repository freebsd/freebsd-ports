--- lib/modules/Parser.pmod/XML.pmod/Tree.pmod.old	Wed Nov 16 12:29:10 2005
+++ lib/modules/Parser.pmod/XML.pmod/Tree.pmod	Wed Nov 16 12:29:14 2005
@@ -1,7 +1,7 @@
 #pike __REAL_VERSION__
 
 /*
- * $Id: Tree.pmod,v 1.53 2004/12/21 16:07:07 grubba Exp $
+ * $Id: Tree.pmod,v 1.54 2005/11/07 14:21:17 nilsson Exp $
  *
  */
 
@@ -757,11 +757,15 @@
   //!
   static void create(int type, string name, mapping attr, string text)
   {
-    if (name) {
+    if (name && has_value(name, ":")) {
       sscanf(reverse(name), "%[^/:]", mTagName);
       mTagName=reverse(mTagName);
       mNamespace=name[..sizeof(name)-(1+sizeof(mTagName))];
     }
+    else {
+      mTagName = name;
+      mNamespace = "";
+    }
     mNodeType = type;
 //     mTagCode = kTagMapping[name] || kUnsupportedTagMapping[name];
     mAttributes = attr;
@@ -1447,25 +1451,27 @@
     //  the W3 spec. This is necessary since CDATA sections are
     //  converted to text nodes which might need to be concatenated
     //  with neighboring text nodes.
+
     Node text_node;
-    foreach(contents, Node child) {
+    int(0..1) modified;
+
+    foreach(contents; int i; Node child) {
       if (child->get_node_type() == XML_TEXT) {
-	if (text_node)
+	if (text_node) {
 	  //  Add this text string to the previous text node.
 	  text_node->_add_to_text (child->get_text());
+	  contents[i]=0;
+	  modified=1;
+	}
 	else
 	  text_node = child;
-      } else {
-	//  Process buffered text before this child is added
-	if (text_node) {
-	  node->add_child(text_node);
-	  text_node = 0;
-	}
-	node->add_child(child);
-      }
+      } else
+	text_node = 0;
     }
-    if (text_node)
-      node->add_child(text_node);
+
+    if( modified )
+      contents -= ({ 0 });
+    node->replace_children( contents );
     return (node);
 
   case "error":
