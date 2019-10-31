diff --git a/src/kdbusservice.cpp b/src/kdbusservice.cpp
--- src/kdbusservice.cpp
+++ src/kdbusservice.cpp
@@ -129,6 +130,18 @@
             } else {
                 d->serviceName += QLatin1Char('-') + QString::number(QCoreApplication::applicationPid());
             }
+        } else if (options & KDBusService::Unique) {
+            auto reply = bus->registeredServiceNames();
+            if (!reply.isValid()) {
+                return;
+            }
+
+            for (const auto& serviceName : reply.value()) {
+                if (serviceName.startsWith(d->serviceName)) {
+                    d->serviceName = serviceName;
+                    return;
+                }
+            }
         }
     }
 

