diff --git a/tools/widl/write_msft.c b/tools/widl/write_msft.c
index 01e98a6..fd237dc 100644
--- tools/widl/write_msft.c
+++ tools/widl/write_msft.c
@@ -2191,6 +2191,30 @@ static void add_module_typeinfo(msft_typelib_t *typelib, type_t *module)
     msft_typeinfo->typeinfo->size = idx;
 }
 
+static void add_type_typeinfo(msft_typelib_t *typelib, type_t *type)
+{
+    switch (type->kind) {
+    case TKIND_INTERFACE:
+    case TKIND_DISPATCH:
+        add_interface_typeinfo(typelib, type);
+        break;
+    case TKIND_RECORD:
+        add_structure_typeinfo(typelib, type);
+        break;
+    case TKIND_ENUM:
+        add_enum_typeinfo(typelib, type);
+        break;
+    case TKIND_COCLASS:
+        add_coclass_typeinfo(typelib, type);
+        break;
+    case TKIND_PRIMITIVE:
+        break;
+    default:
+        error("add_entry: unhandled type %d for %s\n", type->kind, type->name);
+        break;
+    }
+}
+
 static void add_entry(msft_typelib_t *typelib, const statement_t *stmt)
 {
     switch(stmt->type) {
@@ -2206,9 +2230,14 @@ static void add_entry(msft_typelib_t *typelib, const statement_t *stmt)
     case STMT_TYPEDEF:
     {
         const type_list_t *type_entry = stmt->u.type_list;
-        for (; type_entry; type_entry = type_entry->next)
+        for (; type_entry; type_entry = type_entry->next) {
+            /* if the type is public then add the typedef, otherwise attempt
+             * to add the aliased type */
             if (is_attr(type_entry->type->attrs, ATTR_PUBLIC))
                 add_typedef_typeinfo(typelib, type_entry->type);
+            else
+                add_type_typeinfo(typelib, type_entry->type->orig);
+        }
         break;
     }
     case STMT_MODULE:
@@ -2218,24 +2247,7 @@ static void add_entry(msft_typelib_t *typelib, const statement_t *stmt)
     case STMT_TYPEREF:
     {
         type_t *type = stmt->u.type;
-        switch (type->kind) {
-        case TKIND_INTERFACE:
-        case TKIND_DISPATCH:
-            add_interface_typeinfo(typelib, type);
-            break;
-        case TKIND_RECORD:
-            add_structure_typeinfo(typelib, type);
-            break;
-        case TKIND_ENUM:
-            add_enum_typeinfo(typelib, type);
-            break;
-        case TKIND_COCLASS:
-            add_coclass_typeinfo(typelib, type);
-            break;
-        default:
-            error("add_entry: unhandled type %d\n", type->kind);
-            break;
-        }
+        add_type_typeinfo(typelib, type);
         break;
     }
     }
