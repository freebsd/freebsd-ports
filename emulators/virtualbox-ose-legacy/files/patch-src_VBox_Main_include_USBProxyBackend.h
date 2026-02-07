--- src/VBox/Main/include/USBProxyBackend.h.orig	2020-05-13 19:44:06 UTC
+++ src/VBox/Main/include/USBProxyBackend.h
@@ -365,13 +365,10 @@ class USBProxyBackendFreeBSD : public USBProxyBackend 
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
