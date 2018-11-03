--- ebwt.h.orig	2018-11-03 20:51:56 UTC
+++ ebwt.h
@@ -860,7 +860,7 @@ public:
 	TIndexOffU*   ftab() const         { return _ftab; }
 	TIndexOffU*   eftab() const        { return _eftab; }
 	TIndexOffU*   offs() const         { return _offs; }
-	uint32_t*   isa() const          { return _isa; } /* check */
+	uint32_t*   isa() const          { return (uint32_t)_isa; } /* check */
 	TIndexOffU*   plen() const         { return _plen; }
 	TIndexOffU*   rstarts() const      { return _rstarts; }
 	uint8_t*    ebwt() const         { return _ebwt; }
