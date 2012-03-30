--- ./rtengine/CA_correct_RT.cc.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/CA_correct_RT.cc	2012-03-30 13:23:58.000000000 +0400
@@ -467,7 +467,7 @@
 					gdiff=0.3125*(rgb[indx+TS][1]-rgb[indx-TS][1])+0.09375*(rgb[indx+TS+1][1]-rgb[indx-TS+1][1]+rgb[indx+TS-1][1]-rgb[indx-TS-1][1]);
 					deltgrb=(rgb[indx][c]-rgb[indx][1])-0.5*((rgb[indx-v4][c]-rgb[indx-v4][1])+(rgb[indx+v4][c]-rgb[indx+v4][1]));
 					
-					gradwt=fabs(0.25*rbhpfv[indx]+0.125*(rbhpfv[indx+2]+rbhpfv[indx-2]) );//*(grblpfv[indx-v2]+grblpfv[indx+v2])/(eps+0.1*grblpfv[indx-v2]+rblpfv[indx-v2]+0.1*grblpfv[indx+v2]+rblpfv[indx+v2]);
+					gradwt=fabs(0.25*rbhpfv[indx]+0.125*(rbhpfv[indx+2]+rbhpfv[indx-2]) );// *(grblpfv[indx-v2]+grblpfv[indx+v2])/(eps+0.1*grblpfv[indx-v2]+rblpfv[indx-v2]+0.1*grblpfv[indx+v2]+rblpfv[indx+v2]);
 					if (gradwt>eps) {
 					coeff[0][0][c] += gradwt*deltgrb*deltgrb;
 					coeff[0][1][c] += gradwt*gdiff*deltgrb;
@@ -479,7 +479,7 @@
 					gdiff=0.3125*(rgb[indx+1][1]-rgb[indx-1][1])+0.09375*(rgb[indx+1+TS][1]-rgb[indx-1+TS][1]+rgb[indx+1-TS][1]-rgb[indx-1-TS][1]);
 					deltgrb=(rgb[indx][c]-rgb[indx][1])-0.5*((rgb[indx-4][c]-rgb[indx-4][1])+(rgb[indx+4][c]-rgb[indx+4][1]));
 					
-					gradwt=fabs(0.25*rbhpfh[indx]+0.125*(rbhpfh[indx+v2]+rbhpfh[indx-v2]) );//*(grblpfh[indx-2]+grblpfh[indx+2])/(eps+0.1*grblpfh[indx-2]+rblpfh[indx-2]+0.1*grblpfh[indx+2]+rblpfh[indx+2]);
+					gradwt=fabs(0.25*rbhpfh[indx]+0.125*(rbhpfh[indx+v2]+rbhpfh[indx-v2]) );// *(grblpfh[indx-2]+grblpfh[indx+2])/(eps+0.1*grblpfh[indx-2]+rblpfh[indx-2]+0.1*grblpfh[indx+2]+rblpfh[indx+2]);
 					if (gradwt>eps) {
 					coeff[1][0][c] += gradwt*deltgrb*deltgrb;
 					coeff[1][1][c] += gradwt*gdiff*deltgrb;
