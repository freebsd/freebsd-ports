--- modules/controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java.orig	2019-07-22 19:05:36 UTC
+++ modules/controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java
@@ -362,7 +362,7 @@ public abstract class TextInputControlBehavior<T exten
 
     protected void selectNextWord() {
         TextInputControl textInputControl = getControl();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isFreeBSD()) {
             textInputControl.selectEndOfNextWord();
         } else {
             textInputControl.selectNextWord();
@@ -401,7 +401,7 @@ public abstract class TextInputControlBehavior<T exten
 
     protected void nextWord() {
         TextInputControl textInputControl = getControl();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isFreeBSD()) {
             textInputControl.endOfNextWord();
         } else {
             textInputControl.nextWord();
