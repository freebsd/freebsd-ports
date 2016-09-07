--- src/VBox/Main/include/USBProxyBackend.h.orig	2016-08-16 20:00:18 UTC
+++ src/VBox/Main/include/USBProxyBackend.h
@@ -365,7 +365,6 @@ protected:
     virtual int interruptWait(void);
     virtual PUSBDEVICE getDevices(void);
     int addDeviceToChain(PUSBDEVICE pDev, PUSBDEVICE *ppFirst, PUSBDEVICE **pppNext, int rc);
-    virtual void deviceAdded(ComObjPtr<HostUSBDevice> &aDevice, SessionMachinesList &llOpenedMachines, PUSBDEVICE aUSBDevice);
 
 private:
     RTSEMEVENT mNotifyEventSem;
