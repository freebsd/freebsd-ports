--- src/cdtrack.cc	Sat Feb 14 20:11:05 2004
+++ src/cdtrack.cc	Sun Dec 12 21:55:58 2004
@@ -42,6 +42,7 @@
 int cdfd = -1, numtracks;
 string cddbquery, cdid, cdtitle;
 bool ejected = false;
+#define CDROM_LEADOUT	0xAA
 
 struct istracknumber: public binary_function<int, const track*, bool> {
     public: bool operator()(int n, const track *c) const {
@@ -58,51 +59,56 @@
 // ----------------------------------------------------------------------------
 
 void cdtrack::play() {
-    struct cdrom_ti n;
-    n.cdti_trk0 = number;
-    n.cdti_trk1 = number;
+    struct ioc_play_track n;
+    memset (&n, 0, sizeof (struct ioc_play_track));
+    n.start_track = number;
+    n.end_track = number;
 
-    if(!ioctl(cdfd, CDROMPLAYTRKIND, &n)) {
+    if(!ioctl(cdfd, CDIOCPLAYTRACKS, &n)) {
 	paused = false;
-    }
+    } 
 }
 
 void cdtrack::pause() {
     if(paused) {
-	ioctl(cdfd, CDROMRESUME);
+	ioctl(cdfd, CDIOCRESUME);
 	paused = false;
 
-    } else if(ioctl(cdfd, CDROMPAUSE) != -1) {
+    } else if(ioctl(cdfd, CDIOCPAUSE) != -1) {
 	paused = true;
 
-    }
+    } 
 }
 
 void cdtrack::stop() {
-    if(ioctl(cdfd, CDROMSTOP) != -1) {
-    }
+    if(ioctl(cdfd, CDIOCSTOP) != -1) {
+    } 
 }
 
 string cdtrack::getdescription() const {
-    return (string) "(cd) " + i2str(number) + ". " + title;
+    return (string) "(cd) " + i2str(number) + ". " + title; 
 }
 
 vector<string> cdtrack::getstatus() const {
     vector<string> r;
-    struct cdrom_subchnl subc;
+    struct ioc_read_subchannel subc;
+    struct cd_sub_channel_info data;
     char buf[64];
     OrpheusPlayList::iterator it;
     string sb;
 
-    subc.cdsc_format = CDROM_MSF;
+    subc.address_format = CD_MSF_FORMAT;
+    subc.data = &data;
+    subc.data_len = sizeof(data);
+    
 
-    if(ioctl(cdfd, CDROMSUBCHNL, &subc) != -1) {
+    if(ioctl(cdfd, CDIOCREADSUBCHANNEL, &subc) != -1) {
 	sprintf(buf, _("track %d [%02d:%02d]"), number,
-	    subc.cdsc_reladdr.msf.minute, subc.cdsc_reladdr.msf.second);
+	    subc.data->what.position.reladdr.msf.minute, subc.data->what.position.reladdr.msf.second);
 
 	r.push_back("CD: " + cdtitle + "; " + buf);
 
-	it = find_if(plist.begin(), plist.end(), bind1st(istracknumber(), subc.cdsc_trk));
+	it = find_if(plist.begin(), plist.end(), bind1st(istracknumber(), subc.data->what.position.track_number));
 
 	if(it != plist.end()) {
 	    cdtrack *ct = static_cast<cdtrack *>(*it);
@@ -112,92 +118,100 @@
 	}
     }
 
-    return r;
+    return r; 
 }
 
 bool cdtrack::terminated() const {
     double nframes, lframe;
-    struct cdrom_subchnl subc;
+    struct ioc_read_subchannel subc;
+    struct cd_sub_channel_info data;
     int ptime;
 
-    subc.cdsc_format = CDROM_MSF;
-
-    if(ioctl(cdfd, CDROMSUBCHNL, &subc) != -1) {
-	return
-	    subc.cdsc_audiostatus != CDROM_AUDIO_PLAY &&
-	    subc.cdsc_audiostatus != CDROM_AUDIO_PAUSED;
+    subc.address_format = CD_MSF_FORMAT;
+    subc.data_format = CD_CURRENT_POSITION;
+    subc.data = &data;
+    subc.data_len= sizeof(data);
+
+    if(ioctl(cdfd, CDIOCREADSUBCHANNEL, &subc) != -1) {
+	return 
+	    subc.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+	    subc.data->header.audio_status != CD_AS_PLAY_PAUSED;
     }
 
     return true;
 }
 
 void cdtrack::fwd(bool big) {
-    playseconds(big ? 40 : 4);
+    playseconds(big ? 40 : 4); 
 }
 
 void cdtrack::rwd(bool big) {
-    playseconds(big ? -40 : -4);
+    playseconds(big ? -40 : -4); 
 }
 
 void cdtrack::playseconds(int offset) {
-    struct cdrom_msf msf;
-    struct cdrom_subchnl subc;
-
-    subc.cdsc_format = CDROM_MSF;
-
-    if(ioctl(cdfd, CDROMSUBCHNL, &subc) != -1) {
-	msf.cdmsf_sec0 = subc.cdsc_absaddr.msf.second+offset;
-	msf.cdmsf_min0 = subc.cdsc_absaddr.msf.minute;
-	msf.cdmsf_frame0 = subc.cdsc_absaddr.msf.frame;
-	msf.cdmsf_min1 = toc.cdte_addr.msf.minute;
-	msf.cdmsf_sec1 = toc.cdte_addr.msf.second;
-	msf.cdmsf_frame1 = toc.cdte_addr.msf.frame;
-
-	if(msf.cdmsf_sec0 > 60 && (offset < 0)) {
-	    msf.cdmsf_sec0 = 60-abs(offset);
-	    msf.cdmsf_min0--;
+    struct ioc_play_msf msf;
+    struct ioc_read_subchannel subc;
+    struct cd_sub_channel_info data;
+
+    subc.address_format = CD_MSF_FORMAT;
+    subc.data = &data;
+    subc.data_len = sizeof(data);
+    
+
+    if(ioctl(cdfd, CDIOCREADSUBCHANNEL, &subc) != -1) {
+	msf.start_s = subc.data->what.position.absaddr.msf.second+offset;
+	msf.start_m = subc.data->what.position.absaddr.msf.minute;
+	msf.start_f = subc.data->what.position.absaddr.msf.frame;
+	msf.end_m = toc.entry.addr.msf.minute;
+	msf.end_s = toc.entry.addr.msf.second;
+	msf.end_f = toc.entry.addr.msf.frame;
+
+	if(msf.start_s > 60 && (offset < 0)) {
+	    msf.start_s = 60-abs(offset);
+	    msf.start_m--;
 	}
 
-	if(ioctl(cdfd, CDROMPLAYMSF, &msf) != -1) {
+	if(ioctl(cdfd, CDIOCPLAYMSF, &msf) != -1) {
 	}
-    }
+    } 
 }
 
 void cdtrack::readlength() {
     signed int start_sec, start_min, end_min, end_sec;
-    struct cdrom_msf msf;
-    struct cdrom_tochdr toch;
+    struct ioc_play_msf msf;
+    struct ioc_toc_header toch;
 
-    toc.cdte_track = number;
-    toc.cdte_format = CDROM_MSF;
+    toc.track = number;
+    toc.address_format = CD_MSF_FORMAT;
 
-    if(ioctl(cdfd, CDROMREADTOCENTRY, &toc) != -1) {
-	start_sec = toc.cdte_addr.msf.second;
-	start_min = toc.cdte_addr.msf.minute;
-
-	msf.cdmsf_min0 = toc.cdte_addr.msf.minute;
-	msf.cdmsf_sec0 = toc.cdte_addr.msf.second;
-	msf.cdmsf_frame0 = toc.cdte_addr.msf.frame;
-
-	if(ioctl(cdfd, CDROMREADTOCHDR, &toch) != -1) {
-	    if(toch.cdth_trk1 == number) {
-		toc.cdte_track = CDROM_LEADOUT;
+    if(ioctl(cdfd, CDIOREADTOCENTRY, &toc) != -1) {
+	start_sec = toc.entry.addr.msf.second;
+	start_min = toc.entry.addr.msf.minute;
+
+	msf.start_m = toc.entry.addr.msf.minute;
+	msf.start_s = toc.entry.addr.msf.second;
+	msf.start_f = toc.entry.addr.msf.frame;
+
+	if(ioctl(cdfd, CDIOREADTOCHEADER, &toch) != -1) {
+	    if(toch.ending_track == number) {
+		toc.track = CDROM_LEADOUT;
 	    } else {
-		toc.cdte_track = number+1;
+		toc.track = number+1;
 	    }
 
-	    if(ioctl(cdfd, CDROMREADTOCENTRY, &toc) != -1) {
-		msf.cdmsf_min1 = toc.cdte_addr.msf.minute;
-		msf.cdmsf_sec1 = toc.cdte_addr.msf.second;
-		msf.cdmsf_frame1 = toc.cdte_addr.msf.frame;
+	    if(ioctl(cdfd, CDIOREADTOCENTRY, &toc) != -1) {
+		msf.end_m = toc.entry.addr.msf.minute;
+		msf.end_s = toc.entry.addr.msf.second;
+		msf.end_f = toc.entry.addr.msf.frame;
 
-		end_sec = toc.cdte_addr.msf.second;
-		end_min = toc.cdte_addr.msf.minute;
+		end_sec = toc.entry.addr.msf.second;
+		end_min = toc.entry.addr.msf.minute;
 
 		length = (end_min*60+end_sec)-(start_min*60+start_sec);
 	    }
 	}
-    }
+    } 
 }
 
 void cdtrack::toplaylist(ofstream &f) const {
@@ -208,7 +222,7 @@
 
 static bool isourtrack(const track *t) {
     const cdtrack *cd = dynamic_cast<const cdtrack *>(t);
-    return (cd != 0);
+    return (cd != 0); 
 }
 
 static int getdbsum(int val) {
@@ -218,7 +232,7 @@
     for(i = 0; i < buf.size(); i++)
 	ret += buf[i]-'0';
 
-   return ret;
+   return ret; 
 }
 
 void cdtrack::cleartracks() {
@@ -227,15 +241,17 @@
     while((it = find_if(plist.begin(), plist.end(), isourtrack)) != plist.end()) {
 	delete *it;
 	plist.erase(it);
-    }
+    } 
 }
 
 void cdtrack::readtracks() {
     int st_track, lst_track, track, start_sec, start_min, end_sec, end_min;
     int tracklen, tracksum, disklen, sframe;
     unsigned int discid;
-    struct cdrom_tocentry toc;
-    struct cdrom_tochdr toch;
+    struct ioc_read_toc_single_entry toc;
+    struct ioc_toc_header toch;
+    
+      
     cdtrack *ct;
     char buf[64];
 
@@ -248,32 +264,32 @@
 
     cddbquery = "";
 
-    if(!ioctl(cdfd, CDROMSTART) && !ioctl(cdfd, CDROMREADTOCHDR, &toch)) {
-	st_track = toch.cdth_trk0;
-	lst_track = toch.cdth_trk1;
+    if(!ioctl(cdfd, CDIOCSTART) && !ioctl(cdfd, CDIOREADTOCHEADER, &toch)) {
+	st_track = toch.starting_track;
+	lst_track = toch.ending_track;
 
-	toc.cdte_format = CDROM_MSF;
+	toc.address_format = CD_MSF_FORMAT;
 	tracksum = 0;
 
 	for(track = 1; track <= lst_track; track++) {
-	    toc.cdte_track = track;
+	    toc.track = track;
 
-	    if(ioctl(cdfd, CDROMREADTOCENTRY, &toc) != -1) {
-		start_sec = toc.cdte_addr.msf.second;
-		start_min = toc.cdte_addr.msf.minute;
+	    if(ioctl(cdfd, CDIOREADTOCENTRY, &toc) != -1) {
+		start_sec = toc.entry.addr.msf.second;
+		start_min = toc.entry.addr.msf.minute;
 
-		if(toch.cdth_trk1 == track) {
-		    toc.cdte_track = CDROM_LEADOUT;
+		if(toch.ending_track == track) {
+		    toc.track = CDROM_LEADOUT;
 		} else {
-		    toc.cdte_track = track + 1;
+		    toc.track = track + 1;
 		}
 
 		sframe = (start_min * 60 + start_sec) * 75
-		    + toc.cdte_addr.msf.frame;
+		    + toc.entry.addr.msf.frame;
 
-		if(ioctl(cdfd, CDROMREADTOCENTRY, &toc) != -1) {
-		    end_sec = toc.cdte_addr.msf.second;
-		    end_min = toc.cdte_addr.msf.minute;
+		if(ioctl(cdfd, CDIOREADTOCENTRY, &toc) != -1) {
+		    end_sec = toc.entry.addr.msf.second;
+		    end_min = toc.entry.addr.msf.minute;
 
 		    tracklen = (end_min * 60 + end_sec) - (start_min * 60 + start_sec);
 
@@ -308,7 +324,7 @@
     } else {
 	ui.status(_("No CD in the drive!"));
 
-    }
+    } 
 }
 
 bool cdtrack::loadtracks(const string &fname) {
@@ -388,7 +404,7 @@
 
 #endif
 
-    return reply;
+    return reply; 
 }
 
 void cdtrack::getcddb() {
@@ -468,15 +484,15 @@
 	ui.update();
     } else {
 	ui.status(_("Failed to fetch track titles"));
-    }
+    } 
 }
 
 void cdtrack::eject() {
     if(cdfd == -1)
 	cdfd = open(conf.getcddevice().c_str(), O_RDONLY | O_NONBLOCK);
 
-    if(ioctl(cdfd, ejected ? CDROMCLOSETRAY : CDROMEJECT) != -1)
-	ejected = !ejected;
+    if(ioctl(cdfd, ejected ? CDIOCALLOW : CDIOCEJECT) != -1)
+	ejected = !ejected; 
 }
 
 string cdtrack::getcdid() {
