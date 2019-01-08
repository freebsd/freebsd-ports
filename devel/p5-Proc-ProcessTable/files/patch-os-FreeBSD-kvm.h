--- os/FreeBSD-kvm.h-orig       2018-01-27 02:27:42.000000000 -0600
+++ os/FreeBSD-kvm.h    2019-01-07 03:37:31.984718000 -0600
@@ -13,7 +13,7 @@

 /* We need to pass in a cap for ignore, lower for store on object */
 /* We can just lc these! */
-static char Defaultformat[] = "iiiiiiiisssssssssssssissiiiiiiiiiiiiiiVV";
+static char Defaultformat[] = "iiiiiiiisssssssssssssissiiiuiiiiiiiiiiVV";

 /* Mapping of field to type */
 static char* Fields[] = {
