--- src/drivers/sexyal/convert.inc.orig	Mon Apr 19 07:27:01 2004
+++ src/drivers/sexyal/convert.inc	Mon May 17 22:08:07 2004
@@ -1,5 +1,7 @@
 void SexiALI_Convert(SexyAL_format *srcformat, SexyAL_format *destformat, void *vdest, void *vsrc, uint32_t frames)
 {
+ int32_t tmp, tmp2;
+
 if(srcformat->sampformat == SEXYAL_FMT_PCMS8)
 {
 int8_t* src=vsrc;
@@ -16,7 +18,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -26,7 +28,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -40,7 +42,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -51,7 +53,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -69,7 +71,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -81,7 +83,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -97,7 +99,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -110,7 +112,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -133,9 +135,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -146,9 +148,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -163,10 +165,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -178,10 +180,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -200,9 +202,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -214,9 +216,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -233,10 +235,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -249,10 +251,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -280,7 +282,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  *dest=tmp;
@@ -291,7 +293,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
 FLIP32(tmp);
@@ -306,7 +308,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -318,7 +320,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -337,7 +339,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  *dest=tmp;
@@ -350,7 +352,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
 FLIP32(tmp);
@@ -367,7 +369,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -381,7 +383,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -405,9 +407,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp2+=128;
@@ -420,9 +422,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp2+=128;
@@ -439,10 +441,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -456,10 +458,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -480,9 +482,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp2+=128;
@@ -496,9 +498,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp2+=128;
@@ -517,10 +519,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -535,10 +537,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -568,7 +570,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -579,7 +581,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -594,7 +596,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -606,7 +608,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -625,7 +627,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -638,7 +640,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -655,7 +657,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -669,7 +671,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -693,9 +695,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -708,9 +710,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -727,10 +729,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -744,10 +746,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -768,9 +770,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -784,9 +786,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -805,10 +807,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -823,10 +825,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -856,7 +858,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -868,7 +870,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -884,7 +886,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -897,7 +899,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -917,7 +919,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -931,7 +933,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -949,7 +951,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -964,7 +966,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -989,9 +991,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1006,9 +1008,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1027,10 +1029,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1046,10 +1048,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1072,9 +1074,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1090,9 +1092,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1113,10 +1115,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1133,10 +1135,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1168,7 +1170,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -1179,7 +1181,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -1194,7 +1196,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -1206,7 +1208,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -1225,7 +1227,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -1238,7 +1240,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -1255,7 +1257,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -1269,7 +1271,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -1293,9 +1295,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -1308,9 +1310,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -1327,10 +1329,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -1344,10 +1346,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -1368,9 +1370,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -1384,9 +1386,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -1405,10 +1407,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -1423,10 +1425,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -1456,7 +1458,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1468,7 +1470,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1484,7 +1486,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -1497,7 +1499,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -1517,7 +1519,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1531,7 +1533,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1549,7 +1551,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -1564,7 +1566,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -1589,9 +1591,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1606,9 +1608,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1627,10 +1629,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1646,10 +1648,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1672,9 +1674,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1690,9 +1692,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 8;
@@ -1713,10 +1715,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1733,10 +1735,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -1768,7 +1770,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
  *dest=tmp;
@@ -1779,7 +1781,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
 FLIP32(tmp);
@@ -1794,7 +1796,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -1806,7 +1808,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -1825,7 +1827,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
  *dest=tmp;
@@ -1838,7 +1840,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
 FLIP32(tmp);
@@ -1855,7 +1857,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -1869,7 +1871,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -1893,9 +1895,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -1908,9 +1910,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -1927,10 +1929,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -1944,10 +1946,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -1968,9 +1970,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -1984,9 +1986,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -2005,10 +2007,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -2023,10 +2025,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -2056,7 +2058,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2068,7 +2070,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2084,7 +2086,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -2097,7 +2099,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -2117,7 +2119,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2131,7 +2133,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2149,7 +2151,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -2164,7 +2166,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=128;
@@ -2189,9 +2191,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2206,9 +2208,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2227,10 +2229,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -2246,10 +2248,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -2272,9 +2274,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2290,9 +2292,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=128;
  tmp <<= 16;
@@ -2313,10 +2315,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -2333,10 +2335,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=128;
@@ -2372,7 +2374,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  *dest=tmp;
@@ -2383,7 +2385,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
 FLIP32(tmp);
@@ -2398,7 +2400,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2410,7 +2412,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2429,7 +2431,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  *dest=tmp;
@@ -2442,7 +2444,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
 FLIP32(tmp);
@@ -2459,7 +2461,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2473,7 +2475,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2497,9 +2499,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp2-=128;
@@ -2512,9 +2514,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp2-=128;
@@ -2531,10 +2533,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -2548,10 +2550,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -2572,9 +2574,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp2-=128;
@@ -2588,9 +2590,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp2-=128;
@@ -2609,10 +2611,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -2627,10 +2629,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -2660,7 +2662,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -2670,7 +2672,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -2684,7 +2686,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -2695,7 +2697,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -2713,7 +2715,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -2725,7 +2727,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -2741,7 +2743,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -2754,7 +2756,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -2777,9 +2779,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -2790,9 +2792,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -2807,10 +2809,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -2822,10 +2824,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -2844,9 +2846,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -2858,9 +2860,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -2877,10 +2879,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -2893,10 +2895,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -2924,7 +2926,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -2936,7 +2938,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -2952,7 +2954,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2965,7 +2967,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -2985,7 +2987,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -2999,7 +3001,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3017,7 +3019,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3032,7 +3034,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3057,9 +3059,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3074,9 +3076,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3095,10 +3097,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3114,10 +3116,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3140,9 +3142,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3158,9 +3160,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3181,10 +3183,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3201,10 +3203,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3236,7 +3238,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -3247,7 +3249,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -3262,7 +3264,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3274,7 +3276,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3293,7 +3295,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -3306,7 +3308,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -3323,7 +3325,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3337,7 +3339,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3361,9 +3363,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3376,9 +3378,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3395,10 +3397,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -3412,10 +3414,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -3436,9 +3438,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3452,9 +3454,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3473,10 +3475,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -3491,10 +3493,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -3524,7 +3526,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3536,7 +3538,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3552,7 +3554,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3565,7 +3567,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3585,7 +3587,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3599,7 +3601,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3617,7 +3619,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3632,7 +3634,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -3657,9 +3659,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3674,9 +3676,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3695,10 +3697,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3714,10 +3716,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3740,9 +3742,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3758,9 +3760,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 8;
@@ -3781,10 +3783,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3801,10 +3803,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -3836,7 +3838,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -3847,7 +3849,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -3862,7 +3864,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3874,7 +3876,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3893,7 +3895,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -3906,7 +3908,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -3923,7 +3925,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3937,7 +3939,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -3961,9 +3963,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3976,9 +3978,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -3995,10 +3997,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -4012,10 +4014,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -4036,9 +4038,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -4052,9 +4054,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -4073,10 +4075,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -4091,10 +4093,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -4124,7 +4126,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4136,7 +4138,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4152,7 +4154,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -4165,7 +4167,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -4185,7 +4187,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4199,7 +4201,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4217,7 +4219,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -4232,7 +4234,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=128;
@@ -4257,9 +4259,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4274,9 +4276,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4295,10 +4297,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -4314,10 +4316,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -4340,9 +4342,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4358,9 +4360,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=128;
  tmp <<= 16;
@@ -4381,10 +4383,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -4401,10 +4403,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=128;
@@ -4436,7 +4438,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
  *dest=tmp;
@@ -4447,7 +4449,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
 FLIP32(tmp);
@@ -4462,7 +4464,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -4474,7 +4476,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -4493,7 +4495,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
  *dest=tmp;
@@ -4506,7 +4508,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 16;
 FLIP32(tmp);
@@ -4523,7 +4525,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -4537,7 +4539,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 16;
@@ -4561,9 +4563,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -4576,9 +4578,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -4595,10 +4597,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -4612,10 +4614,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -4636,9 +4638,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -4652,9 +4654,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 16;
  tmp2 <<= 16;
@@ -4673,10 +4675,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -4691,10 +4693,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 16;
@@ -4728,7 +4730,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -4739,7 +4741,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP16(tmp);
@@ -4754,7 +4756,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -4766,7 +4768,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -4785,7 +4787,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -4798,7 +4800,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP16(tmp);
@@ -4815,7 +4817,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -4829,7 +4831,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -4853,9 +4855,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -4868,9 +4870,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -4887,10 +4889,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -4904,10 +4906,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -4928,9 +4930,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -4944,9 +4946,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -4965,10 +4967,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -4983,10 +4985,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -5016,7 +5018,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5028,7 +5030,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5044,7 +5046,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5057,7 +5059,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5077,7 +5079,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5091,7 +5093,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5109,7 +5111,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5124,7 +5126,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5149,9 +5151,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5166,9 +5168,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5187,10 +5189,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5206,10 +5208,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5232,9 +5234,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5250,9 +5252,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -5273,10 +5275,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5293,10 +5295,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5328,7 +5330,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -5338,7 +5340,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -5352,7 +5354,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -5363,7 +5365,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp);
@@ -5381,7 +5383,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -5393,7 +5395,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -5409,7 +5411,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -5422,7 +5424,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp);
@@ -5445,9 +5447,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -5458,9 +5460,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -5475,10 +5477,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -5490,10 +5492,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 FLIP16(tmp);
@@ -5512,9 +5514,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -5526,9 +5528,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp2);
@@ -5545,10 +5547,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  *dest=tmp;
@@ -5561,10 +5563,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 FLIP16(tmp);
@@ -5592,7 +5594,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  *dest=tmp;
@@ -5603,7 +5605,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
 FLIP16(tmp);
