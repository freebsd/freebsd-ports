--- base/files/file_path_watcher_bsd.cc.orig	2022-10-24 13:33:33 UTC
+++ base/files/file_path_watcher_bsd.cc
@@ -0,0 +1,54 @@
+// Copyright 2021 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include <memory>
+
+#include "base/files/file_path_watcher.h"
+#include "base/files/file_path_watcher_kqueue.h"
+#include "base/memory/ptr_util.h"
+#include "build/build_config.h"
+
+namespace base {
+
+namespace {
+
+class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
+ public:
+  FilePathWatcherImpl() = default;
+  FilePathWatcherImpl(const FilePathWatcherImpl&) = delete;
+  FilePathWatcherImpl& operator=(const FilePathWatcherImpl&) = delete;
+  ~FilePathWatcherImpl() override = default;
+
+  bool Watch(const FilePath& path,
+             Type type,
+             const FilePathWatcher::Callback& callback) override {
+    DCHECK(!impl_.get());
+    if (type == Type::kRecursive) {
+      if (!FilePathWatcher::RecursiveWatchAvailable())
+        return false;
+    } else {
+      impl_ = std::make_unique<FilePathWatcherKQueue>();
+    }
+    DCHECK(impl_.get());
+    return impl_->Watch(path, type, callback);
+  }
+
+  void Cancel() override {
+    if (impl_.get())
+      impl_->Cancel();
+    set_cancelled();
+  }
+
+ private:
+  std::unique_ptr<PlatformDelegate> impl_;
+};
+
+}  // namespace
+
+FilePathWatcher::FilePathWatcher() {
+  DETACH_FROM_SEQUENCE(sequence_checker_);
+  impl_ = std::make_unique<FilePathWatcherImpl>();
+}
+
+}  // namespace base
