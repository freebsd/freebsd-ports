--- parser.y.orig	Mon Mar 26 10:02:40 2001
+++ parser.y	Wed Sep 17 13:34:05 2003
@@ -3,11 +3,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#if defined(__DECCXX) || defined(__GNUC__)
-#include <alloca.h>
-#else
-#include <malloc.h>
-#endif
 
 #include "nmtbl.h"
 #include "token.h"
@@ -285,23 +280,27 @@
     $2->attrib(ctx_program); 
     $2->translate(ctx_program); 
 } 
+;
 
 input_file: program | module | unit
+	;
 
 program: block '.' { $$ = new program_node(NULL, NULL, NULL, NULL, $1, $2); }
 | PROGRAM IDENT prog_param_list ';' block '.'
 { 
     $$ = new program_node($1, $2, $3, $4, $5, $6);
 }
+;
 
 progend: { $$ = NULL; } | '.'
+;
 
 module: decl_part_list { $$ = new module_node(NULL, NULL, NULL, NULL, $1, NULL); }
 | PROGRAM IDENT prog_param_list ';' decl_part_list progend
 { 
     $$ = new module_node($1, $2, $3, $4, $5, $6);
 }
-
+;
 
 /* Turbo Pascal specific */
 
@@ -313,38 +312,46 @@
     { $$ = new unit_node(NULL, NULL, NULL, $1, $2, $3, $4, NULL, $5, $6); }
 | INTERFACE unit_decl_list IMPLEMENTATION unit_def_list compoundst '.'
     { $$ = new unit_node(NULL, NULL, NULL, $1, $2, $3, $4, $5, NULL, $6); }
+	;
 
 unit_def_list: decl_part_list 
-
+	;
 
 prog_param_list: { $$ = NULL; } 
     | '(' ident_list ')' { $$ = new import_list_node($1, $2, $3); }
+	;
 
 ident_list: IDENT ',' ident_list { $$ = new token_list($1, $3); }
     | IDENT { $$ = new token_list($1); }
+	;
 
 block: decl_part_list compoundst 
 {
     $$ = new block_node($1, $2);
 }
+;
 
 decl_part_list: { $$ = NULL; } 
     | decl_part decl_part_list { $1->next = $2; $$ = $1; }
+;
 
 decl_part: label_decl_part | const_def_part | type_def_part | var_decl_part 
          | proc_def | proc_fwd_decl | unit_spec
+;
 
 unit_spec: UNIT IDENT ';' INTERFACE unit_decl_list UNIT_END  
     {  $$ = new unit_spec_node($1, $2, $3, $4, $5); }
 | INTERFACE unit_decl_list UNIT_END
     {  $$ = new unit_spec_node(NULL, NULL, NULL, $1, $2); }
-  
+;  
 
 unit_decl_list: { $$ = NULL; }
     | unit_decl unit_decl_list { $1->next = $2; $$ = $1; }
+;
 
 unit_decl: label_decl_part | const_def_part | type_def_part | var_decl_part
     | proc_spec | proc_fwd_decl | unit_spec
+;
 
 /*
 //=============================================================================
@@ -401,15 +408,20 @@
     | ICONST ':' statement { $$ = new label_node($1, $2, $3); }
     | IDENT ':' statement { $$ = new label_node($1, $2, $3); }
     | compoundst { $$ = $1; }
+;
   
 compoundst: BEGIN sequence END { $$ = new compound_node($1, $2, $3); }
+;
 
 sequence: statement | statement ';' sequence { $1->next = $3; $$ = $1; }
+;
 
 actual_params: { $$ = NULL; } | expr_group { $$ = $1; }
+;
 
 write_params:  { $$ = NULL; } 
     | '(' write_list ')' { $$ = new write_list_node($1, $2, $3); } 
+;
 
 case_list: case_items
          | case_items otherwise sequence
@@ -423,20 +435,26 @@
 	         $$ = new case_node(NULL, $2, $3);
              }
 	   }
+;
 
 otherwise: OTHERWISE | ELSE /* Turbo Pascal */
+;
 
 case_items: { $$ = NULL; } 
          | case_item 
          | case_item ';' case_items { $1->next = $3; $$ = $1; }
+;
 
 case_item: case_elem_list ':' statement { $$ = new case_node($1, $2, $3); }
