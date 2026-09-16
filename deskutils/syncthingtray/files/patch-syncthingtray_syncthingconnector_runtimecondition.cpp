--- syncthingtray/syncthingconnector/runtimecondition.cpp.orig	2026-09-13 15:05:04 UTC
+++ syncthingtray/syncthingconnector/runtimecondition.cpp
@@ -108,6 +108,7 @@ static std::pair<const QNetworkInformation *, bool> lo
 }
 #endif
 
+#ifdef SYNCTHINGCONNECTION_SUPPORT_BATTERY_MONITORING
 /*!
  * \brief The BatteryMonitorBase class is a base class for battery monitoring,
  * providing the capability to query and update battery states across all runtime condition instances.
@@ -145,6 +146,7 @@ class BatteryMonitorBase { (protected)
     std::optional<int> m_batteryLevel; /*!< The current battery level percentage (0-100). */
     std::optional<bool> m_batterySaving; /*!< Whether battery saving mode is enabled. */
 };
+#endif
 
 #if defined(Q_OS_ANDROID)
 /*!
