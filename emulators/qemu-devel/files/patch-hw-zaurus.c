--- a/hw/zaurus.c
+++ b/hw/zaurus.c
@@ -70,6 +70,10 @@ static uint32_t scoop_readb(void *opaque
 {
     ScoopInfo *s = (ScoopInfo *) opaque;
 
+    // XXX Workaround for base address (0x08800040 in this case)
+    //     rounded down to start of page
+    addr &= 0x3f;
+
     switch (addr) {
     case SCOOP_MCR:
         return s->mcr;
@@ -104,6 +108,10 @@ static void scoop_writeb(void *opaque, t
     ScoopInfo *s = (ScoopInfo *) opaque;
     value &= 0xffff;
 
+    // XXX Workaround for base address (0x08800040 in this case)
+    //     rounded down to start of page
+    addr &= 0x3f;
+
     switch (addr) {
     case SCOOP_MCR:
         s->mcr = value;
