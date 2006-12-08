--- src/slonik/parser.c.orig	Thu Nov 16 22:50:56 2006
+++ src/slonik/parser.c	Fri Dec  8 14:11:29 2006
@@ -226,7 +226,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "src/slonik/parser.y"
+#line 1 "parser.y"
 
 /*-------------------------------------------------------------------------
  * parser.y
@@ -349,7 +349,7 @@
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 106 "src/slonik/parser.y"
+#line 106 "parser.y"
 {
 	int32		ival;
 	char		*str;
@@ -1875,7 +1875,7 @@
   switch (yyn)
     {
         case 2:
-#line 267 "src/slonik/parser.y"
+#line 267 "parser.y"
     {
 						parser_script = (SlonikScript *)
 								malloc(sizeof(SlonikScript));
@@ -1889,24 +1889,24 @@
     break;
 
   case 3:
-#line 280 "src/slonik/parser.y"
+#line 280 "parser.y"
     {
 						(yyval.str) = (yyvsp[(5) - (6)].str);
 					}
     break;
 
   case 4:
-#line 286 "src/slonik/parser.y"
+#line 286 "parser.y"
     { (yyval.adm_info) = (yyvsp[(1) - (1)].adm_info); }
     break;
 
   case 5:
-#line 288 "src/slonik/parser.y"
+#line 288 "parser.y"
     { (yyvsp[(1) - (2)].adm_info)->next = (yyvsp[(2) - (2)].adm_info); (yyval.adm_info) = (yyvsp[(1) - (2)].adm_info); }
     break;
 
   case 6:
-#line 292 "src/slonik/parser.y"
+#line 292 "parser.y"
     {
 						SlonikAdmInfo	   *new;
 
@@ -1925,27 +1925,27 @@
     break;
 
   case 7:
-#line 310 "src/slonik/parser.y"
+#line 310 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 8:
-#line 312 "src/slonik/parser.y"
+#line 312 "parser.y"
     { (yyvsp[(1) - (2)].statement)->next = (yyvsp[(2) - (2)].statement); (yyval.statement) = (yyvsp[(1) - (2)].statement); }
     break;
 
   case 9:
-#line 316 "src/slonik/parser.y"
+#line 316 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 10:
-#line 318 "src/slonik/parser.y"
+#line 318 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 11:
-#line 323 "src/slonik/parser.y"
+#line 323 "parser.y"
     {
 						SlonikStmt_try *new;
 
@@ -1964,7 +1964,7 @@
     break;
 
   case 12:
-#line 340 "src/slonik/parser.y"
+#line 340 "parser.y"
     {
 						SlonikStmt_try *new;
 
@@ -1984,7 +1984,7 @@
     break;
 
   case 13:
-#line 358 "src/slonik/parser.y"
+#line 358 "parser.y"
     {
 						SlonikStmt_try *new;
 
@@ -2004,7 +2004,7 @@
     break;
 
   case 14:
-#line 376 "src/slonik/parser.y"
+#line 376 "parser.y"
     {
 						SlonikStmt_try *new;
 
@@ -2023,7 +2023,7 @@
     break;
 
   case 15:
-#line 392 "src/slonik/parser.y"
+#line 392 "parser.y"
     {
 						SlonikStmt_try *new;
 
@@ -2041,213 +2041,213 @@
     break;
 
   case 16:
-#line 409 "src/slonik/parser.y"
+#line 409 "parser.y"
     { (yyval.statement) = (yyvsp[(4) - (5)].statement); }
     break;
 
   case 17:
-#line 412 "src/slonik/parser.y"
+#line 412 "parser.y"
     { (yyval.statement) = (yyvsp[(4) - (5)].statement); }
     break;
 
   case 18:
-#line 416 "src/slonik/parser.y"
+#line 416 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 19:
-#line 418 "src/slonik/parser.y"
+#line 418 "parser.y"
     { (yyvsp[(1) - (2)].statement)->next = (yyvsp[(2) - (2)].statement); (yyval.statement) = (yyvsp[(1) - (2)].statement); }
     break;
 
   case 20:
-#line 422 "src/slonik/parser.y"
+#line 422 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 21:
-#line 424 "src/slonik/parser.y"
+#line 424 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 22:
-#line 426 "src/slonik/parser.y"
+#line 426 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 23:
-#line 428 "src/slonik/parser.y"
+#line 428 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 24:
-#line 430 "src/slonik/parser.y"
+#line 430 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 25:
-#line 432 "src/slonik/parser.y"
+#line 432 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 26:
-#line 434 "src/slonik/parser.y"
+#line 434 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 27:
-#line 436 "src/slonik/parser.y"
+#line 436 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 28:
-#line 438 "src/slonik/parser.y"
+#line 438 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 29:
-#line 440 "src/slonik/parser.y"
+#line 440 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 30:
-#line 442 "src/slonik/parser.y"
+#line 442 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 31:
-#line 444 "src/slonik/parser.y"
+#line 444 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 32:
-#line 446 "src/slonik/parser.y"
+#line 446 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 33:
-#line 448 "src/slonik/parser.y"
+#line 448 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 34:
-#line 450 "src/slonik/parser.y"
+#line 450 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 35:
-#line 452 "src/slonik/parser.y"
+#line 452 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 36:
-#line 454 "src/slonik/parser.y"
+#line 454 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 37:
-#line 456 "src/slonik/parser.y"
+#line 456 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 38:
-#line 458 "src/slonik/parser.y"
+#line 458 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 39:
-#line 460 "src/slonik/parser.y"
+#line 460 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 40:
-#line 462 "src/slonik/parser.y"
+#line 462 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 41:
-#line 464 "src/slonik/parser.y"
+#line 464 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 42:
-#line 466 "src/slonik/parser.y"
+#line 466 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 43:
-#line 468 "src/slonik/parser.y"
+#line 468 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 44:
-#line 470 "src/slonik/parser.y"
+#line 470 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 45:
-#line 472 "src/slonik/parser.y"
+#line 472 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 46:
-#line 474 "src/slonik/parser.y"
+#line 474 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 47:
-#line 476 "src/slonik/parser.y"
+#line 476 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 48:
-#line 478 "src/slonik/parser.y"
+#line 478 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 49:
-#line 480 "src/slonik/parser.y"
+#line 480 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 50:
-#line 482 "src/slonik/parser.y"
+#line 482 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 51:
-#line 484 "src/slonik/parser.y"
+#line 484 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 52:
-#line 486 "src/slonik/parser.y"
+#line 486 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 53:
-#line 488 "src/slonik/parser.y"
+#line 488 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 54:
-#line 490 "src/slonik/parser.y"
+#line 490 "parser.y"
     { yyerrok;
 						  (yyval.statement) = (yyvsp[(1) - (2)].statement); }
     break;
 
   case 55:
-#line 493 "src/slonik/parser.y"
+#line 493 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 56:
-#line 495 "src/slonik/parser.y"
+#line 495 "parser.y"
     { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
     break;
 
   case 57:
-#line 499 "src/slonik/parser.y"
+#line 499 "parser.y"
     {
 						SlonikStmt_echo *new;
 
@@ -2265,7 +2265,7 @@
     break;
 
   case 58:
-#line 516 "src/slonik/parser.y"
+#line 516 "parser.y"
     {
 						SlonikStmt_exit *new;
 
@@ -2283,7 +2283,7 @@
     break;
 
   case 59:
-#line 533 "src/slonik/parser.y"
+#line 533 "parser.y"
     {
 						SlonikStmt_restart_node *new;
 
@@ -2301,17 +2301,17 @@
     break;
 
   case 60:
-#line 550 "src/slonik/parser.y"
+#line 550 "parser.y"
     { (yyval.ival) = strtol(yytext, NULL, 10); }
     break;
 
   case 61:
-#line 552 "src/slonik/parser.y"
+#line 552 "parser.y"
     { (yyval.ival) = -(yyvsp[(2) - (2)].ival); }
     break;
 
   case 62:
-#line 556 "src/slonik/parser.y"
+#line 556 "parser.y"
     {
 						SlonikStmt *new;
 
@@ -2327,7 +2327,7 @@
     break;
 
   case 63:
-#line 571 "src/slonik/parser.y"
+#line 571 "parser.y"
     {
 						SlonikStmt_init_cluster *new;
 						statement_option opt[] = {
@@ -2356,7 +2356,7 @@
     break;
 
   case 64:
-#line 599 "src/slonik/parser.y"
+#line 599 "parser.y"
     {
 						SlonikStmt_store_node *new;
 						statement_option opt[] = {
@@ -2389,7 +2389,7 @@
     break;
 
   case 65:
-#line 631 "src/slonik/parser.y"
+#line 631 "parser.y"
     {
 						SlonikStmt_drop_node *new;
 						statement_option opt[] = {
@@ -2418,7 +2418,7 @@
     break;
 
   case 66:
-#line 659 "src/slonik/parser.y"
+#line 659 "parser.y"
     {
 						SlonikStmt_failed_node *new;
 						statement_option opt[] = {
@@ -2447,7 +2447,7 @@
     break;
 
   case 67:
-#line 687 "src/slonik/parser.y"
+#line 687 "parser.y"
     {
 						SlonikStmt_uninstall_node *new;
 						statement_option opt[] = {
@@ -2474,7 +2474,7 @@
     break;
 
   case 68:
-#line 713 "src/slonik/parser.y"
+#line 713 "parser.y"
     {
 						SlonikStmt_store_path *new;
 						statement_option opt[] = {
@@ -2507,7 +2507,7 @@
     break;
 
   case 69:
-#line 745 "src/slonik/parser.y"
+#line 745 "parser.y"
     {
 						SlonikStmt_drop_path *new;
 						statement_option opt[] = {
@@ -2538,7 +2538,7 @@
     break;
 
   case 70:
-#line 775 "src/slonik/parser.y"
+#line 775 "parser.y"
     {
 						SlonikStmt_store_listen *new;
 						statement_option opt[] = {
@@ -2569,7 +2569,7 @@
     break;
 
   case 71:
-#line 805 "src/slonik/parser.y"
+#line 805 "parser.y"
     {
 						SlonikStmt_drop_listen *new;
 						statement_option opt[] = {
@@ -2600,7 +2600,7 @@
     break;
 
   case 72:
-#line 835 "src/slonik/parser.y"
+#line 835 "parser.y"
     {
 						SlonikStmt_create_set *new;
 						statement_option opt[] = {
@@ -2631,7 +2631,7 @@
     break;
 
   case 73:
-#line 865 "src/slonik/parser.y"
+#line 865 "parser.y"
     {
 						SlonikStmt_drop_set *new;
 						statement_option opt[] = {
@@ -2660,7 +2660,7 @@
     break;
 
   case 74:
-#line 893 "src/slonik/parser.y"
+#line 893 "parser.y"
     {
 						SlonikStmt_merge_set *new;
 						statement_option opt[] = {
@@ -2691,7 +2691,7 @@
     break;
 
   case 75:
-#line 923 "src/slonik/parser.y"
+#line 923 "parser.y"
     {
 						SlonikStmt_table_add_key *new;
 						statement_option opt[] = {
@@ -2720,7 +2720,7 @@
     break;
 
   case 76:
-#line 951 "src/slonik/parser.y"
+#line 951 "parser.y"
     {
 						SlonikStmt_set_add_table *new;
 						statement_option opt[] = {
@@ -2759,7 +2759,7 @@
     break;
 
   case 77:
-#line 989 "src/slonik/parser.y"
+#line 989 "parser.y"
     {
 						SlonikStmt_set_add_sequence *new;
 						statement_option opt[] = {
@@ -2794,7 +2794,7 @@
     break;
 
   case 78:
-#line 1023 "src/slonik/parser.y"
+#line 1023 "parser.y"
     {
 						SlonikStmt_set_drop_table *new;
 						statement_option opt[] = {
@@ -2821,7 +2821,7 @@
     break;
 
   case 79:
-#line 1049 "src/slonik/parser.y"
+#line 1049 "parser.y"
     {
 						SlonikStmt_set_drop_sequence *new;
 						statement_option opt[] = {
@@ -2850,7 +2850,7 @@
     break;
 
   case 80:
-#line 1077 "src/slonik/parser.y"
+#line 1077 "parser.y"
     {
 						SlonikStmt_set_move_table *new;
 						statement_option opt[] = {
@@ -2879,7 +2879,7 @@
     break;
 
   case 81:
-#line 1105 "src/slonik/parser.y"
+#line 1105 "parser.y"
     {
 						SlonikStmt_set_move_sequence *new;
 						statement_option opt[] = {
@@ -2910,7 +2910,7 @@
     break;
 
   case 82:
-#line 1135 "src/slonik/parser.y"
+#line 1135 "parser.y"
     {
 						SlonikStmt_store_trigger *new;
 						statement_option opt[] = {
@@ -2941,7 +2941,7 @@
     break;
 
   case 83:
-#line 1165 "src/slonik/parser.y"
+#line 1165 "parser.y"
     {
 						SlonikStmt_drop_trigger *new;
 						statement_option opt[] = {
@@ -2972,7 +2972,7 @@
     break;
 
   case 84:
-#line 1195 "src/slonik/parser.y"
+#line 1195 "parser.y"
     {
 						SlonikStmt_subscribe_set *new;
 						statement_option opt[] = {
@@ -3005,7 +3005,7 @@
     break;
 
   case 85:
-#line 1227 "src/slonik/parser.y"
+#line 1227 "parser.y"
     {
 						SlonikStmt_unsubscribe_set *new;
 						statement_option opt[] = {
@@ -3034,7 +3034,7 @@
     break;
 
   case 86:
-#line 1255 "src/slonik/parser.y"
+#line 1255 "parser.y"
     {
 						SlonikStmt_lock_set *new;
 						statement_option opt[] = {
@@ -3063,7 +3063,7 @@
     break;
 
   case 87:
-#line 1283 "src/slonik/parser.y"
+#line 1283 "parser.y"
     {
 						SlonikStmt_unlock_set *new;
 						statement_option opt[] = {
@@ -3092,7 +3092,7 @@
     break;
 
   case 88:
-#line 1311 "src/slonik/parser.y"
+#line 1311 "parser.y"
     {
 						SlonikStmt_move_set *new;
 						statement_option opt[] = {
@@ -3123,7 +3123,7 @@
     break;
 
   case 89:
-#line 1341 "src/slonik/parser.y"
+#line 1341 "parser.y"
     {
 						SlonikStmt_ddl_script *new;
 						statement_option opt[] = {
@@ -3157,7 +3157,7 @@
     break;
 
   case 90:
-#line 1374 "src/slonik/parser.y"
+#line 1374 "parser.y"
     {
 						SlonikStmt_update_functions *new;
 						statement_option opt[] = {
@@ -3184,7 +3184,7 @@
     break;
 
   case 91:
-#line 1399 "src/slonik/parser.y"
+#line 1399 "parser.y"
     {
 						SlonikStmt_repair_config *new;
 						statement_option opt[] = {
@@ -3216,7 +3216,7 @@
     break;
 
   case 92:
-#line 1430 "src/slonik/parser.y"
+#line 1430 "parser.y"
     {
 						SlonikStmt_wait_event *new;
 						statement_option opt[] = {
@@ -3249,7 +3249,7 @@
     break;
 
   case 93:
-#line 1462 "src/slonik/parser.y"
+#line 1462 "parser.y"
     {
 						SlonikStmt_switch_log *new;
 						statement_option opt[] = {
@@ -3276,7 +3276,7 @@
     break;
 
   case 94:
-#line 1488 "src/slonik/parser.y"
+#line 1488 "parser.y"
     {
 						SlonikStmt_sync *new;
 						statement_option opt[] = {
@@ -3303,7 +3303,7 @@
     break;
 
   case 95:
-#line 1514 "src/slonik/parser.y"
+#line 1514 "parser.y"
     {
 						SlonikStmt_sleep *new;
 						statement_option opt[] = {
@@ -3330,27 +3330,27 @@
     break;
 
   case 96:
-#line 1540 "src/slonik/parser.y"
+#line 1540 "parser.y"
     { (yyval.opt_list) = NULL; }
     break;
 
   case 97:
-#line 1542 "src/slonik/parser.y"
+#line 1542 "parser.y"
     { (yyval.opt_list) = (yyvsp[(2) - (4)].opt_list); }
     break;
 
   case 98:
-#line 1546 "src/slonik/parser.y"
+#line 1546 "parser.y"
     { (yyval.opt_list) = (yyvsp[(1) - (1)].opt_list); }
     break;
 
   case 99:
-#line 1548 "src/slonik/parser.y"
+#line 1548 "parser.y"
     { (yyvsp[(1) - (3)].opt_list)->next = (yyvsp[(3) - (3)].opt_list); (yyval.opt_list) = (yyvsp[(1) - (3)].opt_list); }
     break;
 
   case 100:
-#line 1552 "src/slonik/parser.y"
+#line 1552 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_ID;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3358,7 +3358,7 @@
     break;
 
   case 101:
-#line 1557 "src/slonik/parser.y"
+#line 1557 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_BACKUP_NODE;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3366,7 +3366,7 @@
     break;
 
   case 102:
-#line 1562 "src/slonik/parser.y"
+#line 1562 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_EVENT_NODE;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3374,7 +3374,7 @@
     break;
 
   case 103:
-#line 1567 "src/slonik/parser.y"
+#line 1567 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_SERVER;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3382,7 +3382,7 @@
     break;
 
   case 104:
-#line 1572 "src/slonik/parser.y"
+#line 1572 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_CLIENT;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3390,7 +3390,7 @@
     break;
 
   case 105:
-#line 1577 "src/slonik/parser.y"
+#line 1577 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_ORIGIN;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3398,7 +3398,7 @@
     break;
 
   case 106:
-#line 1582 "src/slonik/parser.y"
+#line 1582 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_OLD_ORIGIN;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3406,7 +3406,7 @@
     break;
 
   case 107:
-#line 1587 "src/slonik/parser.y"
+#line 1587 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_NEW_ORIGIN;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3414,7 +3414,7 @@
     break;
 
   case 108:
-#line 1592 "src/slonik/parser.y"
+#line 1592 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_NEW_SET;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3422,7 +3422,7 @@
     break;
 
   case 109:
-#line 1597 "src/slonik/parser.y"
+#line 1597 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_RECEIVER;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3430,7 +3430,7 @@
     break;

   case 110:
-#line 1602 "src/slonik/parser.y"
+#line 1602 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_PROVIDER;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3438,7 +3438,7 @@
     break;

   case 111:
-#line 1607 "src/slonik/parser.y"
+#line 1607 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_CONNRETRY;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3446,7 +3446,7 @@
     break;

   case 112:
-#line 1612 "src/slonik/parser.y"
+#line 1612 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_COMMENT;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3454,7 +3454,7 @@
     break;

   case 113:
-#line 1617 "src/slonik/parser.y"
+#line 1617 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_CONNINFO;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3462,7 +3462,7 @@
     break;

   case 114:
-#line 1622 "src/slonik/parser.y"
+#line 1622 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_SET_ID;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3470,7 +3470,7 @@
     break;

   case 115:
-#line 1627 "src/slonik/parser.y"
+#line 1627 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_ADD_ID;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3478,7 +3478,7 @@
     break;

   case 116:
-#line 1632 "src/slonik/parser.y"
+#line 1632 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_NODE_ID;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3486,7 +3486,7 @@
     break;

   case 117:
-#line 1637 "src/slonik/parser.y"
+#line 1637 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_TAB_ID;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3494,7 +3494,7 @@
     break;

   case 118:
-#line 1642 "src/slonik/parser.y"
+#line 1642 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_TRIG_NAME;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3502,7 +3502,7 @@
     break;

   case 119:
-#line 1647 "src/slonik/parser.y"
+#line 1647 "parser.y"
     {
 						(yyvsp[(5) - (5)].opt_list)->opt_code	= O_FQNAME;
 						(yyval.opt_list) = (yyvsp[(5) - (5)].opt_list);
@@ -3510,7 +3510,7 @@
     break;

   case 120:
-#line 1652 "src/slonik/parser.y"
+#line 1652 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_USE_KEY;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3518,7 +3518,7 @@
     break;

   case 121:
-#line 1657 "src/slonik/parser.y"
+#line 1657 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3534,7 +3534,7 @@
     break;

   case 122:
-#line 1670 "src/slonik/parser.y"
+#line 1670 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_FORWARD;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3542,7 +3542,7 @@
     break;

   case 123:
-#line 1675 "src/slonik/parser.y"
+#line 1675 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_FILENAME;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3550,7 +3550,7 @@
     break;

   case 124:
-#line 1680 "src/slonik/parser.y"
+#line 1680 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3566,7 +3566,7 @@
     break;

   case 125:
-#line 1693 "src/slonik/parser.y"
+#line 1693 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_WAIT_CONFIRMED;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3574,7 +3574,7 @@
     break;

   case 126:
-#line 1698 "src/slonik/parser.y"
+#line 1698 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3590,7 +3590,7 @@
     break;

   case 127:
-#line 1711 "src/slonik/parser.y"
+#line 1711 "parser.y"
     {
 						(yyvsp[(4) - (4)].opt_list)->opt_code	= O_WAIT_ON;
 						(yyval.opt_list) = (yyvsp[(4) - (4)].opt_list);
@@ -3598,7 +3598,7 @@
     break;

   case 128:
-#line 1716 "src/slonik/parser.y"
+#line 1716 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_TIMEOUT;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3606,7 +3606,7 @@
     break;

   case 129:
-#line 1721 "src/slonik/parser.y"
+#line 1721 "parser.y"
     {
 						(yyvsp[(5) - (5)].opt_list)->opt_code	= O_EXECUTE_ONLY_ON;
 						(yyval.opt_list) = (yyvsp[(5) - (5)].opt_list);
@@ -3614,7 +3614,7 @@
     break;

   case 130:
-#line 1726 "src/slonik/parser.y"
+#line 1726 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_SPOOLNODE;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3622,7 +3622,7 @@
     break;

   case 131:
-#line 1731 "src/slonik/parser.y"
+#line 1731 "parser.y"
     {
 						(yyvsp[(3) - (3)].opt_list)->opt_code	= O_SECONDS;
 						(yyval.opt_list) = (yyvsp[(3) - (3)].opt_list);
@@ -3630,7 +3630,7 @@
     break;

   case 132:
-#line 1738 "src/slonik/parser.y"
+#line 1738 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3645,7 +3645,7 @@
     break;

   case 133:
-#line 1752 "src/slonik/parser.y"
+#line 1752 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3660,7 +3660,7 @@
     break;

   case 134:
-#line 1766 "src/slonik/parser.y"
+#line 1766 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3675,7 +3675,7 @@
     break;

   case 135:
-#line 1778 "src/slonik/parser.y"
+#line 1778 "parser.y"
     {
 						option_list *new;
 						new = (option_list *)malloc(sizeof(option_list));
@@ -3690,14 +3690,14 @@
     break;

   case 142:
-#line 1802 "src/slonik/parser.y"
+#line 1802 "parser.y"
     {
 						(yyval.ival) = strtol(yytext, NULL, 10);
 					}
     break;

   case 143:
-#line 1808 "src/slonik/parser.y"
+#line 1808 "parser.y"
     {
 						char   *ret;

@@ -3710,7 +3710,7 @@
     break;

   case 144:
-#line 1820 "src/slonik/parser.y"
+#line 1820 "parser.y"
     {
 						char   *ret;

@@ -3723,7 +3723,7 @@
     break;

   case 145:
-#line 1832 "src/slonik/parser.y"
+#line 1832 "parser.y"
     { (yyval.ival) = yylineno; }
     break;

@@ -3943,7 +3943,7 @@
 }


-#line 1835 "src/slonik/parser.y"
+#line 1835 "parser.y"



