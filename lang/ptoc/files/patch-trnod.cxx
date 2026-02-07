--- trnod.cxx.orig	2008-06-05 08:43:52 UTC
+++ trnod.cxx
@@ -468,7 +468,7 @@ void read_node::translate(int) 
     if (language_c) { 
         if (params) { 
             char const* format = "";
-	    char const* newln = (t_read->tag == TKN_READLN) ? "\\n" : "";
+	    char const* newln = (t_read->tag == TKN_READLN) ? (char *) "\\n" : "";
 	    expr_node *prm = params->expr; 
 
 	    l_tkn = params->rpar;
@@ -626,7 +626,7 @@ void write_node::translate(int) 
 	    write_param_node *prm = params->vals; 
 
 	    l_tkn = params->rpar;
-	    char const* newln = (t_write->tag == TKN_WRITELN) ? "\\n" : "";
+	    char const* newln = (t_write->tag == TKN_WRITELN) ? (char *) "\\n" : "";
             write_format = NULL;
 	    if (prm->type->tag == tp_file) { 
 		prm->translate(ctx_value);
@@ -1008,7 +1008,7 @@ void for_node::translate(int ctx)
     from->translate(ctx_value);
     from->l_tkn->append(";"); 
     t_to->set_trans(t_ident->out_text); 
-    t_to->append(t_to->name->tag == TKN_TO ? " <=" : " >=");  
+    t_to->append(t_to->name->tag == TKN_TO ? (char *) " <=" : (char *) " >=");  
     till->translate(ctx_value);
     till->l_tkn->append(";"); 
     if (t_to->name->tag == TKN_TO) { 
@@ -1077,11 +1077,11 @@ void repeat_node::translate(int ctx)
     bool body_is_block = 
 	body != NULL && body->is_compound() && body->next == NULL;
 
-    t_repeat->set_trans(body_is_block ? "do" : "do {"); 
+    t_repeat->set_trans(body_is_block ? (char *) "do" : (char *) "do {"); 
     for (stmt_node *stmt = body; stmt != NULL; stmt = stmt->next) { 
         stmt->translate(ctx); 
     }
-    t_until->set_trans(body_is_block ? "while" : "} while"); 
+    t_until->set_trans(body_is_block ? (char *) "while" : (char *) "} while"); 
     expr->translate(ctx_condition);
     f_tkn = t_repeat;
     l_tkn = expr->l_tkn; 
@@ -1272,7 +1272,7 @@ void atom_expr_node::translate(int ctx)
 
         } else if (var->type->tag == tp_proc) { 
 	    if (turbo_pascal && tkn->name->tag == TKN_HALT) {
-		tkn->set_trans(ctx == ctx_apply ? "exit" : "exit(0)");
+		tkn->set_trans(ctx == ctx_apply ? (char *) "exit" : (char *) "exit(0)");
 		return;
 	    }
 	    proc_tp* prc = (proc_tp*)var->type->get_typedef();
@@ -1294,8 +1294,8 @@ void atom_expr_node::translate(int ctx)
 			if (prm->var->type->tag == tp_file 
 			    || prm->var->type->tag == tp_text)
 			{
-			    t = t->append(strcmp(var->in_name->text, "page")
-					  ? "input" : "output");
+			    t = t->append(strcmp(var->in_name->text, (char *) "page")
+					  ? (char *) "input" : (char *) "output");
 			} else { 
 			    t = t->append("0");
 			}
@@ -1342,7 +1342,7 @@ void atom_expr_node::translate(int ctx)
 
             if (with != NULL) { 
 		f_tkn = tkn->prepend(language_c && with->tag == symbol::s_ref 
-				     ? "->" : ".")
+				     ? (char *) "->" : (char *) ".")
 		    ->prepend(with->out_name->text);
 	    }
 
@@ -1764,7 +1764,7 @@ void set_node::translate(int)
 	    t_lbr->set_trans("set::of("); 
 	}
     }
-    t_rbr->set_trans(items ? ", eos)" : "eos)"); 
+    t_rbr->set_trans(items ? (char *) ", eos)" : (char *) "eos)"); 
 }
 
 idx_expr_node::idx_expr_node(expr_node* arr, token* t_lbr, expr_node* indices, 
@@ -2196,7 +2196,7 @@ void op_node::translate(int) 
       case tn_and:
         op->set_trans(((left->type && left->type->tag != tp_bool) || 
 	    (right->type && right->type->tag != tp_bool) || nological)
-		      ? "&" : "&&");
+		      ? (char *) "&" : (char *) "&&");
 	if (parent_tag != tn_group && parent_tag != tn_and) { 
 	    f_tkn = left->f_tkn->prepend("(");
 	    l_tkn = right->l_tkn->append(")");
@@ -2216,12 +2216,12 @@ void op_node::translate(int) 
 	if (parent_tag != tn_group) { 
 	    f_tkn = left->f_tkn->prepend(left->type && 
 			left->type->get_typedef() == &longint_type
-			    ? "((unsigned long)" : "((cardinal)");
+			    ? (char *) "((unsigned long)" : (char *) "((cardinal)");
 	    l_tkn = right->l_tkn->append(")");
 	} else { 
 	    f_tkn = left->f_tkn->prepend(left->type && 
 			left->type->get_typedef() == &longint_type
-			    ? "(unsigned long)" : "(cardinal)");
+			    ? (char *) "(unsigned long)" : (char *) "(cardinal)");
 	} 
 	op->set_trans(">>");
 	break;
