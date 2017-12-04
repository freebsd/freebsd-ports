--- src/VBox/Main/include/USBProxyBackend.h.orig	2017-01-17 07:27:19 UTC
+++ src/VBox/Main/include/USBProxyBackend.h
@@ -359,13 +359,10 @@ public:
     virtual int releaseDevice(HostUSBDevice *aDevice);
 
 protected:
-    int initUsbfs(void);
-    int initSysfs(void);
     virtual int wait(RTMSINTERVAL aMillies);
     virtual int interruptWait(void);
     virtual PUSBDEVICE getDevices(void);
-    int addDeviceToChain(PUSBDEVICE pDev, PUSBDEVICE *ppFirst, PUSBDEVICE **pppNext, int rc);
-    virtual void deviceAdded(ComObjPtr<HostUSBDevice> &aDevice, SessionMachinesList &llOpenedMachines, PUSBDEVICE aUSBDevice);
+    virtual bool isFakeUpdateRequired();
 
 private:
     RTSEMEVENT mNotifyEventSem;
