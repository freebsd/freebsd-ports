Nasty, nasty workaround for an error which I can't quite explain.  This
happens only if Fnorb is chosen as CORBA ORB.  Since CORBA support itself
is optional in this port, this patch is added to EXTRA_PATCHES only if
necessary.

-- Johann Visagie <wjv@FreeBSD.org>


--- ../biopython-corba-0.2.1/build_helper.py.orig	Sun Apr 15 15:19:31 2001
+++ ../biopython-corba-0.2.1/build_helper.py	Thu Jun  7 16:25:05 2001
@@ -125,7 +125,12 @@
     # move the new file in place of the old
     input_handle.close()
     output_handle.close()
-    os.rename(output_file, file)
+    input_handle = open(output_file, 'r')
+    output_handle = open(file, 'w')
+    S = input_handle.read()
+    output_handle.write(S)
+    input_handle.close()
+    output_handle.close()
 
 def generate_orbit_stubs(idl_name, remove_old = 1):
     """Move adapters to act as stubs and skeletons for ORBit.