+;
 
 case_elem_list: case_elem 
         | case_elem ',' case_elem_list { $1->next = $3; $$ = $1; }
+;
 
 case_elem: expr { $$ = $1; }
         | expr DOTS expr { $$ = new case_range_node($1, $2, $3); }
+;
 
 /*
 //=============================================================================
@@ -485,6 +503,7 @@
    | expr OR expr  { $$ = new op_node(tn_or, $1, $2, $3); } 
    | expr XOR expr { $$ = new op_node(tn_xor, $1, $2, $3); } 
 
+
    | expr GT expr { $$ = new op_node(tn_gt, $1, $2, $3); } 
    | expr LT expr { $$ = new op_node(tn_lt, $1, $2, $3); } 
    | expr LE expr { $$ = new op_node(tn_le, $1, $2, $3); } 
@@ -492,6 +511,7 @@
    | expr EQ expr { $$ = new op_node(tn_eq, $1, $2, $3); } 
    | expr NE expr { $$ = new op_node(tn_ne, $1, $2, $3); } 
    | expr IN expr { $$ = new op_node(tn_in, $1, $2, $3); } 
+;
 
 simple_expr: primary
    | PLUS simple_expr %prec UPLUS {
@@ -502,6 +522,7 @@
      { $$ = new op_node(tn_not, NULL, $1, $2); }
    | '@' primary { $$ = new address_node($1, $2); }
    | AND primary %prec ADDRESS { $$ = new address_node($1, $2); }
+;
  
 primary: constant 
    | '(' expr_list ')' { $$ = new expr_group_node($1, $2, $3); }
@@ -510,6 +531,7 @@
    | primary '^' { $$ = new deref_expr_node($1, $2); }
    | primary '[' expr_list ']' { $$ = new idx_expr_node($1, $2, $3, $4); }
    | LOOPHOLE '(' type ',' expr ')' { $$ = new loophole_node($1, $2, $3, $4, $5, $6); }
+;
 
 constant: record_constant
         | ICONST { $$ = new integer_node($1); }
@@ -517,41 +539,49 @@
         | SCONST { $$ = new string_node($1); }
         | '[' set_elem_list ']' { $$ = new set_node($1, $2, $3); }
         | IDENT { $$ = new atom_expr_node($1); }
+;
 
 set_elem_list: { $$ = NULL; } 
              | set_elem 
              | set_elem ',' set_elem_list { $1->next = $3; $$ = $1; }
+;
 
 set_elem: expr { $$ = new set_elem_node($1); }
         | expr DOTS expr { $$ = new set_range_node($1, $2, $3); }
+;
 
 expr_list: expr | expr ',' expr_list { $1->next = $3; $$ = $1; }
+;
 
 act_param_list: act_param 
     | act_param ',' act_param_list { $1->next = $3; $$ = $1; }
+;
 
 act_param: expr | { $$ = new skipped_node(curr_token->prev_relevant()); }
-
+;
 
 record_constant: '(' field_init_list ')' { 
     $$ = new record_constant_node($1, $2, $3); 
 }
+;
 
 field_init_list: field_init_item { $$ = $1; }
     | field_init_item ';' field_init_list { $1->next = $3; $$ = $1; }
+;
    
 field_init_item: IDENT ':' expr { $$ = new field_init_node($1, $2, $3); }
-
+;
 
 expr_group: '(' expr_list ')' { $$ = new expr_group_node($1, $2, $3); }
-
+;
 
 write_list: write_param | write_param ',' write_list { $1->next = $3; $$ = $1; }
+;
 
 write_param: expr  { $$ = new write_param_node($1); }
     | expr ':' expr { $$ = new write_param_node($1, $2, $3); }
     | expr ':' expr ':' expr { $$ = new write_param_node($1, $2, $3, $4, $5); }
-
+;
 
 /*
 //=============================================================================
@@ -594,31 +624,40 @@
 
 label_decl_part: LABEL label_list ';' 
     { $$ = new label_decl_part_node($1, $2, $3); }
+;
 
 label_list: ICONST { $$ = new token_list($1); } 
           | ICONST ',' label_list { $$ = new token_list($1, $3); }
           | IDENT { $$ = new token_list($1); } 
           | IDENT ',' label_list { $$ = new token_list($1, $3); }
+;
 
 const_def_part: CONST const_def_list  
     { $$ = new const_def_part_node($1, $2); } 
+;
 
 const_def_list: { $$ = NULL; } 
     | const_def ';' const_def_list { $1->next = $3; $$ = $1; }
+;
 
 const_def: IDENT EQ expr { $$ = new const_def_node($1, $2, $3); }
 | IDENT ':' const_type EQ expr { $$ = new typed_const_def_node($1, $2, $3, $4, $5); }
+;
 
 type_def_part: TYPE type_def_list  
     { $$ = new type_def_part_node($1, $2); }
+;
 
 type_def_list: { $$ = NULL; }
     | type_def ';' type_def_list { $1->next = $3; $$ = $1; }
+;
 
 type_def: IDENT EQ type { $$ = new type_def_node($1, $2, $3); }
+;
 
 var_decl_part: VAR var_decl_list 
      { $$ = new var_decl_part_node($1, $2); }
+;
 
 var_decl_list: { $$ = NULL; }
      | var_decl
@@ -634,29 +673,33 @@
 	 $1->next = $5; $$ = $1; 
        }
      | var_decl ';' var_decl_list { $1->next = $3; $$ = $1; }
+;
 
 var_decl: ident_list ':' type { $$ = new var_decl_node($1, $2, $3); }
      | IDENT ORIGIN expr ':' simple_type 
        { $$ = (var_decl_node*)new var_origin_decl_node($1, $2, $3, $4, $5); }
+;
 
 proc_decl: 
       PROCEDURE IDENT formal_params  
                { $$ = new proc_decl_node($1, $2, $3); } 
     | FUNCTION IDENT formal_params ':' type 
                { $$ = new proc_decl_node($1, $2, $3, $4, $5); } 
-    
+;    
 
 proc_fwd_decl: 
       PROCEDURE IDENT formal_params ';' qualifiers ';' 
         { $$ = new proc_fwd_decl_node($1, $2, $3, NULL, NULL, $4, $5, $6); } 
     | FUNCTION IDENT formal_params ':' type ';' qualifiers ';' 
         { $$ = new proc_fwd_decl_node($1, $2, $3, $4, $5, $6, $7, $8); } 
+;
 
 proc_spec: 
       PROCEDURE IDENT formal_params ';'
         { $$ = new proc_fwd_decl_node($1, $2, $3, NULL, NULL, $4); } 
     | FUNCTION IDENT formal_params ':' type ';'
         { $$ = new proc_fwd_decl_node($1, $2, $3, $4, $5, $6); } 
+;
 
 proc_def: 
       PROCEDURE IDENT formal_params ';' block ';' 
@@ -675,135 +718,166 @@
                { $$ = new proc_def_node($1, NULL, NULL, $2, $3, $4, $5, $6, $7, $8, $9, $10); } 
     | FUNCTION IDENT ';' FAR ';' block ';' 
                { $$ = new proc_def_node($1, NULL, NULL, $2, NULL, NULL, NULL, $3, $4, $5, $6, $7); } 
+;
 
 qualifiers: IDENT qualifiers { $$ = new token_list($1, $2); }
     | SCOPE qualifiers { $$ = new token_list($1, $2); }
     | IDENT { $$ = new token_list($1); }
     | SCOPE { $$ = new token_list($1); }
-
+;
 
 formal_params: { $$ = NULL; } 
     | '(' formal_param_list ')' { $$ = new param_list_node($1, $2, $3); }
+;
 
 formal_param_list: formal_param 
     | formal_param ';' formal_param_list { $1->next = $3; $$ = $1; }
+;
 
 formal_param: VAR param_decl { $$ = new var_decl_part_node($1, $2); }
     | param_decl { $$ = $1; } | proc_decl
+;
 
 param_decl: ident_list ':' param_type { $$ = new var_decl_node($1, $2, $3); }
     | ident_list { $$ = new var_decl_node($1, NULL, NULL); }
+;
 
 param_type: simple_type | conformant_array_type
-
-
+;
 
 /* Types definition */ 
 
 type: simple_type | array_type | record_type | object_type | set_type | file_type 
     | pointer_type | enum_type | range_type | string_type | fptr_type
