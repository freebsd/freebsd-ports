$FreeBSD$

--- ../../j2se/src/share/classes/java/util/Calendar.java.orig	Fri Oct  5 03:18:28 2007
+++ ../../j2se/src/share/classes/java/util/Calendar.java	Sat Feb 28 09:34:02 2009
@@ -23,9 +23,14 @@ package java.util;
 import java.io.IOException;
 import java.io.ObjectInputStream;
 import java.io.ObjectOutputStream;
+import java.io.OptionalDataException;
 import java.io.Serializable;
+import java.security.AccessControlContext;
 import java.security.AccessController;
+import java.security.PermissionCollection;
+import java.security.PrivilegedActionException;
 import java.security.PrivilegedExceptionAction;
+import java.security.ProtectionDomain;
 import java.text.DateFormat;
 import sun.text.resources.LocaleData;
 import sun.util.BuddhistCalendar;
@@ -2396,6 +2401,18 @@ public abstract class Calendar implements Serializable
 	}
     }
 
+    private static class CalendarAccessControlContext {
+        private static final AccessControlContext INSTANCE;
+        static {
+            RuntimePermission perm = new RuntimePermission("accessClassInPackage.sun.util.calendar");
+            PermissionCollection perms = perm.newPermissionCollection();
+            perms.add(perm);
+            INSTANCE = new AccessControlContext(new ProtectionDomain[] {
+                                                    new ProtectionDomain(null, perms)
+                                                });
+        }
+    }
+
     /**
      * Reconstitutes this object from a stream (i.e., deserialize it).
      */
@@ -2425,17 +2442,30 @@ public abstract class Calendar implements Serializable
         serialVersionOnStream = currentSerialVersion;
 
 	// If there's a ZoneInfo object, use it for zone.
+        ZoneInfo zi = null;
 	try {
-	    ZoneInfo zi = (ZoneInfo) AccessController.doPrivileged(
-		new PrivilegedExceptionAction() {
-		    public Object run() throws Exception {
-			return input.readObject();
-		    }
-		});
-	    if (zi != null) {
-		zone = zi;
-	    }
-	} catch (Exception e) {
+            zi = AccessController.doPrivileged(
+                    new PrivilegedExceptionAction<ZoneInfo>() {
+                        public ZoneInfo run() throws Exception {
+                            return (ZoneInfo) input.readObject();
+                        }
+                    },
+                    CalendarAccessControlContext.INSTANCE);
+        } catch (PrivilegedActionException pae) {
+            Exception e = pae.getException();
+            if (!(e instanceof OptionalDataException)) {
+                if (e instanceof RuntimeException) {
+                    throw (RuntimeException) e;
+                } else if (e instanceof IOException) {
+                    throw (IOException) e;
+                } else if (e instanceof ClassNotFoundException) {
+                    throw (ClassNotFoundException) e;
+                }
+                throw new RuntimeException(e);
+            }
+        }
+        if (zi != null) {
+            zone = zi;
 	}
 
 	// If the deserialized object has a SimpleTimeZone, try to
@@ -2444,9 +2474,9 @@ public abstract class Calendar implements Serializable
 	// implementation as much as possible.
 	if (zone instanceof SimpleTimeZone) {
 	    String id = zone.getID();
-	    TimeZone zi = TimeZone.getTimeZone(id);
-	    if (zi != null && zi.hasSameRules(zone) && zi.getID().equals(id)) {
-		zone = zi;
+            TimeZone tz = TimeZone.getTimeZone(id);
+            if (tz != null && tz.hasSameRules(zone) && tz.getID().equals(id)) {
+                zone = tz;
 	    }
 	}
     }
