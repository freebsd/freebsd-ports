--- dummy/netrigctl.c.orig	2017-04-16 02:56:42 UTC
+++ dummy/netrigctl.c
@@ -54,7 +54,7 @@ static int netrigctl_transaction(RIG *ri
   if (ret != RIG_OK)
 	return ret;
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret < 0)
 	return ret;
 
@@ -87,18 +87,18 @@ static int netrigctl_open(RIG *rig)
   if (prot_ver < RIGCTLD_PROT_VER)
 	  return -RIG_EPROTO;
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->itu_region = atoi(buf);
 
   for (i=0; i<FRQRANGESIZ; i++) {
-	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
 	if (ret <= 0)
 		return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -117,7 +117,7 @@ static int netrigctl_open(RIG *rig)
 		break;
   }
   for (i=0; i<FRQRANGESIZ; i++) {
-	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
 	if (ret <= 0)
 		return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -136,7 +136,7 @@ static int netrigctl_open(RIG *rig)
 		break;
   }
   for (i=0; i<TSLSTSIZ; i++) {
-	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   	if (ret <= 0)
 		return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -150,7 +150,7 @@ static int netrigctl_open(RIG *rig)
   }
 
   for (i=0; i<FLTLSTSIZ; i++) {
-	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+	ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   	if (ret <= 0)
 		return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -168,31 +168,31 @@ static int netrigctl_open(RIG *rig)
 chan_t chan_list[CHANLSTSIZ]; /*!< Channel list, zero ended */
 #endif
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->max_rit = atol(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->max_xit = atol(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->max_ifshift = atol(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->announces = atoi(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -205,7 +205,7 @@ chan_t chan_list[CHANLSTSIZ]; /*!< Chann
 	  ret = 0;
   rs->preamp[ret] = RIG_DBLST_END;
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -218,37 +218,37 @@ chan_t chan_list[CHANLSTSIZ]; /*!< Chann
 	  ret = 0;
   rs->attenuator[ret] = RIG_DBLST_END;
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->has_get_func = strtol(buf, NULL, 0);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->has_set_func = strtol(buf, NULL, 0);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->has_get_level = strtol(buf, NULL, 0);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->has_set_level = strtol(buf, NULL, 0);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
   rs->has_get_parm = strtol(buf, NULL, 0);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -354,7 +354,7 @@ static int netrigctl_get_mode(RIG *rig, 
   if (ret > 0 && buf[ret-1]=='\n') buf[ret-1] = '\0';	/* chomp */
   *mode = rig_parse_mode(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -761,7 +761,7 @@ static int netrigctl_get_split_mode(RIG 
   if (ret > 0 && buf[ret-1]=='\n') buf[ret-1] = '\0';	/* chomp */
   *tx_mode = rig_parse_mode(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
@@ -804,7 +804,7 @@ static int netrigctl_get_split_vfo(RIG *
 
   *split = atoi(buf);
 
-  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", sizeof("\n"));
+  ret = read_string(&rig->state.rigport, buf, BUF_MAX, "\n", 1);
   if (ret <= 0)
 	return (ret < 0) ? ret : -RIG_EPROTO;
 
