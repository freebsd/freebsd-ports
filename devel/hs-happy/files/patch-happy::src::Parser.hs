--- happy/src/Parser.hs.orig	Mon Jan 19 11:06:26 2004
+++ happy/src/Parser.hs	Mon Jan 19 11:05:51 2004
@@ -1,4 +1,4 @@
--- parser produced by Happy Version 1.8
+-- parser produced by Happy Version 1.13
 
 module Parser (ourParser,AbsSyn) where
 import ParseMonad
@@ -23,10 +23,10 @@
 type HappyReduction = 
 	   Int 
 	-> (Token)
-	-> HappyState (Token) ([HappyAbsSyn] -> P(AbsSyn))
-	-> [HappyState (Token) ([HappyAbsSyn] -> P(AbsSyn))] 
-	-> [HappyAbsSyn] 
-	-> P(AbsSyn)
+	-> HappyState (Token) (HappyStk HappyAbsSyn -> P(HappyAbsSyn))
+	-> [HappyState (Token) (HappyStk HappyAbsSyn -> P(HappyAbsSyn))] 
+	-> HappyStk HappyAbsSyn 
+	-> P(HappyAbsSyn)
 
 action_0,
  action_1,
@@ -85,7 +85,8 @@
  action_54,
  action_55,
  action_56,
- action_57 :: Int -> HappyReduction
+ action_57,
+ action_58 :: Int -> HappyReduction
 
 happyReduce_1,
  happyReduce_2,
@@ -121,215 +122,218 @@
  happyReduce_32 :: HappyReduction
 
 action_0 (27) = happyShift action_3
-action_0 (4) = happyGoto action_1
+action_0 (4) = happyGoto action_4
 action_0 (16) = happyGoto action_2
 action_0 _ = happyReduce_32
 
-action_1 (33) = happyAccept
+action_1 (27) = happyShift action_3
+action_1 (16) = happyGoto action_2
 action_1 _ = happyFail
 
-action_2 (18) = happyShift action_6
-action_2 (19) = happyShift action_7
-action_2 (20) = happyShift action_8
-action_2 (21) = happyShift action_9
-action_2 (22) = happyShift action_10
-action_2 (23) = happyShift action_11
-action_2 (24) = happyShift action_12
-action_2 (25) = happyShift action_13
-action_2 (10) = happyGoto action_4
-action_2 (11) = happyGoto action_5
+action_2 (18) = happyShift action_7
+action_2 (19) = happyShift action_8
+action_2 (20) = happyShift action_9
+action_2 (21) = happyShift action_10
+action_2 (22) = happyShift action_11
+action_2 (23) = happyShift action_12
+action_2 (24) = happyShift action_13
+action_2 (25) = happyShift action_14
+action_2 (10) = happyGoto action_5
+action_2 (11) = happyGoto action_6
 action_2 _ = happyFail
 
 action_3 _ = happyReduce_31
 
-action_4 (18) = happyShift action_6
-action_4 (19) = happyShift action_7
-action_4 (20) = happyShift action_8
-action_4 (21) = happyShift action_9
-action_4 (22) = happyShift action_10
-action_4 (23) = happyShift action_11
-action_4 (24) = happyShift action_12
-action_4 (25) = happyShift action_13
-action_4 (31) = happyShift action_26
-action_4 (11) = happyGoto action_25
+action_4 (33) = happyAccept
 action_4 _ = happyFail
 
-action_5 _ = happyReduce_14
+action_5 (18) = happyShift action_7
+action_5 (19) = happyShift action_8
+action_5 (20) = happyShift action_9
+action_5 (21) = happyShift action_10
+action_5 (22) = happyShift action_11
+action_5 (23) = happyShift action_12
+action_5 (24) = happyShift action_13
+action_5 (25) = happyShift action_14
+action_5 (31) = happyShift action_27
+action_5 (11) = happyGoto action_26
+action_5 _ = happyFail
 
-action_6 (27) = happyShift action_24
-action_6 _ = happyFail
+action_6 _ = happyReduce_14
 
