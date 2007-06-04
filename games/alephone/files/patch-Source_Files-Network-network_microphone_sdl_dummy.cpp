diff -ruN Source_Files.orig/Network/network_microphone_sdl_dummy.cpp Source_Files/Network/network_microphone_sdl_dummy.cpp
--- Source_Files.orig/Network/network_microphone_sdl_dummy.cpp	Wed Dec 31 19:00:00 1969
+++ Source_Files/Network/network_microphone_sdl_dummy.cpp	Thu May 31 21:30:37 2007
@@ -0,0 +1,59 @@
+/*
+ *  network_microphone_sdl_dummy.cpp
+ *  created for Marathon: Aleph One <http://source.bungie.org/>
+
+	Copyright (C) 2002 and beyond by Woody Zenfell, III
+	and the "Aleph One" developers.
+ 
+	This program is free software; you can redistribute it and/or modify
+	it under the terms of the GNU General Public License as published by
+	the Free Software Foundation; either version 2 of the License, or
+	(at your option) any later version.
+
+	This program is distributed in the hope that it will be useful,
+	but WITHOUT ANY WARRANTY; without even the implied warranty of
+	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+	GNU General Public License for more details.
+
+	This license is contained in the file "COPYING",
+	which is included with this source code; it is available online at
+	http://www.gnu.org/licenses/gpl.html
+
+ *  The code in this file is licensed to you under the GNU GPL.  As the copyright holder,
+ *  however, I reserve the right to use this code as I see fit, without being bound by the
+ *  GPL's terms.  This exemption is not intended to apply to modified versions of this file -
+ *  if I were to use a modified version, I would be a licensee of whomever modified it, and
+ *  thus must observe the GPL terms.
+ *
+ *  Dummy implementation of SDL-style network microphone.
+ *  Does nothing except satisfy the linker (and admit to anyone interested it's a poseur).
+ *
+ *  Created by woody March 9, 2002.
+ */
+
+void
+open_network_microphone() {
+    // Nothing
+}
+
+void
+close_network_microphone() {
+    // Nothing
+}
+
+void
+set_network_microphone_state(bool inActive) {
+    // Nothing
+    (void) (inActive);
+}
+
+bool
+is_network_microphone_implemented() {
+    // No!  You'll get nothing useful from us!
+    return false;
+}
+
+void
+network_microphone_idle_proc() {
+    // Nothing
+}
