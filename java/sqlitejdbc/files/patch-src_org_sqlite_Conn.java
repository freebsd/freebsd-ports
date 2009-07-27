--- src/org/sqlite/Conn.java.orig	2009-07-22 18:33:46.000000000 +0200
+++ src/org/sqlite/Conn.java	2009-07-22 18:33:53.000000000 +0200
@@ -214,7 +214,10 @@ class Conn implements Connection
                                      ResultSet.CONCUR_READ_ONLY);
     }
     public PreparedStatement prepareStatement(String sql, int autoC)
-        throws SQLException { throw new SQLException("NYI"); }
+                                throws SQLException {
+        return prepareStatement(sql, ResultSet.TYPE_FORWARD_ONLY,
+                                     ResultSet.CONCUR_READ_ONLY);
+    }
     public PreparedStatement prepareStatement(String sql, int[] colInds)
         throws SQLException { throw new SQLException("NYI"); }
     public PreparedStatement prepareStatement(String sql, String[]
