Description: Fix view validation on Python 3.14: check ast.Constant values
  instead of ast.Str and .s.
Issue ID: none (not yet reported to https://github.com/odoo/odoo)
Changeset: none
TODO: Upstream not checked yet: check whether it is fixed there and submit it
  if not.

--- odoo/addons/base/models/ir_ui_view.py.orig	2026-06-18 17:00:14 UTC
+++ odoo/addons/base/models/ir_ui_view.py
@@ -1773,13 +1773,13 @@ actual arch.
             elif attr == 'context':
                 for key, val_ast in get_dict_asts(expr).items():
                     if key == 'group_by':  # only in context
-                        if not isinstance(val_ast, ast.Str):
+                        if not (isinstance(val_ast, ast.Constant) and isinstance(val_ast.value, str)):
                             msg = _(
                                 '"group_by" value must be a string %(attribute)s=%(value)r',
                                 attribute=attr, value=expr,
                             )
                             self._raise_view_error(msg, node)
-                        group_by = val_ast.s
+                        group_by = val_ast.value
                         fname = group_by.split(':')[0]
                         if fname not in name_manager.model._fields:
                             msg = _(