@@ -2239,14 +2239,14 @@ void op_node::translate(int) 
 	}
 	op->set_trans(((left->type && left->type->tag != tp_bool) || 
 		       (right->type && right->type->tag != tp_bool) || 
-		       nological) ? "|" : "||");
+		       nological) ? (char *) "|" : (char *) "||");
         break; 
       case tn_in:
         token::disable(left->l_tkn->next, right->f_tkn->prev);
 	if (language_c) { 
             f_tkn = left->f_tkn->prepend(
 		        short_set && ((set_tp*)right->type)->is_short_set()
-                        ? "INSET(" : "inset(");
+                        ? (char *) "INSET(" : (char *) "inset(");
 	    left->l_tkn->append(", ");
 	    l_tkn = right->l_tkn->append(")");
 	} else { 
@@ -2268,14 +2268,14 @@ void op_node::translate(int) 
 	    if (language_c) { 
 		if (short_set && ((set_tp*)type)->is_short_set()) {
 		    f_tkn = left->f_tkn->prepend(tag == tn_add 
-						 ? "JOIN(" : tag == tn_sub 
-						 ? "DIFFERENCE(" 
-						 : "INTERSECT(");
+						 ? (char *) "JOIN(" : tag == tn_sub 
+						 ? (char *) "DIFFERENCE(" 
+						 : (char *) "INTERSECT(");
 		} else { 		    
 		    f_tkn = left->f_tkn->prepend(tag == tn_add 
-						 ? "join(" : tag == tn_sub 
-						 ? "difference(" 
-						 : "intersect(");
+						 ? (char *) "join(" : tag == tn_sub 
+						 ? (char *) "difference(" 
+						 : (char *) "intersect(");
 		}
 		l_tkn = right->l_tkn->append(")");
 		token::disable(left->l_tkn->next, right->f_tkn->prev);
@@ -2313,9 +2313,9 @@ void op_node::translate(int) 
 		} 
 		else if (ltype->tag == tp_enum || rtype->size <= ltype->size)
 		{
-		    right->f_tkn->prepend(rtype->size == 1 ? "(unsigned char)":
-					  rtype->size == 2 ? "(unsigned short)"
-					  : "(unsigned)"); 
+		    right->f_tkn->prepend(rtype->size == 1 ? (char *) "(unsigned char)":
+					  rtype->size == 2 ? (char *) "(unsigned short)"
+					  : (char *) "(unsigned)"); 
 		}
 	    } else if (((rtype->tag == tp_range && rtype->min_value >= 0) ||
 			rtype->tag == tp_enum) &&
@@ -2328,9 +2328,9 @@ void op_node::translate(int) 
                 else if (rtype->tag == tp_enum || ltype->size <= rtype->size)
 		{
 		    f_tkn = left->f_tkn->prepend(
-					  ltype->size == 1 ? "(unsigned char)":
-					  ltype->size == 2 ? "(unsigned short)"
-					  : "(unsigned)"); 
+					  ltype->size == 1 ? (char *) "(unsigned char)":
+					  ltype->size == 2 ? (char *) "(unsigned short)"
+					  : (char *) "(unsigned)"); 
 		}
 	    }
 	}
