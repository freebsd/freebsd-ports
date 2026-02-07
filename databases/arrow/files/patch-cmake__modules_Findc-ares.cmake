--- cmake_modules/Findc-ares.cmake.orig 2020-08-17 17:58:35 UTC
+++ cmake_modules/Findc-ares.cmake
@@ -0,0 +1,42 @@
+# Licensed to the Apache Software Foundation (ASF) under one
+# or more contributor license agreements.  See the NOTICE file
+# distributed with this work for additional information
+# regarding copyright ownership.  The ASF licenses this file
+# to you under the Apache License, Version 2.0 (the
+# "License"); you may not use this file except in compliance
+# with the License.  You may obtain a copy of the License at
+#
+#   http://www.apache.org/licenses/LICENSE-2.0
+#
+# Unless required by applicable law or agreed to in writing,
+# software distributed under the License is distributed on an
+# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
+# KIND, either express or implied.  See the License for the
+# specific language governing permissions and limitations
+# under the License.
+
+if(c-ares_ROOT)
+  find_library(CARES_STATIC_LIB
+               NAMES cares
+               PATHS ${c-ares_ROOT}
+               PATH_SUFFIXES ${LIB_PATH_SUFFIXES}
+               NO_DEFAULT_PATH)
+  find_path(CARES_INCLUDE_DIR
+            NAMES ares.h
+            PATHS ${c-ares_ROOT}
+            NO_DEFAULT_PATH
+            PATH_SUFFIXES ${INCLUDE_PATH_SUFFIXES})
+else()
+  find_library(CARES_STATIC_LIB NAMES cares)
+  find_path(CARES_INCLUDE_DIR NAMES ares.h PATH_SUFFIXES ${INCLUDE_PATH_SUFFIXES})
+endif()
+
+find_package_handle_standard_args(c-ares REQUIRED_VARS CARES_STATIC_LIB CARES_INCLUDE_DIR)
+
+if(c-ares_FOUND)
+  add_library(c-ares::cares STATIC IMPORTED)
+  set_target_properties(c-ares::cares
+                        PROPERTIES IMPORTED_LOCATION "${CARES_STATIC_LIB}"
+                                   INTERFACE_INCLUDE_DIRECTORIES "${CARES_INCLUDE_DIR}")
+endif()
+
