--- cwdetect.c.orig	2014-11-04 10:25:00 UTC
+++ cwdetect.c
@@ -1857,7 +1857,8 @@ int region, region_flag;
 int i,j,k,ia,ib,ja,jb;
 int ka,kb,k1,k2,k3;
 int mix2_mask, sizhalf, carrfilter_pts;
-float amp,t1,t2,t3,r1,r2;
+//float amp,t1,t2,t3,r1,r2;
+float amp,t1,t2,t3,r2;
 double dt1, dt2, dt3;
 sizhalf=mix2.size>>1;
 mix2_mask=mix2.size-1;
@@ -2250,7 +2251,7 @@ new_carrier:;    
   if(i>sizhalf)i-=mix2.size;
   if(abs(i) > k3)goto fail;
   i=k1;
-  r1=0;
+  //  r1=0;
   r2=0;
   while(i!=k2)
     {
@@ -2258,7 +2259,7 @@ new_carrier:;    
     if(k>sizhalf)k=mix2.size-k;
     if(k<k3)
       {
-      r1+=mix2_pwr[i];
+	//      r1+=mix2_pwr[i];
       }
     else
       {
@@ -2266,7 +2267,7 @@ new_carrier:;    
       }
     i=(i+1)&mix2_mask;
     }
-  r1/=ia;  
+  //  r1/=ia;  
   r2/=ib;
   ia=(j-k3+mix2.size)&mix2_mask;
   ib=(j+k3)&mix2_mask;
@@ -3998,7 +3999,8 @@ void improve_cwspeed(void)
 int i, k, n, dashno;
 int repeat_flag;
 float r1, r3, t1, t2, t3;
-double s_sum, n_sum;
+//double s_sum;
+//, n_sum;
 STONDATA *stondt;
 stondt=(STONDATA*)(fftn_tmp);
 // Collect the average waveform again.
@@ -4016,8 +4018,8 @@ check_cw(2003,1);
 if(kill_all_flag)return;
 dashno=0;
 t3=0;
-s_sum=0;
-n_sum=0;
+//s_sum=0;
+//n_sum=0;
 check_cw(22001,1);
 if(kill_all_flag)return;
 while(cw_ptr<no_of_cwdat)
@@ -4052,8 +4054,8 @@ if(kill_all_flag)return;
         cw[cw_ptr+1].sep=cw[cw_ptr+1].midpoint-cg_wave_midpoint;
         if(cw[cw_ptr+1].sep < 0)cw[cw_ptr+1].sep+=baseband_size;
         }
-      s_sum+=cg_wave_dat;
-      n_sum+=cg_wave_err;
+      //      s_sum+=cg_wave_dat;
+      //      n_sum+=cg_wave_err;
       stondt[dashno].s=cg_wave_dat;
       stondt[dashno].n=cg_wave_err;
       stondt[dashno].cwptr=cw_ptr;
