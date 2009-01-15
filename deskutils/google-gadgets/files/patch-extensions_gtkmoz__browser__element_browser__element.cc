
$FreeBSD$

--- extensions/gtkmoz_browser_element/browser_element.cc.orig
+++ extensions/gtkmoz_browser_element/browser_element.cc
@@ -157,7 +157,7 @@
       std::string up_fd_str = StringPrintf("%d", up_fds[1]);
       for (size_t i = 0; kBrowserChildNames[i]; ++i) {
         execl(kBrowserChildNames[i], kBrowserChildNames[i],
-              down_fd_str.c_str(), up_fd_str.c_str(), NULL);
+              down_fd_str.c_str(), up_fd_str.c_str(), (char*)0);
       }
       LOG("Failed to execute browser child");
       _exit(-1);
@@ -416,6 +416,8 @@
           object_id_str_(StringPrintf("%zu", object_id)),
           call_self_(this),
           to_string_(NewSlot(this, &BrowserObjectWrapper::ToString)) {
+      if (parent_)
+        parent_->Ref();
     }
 
     virtual ~BrowserObjectWrapper() {
@@ -426,6 +428,8 @@
         owner_->controller_->SendCommand(kUnrefCommand, owner_->browser_id_,
                                          object_id_str_.c_str(), NULL);
       }
+      if (parent_)
+        parent_->Unref();
     }
 
     void OnOwnerDestroy() {
@@ -523,8 +527,8 @@
         buffer += '\n';
         buffer += wrapper_->object_id_str_;
         buffer += '\n';
-        if (wrapper_->parent_.Get())
-          buffer += wrapper_->parent_.Get()->object_id_str_;
+        if (wrapper_->parent_)
+          buffer += wrapper_->parent_->object_id_str_;
         for (int i = 0; i < argc; i++) {
           buffer += '\n';
           buffer += wrapper_->owner_->EncodeValue(argv[i]);
@@ -546,7 +550,7 @@
     };
 
     BrowserElementImpl *owner_;
-    ScriptableHolder<BrowserObjectWrapper> parent_;
+    BrowserObjectWrapper *parent_;
     size_t object_id_;
     std::string object_id_str_;
     CallSelfSlot call_self_;
