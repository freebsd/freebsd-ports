--- ncurses-0.2.16/lib/UI/NCurses.chs.orig	2016-08-29 01:09:37 UTC
+++ ncurses-0.2.16/lib/UI/NCurses.chs
@@ -435,12 +435,12 @@ setColor (ColorID pair) = withWindow_ "s
 -- | Add some text to the window, at the current cursor position.
 drawString :: String -> Update ()
 drawString str = withWindow_ "drawString" $ \win ->
-	withCWString str ({# call waddwstr #} win)
+	withCWString str $ \s -> ({# call waddwstr #} win) (castPtr s)

 -- | Add some text to the window, at the current cursor position.
 drawText :: T.Text -> Update ()
 drawText txt = withWindow_ "drawText" $ \win ->
-	withCWString (T.unpack txt) ({# call waddwstr #} win)
+	withCWString (T.unpack txt) $ \s -> ({# call waddwstr #} win) (castPtr s)

 drawGlyph :: Glyph -> Update ()
 drawGlyph glyph = withWindow_ "drawGlyph" $ \win ->
@@ -718,7 +718,7 @@ withGlyph (Glyph char attrs) io =
 	let cAttrs = foldl' (\acc a -> acc .|. attrToInt a) 0 attrs in
 	withCWStringLen [char] $ \(cChars, cCharsLen) ->
 	allocaBytes {# sizeof cchar_t #} $ \pBuf -> do
-	{# call hsncurses_init_cchar_t #} (CCharT pBuf) cAttrs cChars (fromIntegral cCharsLen)
+	{# call hsncurses_init_cchar_t #} (CCharT pBuf) cAttrs (castPtr cChars) (fromIntegral cCharsLen)
 	io (CCharT pBuf)

 -- | Upper left corner
