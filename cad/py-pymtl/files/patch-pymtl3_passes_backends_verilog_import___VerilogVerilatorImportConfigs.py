-- Update the Verilator import config for the current FreeBSD toolchain.
-- Simplify unsupported GCC-only compiler flags for clang, suppress fatal
-- Verilator 5 warnings that are non-fatal for the tests, and find/reorder
-- generated support files the way modern Verilator emits them.

--- pymtl3/passes/backends/verilog/import_/VerilogVerilatorImportConfigs.py.orig	2026-07-02 20:56:13 UTC
+++ pymtl3/passes/backends/verilog/import_/VerilogVerilatorImportConfigs.py
@@ -6,6 +6,7 @@ import copy
 """Configuration of Verilator import pass."""
 
 import copy
+import glob
 import os
 import subprocess
 from textwrap import fill, indent
@@ -68,11 +69,11 @@ class VerilogVerilatorImportConfigs( BasePassConfigs )
     # False to disable the warnings, True to enable
     "vl_W_lint" : True,
     "vl_W_style" : True,
-    "vl_W_fatal" : True,
+    "vl_W_fatal" : False,
 
     # Un-warn all warnings in the given list; [] to disable this option
     # The given list should only include strings that appear in `Warnings`
-    "vl_Wno_list" : [ 'UNOPTFLAT', 'UNSIGNED', 'WIDTH' ],
+    "vl_Wno_list" : [ 'MULTIDRIVEN', 'UNOPTFLAT', 'UNSIGNED', 'WIDTH' ],
 
     # Verilator misc options
 
@@ -317,9 +318,11 @@ class VerilogVerilatorImportConfigs( BasePassConfigs )
     # (7/9/2020): Use -O0 by default so that normally the tests are super fast and don't corrupt cffi,
     # but when the user gives a "fast" flag, it uses -O1.
     if s.fast:
-      c_flags = "-O1 -fno-guess-branch-probability -fno-reorder-blocks -fno-if-conversion -fno-if-conversion2 -fno-dce -fno-delayed-branch -fno-dse -fno-auto-inc-dec -fno-branch-count-reg -fno-combine-stack-adjustments -fno-cprop-registers -fno-forward-propagate -fno-inline-functions-called-once -fno-ipa-profile -fno-ipa-pure-const -fno-ipa-reference -fno-move-loop-invariants -fno-omit-frame-pointer -fno-split-wide-types -fno-tree-bit-ccp -fno-tree-ccp -fno-tree-ch -fno-tree-coalesce-vars -fno-tree-copy-prop -fno-tree-dce -fno-tree-dominator-opts -fno-tree-dse -fno-tree-fre -fno-tree-phiprop -fno-tree-pta -fno-tree-scev-cprop -fno-tree-sink -fno-tree-slsr -fno-tree-sra -fno-tree-ter -fno-tree-reassoc -fPIC -fno-gnu-unique -shared"
+      #c_flags = "-O1 -fno-guess-branch-probability -fno-reorder-blocks -fno-if-conversion -fno-if-conversion2 -fno-dce -fno-delayed-branch -fno-dse -fno-auto-inc-dec -fno-branch-count-reg -fno-combine-stack-adjustments -fno-cprop-registers -fno-forward-propagate -fno-inline-functions-called-once -fno-ipa-profile -fno-ipa-pure-const -fno-ipa-reference -fno-move-loop-invariants -fno-omit-frame-pointer -fno-split-wide-types -fno-tree-bit-ccp -fno-tree-ccp -fno-tree-ch -fno-tree-coalesce-vars -fno-tree-copy-prop -fno-tree-dce -fno-tree-dominator-opts -fno-tree-dse -fno-tree-fre -fno-tree-phiprop -fno-tree-pta -fno-tree-scev-cprop -fno-tree-sink -fno-tree-slsr -fno-tree-sra -fno-tree-ter -fno-tree-reassoc -fPIC -fno-gnu-unique -shared"
+      c_flags = "-O1 -fPIC -shared"
     else:
