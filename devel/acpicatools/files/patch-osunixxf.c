--- acpica-unix-20030523/osunixxf.c.orig	2003-05-24 03:11:02.000000000 +0300
+++ acpica-unix-20030523/osunixxf.c	2007-08-28 15:57:49.000000000 +0300
@@ -452,7 +452,7 @@
 ACPI_STATUS
 AcpiOsMapMemory (
     ACPI_PHYSICAL_ADDRESS   where,
-    UINT32                  length,
+    ACPI_SIZE               length,
     void                    **there)
 {
     *there = (void *) (UINT32) where;
@@ -478,7 +478,7 @@
 void
 AcpiOsUnmapMemory (
     void                    *where,
-    UINT32                  length)
+    ACPI_SIZE               length)
 {
 
     return;
@@ -499,7 +499,7 @@
 
 void *
 AcpiOsAllocate (
-    UINT32                  size)
+    ACPI_SIZE               size)
 {
     void                    *Mem;
 
@@ -815,7 +815,7 @@
     UINT32                  milliseconds)
 {
 
-    sleep ((seconds * 1000) + milliseconds);
+    usleep ((seconds * 1000) + milliseconds);
     return;
 }
 
