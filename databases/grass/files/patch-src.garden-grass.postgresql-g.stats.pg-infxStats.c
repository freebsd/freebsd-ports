--- src.garden/grass.postgresql/g.stats.pg/infxStats.c.orig	Sun Jul 11 17:20:22 2004
+++ src.garden/grass.postgresql/g.stats.pg/infxStats.c	Sun Jul 11 17:20:41 2004
@@ -37,7 +37,7 @@
     }
     
  if (freq )  {
-  sprintf (SQL_stmt,"SELECT count(*) as count, %s from %s %s 
+  sprintf (SQL_stmt,"SELECT count(*) as count, %s from %s %s\
          group by %s order by count(*)"
          ,col,tab,wherecl,col);  }
   else 
@@ -48,10 +48,10 @@
  
     PQclear (res);     
     if ( can_avg_col ) {
-       sprintf (SQL_stmt,"SELECT min(%s) as Min, max(%s) as Max, avg(%s) as Mean
+       sprintf (SQL_stmt,"SELECT min(%s) as Min, max(%s) as Max, avg(%s) as Mean\
        FROM %s %s",col,col,col,tab,wherecl);  }
     else
-       {sprintf (SQL_stmt,"SELECT min(%s) as Min, max(%s) as Max
+       {sprintf (SQL_stmt,"SELECT min(%s) as Min, max(%s) as Max\
        FROM %s %s",col,col,tab,wherecl);  }     
     }
     
