--- src/Settings.cpp.orig	2020-12-12 00:59:10 UTC
+++ src/Settings.cpp
@@ -1054,7 +1054,7 @@ void Settings_ModalOptions (struct thread_Settings *mE
 	    bail = true;
 	} else if (isTxStartTime(mExtSettings) || isTxHoldback(mExtSettings)) {
 	    Timestamp now;
-	    long nowsecs = now.getSecs();
+	    time_t nowsecs = now.getSecs();
 	    // fill out the formats in the event they are needed per an time error
 	    char start_timebuf[80];
 	    struct tm ts = *localtime(&mExtSettings->txstart_epoch.tv_sec);
@@ -1731,13 +1731,13 @@ int Settings_GenerateClientHdr (struct thread_Settings
 	    if (isFullDuplex(client) || isReverse(client)) {
 		upperflags |= HEADER_ISOCH_SETTINGS;
 		hdr->isoch_settings.FPSl = htonl((long)(client->mFPS));
-		hdr->isoch_settings.FPSu = htonl(((client->mFPS - (long)(client->mFPS)) * rMillion));
+		hdr->isoch_settings.FPSu = htonl((long)((client->mFPS - (long)(client->mFPS)) * rMillion));
 		hdr->isoch_settings.Meanl = htonl((long)(client->mMean));
-		hdr->isoch_settings.Meanu = htonl((((client->mMean) - (long)(client->mMean)) * rMillion));
+		hdr->isoch_settings.Meanu = htonl((long)(((client->mMean) - (long)(client->mMean)) * rMillion));
 		hdr->isoch_settings.Variancel = htonl((long)(client->mVariance));
-		hdr->isoch_settings.Varianceu = htonl(((client->mVariance - (long)(client->mVariance)) * rMillion));
+		hdr->isoch_settings.Varianceu = htonl((long)((client->mVariance - (long)(client->mVariance)) * rMillion));
 		hdr->isoch_settings.BurstIPGl = htonl((long)(client->mBurstIPG));
-		hdr->isoch_settings.BurstIPGu = htonl(((client->mBurstIPG - (long)(client->mBurstIPG)) * rMillion));
+		hdr->isoch_settings.BurstIPGu = htonl((long)((client->mBurstIPG - (long)(client->mBurstIPG)) * rMillion));
 		len += sizeof(struct client_hdrext_isoch_settings);
 	    }
 	}
@@ -1822,13 +1822,13 @@ int Settings_GenerateClientHdr (struct thread_Settings
 	    upperflags |= HEADER_ISOCH;
 	    if (isFullDuplex(client) || isReverse(client)) {
 		upperflags |= HEADER_ISOCH_SETTINGS;
-		hdr->isoch_settings.FPSl = htonl(client->mFPS);
+		hdr->isoch_settings.FPSl = htonl((long)client->mFPS);
 		hdr->isoch_settings.FPSu = htonl(((long)(client->mFPS) - (long)client->mFPS * rMillion));
-		hdr->isoch_settings.Meanl = htonl(client->mMean);
+		hdr->isoch_settings.Meanl = htonl((long)client->mMean);
 		hdr->isoch_settings.Meanu = htonl(((long)(client->mMean) - (long)client->mMean * rMillion));
-		hdr->isoch_settings.Variancel = htonl(client->mVariance);
+		hdr->isoch_settings.Variancel = htonl((long)client->mVariance);
 		hdr->isoch_settings.Varianceu = htonl(((long)(client->mVariance) - (long)client->mVariance * rMillion));
-		hdr->isoch_settings.BurstIPGl = htonl(client->mBurstIPG);
+		hdr->isoch_settings.BurstIPGl = htonl((long)client->mBurstIPG);
 		hdr->isoch_settings.BurstIPGu = htonl(((long)(client->mBurstIPG) - (long)client->mBurstIPG * rMillion));
 		len += sizeof(struct client_hdrext_isoch_settings);
 	    }
