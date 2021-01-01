--- libs/ardour/ardour/io.h.orig
+++ libs/ardour/ardour/io.h
@@ -288,6 +288,10 @@ class IO : public PBD::StatefulDestructi
 	XMLNode *pending_state_node;
 	int ports_became_legal ();
 
+	static bool connecting_is_legal() {
+		return connecting_legal;
+	}
+
   private:
 	mutable Glib::Mutex io_lock;
 
