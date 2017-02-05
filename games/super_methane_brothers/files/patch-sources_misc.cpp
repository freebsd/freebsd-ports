--- sources/misc.cpp.orig	2009-04-28 14:42:43 UTC
+++ sources/misc.cpp
@@ -40,15 +40,15 @@ static PARTYOFFS	party_08 = {SPR_ENDSPR_
 static PARTYOFFS	party_09 = {SPR_ENDSPR_1+0x09,0x0048,0x0002};
 static PARTYOFFS	party_0a = {SPR_ENDSPR_1+0x0a,0x0058,0x0002};
 static PARTYOFFS	party_0b = {SPR_ENDSPR_1+0x0b,0x0000,0x0000};
-static PARTYOFFS	party_0c = {SPR_ENDSPR_1+0x0c,0x0020,0xFFFFFFD0};
+static PARTYOFFS	party_0c = {SPR_ENDSPR_1+0x0c,0x0020,0xFFFFFD0};
 static PARTYOFFS	party_0d = {SPR_ENDSPR_1+0x0d,0x0040,0x0000};
 static PARTYOFFS	party_0e = {SPR_ENDSPR_1+0x0e,0x0000,0x0000};
-static PARTYOFFS	party_0f = {SPR_ENDSPR_1+0x0f,0x005E,0xFFFFFFF2};
-static PARTYOFFS	party_10 = {SPR_ENDSPR_1+0x10,0x007E,0xFFFFFFFA};
-static PARTYOFFS	party_11 = {SPR_ENDSPR_1+0x11,0x008E,0xFFFFFFF9};
+static PARTYOFFS	party_0f = {SPR_ENDSPR_1+0x0f,0x005E,0xFFFFFF2};
+static PARTYOFFS	party_10 = {SPR_ENDSPR_1+0x10,0x007E,0xFFFFFFA};
+static PARTYOFFS	party_11 = {SPR_ENDSPR_1+0x11,0x008E,0xFFFFFF9};
 static PARTYOFFS	party_12 = {SPR_ENDSPR_1+0x12,0x0092,0x000B};
-static PARTYOFFS	party_13 = {SPR_ENDSPR_1+0x13,0x00B2,0xFFFFFFFB};
-static PARTYOFFS	party_14 = {SPR_ENDSPR_1+0x14,0x00C2,0xFFFFFFFA};
+static PARTYOFFS	party_13 = {SPR_ENDSPR_1+0x13,0x00B2,0xFFFFFFB};
+static PARTYOFFS	party_14 = {SPR_ENDSPR_1+0x14,0x00C2,0xFFFFFFA};
 static PARTYOFFS	party_15 = {SPR_ENDSPR_1+0x15,0x0000,0x0000};
 static PARTYOFFS	party_16 = {SPR_ENDSPR_1+0x16,0x0020,0x0008};
 static PARTYOFFS	party_17 = {SPR_ENDSPR_1+0x17,0x0020,0x0000};
@@ -57,7 +57,7 @@ static PARTYOFFS	party_19 = {SPR_ENDSPR_
 static PARTYOFFS	party_1a = {SPR_ENDSPR_1+0x1a,0x0020,0x0000};
 static PARTYOFFS	party_1b = {SPR_ENDSPR_1+0x1b,0x0000,0x0010};
 static PARTYOFFS	party_1c = {SPR_ENDSPR_1+0x1c,0x0010,0x0};
-static PARTYOFFS	party_1d = {SPR_ENDSPR_1+0x1d,0x0030,0xFFFFFFF0};
+static PARTYOFFS	party_1d = {SPR_ENDSPR_1+0x1d,0x0030,0xFFFFFF0};
 
 static PARTYOFFS	*party_group1[] = {
 	&party_00,&party_01,&party_02,&party_00,&party_03,&party_04,0};