@@ -5618,7 +5620,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5630,7 +5632,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5649,7 +5651,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  *dest=tmp;
@@ -5662,7 +5664,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
 FLIP16(tmp);
@@ -5679,7 +5681,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5693,7 +5695,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -5717,9 +5719,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -5732,9 +5734,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -5751,10 +5753,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5768,10 +5770,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5792,9 +5794,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -5808,9 +5810,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -5829,10 +5831,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5847,10 +5849,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -5880,7 +5882,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -5891,7 +5893,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP16(tmp);
@@ -5906,7 +5908,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -5918,7 +5920,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -5937,7 +5939,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -5950,7 +5952,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP16(tmp);
@@ -5967,7 +5969,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -5981,7 +5983,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -6005,9 +6007,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -6020,9 +6022,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -6039,10 +6041,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -6056,10 +6058,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -6080,9 +6082,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -6096,9 +6098,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -6117,10 +6119,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -6135,10 +6137,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -6168,7 +6170,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6180,7 +6182,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6196,7 +6198,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6209,7 +6211,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6229,7 +6231,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6243,7 +6245,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6261,7 +6263,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6276,7 +6278,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6301,9 +6303,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6318,9 +6320,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6339,10 +6341,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6358,10 +6360,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6384,9 +6386,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6402,9 +6404,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -6425,10 +6427,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6445,10 +6447,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6480,7 +6482,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -6491,7 +6493,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP16(tmp);
@@ -6506,7 +6508,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -6518,7 +6520,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -6537,7 +6539,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -6550,7 +6552,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP16(tmp);
@@ -6567,7 +6569,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -6581,7 +6583,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -6605,9 +6607,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -6620,9 +6622,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -6639,10 +6641,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -6656,10 +6658,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -6680,9 +6682,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -6696,9 +6698,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -6717,10 +6719,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -6735,10 +6737,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -6768,7 +6770,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6780,7 +6782,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6796,7 +6798,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6809,7 +6811,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6829,7 +6831,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6843,7 +6845,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6861,7 +6863,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6876,7 +6878,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp+=32768;
@@ -6901,9 +6903,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6918,9 +6920,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -6939,10 +6941,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6958,10 +6960,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -6984,9 +6986,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -7002,9 +7004,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -7025,10 +7027,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -7045,10 +7047,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp+=32768;
@@ -7084,7 +7086,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7096,7 +7098,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7112,7 +7114,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7125,7 +7127,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7145,7 +7147,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7159,7 +7161,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7177,7 +7179,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7192,7 +7194,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7217,9 +7219,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7234,9 +7236,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7255,10 +7257,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7274,10 +7276,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7300,9 +7302,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7318,9 +7320,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -7341,10 +7343,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7361,10 +7363,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7396,7 +7398,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -7407,7 +7409,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP16(tmp);
@@ -7422,7 +7424,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -7434,7 +7436,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -7453,7 +7455,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -7466,7 +7468,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP16(tmp);
@@ -7483,7 +7485,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -7497,7 +7499,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp >>= 8;
@@ -7521,9 +7523,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -7536,9 +7538,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -7555,10 +7557,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -7572,10 +7574,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -7596,9 +7598,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -7612,9 +7614,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -7633,10 +7635,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -7651,10 +7653,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp >>= 8;
@@ -7684,7 +7686,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  *dest=tmp;
@@ -7695,7 +7697,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
 FLIP16(tmp);
