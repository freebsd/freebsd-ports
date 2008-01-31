--- sql/sql_select.cc.orig	2008-01-31 23:10:38.000000000 +0100
+++ sql/sql_select.cc	2008-01-31 23:11:31.000000000 +0100
@@ -1068,7 +1068,8 @@
         <fields> to ORDER BY <fields>. One exception is if skip_sort_order is
         set (see above), then we can simply skip GROUP BY.
        */
-      order= skip_sort_order ? 0 : group_list;
+      if (!order || test_if_subpart(group_list, order))
+          order= skip_sort_order ? 0 : group_list;
       group_list= 0;
       group= 0;
     }
