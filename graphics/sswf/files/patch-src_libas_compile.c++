--- src/libas/compile.c++.orig	2011-06-20 23:06:36.000000000 +0200
+++ src/libas/compile.c++	2011-06-20 23:13:11.000000000 +0200
@@ -706,18 +706,7 @@
 	//	frames and then we search that array with each
 	//	parent of the label
 
-#ifdef _MSVC
-	// alloca() not available with cl
-	class AutoDelete {
-	public: AutoDelete(NodePtr *ptr) { f_ptr = ptr; }
-		~AutoDelete() { delete f_ptr; }
-	private: NodePtr *f_ptr;
-	};
 	NodePtr *parents = new NodePtr[count];
-	AutoDelete ad_parent(parents);
-#else
-	NodePtr parents[count];
-#endif
 	parent = goto_node;
 	for(idx = 0; idx < count; ++idx) {
 		parent = parent.GetParent();
@@ -731,16 +720,19 @@
 		parent = parent.GetParent();
 		if(!parent.HasNode()) {
 			f_error_stream->ErrMsg(AS_ERR_INTERNAL_ERROR, goto_node, "IntCompiler::Goto(): Out of parent before we find the common node?!");
+			delete parents;
 			AS_ASSERT(0);
 			return;
 		}
 		for(idx = 0; idx < count; ++idx) {
 			if(parents[idx].SameAs(parent)) {
 				goto_node.SetLink(NodePtr::LINK_GOTO_EXIT, parent);
+				delete parents;
 				return;
 			}
 		}
 	}
+	delete parents;
 }
 
 
