--- src/VBox/Devices/Graphics/DevVGA_VBVA.cpp.orig	2014-03-26 15:17:10.000000000 -0400
+++ src/VBox/Devices/Graphics/DevVGA_VBVA.cpp	2014-04-03 14:58:41.000000000 -0400
@@ -1939,6 +1939,7 @@
 
     switch (u16ChannelInfo)
     {
+#ifdef VBOX_WITH_VDMA
         case VBVA_CMDVBVA_SUBMIT:
         {
             rc = vboxCmdVBVACmdSubmit(pVGAState);
@@ -1965,7 +1966,6 @@
             rc = vboxCmdVBVACmdCtl(pVGAState, pCtl, cbBuffer - VBoxSHGSMIBufferHeaderSize());
             break;
         }
-#ifdef VBOX_WITH_VDMA
         case VBVA_VDMA_CMD:
         {
             if (cbBuffer < VBoxSHGSMIBufferHeaderSize() + sizeof (VBOXVDMACBUF_DR))
@@ -2277,7 +2277,6 @@
             pVGAState->fGuestCaps = pCaps->fCaps;
             pCaps->rc = VINF_SUCCESS;
         } break;
-#endif
         case VBVA_SCANLINE_CFG:
         {
             if (cbBuffer < sizeof (VBVASCANLINECFG))
@@ -2290,6 +2289,7 @@
             pVGAState->fScanLineCfg = pCfg->fFlags;
             pCfg->rc = VINF_SUCCESS;
         } break;
+#endif
         default:
             Log(("Unsupported VBVA guest command %d!!!\n",
                  u16ChannelInfo));