-action_7 (17) = happyShift action_23
-action_7 (13) = happyGoto action_21
-action_7 (14) = happyGoto action_22
+action_7 (27) = happyShift action_25
 action_7 _ = happyFail
 
-action_8 (17) = happyShift action_20
+action_8 (17) = happyShift action_24
+action_8 (13) = happyGoto action_22
+action_8 (14) = happyGoto action_23
 action_8 _ = happyFail
 
-action_9 (27) = happyShift action_19
+action_9 (17) = happyShift action_21
 action_9 _ = happyFail
 
-action_10 (27) = happyShift action_18
+action_10 (27) = happyShift action_20
 action_10 _ = happyFail
 
-action_11 (17) = happyShift action_15
-action_11 (15) = happyGoto action_17
-action_11 _ = happyReduce_30
+action_11 (27) = happyShift action_19
+action_11 _ = happyFail
 
-action_12 (17) = happyShift action_15
-action_12 (15) = happyGoto action_16
+action_12 (17) = happyShift action_16
+action_12 (15) = happyGoto action_18
 action_12 _ = happyReduce_30
 
-action_13 (17) = happyShift action_15
-action_13 (15) = happyGoto action_14
+action_13 (17) = happyShift action_16
+action_13 (15) = happyGoto action_17
 action_13 _ = happyReduce_30
 
-action_14 _ = happyReduce_22
+action_14 (17) = happyShift action_16
+action_14 (15) = happyGoto action_15
+action_14 _ = happyReduce_30
 
-action_15 (17) = happyShift action_15
-action_15 (15) = happyGoto action_36
-action_15 _ = happyReduce_30
+action_15 _ = happyReduce_22
 
-action_16 _ = happyReduce_23
+action_16 (17) = happyShift action_16
+action_16 (15) = happyGoto action_37
+action_16 _ = happyReduce_30
 
-action_17 _ = happyReduce_21
+action_17 _ = happyReduce_23
 
-action_18 (27) = happyShift action_35
-action_18 _ = happyReduce_19
+action_18 _ = happyReduce_21
 
-action_19 (27) = happyShift action_34
-action_19 _ = happyFail
+action_19 (27) = happyShift action_36
+action_19 _ = happyReduce_19
 
-action_20 (17) = happyShift action_33
-action_20 (12) = happyGoto action_32
-action_20 _ = happyReduce_25
+action_20 (27) = happyShift action_35
+action_20 _ = happyFail
 
-action_21 _ = happyReduce_16
+action_21 (17) = happyShift action_34
+action_21 (12) = happyGoto action_33
+action_21 _ = happyReduce_25
 
-action_22 (17) = happyShift action_23
-action_22 (13) = happyGoto action_31
-action_22 (14) = happyGoto action_22
-action_22 _ = happyReduce_27
+action_22 _ = happyReduce_16
 
-action_23 (27) = happyShift action_30
-action_23 _ = happyFail
+action_23 (17) = happyShift action_24
+action_23 (13) = happyGoto action_32
+action_23 (14) = happyGoto action_23
+action_23 _ = happyReduce_27
 
-action_24 _ = happyReduce_15
+action_24 (27) = happyShift action_31
+action_24 _ = happyFail
 
-action_25 _ = happyReduce_13
+action_25 _ = happyReduce_15
 
-action_26 (17) = happyShift action_29
-action_26 (5) = happyGoto action_27
-action_26 (6) = happyGoto action_28
-action_26 _ = happyFail
+action_26 _ = happyReduce_13
 
-action_27 (17) = happyShift action_29
-action_27 (27) = happyShift action_3
-action_27 (6) = happyGoto action_40
-action_27 (16) = happyGoto action_41
-action_27 _ = happyReduce_32
+action_27 (17) = happyShift action_30
+action_27 (5) = happyGoto action_28
+action_27 (6) = happyGoto action_29
+action_27 _ = happyFail
 
-action_28 _ = happyReduce_3
+action_28 (17) = happyShift action_30
+action_28 (27) = happyShift action_3
+action_28 (6) = happyGoto action_41
+action_28 (16) = happyGoto action_42
+action_28 _ = happyReduce_32
 