@@ -7710,7 +7712,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7722,7 +7724,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7741,7 +7743,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  *dest=tmp;
@@ -7754,7 +7756,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
 FLIP16(tmp);
@@ -7771,7 +7773,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7785,7 +7787,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -7809,9 +7811,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -7824,9 +7826,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -7843,10 +7845,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7860,10 +7862,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7884,9 +7886,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -7900,9 +7902,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -7921,10 +7923,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7939,10 +7941,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -7972,7 +7974,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -7982,7 +7984,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -7996,7 +7998,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -8007,7 +8009,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp);
@@ -8025,7 +8027,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -8037,7 +8039,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -8053,7 +8055,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  *dest=tmp;
@@ -8066,7 +8068,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp);
@@ -8089,9 +8091,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -8102,9 +8104,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -8119,10 +8121,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -8134,10 +8136,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 FLIP16(tmp);
@@ -8156,9 +8158,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -8170,9 +8172,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp);
 FLIP16(tmp2);
@@ -8189,10 +8191,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  *dest=tmp;
@@ -8205,10 +8207,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
 FLIP16(tmp);
@@ -8236,7 +8238,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8248,7 +8250,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8264,7 +8266,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8277,7 +8279,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8297,7 +8299,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8311,7 +8313,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8329,7 +8331,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8344,7 +8346,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8369,9 +8371,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8386,9 +8388,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8407,10 +8409,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -8426,10 +8428,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -8452,9 +8454,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8470,9 +8472,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -8493,10 +8495,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -8513,10 +8515,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -8548,7 +8550,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -8559,7 +8561,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP16(tmp);
@@ -8574,7 +8576,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -8586,7 +8588,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -8605,7 +8607,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -8618,7 +8620,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP16(tmp);
@@ -8635,7 +8637,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -8649,7 +8651,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 0;
@@ -8673,9 +8675,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -8688,9 +8690,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -8707,10 +8709,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -8724,10 +8726,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -8748,9 +8750,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -8764,9 +8766,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -8785,10 +8787,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -8803,10 +8805,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 0;
@@ -8836,7 +8838,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -8848,7 +8850,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -8864,7 +8866,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8877,7 +8879,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8897,7 +8899,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -8911,7 +8913,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -8929,7 +8931,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8944,7 +8946,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp-=32768;
@@ -8969,9 +8971,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -8986,9 +8988,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -9007,10 +9009,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -9026,10 +9028,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -9052,9 +9054,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -9070,9 +9072,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -9093,10 +9095,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -9113,10 +9115,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp-=32768;
@@ -9148,7 +9150,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -9159,7 +9161,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP16(tmp);
@@ -9174,7 +9176,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -9186,7 +9188,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -9205,7 +9207,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -9218,7 +9220,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP16(tmp);
@@ -9235,7 +9237,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -9249,7 +9251,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
  tmp <<= 8;