-      c_flags = "-O0 -fno-guess-branch-probability -fno-reorder-blocks -fno-if-conversion -fno-if-conversion2 -fno-dce -fno-delayed-branch -fno-dse -fno-auto-inc-dec -fno-branch-count-reg -fno-combine-stack-adjustments -fno-cprop-registers -fno-forward-propagate -fno-inline-functions-called-once -fno-ipa-profile -fno-ipa-pure-const -fno-ipa-reference -fno-move-loop-invariants -fno-omit-frame-pointer -fno-split-wide-types -fno-tree-bit-ccp -fno-tree-ccp -fno-tree-ch -fno-tree-coalesce-vars -fno-tree-copy-prop -fno-tree-dce -fno-tree-dominator-opts -fno-tree-dse -fno-tree-fre -fno-tree-phiprop -fno-tree-pta -fno-tree-scev-cprop -fno-tree-sink -fno-tree-slsr -fno-tree-sra -fno-tree-ter -fno-tree-reassoc -fPIC -fno-gnu-unique -shared"
+      #c_flags = "-O0 -fno-guess-branch-probability -fno-reorder-blocks -fno-if-conversion -fno-if-conversion2 -fno-dce -fno-delayed-branch -fno-dse -fno-auto-inc-dec -fno-branch-count-reg -fno-combine-stack-adjustments -fno-cprop-registers -fno-forward-propagate -fno-inline-functions-called-once -fno-ipa-profile -fno-ipa-pure-const -fno-ipa-reference -fno-move-loop-invariants -fno-omit-frame-pointer -fno-split-wide-types -fno-tree-bit-ccp -fno-tree-ccp -fno-tree-ch -fno-tree-coalesce-vars -fno-tree-copy-prop -fno-tree-dce -fno-tree-dominator-opts -fno-tree-dse -fno-tree-fre -fno-tree-phiprop -fno-tree-pta -fno-tree-scev-cprop -fno-tree-sink -fno-tree-slsr -fno-tree-sra -fno-tree-ter -fno-tree-reassoc -fPIC -fno-gnu-unique -shared"
+      c_flags = "-O0 -fPIC -shared"
 
     if not s.is_default("c_flags"):
       c_flags += f" {expand(s.c_flags)}"
@@ -347,9 +350,9 @@ class VerilogVerilatorImportConfigs( BasePassConfigs )
   #---------------------
 
   def _create_vl_warning_cmd( s ):
-    lint = "" if s.is_default("vl_W_lint") else "--Wno-lint"
-    style = "" if s.is_default("vl_W_style") else "--Wno-style"
-    fatal = "" if s.is_default("vl_W_fatal") else "--Wno-fatal"
+    lint = "" if s.vl_W_lint else "--Wno-lint"
+    style = "" if s.vl_W_style else "--Wno-style"
+    fatal = "" if s.vl_W_fatal else "--Wno-fatal"
     wno = " ".join(f"--Wno-{w}" for w in s.vl_Wno_list)
     return " ".join(w for w in [lint, style, fatal, wno] if w)
 
@@ -382,7 +385,10 @@ $PYMTL_VERILATOR_INCLUDE_DIR is set or `pkg-config` ha
   def _get_c_src_files( s ):
     top_module = s.translated_top_module
     vl_mk_dir = s.vl_mk_dir
-    vl_class_mk = f"{vl_mk_dir}/V{top_module}_classes.mk"
+    vl_class_mks = sorted(glob.glob(f"{vl_mk_dir}/*_classes.mk"))
+    if not vl_class_mks:
+      raise FileNotFoundError(f"No Verilator classes makefile found in {vl_mk_dir}")
+    vl_class_mk = vl_class_mks[0]
 
     # Add C wrapper
     o0 = []
@@ -391,13 +397,13 @@ $PYMTL_VERILATOR_INCLUDE_DIR is set or `pkg-config` ha
     # Add files listed in class makefile
     with open(vl_class_mk) as class_mk:
       all_lines = class_mk.readlines()
+      o1 += s._get_srcs_from_vl_class_mk( all_lines, s.vl_include_dir, "VM_GLOBAL_FAST")
       o1 += s._get_srcs_from_vl_class_mk( all_lines, vl_mk_dir, "VM_CLASSES_FAST")
       o1 += s._get_srcs_from_vl_class_mk( all_lines, vl_mk_dir, "VM_SUPPORT_FAST")
-      o1 += s._get_srcs_from_vl_class_mk( all_lines, s.vl_include_dir, "VM_GLOBAL_FAST")
 
+      o0 += s._get_srcs_from_vl_class_mk( all_lines, s.vl_include_dir, "VM_GLOBAL_SLOW")
       o0 += s._get_srcs_from_vl_class_mk( all_lines, vl_mk_dir, "VM_CLASSES_SLOW")
       o0 += s._get_srcs_from_vl_class_mk( all_lines, vl_mk_dir, "VM_SUPPORT_SLOW")
-      o0 += s._get_srcs_from_vl_class_mk( all_lines, s.vl_include_dir, "VM_GLOBAL_SLOW")
 
     with open(f"{top_module}_v__ALL_pickled.cpp", 'w') as out:
 
