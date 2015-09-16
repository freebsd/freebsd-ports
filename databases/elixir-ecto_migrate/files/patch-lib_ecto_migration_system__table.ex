--- lib/ecto/migration/system_table.ex.orig	2015-09-09 09:37:03 UTC
+++ lib/ecto/migration/system_table.ex
@@ -5,7 +5,7 @@ defmodule Ecto.Migration.SystemTable.Ind
       add :tablename, :string
       add :index, :string
       add :name, :string
-      add :concurrently
+      add :concurrently, :boolean
       add :unique, :boolean
       add :using, :string
     end