-action_29 (28) = happyShift action_38
-action_29 (30) = happyShift action_39
-action_29 _ = happyFail
+action_29 _ = happyReduce_3
 
-action_30 _ = happyReduce_28
+action_30 (28) = happyShift action_39
+action_30 (30) = happyShift action_40
+action_30 _ = happyFail
 
-action_31 _ = happyReduce_26
+action_31 _ = happyReduce_28
 
-action_32 _ = happyReduce_17
+action_32 _ = happyReduce_26
 
-action_33 _ = happyReduce_24
+action_33 _ = happyReduce_17
 
-action_34 _ = happyReduce_18
+action_34 _ = happyReduce_24
 
-action_35 (27) = happyShift action_37
-action_35 _ = happyFail
+action_35 _ = happyReduce_18
 
-action_36 _ = happyReduce_29
+action_36 (27) = happyShift action_38
+action_36 _ = happyFail
 
-action_37 _ = happyReduce_20
+action_37 _ = happyReduce_29
 
-action_38 (17) = happyShift action_15
-action_38 (7) = happyGoto action_43
-action_38 (8) = happyGoto action_44
-action_38 (15) = happyGoto action_45
-action_38 _ = happyReduce_30
+action_38 _ = happyReduce_20
 
-action_39 (27) = happyShift action_42
-action_39 _ = happyFail
+action_39 (17) = happyShift action_16
+action_39 (7) = happyGoto action_44
+action_39 (8) = happyGoto action_45
+action_39 (15) = happyGoto action_46
+action_39 _ = happyReduce_30
 
-action_40 _ = happyReduce_2
+action_40 (27) = happyShift action_43
+action_40 _ = happyFail
 
-action_41 _ = happyReduce_1
+action_41 _ = happyReduce_2
 
-action_42 (17) = happyShift action_49
-action_42 (28) = happyShift action_50
-action_42 _ = happyFail
+action_42 _ = happyReduce_1
 
-action_43 _ = happyReduce_6
+action_43 (17) = happyShift action_50
+action_43 (28) = happyShift action_51
+action_43 _ = happyFail
 
-action_44 (32) = happyShift action_48
-action_44 _ = happyReduce_8
+action_44 _ = happyReduce_6
 
-action_45 (26) = happyShift action_47
-action_45 (9) = happyGoto action_46
-action_45 _ = happyReduce_12
+action_45 (32) = happyShift action_49
+action_45 _ = happyReduce_8
 
-action_46 (27) = happyShift action_55
-action_46 _ = happyFail
+action_46 (26) = happyShift action_48
+action_46 (9) = happyGoto action_47
+action_46 _ = happyReduce_12
 
-action_47 (17) = happyShift action_54
+action_47 (27) = happyShift action_56
 action_47 _ = happyFail
 
-action_48 (17) = happyShift action_15
-action_48 (7) = happyGoto action_53
-action_48 (8) = happyGoto action_44
-action_48 (15) = happyGoto action_45
-action_48 _ = happyReduce_30
+action_48 (17) = happyShift action_55
+action_48 _ = happyFail
 
-action_49 (28) = happyShift action_52
-action_49 _ = happyFail
+action_49 (17) = happyShift action_16
+action_49 (7) = happyGoto action_54
+action_49 (8) = happyGoto action_45
+action_49 (15) = happyGoto action_46
+action_49 _ = happyReduce_30
 
-action_50 (17) = happyShift action_15
-action_50 (7) = happyGoto action_51
-action_50 (8) = happyGoto action_44
-action_50 (15) = happyGoto action_45
-action_50 _ = happyReduce_30
+action_50 (28) = happyShift action_53
+action_50 _ = happyFail
 
-action_51 _ = happyReduce_4
+action_51 (17) = happyShift action_16
+action_51 (7) = happyGoto action_52
+action_51 (8) = happyGoto action_45
+action_51 (15) = happyGoto action_46
+action_51 _ = happyReduce_30
 
