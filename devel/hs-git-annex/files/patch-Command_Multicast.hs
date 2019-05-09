--- Command/Multicast.hs.orig	2019-01-29 19:25:02 UTC
+++ Command/Multicast.hs
@@ -48,7 +48,7 @@ data MultiCastOptions = MultiCastOptions MultiCastActi
 	deriving (Show)
 
 optParser :: CmdParamsDesc -> Parser MultiCastOptions
-optParser _ = MultiCastOptions 
+optParser _ = MultiCastOptions
 	<$> (genaddressp <|> sendp <|> receivep)
 	<*> many uftpopt
 	<*> cmdParams paramPaths
@@ -73,7 +73,7 @@ optParser _ = MultiCastOptions 
 		)
 
 seek :: MultiCastOptions -> CommandSeek
-seek (MultiCastOptions GenAddress _ _) = commandAction genAddress 
+seek (MultiCastOptions GenAddress _ _) = commandAction genAddress
 seek (MultiCastOptions Send ups fs) = commandAction $ send ups fs
 seek (MultiCastOptions Receive ups []) = commandAction $ receive ups
 seek (MultiCastOptions Receive _ _) = giveup "Cannot specify list of files with --receive; this receives whatever files the sender chooses to send."
@@ -108,7 +108,7 @@ genAddress = do
 	-- Except for on Windows XP, secp521r1 is supported on all
 	-- platforms by uftp. DJB thinks it's pretty good compared
 	-- with other NIST curves: "there's one standard NIST curve
-	-- using a nice prime, namely 2521−1  but the sheer size of this
+	-- using a nice prime, namely 2521-1  but the sheer size of this
 	-- prime makes it much slower than NIST P-256"
 	-- (http://blog.cr.yp.to/20140323-ecdsa.html)
 	-- Since this key is only used to set up the block encryption,
@@ -116,12 +116,12 @@ genAddress = do
 	keyparam = Param "ec:secp521r1"
 
 parseFingerprint :: String -> Maybe Fingerprint
-parseFingerprint = Fingerprint <$$> lastMaybe . filter isfingerprint . words 
+parseFingerprint = Fingerprint <$$> lastMaybe . filter isfingerprint . words
   where
-	isfingerprint s = 
+	isfingerprint s =
 		let os = filter (all isHexDigit) (splitc ':' s)
 		in length os == 20
-	
+
 send :: [CommandParam] -> [FilePath] -> CommandStart
 send ups fs = withTmpFile "send" $ \t h -> do
 	-- Need to be able to send files with the names of git-annex
@@ -131,7 +131,7 @@ send ups fs = withTmpFile "send" $ \t h -> do
 	-- expensive.
 	whenM isDirect $
 		giveup "Sorry, multicast send cannot be done from a direct mode repository."
-	
+
 	showStart' "generating file list" Nothing
 	fs' <- seekHelper LsFiles.inRepo =<< workTreeItems fs
 	matcher <- Limit.getMatcher
@@ -173,7 +173,7 @@ receive :: [CommandParam] -> CommandStart
 receive ups = do
 	showStart' "receiving multicast files" Nothing
 	showNote "Will continue to run until stopped by ctrl-c"
-	
+
 	showOutput
 	clientkey <- uftpKey
 	u <- getUUID
@@ -235,7 +235,7 @@ uftpKey = do
 uftpKey = KeyFile <$> credsFile "multicast"
 #endif
 
--- uftp needs a unique UID for each client and server, which 
+-- uftp needs a unique UID for each client and server, which
 -- is a 8 digit hex number in the form "0xnnnnnnnn"
 -- Derive it from the UUID.
 uftpUID :: UUID -> String
