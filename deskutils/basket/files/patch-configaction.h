--- basket/configaction.h.orig	Mon Sep  8 19:21:02 2003
+++ basket/configaction.h	Mon Sep  8 19:22:16 2003
@@ -35,8 +35,8 @@
   public:
 	ConfigAction(int action = 0, QString runCommand = "");
 	~ConfigAction();
-	inline int action();
-	inline QString runCommand();
+	inline int action() { return m_action; };
+	inline QString runCommand() { return m_runCommand; };
 	inline void setAction(int action);
 	inline void setRunCommand(QString runCommand);
   private:
