--- a-chahan.adb.orig	Fri Sep  1 10:13:48 2000
+++ a-chahan.adb	Fri Feb  8 22:14:02 2002
@@ -38,7 +38,6 @@
 with Ada.Strings.Maps.Constants;  use Ada.Strings.Maps.Constants;
 
 package body Ada.Characters.Handling is
-pragma Preelaborate (Handling);
 
    ------------------------------------
    -- Character Classification Table --
