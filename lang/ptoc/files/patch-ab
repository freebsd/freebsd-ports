--- trnod.cxx.orig	Sat Oct 21 04:24:34 2000
+++ trnod.cxx	Sat Oct 21 04:45:38 2000
@@ -460,7 +460,7 @@
     if (language_c) { 
         if (params) { 
             char const* format = "";
-	    char const* newln = (t_read->tag == TKN_READLN) ? "\\n" : "";
+	    char const* newln = (t_read->tag == TKN_READLN) ? (char *) "\\n" : "";
 	    expr_node *prm = params->expr; 
 
 	    l_tkn = params->rpar;
@@ -618,7 +618,7 @@
 	    write_param_node *prm = params->vals; 
 
 	    l_tkn = params->rpar;
-	    char const* newln = (t_write->tag == TKN_WRITELN) ? "\\n" : "";
+	    char const* newln = (t_write->tag == TKN_WRITELN) ? (char *) "\\n" : "";
             write_format = NULL;
 	    if (prm->type->tag == tp_file) { 
 		prm->translate(ctx_value);
@@ -1000,7 +1000,7 @@
     from->translate(ctx_value);
     from->l_tkn->append(";"); 
     t_to->set_trans(t_ident->out_text); 
-    t_to->append(t_to->name->tag == TKN_TO ? " <=" : " >=");  
+    t_to->append(t_to->name->tag == TKN_TO ? (char *) " <=" : (char *) " >=");  
     till->translate(ctx_value);
     till->l_tkn->append(";"); 
     if (t_to->name->tag == TKN_TO) { 
@@ -1069,11 +1069,11 @@
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
@@ -1264,7 +1264,7 @@
 
         } else if (var->type->tag == tp_proc) { 
 	    if (turbo_pascal && tkn->name->tag == TKN_HALT) {
-		tkn->set_trans(ctx == ctx_apply ? "exit" : "exit(0)");
+		tkn->set_trans(ctx == ctx_apply ? (char *) "exit" : (char *) "exit(0)");
 		return;
 	    }
 	    proc_tp* prc = (proc_tp*)var->type->get_typedef();
@@ -1286,8 +1286,8 @@
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
@@ -1334,7 +1334,7 @@
 
             if (with != NULL) { 
 		f_tkn = tkn->prepend(language_c && with->tag == symbol::s_ref 
-				     ? "->" : ".")
+				     ? (char *) "->" : (char *) ".")
 		    ->prepend(with->out_name->text);
 	    }
 
@@ -1750,7 +1750,7 @@
 	    t_lbr->set_trans("set::of("); 
 	}
     }
-    t_rbr->set_trans(items ? ", eos)" : "eos)"); 
+    t_rbr->set_trans(items ? (char *) ", eos)" : (char *) "eos)"); 
 }
 
 idx_expr_node::idx_expr_node(expr_node* arr, token* t_lbr, expr_node* indices, 
@@ -2181,7 +2181,7 @@
       case tn_and:
         op->set_trans(((left->type && left->type->tag != tp_bool) || 
 	    (right->type && right->type->tag != tp_bool) || nological)
-		      ? "&" : "&&");
+		      ? (char *) "&" : (char *) "&&");
 	if (parent_tag != tn_group && parent_tag != tn_and) { 
 	    f_tkn = left->f_tkn->prepend("(");
 	    l_tkn = right->l_tkn->append(")");
@@ -2201,12 +2201,12 @@
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
@@ -2224,14 +2224,14 @@
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
@@ -2253,14 +2253,14 @@
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
@@ -2298,9 +2298,9 @@
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
@@ -2313,9 +2313,9 @@
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
@@ -2439,7 +2439,7 @@
 	op->set_trans(CMP_OP(tag)); 
         break; 
       case tn_not:
-        op->set_trans(right->type && right->type->tag == tp_bool ? "!" : "~"); 
+        op->set_trans(right->type && right->type->tag == tp_bool ? (char *) "!" : (char *) "~"); 
         break; 
     }
     if ((unsigned(tag - tn_add) <= tn_div - tn_add) && type && type->tag == tp_longint)
@@ -3406,7 +3406,7 @@
 	    }
 	}
     } else { 
-	f_tkn = ident->prepend(language_c ? "static const " : "const "); 
+	f_tkn = ident->prepend(language_c ? (char *) "static const " : (char *) "const "); 
 	enumeration = NULL;
 	if (constant->type->tag == tp_string) { 
 	    ident->prepend("char ");
@@ -3749,16 +3749,16 @@
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
@@ -3823,7 +3823,7 @@
 		// initialize file structure
 		tkn->ident->append(
 		    (tp->tag == tp_file || tp->tag == tp_text)
-		    ? " = VOID_FILE" : " = {0}");
+		    ? (char *) " = VOID_FILE" : (char *) " = {0}");
 	    }
 	    if (tkn->var->flags & symbol::f_static) { 
 		is_static = TRUE;
@@ -3854,8 +3854,8 @@
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
@@ -4215,7 +4215,7 @@
     if (qualifiers) { 
 	if (is_external) { 
 	    f_tkn = f_tkn->prepend(type->is_extern_c && !language_c 
-				   ? "extern \"C\" " : "extern ");
+				   ? (char *) "extern \"C\" " : (char *) "extern ");
 	} else if (is_static) { 
 	    f_tkn = f_tkn->prepend("static ");
 	} else if (is_virtual) { 
@@ -4832,7 +4832,7 @@
 		t_array->set_trans("conf_matrix");
 	    } else {  	
 		t_array->set_trans(indices->next == NULL 
-				   ? "conf_array" : "conf_matrix");
+				   ? (char *) "conf_array" : (char *) "conf_matrix");
 	    }
 	    token::disable(t_array->next, eltd->f_tkn->prev);
 	    eltd->f_tkn->prepend("<");
