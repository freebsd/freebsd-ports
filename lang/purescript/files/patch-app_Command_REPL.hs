--- app/Command/REPL.hs.orig	2019-11-02 17:39:14 UTC
+++ app/Command/REPL.hs
@@ -22,9 +22,10 @@ import           Control.Concurrent.STM (TVar, atomica
                                         readTVarIO,
                                         TChan, newBroadcastTChanIO, dupTChan,
                                         readTChan, writeTChan)
-import           Control.Exception (fromException)
+import           Control.Exception (fromException, SomeException)
 import           Control.Monad
-import           Control.Monad.IO.Class (liftIO)
+import           Control.Monad.Catch (MonadMask)
+import           Control.Monad.IO.Class (liftIO, MonadIO)
 import           Control.Monad.Trans.Class
 import           Control.Monad.Trans.Except (ExceptT(..), runExceptT)
 import           Control.Monad.Trans.State.Strict (StateT, evalStateT)
@@ -97,7 +98,7 @@ psciOptions = PSCiOptions <$> many inputFile
                           <*> backend
 
 -- | Parses the input and returns either a command, or an error as a 'String'.
-getCommand :: forall m. MonadException m => InputT m (Either String [Command])
+getCommand :: forall m. (MonadMask m, MonadIO m) => InputT m (Either String [Command])
 getCommand = handleInterrupt (return (Right [])) $ do
   line <- withInterrupt $ getInputLine "> "
   case line of
@@ -105,7 +106,7 @@ getCommand = handleInterrupt (return (Right [])) $ do
     Just "" -> return (Right [])
     Just s  -> return (parseCommand s)
 
-pasteMode :: forall m. MonadException m => InputT m (Either String [Command])
+pasteMode :: forall m. (MonadMask m, MonadIO m) => InputT m (Either String [Command])
 pasteMode =
     parseCommand <$> go []
   where
