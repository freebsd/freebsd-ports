--- tools/qdbus/qdbus/qdbus.cpp.orig	2012-04-26 21:45:51.000000000 +0200
+++ tools/qdbus/qdbus/qdbus.cpp	2012-12-07 14:46:43.000000000 +0100
@@ -54,7 +54,6 @@ QT_BEGIN_NAMESPACE
 Q_DBUS_EXPORT extern bool qt_dbus_metaobject_skip_annotations;
 QT_END_NAMESPACE
 
-static QDBusConnection connection(QLatin1String(""));
 static bool printArgumentsLiterally = false;
 
 static void showUsage()
@@ -111,7 +110,7 @@ static void printArg(const QVariant &v)
     }
 }
 
-static void listObjects(const QString &service, const QString &path)
+static void listObjects(const QString &service, const QString &path, const QDBusConnection &connection)
 {
     // make a low-level call, to avoid introspecting the Introspectable interface
     QDBusMessage call = QDBusMessage::createMethodCall(service, path.isEmpty() ? QLatin1String("/") : path,
@@ -144,13 +143,13 @@ static void listObjects(const QString &s
         if (child.tagName() == QLatin1String("node")) {
             QString sub = path + QLatin1Char('/') + child.attribute(QLatin1String("name"));
             printf("%s\n", qPrintable(sub));
-            listObjects(service, sub);
+            listObjects(service, sub, connection);
         }
         child = child.nextSiblingElement();
     }
 }
 
-static void listInterface(const QString &service, const QString &path, const QString &interface)
+static void listInterface(const QString &service, const QString &path, const QString &interface, const QDBusConnection &connection)
 {
     QDBusInterface iface(service, path, interface, connection);
     if (!iface.isValid()) {
@@ -204,7 +203,7 @@ static void listInterface(const QString 
     }
 }
 
-static void listAllInterfaces(const QString &service, const QString &path)
+static void listAllInterfaces(const QString &service, const QString &path, const QDBusConnection &connection)
 {
     // make a low-level call, to avoid introspecting the Introspectable interface
     QDBusMessage call = QDBusMessage::createMethodCall(service, path.isEmpty() ? QLatin1String("/") : path,
@@ -229,7 +228,7 @@ static void listAllInterfaces(const QStr
         if (child.tagName() == QLatin1String("interface")) {
             QString ifaceName = child.attribute(QLatin1String("name"));
             if (QDBusUtil::isValidInterfaceName(ifaceName))
-                listInterface(service, path, ifaceName);
+                listInterface(service, path, ifaceName, connection);
             else {
                 qWarning("Invalid D-BUS interface name '%s' found while parsing introspection",
                          qPrintable(ifaceName));
@@ -253,7 +252,7 @@ static QStringList readList(QStringList 
     return retval;
 }
 
-static int placeCall(const QString &service, const QString &path, const QString &interface,
+static int placeCall(const QString &service, const QString &path, const QString &interface, const QDBusConnection &connection,
                const QString &member, const QStringList& arguments, bool try_prop=true)
 {
     QDBusInterface iface(service, path, interface, connection);
@@ -291,7 +290,7 @@ static int placeCall(const QString &serv
                     proparg += interface;
                     proparg += member;
                     proparg += args.first();
-                    if (!placeCall(service, path, "org.freedesktop.DBus.Properties", "Set", proparg, false))
+                    if (!placeCall(service, path, "org.freedesktop.DBus.Properties", connection, "Set", proparg, false))
                         return 0;
                 }
                 fprintf(stderr, "Cannot find '%s.%s' in object %s at %s\n",
@@ -387,7 +386,7 @@ static int placeCall(const QString &serv
             QStringList proparg;
             proparg += interface;
             proparg += member;
-            if (!placeCall(service, path, "org.freedesktop.DBus.Properties", "Get", proparg, false))
+            if (!placeCall(service, path, "org.freedesktop.DBus.Properties", connection, "Get", proparg, false))
                 return 0;
         }
         if (err.type() == QDBusError::ServiceUnknown)
@@ -448,6 +447,7 @@ int main(int argc, char **argv)
     QCoreApplication app(argc, argv);
     QStringList args = app.arguments();
     args.takeFirst();
+    QDBusConnection connection(QLatin1String(""));
 
     bool connectionOpened = false;
     while (!args.isEmpty() && args.at(0).startsWith(QLatin1Char('-'))) {
@@ -481,7 +481,7 @@ int main(int argc, char **argv)
     QDBusConnectionInterface *bus = connection.interface();
     if (args.isEmpty()) {
         printAllServices(bus);
-        exit(0);
+        return 0;
     }
 
     QString service = args.takeFirst();
@@ -491,22 +491,22 @@ int main(int argc, char **argv)
                 return 0;
         }
         fprintf(stderr, "Service '%s' is not a valid name.\n", qPrintable(service));
-        exit(1);
+        return 1;
     }
 
     if (args.isEmpty()) {
-        listObjects(service, QString());
-        exit(0);
+        listObjects(service, QString(), connection);
+        return 0;
     }
 
     QString path = args.takeFirst();
     if (!QDBusUtil::isValidObjectPath(path)) {
         fprintf(stderr, "Path '%s' is not a valid path name.\n", qPrintable(path));
-        exit(1);
+        return 1;
     }
     if (args.isEmpty()) {
-        listAllInterfaces(service, path);
-        exit(0);
+        listAllInterfaces(service, path, connection);
+        return 0;
     }
 
     QString interface = args.takeFirst();
@@ -521,14 +521,13 @@ int main(int argc, char **argv)
     }
     if (!interface.isEmpty() && !QDBusUtil::isValidInterfaceName(interface)) {
         fprintf(stderr, "Interface '%s' is not a valid interface name.\n", qPrintable(interface));
-        exit(1);
+        return 1;
     }
     if (!QDBusUtil::isValidMemberName(member)) {
         fprintf(stderr, "Method name '%s' is not a valid member name.\n", qPrintable(member));
-        exit(1);
+        return 1;
     }
 
-    int ret = placeCall(service, path, interface, member, args);
-    exit(ret);
+    return placeCall(service, path, interface, connection, member, args);
 }
 
