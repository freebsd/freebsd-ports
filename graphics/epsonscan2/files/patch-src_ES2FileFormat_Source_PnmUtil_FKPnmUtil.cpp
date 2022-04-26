--- src/ES2FileFormat/Source/PnmUtil/FKPnmUtil.cpp.orig	2022-02-17 18:20:53 UTC
+++ src/ES2FileFormat/Source/PnmUtil/FKPnmUtil.cpp
@@ -137,7 +137,7 @@ BOOL CFKPnmEncodeUtil::StartEncodingWithData(IFKDestin
    ES_ErrorBailWithAction(m_cData.AllocBuffer(nHeaderSize + 4), BAIL,
     this, eError = kFKMemError, ES_STRING("memory alloc error"));
   }
-  memcpy(m_cData.GetBufferPtr(), m_pnmHeader.c_str(), sizeof(m_pnmHeader.c_str()));
+  memcpy(m_cData.GetBufferPtr(), m_pnmHeader.c_str(), strlen(m_pnmHeader.c_str())+1);
   m_rowBytes = ES_IMAGE_INFO::GetESImageBytesPerRow(imageInfo);
   pDest->NotifyDidBeginReceivingForImageInfo(m_strImageJson.c_str());
   if (pDest->GetFKDestinationType() == kFKDestinationTypeEmpty){
