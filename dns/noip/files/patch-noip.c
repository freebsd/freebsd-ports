--- noip.c.bak	Sat Mar 30 17:59:58 2002
+++ noip.c	Sat Mar 30 17:59:15 2002
@@ -452,7 +452,8 @@
 		    else
 			getip(IPaddress);
 #ifdef DEBUG
-		    ErrMsg("! LIA = %s, IP = %s",Last_IP_Addr, IPaddress);
+		    if (debug)
+			ErrMsg("! LIA = %s, IP = %s",Last_IP_Addr, IPaddress);
 #endif
 		    if ((*IPaddress != 0) && 
 				(strcmp(IPaddress, Last_IP_Addr) != 0)) {
