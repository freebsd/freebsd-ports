diff -druN svgalib-1.4.2.orig/src/mach32.c src/mach32.c
--- svgalib-1.4.2.orig/src/mach32.c	Fri Aug 25 04:39:39 2000
+++ src/mach32.c	Fri Aug 25 04:39:57 2000
@@ -1544,7 +1544,7 @@
 		goto writerr;
 	    printf("mach32: Notice: new EEPROM file >%s< succesful created.\n",
 		   eeprom_fname);
-	  finish_w_eeprom:
+	  finish_w_eeprom: ;
 	}
 	/* Change eeprom contents if requested: */
 	if (!(eeprom_option & EEPROM_USE_MEMCFG))
@@ -2415,7 +2415,7 @@
     return ptr;
 }
 
-static int isnumber(char *str)
+static int is_number(char *str)
 {
     if (str == NULL)
 	return 0;
@@ -2607,11 +2607,11 @@
 	    goto ex_inv_mod;
 	}
 	if (*ptr == ':') {	/*No. of clock given */
-	    if (!isnumber(ptr + 1))
+	    if (!is_number(ptr + 1))
 		goto inv_clk;
 	    i = atoi(ptr + 1);
 	} else {		/* search clock in table */
-	    if (!isnumber(ptr))
+	    if (!is_number(ptr))
 		goto inv_clk;
 	    flag = atoi(ptr);
 	    for (i = 0; i < 32; i++)
@@ -2627,45 +2627,45 @@
 	mptr->disp_cntl = 0x23;	/* Assume non interlaced */
 	/* The rest is straight forward: */
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	  inv_time:
 	    puts("mach32-config: Invalid define command, timing is invalid");
 	    goto ex_inv_mod;
 	}
 	mptr->h_disp = (atoi(ptr) >> 3) - 1;
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	i = atoi(ptr);
 	mptr->h_sync_strt = (i >> 3) - 1;
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	mptr->h_sync_wid = ((atoi(ptr) - i) >> 3);
 	if (mptr->h_sync_wid > 0x1f)
 	    mptr->h_sync_wid = 0x1f;
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	mptr->h_total = (atoi(ptr) >> 3) - 1;
 
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	mptr->v_disp = mach32_skip2(atoi(ptr) - 1);
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	i = atoi(ptr);
 	mptr->v_sync_strt = mach32_skip2(i - 1);
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	mptr->v_sync_wid = atoi(ptr) - i;
 	if (mptr->v_sync_wid > 0x1f)
 	    mptr->v_sync_wid = 0x1f;
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto inv_time;
 	mptr->v_total = mach32_skip2(atoi(ptr) - 1);
 	for (;;) {		/* Parse for additional goodies */
@@ -2701,7 +2701,7 @@
 	return ptr;
     case 3:
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	    puts("mach32-config: illegal setlinelength command.\n"
 		 "Usage: setlinelength integer modes...");
 	    return ptr;
@@ -2719,7 +2719,7 @@
 	    puts("Don't use the maxclock's commands out of the environment variable.");
 	    return ptr;
 	}
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	  ilmaxclk:
 	    puts("mach32-config: illegal maxclock16 or maxclock24 command.\n"
 		 "Usage: maxclock16 integer or maxclock24 integer");
@@ -2731,7 +2731,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto maxclk_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilmaxclk;
 	mach32_maxclk24 = atoi(ptr);
 	break;
@@ -2741,7 +2741,7 @@
 	for (i = 0; i < 16; i++) {
 	    ptr = strtok(NULL, " ");
 	    clocks_set = 1;
-	    if (!isnumber(ptr)) {
+	    if (!is_number(ptr)) {
 		puts("mach32-config: illegal clocks command.\n"
 		     "Usage: clocks integer integer ...\n"
 		     "16 clocks have to be specified.\n"
@@ -2776,7 +2776,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto maxclk_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilmaxclk;
 	mach32_maxclk8 = atoi(ptr);
 	break;
@@ -2784,7 +2784,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto maxclk_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilmaxclk;
 	mach32_maxclk32 = atoi(ptr);
 	break;
@@ -2803,7 +2803,7 @@
 	    puts("The vfifo, latch, blank commands are not allowed out of the environment.");
 	    return ptr;
 	}
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	  ilvfi:
 	    puts("Illegal vfifo command");
 	    return ptr;
@@ -2814,7 +2814,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto tweak_deny;
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	    puts("Illegal latch command");
 	    return ptr;
 	}
@@ -2824,7 +2824,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto tweak_deny;
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	    puts("Illegal blank command");
 	    return ptr;
 	}
@@ -2834,7 +2834,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto tweak_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilvfi;
 	vfifo16 = atoi(ptr) & 0xf;
 	break;
@@ -2842,7 +2842,7 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto tweak_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilvfi;
 	vfifo24 = atoi(ptr) & 0xf;
 	break;
@@ -2850,13 +2850,13 @@
 	ptr = strtok(NULL, " ");
 	if (!mode)
 	    goto tweak_deny;
-	if (!isnumber(ptr))
+	if (!is_number(ptr))
 	    goto ilvfi;
 	vfifo32 = atoi(ptr) & 0xf;
 	break;
     case 20:
 	ptr = strtok(NULL, " ");
-	if (!isnumber(ptr)) {
+	if (!is_number(ptr)) {
 	  ilsetupli:
 	    puts("Illegal setuplinear command.\n"
 		 "usage: setuplinear address size\n"
@@ -2998,7 +2998,7 @@
 	else if (!strcasecmp(ptr, "keep"))
 	    svga_clock = (-1);
 	else {
-	    if (!isnumber(ptr))
+	    if (!is_number(ptr))
 		goto invpar;
 	    i = atoi(ptr);
 	    if ((i < 0) || (i > 0x1f))