-action_52 (17) = happyShift action_15
-action_52 (7) = happyGoto action_57
-action_52 (8) = happyGoto action_44
-action_52 (15) = happyGoto action_45
-action_52 _ = happyReduce_30
+action_52 _ = happyReduce_4
 
-action_53 _ = happyReduce_7
+action_53 (17) = happyShift action_16
+action_53 (7) = happyGoto action_58
+action_53 (8) = happyGoto action_45
+action_53 (15) = happyGoto action_46
+action_53 _ = happyReduce_30
 
-action_54 _ = happyReduce_11
+action_54 _ = happyReduce_7
 
-action_55 (29) = happyShift action_56
-action_55 _ = happyReduce_10
+action_55 _ = happyReduce_11
 
-action_56 _ = happyReduce_9
+action_56 (29) = happyShift action_57
+action_56 _ = happyReduce_10
 
-action_57 _ = happyReduce_5
+action_57 _ = happyReduce_9
+
+action_58 _ = happyReduce_5
 
 happyReduce_1 = happyReduce 5 4 happyReduction_1
-happyReduction_1 ((HappyAbsSyn9  happy_var_5) :
-	(HappyAbsSyn5  happy_var_4) :
-	_ :
-	(HappyAbsSyn10  happy_var_2) :
-	(HappyAbsSyn9  happy_var_1) :
+happyReduction_1 ((HappyAbsSyn9  happy_var_5) `HappyStk`
+	(HappyAbsSyn5  happy_var_4) `HappyStk`
+	_ `HappyStk`
+	(HappyAbsSyn10  happy_var_2) `HappyStk`
+	(HappyAbsSyn9  happy_var_1) `HappyStk`
 	happyRest)
 	 = HappyAbsSyn4
 		 (AbsSyn happy_var_1 (reverse happy_var_2) (reverse happy_var_4) happy_var_5
-	) : happyRest
-happyReduction_1 _ = notHappyAtAll 
+	) `HappyStk` happyRest
 
 happyReduce_2 = happySpecReduce_2 5 happyReduction_2
 happyReduction_2 (HappyAbsSyn6  happy_var_2)
@@ -347,29 +351,27 @@
 happyReduction_3 _  = notHappyAtAll 
 
 happyReduce_4 = happyReduce 5 6 happyReduction_4
-happyReduction_4 ((HappyAbsSyn7  happy_var_5) :
-	_ :
-	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) :
-	_ :
-	(HappyTerminal (TokenInfo happy_var_1 TokId)) :
+happyReduction_4 ((HappyAbsSyn7  happy_var_5) `HappyStk`
+	_ `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) `HappyStk`
+	_ `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_1 TokId)) `HappyStk`
 	happyRest)
 	 = HappyAbsSyn6
 		 ((happy_var_1,happy_var_5,Just happy_var_3)
-	) : happyRest
-happyReduction_4 _ = notHappyAtAll 
+	) `HappyStk` happyRest
 
 happyReduce_5 = happyReduce 6 6 happyReduction_5
-happyReduction_5 ((HappyAbsSyn7  happy_var_6) :
-	_ :
-	_ :
-	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) :
-	_ :
-	(HappyTerminal (TokenInfo happy_var_1 TokId)) :
+happyReduction_5 ((HappyAbsSyn7  happy_var_6) `HappyStk`
+	_ `HappyStk`
+	_ `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) `HappyStk`
+	_ `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_1 TokId)) `HappyStk`
 	happyRest)
 	 = HappyAbsSyn6
 		 ((happy_var_1,happy_var_6,Just happy_var_3)
-	) : happyRest
-happyReduction_5 _ = notHappyAtAll 
+	) `HappyStk` happyRest
 
 happyReduce_6 = happySpecReduce_3 6 happyReduction_6
 happyReduction_6 (HappyAbsSyn7  happy_var_3)
@@ -397,23 +399,21 @@
 happyReduction_8 _  = notHappyAtAll 
 
 happyReduce_9 = happyMonadReduce 4 8 happyReduction_9
