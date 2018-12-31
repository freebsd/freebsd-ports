--- smlnj-lib/JSON/json-parser.sml.orig	2011-05-10 20:58:08.000000000 +0200
+++ smlnj-lib/JSON/json-parser.sml	2017-10-03 22:49:26.569924000 +0200
@@ -22,6 +22,26 @@
 		  msg, ", found '", JSONTokens.toString tok, "'"
 		])
 	  val lexer = Lex.lex srcMap
+	  fun parse_sequence (is_tok_end, parse_item) (strm : Lex.strm, itms) = let
+		fun is_tok_sep tok = case tok of T.COMMA => true | _ => false
+		val (tok, pos, strm') = lexer strm
+		in if is_tok_sep tok
+		   then error (pos, "parsing sequence", tok)
+		   else if is_tok_end tok
+			then (strm', itms)
+			else let val (strm'', itm) = parse_item strm
+				 val (tok', pos', strm''') = lexer strm''
+			     in if is_tok_end tok'
+				then (strm''', itm :: itms)
+				else if is_tok_sep tok'
+				     then let val (tok'', pos'', _) = lexer strm'''
+					  in if is_tok_end tok''
+					     then error (pos'', "parsing sequence", tok'')
+					     else parse_sequence (is_tok_end, parse_item) (strm''', itm :: itms)
+					  end
+				     else error (pos', "parsing sequence", tok')
+				 end
+		end
 	  fun parseValue (strm : Lex.strm) = let
 		val (tok, pos, strm) = lexer strm
 		in
@@ -37,50 +57,29 @@
 		    | _ => error (pos, "parsing value", tok)
 		  (* end case *)
 		end
-	  and parseArray (strm : Lex.strm) = (case lexer strm
-		 of (T.RB, _, strm) => (strm, J.ARRAY[])
-		  | _ => let
-		      fun loop (strm, items) = let
-			    val (strm, v) = parseValue strm
-			  (* expect either a "," or a "]" *)
-			    val (tok, pos, strm) = lexer strm
-			    in
-			      case tok
-			       of T.RB => (strm, v::items)
-				| T.COMMA => loop (strm, v::items)
-				| _ => error (pos, "parsing array", tok)
-			      (* end case *)
-			    end
-		      val (strm, items) = loop (strm, [])
-		      in
-			(strm, J.ARRAY(List.rev items))
-		      end
-		(* end case *))
+	  and parseArray (strm : Lex.strm) = let
+		fun is_RB tok = case tok of T.RB => true | _ => false
+		val (strm', elmnts) = parse_sequence (is_RB, parseValue) (strm, [])
+		in (strm', J.ARRAY(List.rev elmnts))
+		end
 	  and parseObject (strm : Lex.strm) = let
-		fun parseField strm = (case lexer strm
-		       of (T.STRING s, pos, strm) => (case lexer strm
-			     of (T.COLON, _, strm) => let
-				  val (strm, v) = parseValue strm
-				  in
-				    SOME(strm, (s, v))
-				  end
-			      | (tok, pos, _) => error (pos, "parsing field", tok)
-			    (* end case *))
-			| _ => NONE
-		      (* end case *))
-		fun loop (strm, flds) = (case parseField strm
-		       of SOME(strm, fld) => (
-			  (* expect either "," or "}" *)
-			    case lexer strm
-			     of (T.RCB, pos, strm) => (strm, fld::flds)
-			      | (T.COMMA, pos, strm) => loop (strm, fld::flds)
-			      | (tok, pos, _) => error (pos, "parsing object", tok)
-			    (* end case *))
-			| NONE => (strm, flds)
-		      (* end case *))
-		val (strm, flds) = loop (strm, [])
-		in
-		  (strm, J.OBJECT(List.rev flds))
+		fun is_RCB tok = case tok of T.RCB => true | _ => false
+		fun parse_field strm = let
+			val (tok, pos, strm') = lexer strm
+			in case tok
+			    of T.STRING s =>
+				(case lexer strm'
+				  of (T.COLON, _, strm'') => let
+					val (strm''', v) = parseValue strm''
+					in (strm''', (s, v))
+					end
+				   | (tok', pos', _) => error (pos', "parsing field", tok')
+				 (* end case *))
+			     | _ => error (pos, "parsing field", tok)
+			   (* end case *)
+			end
+		val (strm', flds) = parse_sequence (is_RCB, parse_field) (strm, [])
+		in (strm', J.OBJECT(List.rev flds))
 		end
 	  in
 	    #2 (parseValue (Lex.streamifyInstream inStrm))
