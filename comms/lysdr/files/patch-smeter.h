--- smeter.h.orig	2014-06-02 02:51:37.000000000 -0700
+++ smeter.h	2014-06-02 02:51:54.000000000 -0700
@@ -55,6 +55,7 @@
 
 GtkWidget *sdr_smeter_new();
 void sdr_smeter_set_level(SDRSMeter *sm, gdouble value);
+GType sdr_smeter_get_type(void);
 
 #endif /* __SMETER_H */
 