@@ -2454,7 +2454,7 @@ void op_node::translate(int) 
 	op->set_trans(CMP_OP(tag)); 
         break; 
       case tn_not:
-        op->set_trans(right->type && right->type->tag == tp_bool ? "!" : "~"); 
+        op->set_trans(right->type && right->type->tag == tp_bool ? (char *) "!" : (char *) "~"); 
         break; 
     }
     if ((unsigned(tag - tn_add) <= tn_div - tn_add) && type && type->tag == tp_longint)
@@ -3440,7 +3440,7 @@ void const_def_node::translate(int)
 	    }
 	}
     } else { 
-	f_tkn = ident->prepend(language_c ? "static const " : "const "); 
+	f_tkn = ident->prepend(language_c ? (char *) "static const " : (char *) "const "); 
 	enumeration = NULL;
 	if (constant->type->tag == tp_string) { 
 	    ident->prepend("char ");
@@ -3783,16 +3783,16 @@ void  var_decl_node::translate(int ctx) 
 			t = tkn->ident->copy(eltd->f_tkn, eltd->l_tkn);
 			if (tp->tag == tp_dynarray) { 
 			    tkn->ident->prepend(ctx == ctx_varpar 
-						? "* " : " const* ");
+						? (char *) "* " : (char *) " const* ");
 			} else { 
 			    tkn->ident->prepend(ctx == ctx_varpar 
-						? " " : "  const ");
+						? (char *) " " : (char *) "  const ");
 			    tkn->ident->next->copy(tpd->f_tkn, tpd->l_tkn); 
 			}
 		    } else { 
 			t = tkn->ident->prepend(ctx == ctx_varpar
-						? tp->tag == tp_array || tp->tag == tp_string ? " " : "* "
-						: tp->tag == tp_array ? " const " : " ")->
+						? tp->tag == tp_array || tp->tag == tp_string ? (char *) " " : (char *) "* "
+						: tp->tag == tp_array ? (char *) " const " : (char *) " ")->
 			    copy(tpd->f_tkn, tpd->l_tkn); 
 		    }
 		} else { 
@@ -3857,7 +3857,7 @@ void  var_decl_node::translate(int ctx) 
 		// initialize file structure
 		tkn->ident->append(
 		    (tp->tag == tp_file || tp->tag == tp_text)
-		    ? " = VOID_FILE" : " = {0}");
+		    ? (char *) " = VOID_FILE" : (char *) " = {0}");
 	    }
 	    if (tkn->var->flags & symbol::f_static) { 
 		is_static = TRUE;
@@ -3888,8 +3888,8 @@ void  var_decl_node::translate(int ctx) 
         { 
 	    f_tkn = f_tkn->prepend("EXTERN ");
 	} else if (scope != NULL) { 
-	    f_tkn = f_tkn->prepend(scope->tag == TKN_EXTERNAL ? "extern " :
-				   scope->tag == TKN_STATIC ? "static " : "");
+	    f_tkn = f_tkn->prepend(scope->tag == TKN_EXTERNAL ? (char *) "extern " :
+				   scope->tag == TKN_STATIC ? (char *) "static " : (char *) "");
 	}
         force_semicolon();
 	if (is_static) { 
@@ -4249,7 +4249,7 @@ void proc_fwd_decl_node::translate(int) 
     if (qualifiers) { 
 	if (is_external) { 
 	    f_tkn = f_tkn->prepend(type->is_extern_c && !language_c 
-				   ? "extern \"C\" " : "extern ");
+				   ? (char *) "extern \"C\" " : (char *) "extern ");
 	} else if (is_static) { 
 	    f_tkn = f_tkn->prepend("static ");
 	} else if (is_virtual) { 
@@ -4875,7 +4875,7 @@ void array_tpd_node::translate(int ctx) 
 		t_array->set_trans("conf_matrix");
 	    } else {  	
 		t_array->set_trans(indices->next == NULL 
-				   ? "conf_array" : "conf_matrix");
+				   ? (char *) "conf_array" : (char *) "conf_matrix");
 	    }
 	    token::disable(t_array->next, eltd->f_tkn->prev);
 	    eltd->f_tkn->prepend("<");
