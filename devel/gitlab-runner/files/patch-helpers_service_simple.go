--- helpers/service/simple.go.orig	2017-06-22 10:21:35 UTC
+++ helpers/service/simple.go
@@ -6,6 +6,8 @@ import (
 	"os"
 	"os/signal"
 	"syscall"
+	"fmt"
+	"log/syslog"
 )
 
 var (
@@ -18,6 +20,39 @@ type SimpleService struct {
 	c *service.Config
 }
 
+// Begin copy from /vendor/github.com/ayufan/golang-kardianos-service/service_unix.go
+type sysLogger struct {
+        *syslog.Writer
+        errs chan<- error
+}
+
+func (s sysLogger) send(err error) error {
+        if err != nil && s.errs != nil {
+                s.errs <- err
+        }
+        return err
+}
+
+func (s sysLogger) Error(v ...interface{}) error {
+        return s.send(s.Writer.Err(fmt.Sprint(v...)))
+}
+func (s sysLogger) Warning(v ...interface{}) error {
+        return s.send(s.Writer.Warning(fmt.Sprint(v...)))
+}
+func (s sysLogger) Info(v ...interface{}) error {
+        return s.send(s.Writer.Info(fmt.Sprint(v...)))
+}
+func (s sysLogger) Errorf(format string, a ...interface{}) error {
+        return s.send(s.Writer.Err(fmt.Sprintf(format, a...)))
+}
+func (s sysLogger) Warningf(format string, a ...interface{}) error {
+        return s.send(s.Writer.Warning(fmt.Sprintf(format, a...)))
+}
+func (s sysLogger) Infof(format string, a ...interface{}) error {
+        return s.send(s.Writer.Info(fmt.Sprintf(format, a...)))
+}
+// End copy
+
 // Run should be called shortly after the program entry point.
 // After Interface.Stop has finished running, Run will stop blocking.
 // After Run stops blocking, the program must exit shortly after.
@@ -79,7 +114,13 @@ func (s *SimpleService) Logger(errs chan<- error) (ser
 // SystemLogger opens and returns a system logger. If errs is non-nil errors
 // will be sent on errs as well as returned from Logger's functions.
 func (s *SimpleService) SystemLogger(errs chan<- error) (service.Logger, error) {
-	return nil, ErrNotSupported
+	// Begin copy from vendor/github.com/ayufan/golang-kardianos-service/service_unix.go
+        w, err := syslog.New(syslog.LOG_INFO, s.c.Name)
+        if err != nil {
+                return nil, err
+        }
+        return sysLogger{w, errs}, nil
+	// End copy
 }
 
 // String displays the name of the service. The display name if present,
