--- sched.c.orig	Thu Jun 15 05:06:39 1995
+++ sched.c	Mon Mar 20 13:29:12 2000
@@ -794,11 +794,14 @@
    changed.  A volatile and non-volatile reference can be interchanged
    though. 
 
-   A MEM_IN_STRUCT reference at a non-QImode varying address can never
+   A MEM_IN_STRUCT reference at a non-QImode non-AND varying address can never
    conflict with a non-MEM_IN_STRUCT reference at a fixed address.   We must
    allow QImode aliasing because the ANSI C standard allows character
    pointers to alias anything.  We are assuming that characters are
-   always QImode here.  */
+   always QImode here.  We also must allow AND addresses, because they may
+   generate accesses outside the object being referenced.  This is used to
+   generate aligned addresses from unaligned addresses, for instance, the
+   alpha storeqi_unaligned pattern.  */
 
 /* Read dependence: X is read after read in MEM takes place.  There can
    only be a dependence here if both reads are volatile.  */
@@ -833,9 +836,11 @@
 				  SIZE_FOR_MODE (x), XEXP (x, 0), 0)
 	      && ! (MEM_IN_STRUCT_P (mem) && rtx_addr_varies_p (mem)
 		    && GET_MODE (mem) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (x) && ! rtx_addr_varies_p (x))
 	      && ! (MEM_IN_STRUCT_P (x) && rtx_addr_varies_p (x)
 		    && GET_MODE (x) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (mem) && ! rtx_addr_varies_p (mem))));
 }
 
@@ -857,9 +862,11 @@
 				  SIZE_FOR_MODE (x), XEXP (x, 0), 0)
 	      && ! (MEM_IN_STRUCT_P (mem) && rtx_addr_varies_p (mem)
 		    && GET_MODE (mem) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (x) && ! rtx_addr_varies_p (x))
 	      && ! (MEM_IN_STRUCT_P (x) && rtx_addr_varies_p (x)
 		    && GET_MODE (x) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (mem) && ! rtx_addr_varies_p (mem))));
 }
 
@@ -875,9 +882,11 @@
 				  SIZE_FOR_MODE (x), XEXP (x, 0), 0)
 	      && ! (MEM_IN_STRUCT_P (mem) && rtx_addr_varies_p (mem)
 		    && GET_MODE (mem) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (x) && ! rtx_addr_varies_p (x))
 	      && ! (MEM_IN_STRUCT_P (x) && rtx_addr_varies_p (x)
 		    && GET_MODE (x) != QImode
+		    && GET_CODE (XEXP (mem, 0)) != AND
 		    && ! MEM_IN_STRUCT_P (mem) && ! rtx_addr_varies_p (mem))));
 }
 
