--- terminaltexteffects/template/effect_template.py.orig	2020-02-02 00:00:00 UTC
+++ terminaltexteffects/template/effect_template.py
@@ -69,7 +69,6 @@ class EffectConfig(BaseConfig):
         nargs="+",
         action=argutils.TupleAction,
         default=12,
-        action=argutils.TupleAction,
         metavar=argutils.PositiveInt.METAVAR,
         help=(
             "Space separated, unquoted, list of the number of gradient steps to use. More steps will "
