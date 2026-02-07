--- src/org/gnu/readline/Readline.java.orig	2003-01-07 10:14:35 UTC
+++ src/org/gnu/readline/Readline.java
@@ -568,6 +568,31 @@ public class Readline {
   /////////////////////////////////////////////////////////////////////////////
 
   /**
+     Query and set the completion append character. You might need
+     this in a {@link ReadlineCompleter} implementation. The argument
+     appendCharacter should be in the ASCII range.
+
+     <p>Supporting implementations:
+        <ul>
+	  <li>GNU-Readline</li>
+	  <li>Editline</li>
+        </ul>
+     </p>
+
+  */
+    
+  public static char setCompletionAppendCharacter(char appendCharacter) {
+    if (iLib == ReadlineLibrary.GnuReadline || iLib == ReadlineLibrary.Editline)
+      return setCompletionAppendCharacterImpl(appendCharacter);
+    else if (iThrowException)
+      throw new UnsupportedOperationException();
+    else
+      return '\uFFFF';
+  }
+
+  /////////////////////////////////////////////////////////////////////////////
+
+  /**
      Query the current line buffer. This returns the current content of
      the internal line buffer. You might need this in a 
      {@link ReadlineCompleter} implementation to access the full text
@@ -838,4 +863,17 @@ public class Readline {
   private native static void 
     setWordBreakCharactersImpl(String wordBreakCharacters)
                               throws UnsupportedEncodingException;
+
+  /////////////////////////////////////////////////////////////////////////////
+
+  /**
+     Native implementation of setCompletionAppendCharacter()
+
+     @see 
+   org.gnu.readline.Readline#setCompletionAppendCharacter(char appendCharacter)
+  */
+
+  private native static char 
+    setCompletionAppendCharacterImpl(char appendCharacter);
+
 }