@@ -9273,9 +9275,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -9288,9 +9290,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -9307,10 +9309,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -9324,10 +9326,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -9348,9 +9350,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -9364,9 +9366,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -9385,10 +9387,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -9403,10 +9405,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP16(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP16(tmp2);
  tmp <<= 8;
@@ -9440,7 +9442,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -9451,7 +9453,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -9466,7 +9468,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -9478,7 +9480,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -9497,7 +9499,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -9510,7 +9512,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -9527,7 +9529,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -9541,7 +9543,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -9565,9 +9567,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -9580,9 +9582,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -9599,10 +9601,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -9616,10 +9618,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -9640,9 +9642,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -9656,9 +9658,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -9677,10 +9679,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -9695,10 +9697,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -9728,7 +9730,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9740,7 +9742,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9756,7 +9758,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -9769,7 +9771,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -9789,7 +9791,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9803,7 +9805,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9821,7 +9823,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -9836,7 +9838,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -9861,9 +9863,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9878,9 +9880,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9899,10 +9901,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -9918,10 +9920,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -9944,9 +9946,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9962,9 +9964,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp >>= 8;
@@ -9985,10 +9987,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10005,10 +10007,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10040,7 +10042,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -10051,7 +10053,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP32(tmp);
@@ -10066,7 +10068,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -10078,7 +10080,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -10097,7 +10099,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -10110,7 +10112,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP32(tmp);
@@ -10127,7 +10129,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -10141,7 +10143,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -10165,9 +10167,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -10180,9 +10182,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -10199,10 +10201,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -10216,10 +10218,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -10240,9 +10242,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -10256,9 +10258,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -10277,10 +10279,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -10295,10 +10297,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -10328,7 +10330,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10340,7 +10342,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10356,7 +10358,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10369,7 +10371,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10389,7 +10391,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10403,7 +10405,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10421,7 +10423,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10436,7 +10438,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10461,9 +10463,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10478,9 +10480,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10499,10 +10501,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10518,10 +10520,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10544,9 +10546,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10562,9 +10564,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 0;
@@ -10585,10 +10587,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10605,10 +10607,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -10640,7 +10642,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -10650,7 +10652,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -10664,7 +10666,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -10675,7 +10677,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -10693,7 +10695,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -10705,7 +10707,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -10721,7 +10723,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -10734,7 +10736,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -10757,9 +10759,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -10770,9 +10772,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -10787,10 +10789,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -10802,10 +10804,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -10824,9 +10826,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -10838,9 +10840,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -10857,10 +10859,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -10873,10 +10875,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -10904,7 +10906,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  *dest=tmp;
@@ -10915,7 +10917,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
 FLIP32(tmp);
@@ -10930,7 +10932,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10942,7 +10944,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -10961,7 +10963,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  *dest=tmp;
@@ -10974,7 +10976,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
 FLIP32(tmp);
@@ -10991,7 +10993,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11005,7 +11007,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11029,9 +11031,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -11044,9 +11046,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -11063,10 +11065,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11080,10 +11082,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11104,9 +11106,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -11120,9 +11122,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp2+=32768;
@@ -11141,10 +11143,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11159,10 +11161,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11192,7 +11194,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -11203,7 +11205,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -11218,7 +11220,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -11230,7 +11232,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -11249,7 +11251,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -11262,7 +11264,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -11279,7 +11281,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -11293,7 +11295,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -11317,9 +11319,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -11332,9 +11334,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -11351,10 +11353,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -11368,10 +11370,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -11392,9 +11394,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -11408,9 +11410,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -11429,10 +11431,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -11447,10 +11449,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -11480,7 +11482,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11492,7 +11494,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11508,7 +11510,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11521,7 +11523,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11541,7 +11543,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11555,7 +11557,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11573,7 +11575,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11588,7 +11590,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=32768;
@@ -11613,9 +11615,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11630,9 +11632,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11651,10 +11653,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11670,10 +11672,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11696,9 +11698,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11714,9 +11716,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=32768;
  tmp <<= 8;
@@ -11737,10 +11739,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11757,10 +11759,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=32768;
@@ -11796,7 +11798,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11808,7 +11810,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11824,7 +11826,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -11837,7 +11839,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -11857,7 +11859,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11871,7 +11873,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11889,7 +11891,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -11904,7 +11906,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -11929,9 +11931,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11946,9 +11948,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -11967,10 +11969,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -11986,10 +11988,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12012,9 +12014,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -12030,9 +12032,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp >>= 8;
@@ -12053,10 +12055,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12073,10 +12075,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12108,7 +12110,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -12119,7 +12121,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -12134,7 +12136,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -12146,7 +12148,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -12165,7 +12167,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -12178,7 +12180,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -12195,7 +12197,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -12209,7 +12211,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -12233,9 +12235,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -12248,9 +12250,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -12267,10 +12269,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -12284,10 +12286,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -12308,9 +12310,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -12324,9 +12326,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -12345,10 +12347,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -12363,10 +12365,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -12396,7 +12398,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12408,7 +12410,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12424,7 +12426,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -12437,7 +12439,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -12457,7 +12459,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12471,7 +12473,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12489,7 +12491,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -12504,7 +12506,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -12529,9 +12531,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12546,9 +12548,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12567,10 +12569,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12586,10 +12588,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12612,9 +12614,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12630,9 +12632,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 0;
@@ -12653,10 +12655,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12673,10 +12675,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -12708,7 +12710,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -12719,7 +12721,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP32(tmp);
@@ -12734,7 +12736,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -12746,7 +12748,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -12765,7 +12767,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
  *dest=tmp;
@@ -12778,7 +12780,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 0;
 FLIP32(tmp);
@@ -12795,7 +12797,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -12809,7 +12811,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 0;
@@ -12833,9 +12835,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -12848,9 +12850,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -12867,10 +12869,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -12884,10 +12886,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -12908,9 +12910,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -12924,9 +12926,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 0;
  tmp2 <<= 0;
@@ -12945,10 +12947,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -12963,10 +12965,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 0;
@@ -12996,7 +12998,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  *dest=tmp;
@@ -13007,7 +13009,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
 FLIP32(tmp);
@@ -13022,7 +13024,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13034,7 +13036,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13053,7 +13055,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  *dest=tmp;
@@ -13066,7 +13068,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
 FLIP32(tmp);
@@ -13083,7 +13085,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13097,7 +13099,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13121,9 +13123,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -13136,9 +13138,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -13155,10 +13157,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13172,10 +13174,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13196,9 +13198,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -13212,9 +13214,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp2-=32768;
@@ -13233,10 +13235,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13251,10 +13253,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13284,7 +13286,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -13294,7 +13296,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -13308,7 +13310,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -13319,7 +13321,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -13337,7 +13339,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -13349,7 +13351,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -13365,7 +13367,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -13378,7 +13380,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -13401,9 +13403,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -13414,9 +13416,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -13431,10 +13433,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -13446,10 +13448,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -13468,9 +13470,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -13482,9 +13484,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -13501,10 +13503,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -13517,10 +13519,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -13548,7 +13550,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13560,7 +13562,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13576,7 +13578,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13589,7 +13591,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13609,7 +13611,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13623,7 +13625,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13641,7 +13643,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13656,7 +13658,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=32768;
@@ -13681,9 +13683,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13698,9 +13700,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13719,10 +13721,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13738,10 +13740,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13764,9 +13766,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13782,9 +13784,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=32768;
  tmp <<= 8;
@@ -13805,10 +13807,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13825,10 +13827,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=32768;
@@ -13860,7 +13862,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -13871,7 +13873,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -13886,7 +13888,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -13898,7 +13900,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -13917,7 +13919,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
  *dest=tmp;
@@ -13930,7 +13932,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp <<= 8;
 FLIP32(tmp);
@@ -13947,7 +13949,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -13961,7 +13963,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp <<= 8;
@@ -13985,9 +13987,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -14000,9 +14002,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -14019,10 +14021,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -14036,10 +14038,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -14060,9 +14062,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -14076,9 +14078,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp <<= 8;
  tmp2 <<= 8;
@@ -14097,10 +14099,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -14115,10 +14117,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp <<= 8;
@@ -14152,7 +14154,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
  *dest=tmp;
@@ -14163,7 +14165,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
 FLIP32(tmp);
@@ -14178,7 +14180,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -14190,7 +14192,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -14209,7 +14211,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
  *dest=tmp;
@@ -14222,7 +14224,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
 FLIP32(tmp);
@@ -14239,7 +14241,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -14253,7 +14255,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -14277,9 +14279,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -14292,9 +14294,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -14311,10 +14313,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -14328,10 +14330,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -14352,9 +14354,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -14368,9 +14370,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -14389,10 +14391,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -14407,10 +14409,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -14440,7 +14442,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14452,7 +14454,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14468,7 +14470,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -14481,7 +14483,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -14501,7 +14503,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14515,7 +14517,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14533,7 +14535,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -14548,7 +14550,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -14573,9 +14575,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14590,9 +14592,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14611,10 +14613,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -14630,10 +14632,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -14656,9 +14658,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14674,9 +14676,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 16;
@@ -14697,10 +14699,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -14717,10 +14719,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -14752,7 +14754,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -14763,7 +14765,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -14778,7 +14780,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -14790,7 +14792,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -14809,7 +14811,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -14822,7 +14824,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -14839,7 +14841,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -14853,7 +14855,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -14877,9 +14879,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -14892,9 +14894,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -14911,10 +14913,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -14928,10 +14930,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -14952,9 +14954,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -14968,9 +14970,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -14989,10 +14991,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15007,10 +15009,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15040,7 +15042,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15052,7 +15054,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15068,7 +15070,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15081,7 +15083,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15101,7 +15103,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15115,7 +15117,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15133,7 +15135,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15148,7 +15150,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15173,9 +15175,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15190,9 +15192,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15211,10 +15213,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15230,10 +15232,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15256,9 +15258,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15274,9 +15276,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15297,10 +15299,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15317,10 +15319,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15352,7 +15354,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -15363,7 +15365,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -15378,7 +15380,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -15390,7 +15392,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -15409,7 +15411,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -15422,7 +15424,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -15439,7 +15441,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -15453,7 +15455,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -15477,9 +15479,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -15492,9 +15494,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -15511,10 +15513,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15528,10 +15530,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15552,9 +15554,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -15568,9 +15570,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -15589,10 +15591,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15607,10 +15609,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -15640,7 +15642,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15652,7 +15654,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15668,7 +15670,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15681,7 +15683,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15701,7 +15703,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15715,7 +15717,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15733,7 +15735,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15748,7 +15750,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -15773,9 +15775,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15790,9 +15792,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15811,10 +15813,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15830,10 +15832,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15856,9 +15858,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15874,9 +15876,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp >>= 8;
@@ -15897,10 +15899,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15917,10 +15919,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -15952,7 +15954,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -15962,7 +15964,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -15976,7 +15978,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -15987,7 +15989,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -16005,7 +16007,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -16017,7 +16019,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -16033,7 +16035,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -16046,7 +16048,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -16069,9 +16071,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -16082,9 +16084,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -16099,10 +16101,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -16114,10 +16116,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -16136,9 +16138,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -16150,9 +16152,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -16169,10 +16171,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -16185,10 +16187,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -16216,7 +16218,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  *dest=tmp;
@@ -16227,7 +16229,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
 FLIP32(tmp);
@@ -16242,7 +16244,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -16254,7 +16256,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -16273,7 +16275,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
  *dest=tmp;
@@ -16286,7 +16288,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp+=(1<<23);
 FLIP32(tmp);
@@ -16303,7 +16305,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -16317,7 +16319,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp+=(1<<23);
@@ -16341,9 +16343,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp2+=(1<<23);
@@ -16356,9 +16358,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp2+=(1<<23);
@@ -16375,10 +16377,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -16392,10 +16394,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -16416,9 +16418,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp2+=(1<<23);
@@ -16432,9 +16434,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp+=(1<<23);
  tmp2+=(1<<23);
@@ -16453,10 +16455,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -16471,10 +16473,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp+=(1<<23);
@@ -16508,7 +16510,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16520,7 +16522,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16536,7 +16538,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -16549,7 +16551,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -16569,7 +16571,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16583,7 +16585,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16601,7 +16603,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -16616,7 +16618,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -16641,9 +16643,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16658,9 +16660,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16679,10 +16681,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -16698,10 +16700,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -16724,9 +16726,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16742,9 +16744,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 16;
@@ -16765,10 +16767,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -16785,10 +16787,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -16820,7 +16822,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
  *dest=tmp;
@@ -16831,7 +16833,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
 FLIP32(tmp);
@@ -16846,7 +16848,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -16858,7 +16860,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -16877,7 +16879,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
  *dest=tmp;
@@ -16890,7 +16892,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 16;
 FLIP32(tmp);
@@ -16907,7 +16909,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -16921,7 +16923,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 16;
@@ -16945,9 +16947,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -16960,9 +16962,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -16979,10 +16981,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -16996,10 +16998,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -17020,9 +17022,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -17036,9 +17038,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 16;
  tmp2 >>= 16;
@@ -17057,10 +17059,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -17075,10 +17077,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 16;
@@ -17108,7 +17110,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17120,7 +17122,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17136,7 +17138,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17149,7 +17151,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17169,7 +17171,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17183,7 +17185,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17201,7 +17203,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17216,7 +17218,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17241,9 +17243,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17258,9 +17260,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17279,10 +17281,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17298,10 +17300,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17324,9 +17326,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17342,9 +17344,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17365,10 +17367,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17385,10 +17387,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17420,7 +17422,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -17431,7 +17433,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -17446,7 +17448,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -17458,7 +17460,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -17477,7 +17479,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -17490,7 +17492,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -17507,7 +17509,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -17521,7 +17523,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -17545,9 +17547,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -17560,9 +17562,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -17579,10 +17581,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -17596,10 +17598,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -17620,9 +17622,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -17636,9 +17638,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -17657,10 +17659,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -17675,10 +17677,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -17708,7 +17710,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17720,7 +17722,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17736,7 +17738,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17749,7 +17751,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17769,7 +17771,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17783,7 +17785,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17801,7 +17803,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17816,7 +17818,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -17841,9 +17843,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17858,9 +17860,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17879,10 +17881,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17898,10 +17900,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17924,9 +17926,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17942,9 +17944,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp >>= 8;
@@ -17965,10 +17967,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -17985,10 +17987,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -18020,7 +18022,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -18031,7 +18033,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -18046,7 +18048,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -18058,7 +18060,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -18077,7 +18079,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
  *dest=tmp;
@@ -18090,7 +18092,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp >>= 8;
 FLIP32(tmp);
@@ -18107,7 +18109,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -18121,7 +18123,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp >>= 8;
@@ -18145,9 +18147,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -18160,9 +18162,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -18179,10 +18181,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -18196,10 +18198,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -18220,9 +18222,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -18236,9 +18238,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp >>= 8;
  tmp2 >>= 8;
@@ -18257,10 +18259,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -18275,10 +18277,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp >>= 8;
@@ -18308,7 +18310,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  *dest=tmp;
@@ -18319,7 +18321,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
 FLIP32(tmp);
@@ -18334,7 +18336,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -18346,7 +18348,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -18365,7 +18367,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
  *dest=tmp;
@@ -18378,7 +18380,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  tmp-=(1<<23);
 FLIP32(tmp);
@@ -18395,7 +18397,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -18409,7 +18411,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  tmp-=(1<<23);
@@ -18433,9 +18435,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp2-=(1<<23);
@@ -18448,9 +18450,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp2-=(1<<23);
@@ -18467,10 +18469,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -18484,10 +18486,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -18508,9 +18510,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp2-=(1<<23);
@@ -18524,9 +18526,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  tmp-=(1<<23);
  tmp2-=(1<<23);
@@ -18545,10 +18547,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -18563,10 +18565,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  tmp-=(1<<23);
@@ -18596,7 +18598,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -18606,7 +18608,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -18620,7 +18622,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -18631,7 +18633,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -18649,7 +18651,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -18661,7 +18663,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -18677,7 +18679,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
  *dest=tmp;
@@ -18690,7 +18692,7 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp);
@@ -18713,9 +18715,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 tmp = (tmp+tmp2)>>1;
  *dest=tmp;
@@ -18726,9 +18728,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 tmp = (tmp+tmp2)>>1;
@@ -18743,10 +18745,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 tmp = (tmp+tmp2)>>1;
@@ -18758,10 +18760,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
@@ -18780,9 +18782,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
  *dest=tmp;
  dest++;
@@ -18794,9 +18796,9 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp);
 FLIP32(tmp2);
@@ -18813,10 +18815,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
  *dest=tmp;
@@ -18829,10 +18831,10 @@
 {
 while(frames--)
 {
- int32_t tmp=*src;
+ tmp=*src;
  src++;
 FLIP32(tmp);
- int32_t tmp2=*src;
+ tmp2=*src;
  src++;
 FLIP32(tmp2);
 FLIP32(tmp);