+;
 
 const_type: simple_type | const_array_type | record_type | const_set_type | string_type
+;
 
 fptr_type: FUNCTION formal_params ':' type
     { $$ = new fptr_tpd_node($1, $2, $3, $4); }
     | PROCEDURE formal_params { $$ = new fptr_tpd_node($1, $2); }
+;
 
 string_type: STRING '[' expr ']' { $$ = new varying_tpd_node($1, $2, $3, $4); }
+;
 
 simple_type: IDENT { $$ = new simple_tpd_node($1); } 
     | STRING { $$ = new string_tpd_node($1); }
+;
 
 array_type: packed ARRAY '[' indices ']' OF type 
     { $$ = new array_tpd_node($1, $2, $3, $4, $5, $6, $7); }
+;
 
 const_array_type: packed ARRAY '[' indices ']' OF const_type 
     { $$ = new array_tpd_node($1, $2, $3, $4, $5, $6, $7); }
+;
 
 conformant_array_type: packed ARRAY '[' conformant_indices ']' OF simple_type 
          { $$ = new array_tpd_node($1, $2, $3, $4, $5, $6, $7); }
     | packed ARRAY '[' conformant_indices ']' OF conformant_array_type 
          { $$ = new array_tpd_node($1, $2, $3, $4, $5, $6, $7); }
