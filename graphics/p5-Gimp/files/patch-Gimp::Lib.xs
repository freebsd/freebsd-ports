--- Gimp/Lib.xs.orig	Thu Apr 11 17:46:42 2002
+++ Gimp/Lib.xs	Thu Apr 11 17:47:51 2002
@@ -968,6 +968,10 @@
                   {
                                         arg->data.d_image      = unbless(sv, PKG_IMAGE   , croak_str); break;
                   }
+		else if (sv_derived_from (sv, PKG_IMAGE) || SvROK(sv))
+		  {
+			  		arg->data.d_image      = unbless(SvRV(sv), PKG_IMAGE   , croak_str); break;
+		  }
                 else
                   strcpy (croak_str, __("argument incompatible with type IMAGE"));
 
