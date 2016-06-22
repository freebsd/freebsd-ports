--- src/plugins/projectexplorer/runnables.h.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/projectexplorer/runnables.h
@@ -43,8 +43,22 @@ public:
     Utils::Environment environment;
     ApplicationLauncher::Mode runMode = ApplicationLauncher::Gui;
     IDevice::ConstPtr device; // Override the kit's device. Keep unset by default.
+
+    static void *staticTypeId;
 };
 
 PROJECTEXPLORER_EXPORT bool operator==(const StandardRunnable &r1, const StandardRunnable &r2);
 
+class PROJECTEXPLORER_EXPORT HostName
+{
+public:
+    explicit HostName(const QString &host) : m_host(host) {}
+    QString host() const { return m_host; }
+
+    static void *staticTypeId;
+
+private:
+    QString m_host;
+};
+
 } // namespace ProjectExplorer