-happyReduction_9 (_ :
-	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) :
-	(HappyAbsSyn9  happy_var_2) :
-	(HappyAbsSyn15  happy_var_1) :
+happyReduction_9 (_ `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) `HappyStk`
+	(HappyAbsSyn9  happy_var_2) `HappyStk`
+	(HappyAbsSyn15  happy_var_1) `HappyStk`
 	happyRest)
 	 = happyThen ( \s l -> returnP (happy_var_1,happy_var_3,l,happy_var_2) s l
 	) (\r -> happyReturn (HappyAbsSyn8 r))
-happyReduction_9 _ = notHappyAtAll 
 
 happyReduce_10 = happyMonadReduce 3 8 happyReduction_10
-happyReduction_10 ((HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) :
-	(HappyAbsSyn9  happy_var_2) :
-	(HappyAbsSyn15  happy_var_1) :
+happyReduction_10 ((HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) `HappyStk`
+	(HappyAbsSyn9  happy_var_2) `HappyStk`
+	(HappyAbsSyn15  happy_var_1) `HappyStk`
 	happyRest)
 	 = happyThen ( \s l -> returnP (happy_var_1,happy_var_3,l,happy_var_2) s l
 	) (\r -> happyReturn (HappyAbsSyn8 r))
-happyReduction_10 _ = notHappyAtAll 
 
 happyReduce_11 = happySpecReduce_2 9 happyReduction_11
 happyReduction_11 (HappyTerminal (TokenInfo happy_var_2 TokId))
@@ -486,15 +486,14 @@
 happyReduction_19 _ _  = notHappyAtAll 
 
 happyReduce_20 = happyReduce 4 11 happyReduction_20
-happyReduction_20 ((HappyTerminal (TokenInfo happy_var_4 TokCodeQuote)) :
-	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) :
-	(HappyTerminal (TokenInfo happy_var_2 TokCodeQuote)) :
-	_ :
+happyReduction_20 ((HappyTerminal (TokenInfo happy_var_4 TokCodeQuote)) `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_3 TokCodeQuote)) `HappyStk`
+	(HappyTerminal (TokenInfo happy_var_2 TokCodeQuote)) `HappyStk`
+	_ `HappyStk`
 	happyRest)
 	 = HappyAbsSyn11
 		 (TokenMonad happy_var_2 happy_var_3 happy_var_4
-	) : happyRest
-happyReduction_20 _ = notHappyAtAll 
+	) `HappyStk` happyRest
 
 happyReduce_21 = happySpecReduce_2 11 happyReduction_21
 happyReduction_21 (HappyAbsSyn15  happy_var_2)
@@ -601,38 +600,30 @@
 	TokenKW      TokDoubleColon -> cont 30;
 	TokenKW      TokDoublePercent -> cont 31;
 	TokenKW      TokBar -> cont 32;
+	_ -> happyError
 	})
 
 happyThen :: P a -> (a -> P b) -> P b
 happyThen = (thenP)
+happyReturn :: a -> P a
 happyReturn = (returnP)
 happyThen1 = happyThen
 happyReturn1 = happyReturn
 
-ourParser = happyParse
-
-happyError :: P a
-happyError s l = failP (show l ++ ": Parse error\n") s l{-# LINE 1 "GenericTemplate.hs" -}
-{-# LINE 1 "GenericTemplate.hs" -}
--- $Id: Parser.hs,v 1.16 2000/12/03 16:53:53 simonmar Exp $
-
-{-# LINE 15 "GenericTemplate.hs" -}
-
-
-
-
-
-
-
-
-
-
-
-
-
+ourParser = happyThen (happyParse action_0) (\x -> case x of {HappyAbsSyn4 z -> happyReturn z; _other -> notHappyAtAll })
 
+happySeq = happyDontSeq
 
+happyError :: P a
+happyError s l = failP (show l ++ ": Parse error\n") s l
+{-# LINE 1 "GenericTemplate.hs" #-}
+{-# LINE 1 "<built-in>" #-}
+{-# LINE 1 "<command line>" #-}
+{-# LINE 1 "GenericTemplate.hs" #-}
+-- Id: GenericTemplate.hs,v 1.24 2003/06/03 09:41:51 ross Exp 
 
+{-# LINE 16 "GenericTemplate.hs" #-}
+{-# LINE 28 "GenericTemplate.hs" #-}
 
 
 
@@ -674,19 +665,25 @@
 
 
 
+infixr 9 `HappyStk`
+data HappyStk a = HappyStk a (HappyStk a)
 
+-----------------------------------------------------------------------------
+-- starting the parse
 
+happyParse start_state = happyNewToken start_state notHappyAtAll notHappyAtAll
 
 -----------------------------------------------------------------------------
--- starting the parse
+-- Accepting the parse
+
+happyAccept j tk st sts (HappyStk ans _) = 
 
-happyParse = happyNewToken action_0 [] []
+					   (happyReturn1 ans)
 
 -----------------------------------------------------------------------------
 -- Arrays only: do the next action
 
-{-# LINE 123 "GenericTemplate.hs" -}
-
+{-# LINE 151 "GenericTemplate.hs" #-}
 
 -----------------------------------------------------------------------------
 -- HappyState data type (not arrays)
@@ -704,72 +701,66 @@
 
 
 -----------------------------------------------------------------------------
--- Accepting the parse
-
-happyAccept j tk st sts [ ans ] = happyReturn1 (case (ans) of {HappyAbsSyn4 z -> z })
-happyAccept j tk st sts _       = 
-
-				  notHappyAtAll
-
------------------------------------------------------------------------------
 -- Shifting a token
 
-happyShift new_state (1) tk st sts stk@(x : _) =
+happyShift new_state (1) tk st sts stk@(x `HappyStk` _) =
      let i = (case x of { HappyErrorToken (i) -> i }) in
 --     trace "shifting the error token" $
      new_state i i tk (HappyState (new_state)) ((st):(sts)) (stk)
 
 happyShift new_state i tk st sts stk =
-     happyNewToken new_state ((st):(sts)) ((HappyTerminal (tk)):stk)
+     happyNewToken new_state ((st):(sts)) ((HappyTerminal (tk))`HappyStk`stk)
 
 -- happyReduce is specialised for the common cases.
 
 happySpecReduce_0 i fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
 happySpecReduce_0 nt fn j tk st@((HappyState (action))) sts stk
-     = action nt j tk st ((st):(sts)) (fn : stk)
+     = action nt j tk st ((st):(sts)) (fn `HappyStk` stk)
 
 happySpecReduce_1 i fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
-happySpecReduce_1 nt fn j tk _ sts@(((st@(HappyState (action))):(_))) (v1:stk')
-     = action nt j tk st sts (fn v1 : stk')
-happySpecReduce_1 _ _ _ _ _ _ _
-     = notHappyAtAll
+happySpecReduce_1 nt fn j tk _ sts@(((st@(HappyState (action))):(_))) (v1`HappyStk`stk')
+     = let r = fn v1 in
+       happySeq r (action nt j tk st sts (r `HappyStk` stk'))
 
 happySpecReduce_2 i fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
-happySpecReduce_2 nt fn j tk _ ((_):(sts@(((st@(HappyState (action))):(_))))) (v1:v2:stk')
-     = action nt j tk st sts (fn v1 v2 : stk')
-happySpecReduce_2 _ _ _ _ _ _ _
-     = notHappyAtAll
+happySpecReduce_2 nt fn j tk _ ((_):(sts@(((st@(HappyState (action))):(_))))) (v1`HappyStk`v2`HappyStk`stk')
+     = let r = fn v1 v2 in
+       happySeq r (action nt j tk st sts (r `HappyStk` stk'))
 
 happySpecReduce_3 i fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
-happySpecReduce_3 nt fn j tk _ ((_):(((_):(sts@(((st@(HappyState (action))):(_))))))) (v1:v2:v3:stk')
-     = action nt j tk st sts (fn v1 v2 v3 : stk')
-happySpecReduce_3 _ _ _ _ _ _ _
-     = notHappyAtAll
+happySpecReduce_3 nt fn j tk _ ((_):(((_):(sts@(((st@(HappyState (action))):(_))))))) (v1`HappyStk`v2`HappyStk`v3`HappyStk`stk')
+     = let r = fn v1 v2 v3 in
+       happySeq r (action nt j tk st sts (r `HappyStk` stk'))
 
 happyReduce k i fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
-happyReduce k nt fn j tk st sts stk = action nt j tk st1 sts1 (fn stk)
-       where sts1@(((st1@(HappyState (action))):(_))) = happyDrop k ((st):(sts))
+happyReduce k nt fn j tk st sts stk
+     = case happyDrop (k - ((1) :: Int)) sts of
+	 sts1@(((st1@(HappyState (action))):(_))) ->
+        	let r = fn stk in  -- it doesn't hurt to always seq here...
+       		happyDoSeq r (action nt j tk st1 sts1 r)
 
 happyMonadReduce k nt fn (1) tk st sts stk
      = happyFail (1) tk st sts stk
 happyMonadReduce k nt fn j tk st sts stk =
-        happyThen1 (fn stk) (\r -> action nt j tk st1 sts1 (r : drop_stk))
+        happyThen1 (fn stk) (\r -> action nt j tk st1 sts1 (r `HappyStk` drop_stk))
        where sts1@(((st1@(HappyState (action))):(_))) = happyDrop k ((st):(sts))
-             drop_stk = drop (k) stk
+             drop_stk = happyDropStk k stk
 
 happyDrop (0) l = l
-happyDrop n ((_):(t)) = happyDrop (n - (1)) t
+happyDrop n ((_):(t)) = happyDrop (n - ((1) :: Int)) t
+
+happyDropStk (0) l = l
+happyDropStk n (x `HappyStk` xs) = happyDropStk (n - ((1)::Int)) xs
 
 -----------------------------------------------------------------------------
 -- Moving to a new state after a reduction
 
-{-# LINE 214 "GenericTemplate.hs" -}
-
+{-# LINE 235 "GenericTemplate.hs" #-}
 happyGoto action j tk st = action j j tk (HappyState action)
 
 
@@ -788,16 +779,16 @@
 
 -- discard a state
 happyFail  (1) tk old_st (((HappyState (action))):(sts)) 
-						(saved_tok : _ : stk) =
+						(saved_tok `HappyStk` _ `HappyStk` stk) =
 --	trace ("discarding state, depth " ++ show (length stk))  $
-	action (1) (1) tk (HappyState (action)) sts ((saved_tok:stk))
+	action (1) (1) tk (HappyState (action)) sts ((saved_tok`HappyStk`stk))
 -}
 
 -- Enter error recovery: generate an error token,
 --                       save the old token and carry on.
 happyFail  i tk (HappyState (action)) sts stk =
 --      trace "entering error recovery" $
-	action (1) (1) tk (HappyState (action)) sts ( (HappyErrorToken (i)) : stk)
+	action (1) (1) tk (HappyState (action)) sts ( (HappyErrorToken (i)) `HappyStk` stk)
 
 -- Internal happy errors:
 
@@ -813,18 +804,21 @@
 
 
 -----------------------------------------------------------------------------
+-- Seq-ing.  If the --strict flag is given, then Happy emits 
+--	happySeq = happyDoSeq
+-- otherwise it emits
+-- 	happySeq = happyDontSeq
+
+happyDoSeq, happyDontSeq :: a -> b -> b
+happyDoSeq   a b = a `seq` b
+happyDontSeq a b = b
+
+-----------------------------------------------------------------------------
 -- Don't inline any functions from the template.  GHC has a nasty habit
 -- of deciding to inline happyGoto everywhere, which increases the size of
 -- the generated parser quite a bit.
 
-
-
-
-
-
-
-
-
+{-# LINE 300 "GenericTemplate.hs" #-}
 {-# NOINLINE happyShift #-}
 {-# NOINLINE happySpecReduce_0 #-}
 {-# NOINLINE happySpecReduce_1 #-}
