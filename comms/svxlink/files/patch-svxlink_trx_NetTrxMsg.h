--- svxlink/trx/NetTrxMsg.h.orig	2014-04-09 23:51:14.000000000 -0700
+++ svxlink/trx/NetTrxMsg.h	2014-04-09 23:51:53.000000000 -0700
@@ -176,8 +176,8 @@
     MsgProtoVer(void)
       : Msg(TYPE, sizeof(MsgProtoVer)), m_major(MAJOR),
         m_minor(MINOR) {}
-    uint16_t major(void) const { return m_major; }
-    uint16_t minor(void) const { return m_minor; }
+    uint16_t FBSD_major(void) const { return m_major; }
+    uint16_t FBSD_minor(void) const { return m_minor; }
   
   private:
     uint16_t m_major;