+;
 
 enum_type: '(' ident_list ')' { $$ = new enum_tpd_node($1, $2, $3); }
+;
 
 range_type: expr DOTS expr 
     { $$ = new range_tpd_node($1, $2, $3); } 
+;
 
 pointer_type: '^' type { $$ = new ptr_tpd_node($1, $2); }
+;
 
 set_type: packed SET OF type { $$ = new set_tpd_node($1, $2, $3, $4); }
+;
 
 const_set_type: packed SET OF const_type { $$ = new set_tpd_node($1, $2, $3, $4); }
+;
 
 record_type: packed RECORD field_list END 
     { $$ = new record_tpd_node($1, $2, $3, $4); }
+;
 
 object_type: OBJECT object_components END
     { $$ = new object_tpd_node($1, NULL, NULL, NULL, $2, $3); }
 | OBJECT '(' IDENT ')' object_components END
     { $$ = new object_tpd_node($1, $2, $3, $4, $5, $6); }
+;
 
 object_components: object_fields object_methods
     { $1->next = $2; $$ = $1; } 
   | object_methods
   | object_fields
+;
 
 object_fields: field_decl_list 
     { $$ = new var_decl_part_node(NULL, $1); }
+;
 
 field_decl_list: var_decl
      | var_decl ';' { $$ = $1; }
      | var_decl ';' field_decl_list { $1->next = $3; $$ = $1; }
+;
 
 object_methods: proc_fwd_decl | proc_spec
   | proc_fwd_decl object_methods { $1->next = $2; $$ = $1; }
   | proc_spec object_methods { $1->next = $2; $$ = $1; }
-  
-
+;
 
 file_type: packed FIL OF type { $$ = new file_tpd_node($1, $2, $3, $4); }
+;
 
-packed: { $$ = NULL; } | PACKED 
+packed: { $$ = NULL; } | PACKED
+;
 
 conformant_indices: conformant_index
     | conformant_index ';' conformant_indices { $1->next = $3; $$ = $1; }
+;
 
 conformant_index: IDENT DOTS IDENT ':' type 
     { $$ = new conformant_index_node($1, $2, $3, $4, $5); }
+;
 
 indices: index_spec | index_spec ',' indices 
     { $1->next = $3; $$ = $1; }
+;
 
 index_spec: simple_type { $$ = new type_index_node($1); }
     | expr DOTS expr { $$ = new range_index_node($1, $2, $3); }
-
+;
 
 field_list: 
     fixed_part variant_part     
         { $$ = new field_list_node($1, $2); }
     | fixed_part                   
         { $$ = new field_list_node($1); }
+;
 
 fixed_part: var_decl_list
+;
 
 variant_part: CASE selector OF variant_list 
 { 
     $$ = new variant_part_node($1, $2, $3, $4); 
 }
+;
 
 selector: IDENT ':' type { $$ = new selector_node($1, $2, $3); }
         | type { $$ = new selector_node(NULL, NULL, $1); }
-
+;
 
 variant_list: variant
         | variant ';' { $$ = $1; }
         | variant ';' variant_list { $1->next = $3; $$ = $1; }
+;
 
 variant: expr_list ':' '(' field_list ')' 
 { 
     $$ = new variant_node($1, $2, $3, $4, $5); 
 }
+;
 
 %%
 
