--- klaptopdaemon/portable.cpp-	Thu Jun 28 00:08:02 2001
+++ klaptopdaemon/portable.cpp	Thu Jun 28 00:08:22 2001
@@ -453,7 +453,7 @@
 	if (ret == -1)
 	  return 0;
 
-	return (info.ai_batt_time != 0xffff);
+	return (info.ai_batt_time != -1);
 }
 
 //
@@ -638,7 +638,7 @@
 
        	p.powered = info.ai_acline;
        	p.percentage = (info.ai_batt_life==255 ? 100 : info.ai_batt_life);
-       	p.time = (info.ai_batt_time != 0xffff ? info.ai_batt_time/60 : -1);
+       	p.time = (info.ai_batt_time != -1 ? info.ai_batt_time/60 : -1);
        	return(p);
 
 bad:
