--- lib/native-package-installer/platform/freebsd.rb.orig	2017-04-27 16:32:17 UTC
+++ lib/native-package-installer/platform/freebsd.rb
@@ -0,0 +1,40 @@
+# Copyright (C) 2017  Ruby-GNOME2 Project Team
+#
+# This library is free software: you can redistribute it and/or modify
+# it under the terms of the GNU Lesser General Public License as published by
+# the Free Software Foundation, either version 3 of the License, or
+# (at your option) any later version.
+#
+# This program is distributed in the hope that it will be useful,
+# but WITHOUT ANY WARRANTY; without even the implied warranty of
+# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+# GNU Lesser General Public License for more details.
+#
+# You should have received a copy of the GNU Lesser General Public License
+# along with this program.  If not, see <http://www.gnu.org/licenses/>.
+
+class NativePackageInstaller
+  module Platform
+    class FreeBSD
+      Platform.register(self)
+
+      class << self
+        def current_platform?
+          ExecutableFinder.exist?("pkg")
+        end
+      end
+
+      def package(spec)
+        spec[:freebsd]
+      end
+
+      def install_command
+        "pkg install -y"
+      end
+
+      def need_super_user_priviledge?
+        true
+      end
+    end
+  end
+end
