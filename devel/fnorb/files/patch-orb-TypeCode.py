Yet another patch to ensure compatibility with Python 2.0+.

Thanks to Brad Chapman <chapmanb@arches.uga.edu> and
David Konerding <dek@cgl.ucsf.edu>.

-- Johann <wjv@FreeBSD.org>


--- orb/TypeCode.py.orig	Mon Apr  3 16:08:35 2000
+++ orb/TypeCode.py	Tue Oct  9 12:38:52 2001
@@ -1240,13 +1240,17 @@
     def _fnorb_marshal_value(self, cursor, value):
 	""" Marshal a VALUE of this type onto an octet stream. """
 
-	if (not isinstance(value, CORBA.Object) and
-	    not isinstance(value, CORBA.Object_skel)):
-	    raise CORBA.BAD_PARAM()
-
+    ## Bugfix: check if value is None *before* checking its
+    ## instance type (otherwise, trying to return a None
+    ## in place of an InterfaceObject would fail with BAD_PARAM
+    
 	# Python 'None' is used to represent CORBA 'nil'
 	if value is None:
 	    value = CORBA.Object(IOP.IOR())
+
+	if (not isinstance(value, CORBA.Object) and
+	    not isinstance(value, CORBA.Object_skel)):
+	    raise CORBA.BAD_PARAM()
 
 	value._fnorb_marshal(cursor)
 
