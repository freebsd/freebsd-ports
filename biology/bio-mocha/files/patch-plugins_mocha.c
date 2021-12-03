--- plugins/mocha.c.orig	2021-10-15 02:37:57 UTC
+++ plugins/mocha.c
@@ -705,6 +705,44 @@ static double baf_phase_lod(const float *baf_arr, cons
     return (double)ret * M_LOG10E;
 }
 
+typedef struct
+{
+    const float *baf;
+    const int8_t *gt_phase;
+    int n;
+    const int *imap;
+    int8_t *path;
+    float err_log_prb;
+    float baf_sd;
+}   f1_data_t;
+
+double f1(double x, void *data)
+{
+    f1_data_t	*d = data;
+
+    return -baf_phase_lod(d->baf, d->gt_phase, d->n, d->imap, d->path,
+                          d->err_log_prb, d->baf_sd, x);
+}
+
+static inline f1_data_t *f1_pack(const float *baf, const int8_t *gt_phase, int n,
+		   const int *imap, int8_t *path, float err_log_prb,
+		   float baf_sd)
+{
+    // Switch to malloc() and free() if more than one object must exist at
+    // any given time
+    f1_data_t	*d = malloc(sizeof(f1_data_t));
+
+    d->baf = baf;
+    d->gt_phase = gt_phase;
+    d->n = n;
+    d->imap = imap;
+    d->path = path;
+    d->err_log_prb = err_log_prb;
+    d->baf_sd = baf_sd;
+
+    return d;
+}
+
 // TODO find a better title for this function
 static float compare_models(const float *baf, const int8_t *gt_phase, int n, const int *imap, float xy_log_prb,
                             float err_log_prb, float flip_log_prb, float tel_log_prb, float baf_sd, const float *bdev,
@@ -716,8 +754,11 @@ static float compare_models(const float *baf, const in
     int n_flips = 0;
     for (int i = 1; i < n; i++)
         if (path[i - 1] && path[i] && path[i - 1] != path[i]) n_flips++;
-    double f(double x, void *data) { return -baf_phase_lod(baf, gt_phase, n, imap, path, err_log_prb, baf_sd, x); }
-    double x, fx = kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x);
+    double x;
+    f1_data_t *f1_data = f1_pack(baf, gt_phase, n, imap, path, err_log_prb,
+				 baf_sd);
+    double fx = kmin_brent(f1, 0.1, 0.2, f1_data, KMIN_EPS, &x);
+    free(f1_data);
     free(path);
     return -(float)fx + (float)n_flips * flip_log_prb * (float)M_LOG10E;
 }
@@ -750,6 +791,34 @@ static float get_sample_mean(const float *v, int n, co
     return mean /= (float)j;
 }
 
+typedef struct
+{
+    const float *baf_arr;
+    int n;
+    const int *imap;
+    float baf_sd;
+}   f7_data_t;
+
+double f7(double x, void *data)
+{
+    f7_data_t *d = data;
+
+    return -baf_log_lkl(d->baf_arr, d->n, d->imap, d->baf_sd, x);
+}
+
+static inline f7_data_t *f7_pack(const float *baf_arr, int n, const int *imap,
+    float baf_sd)
+{
+    f7_data_t *d = malloc(sizeof(f7_data_t));
+
+    d->baf_arr = baf_arr;
+    d->n = n;
+    d->imap = imap;
+    d->baf_sd = baf_sd;
+
+    return d;
+}
+
 static float get_baf_bdev(const float *baf_arr, int n, const int *imap, float baf_sd) {
     double bdev = 0.0;
     int j = 0;
@@ -763,8 +832,9 @@ static float get_baf_bdev(const float *baf_arr, int n,
     bdev /= j;
     // simple method to compute bdev should work well for germline duplications
     if ((float)bdev > 2.0f * baf_sd) return (float)bdev;
-    double f(double x, void *data) { return -baf_log_lkl(baf_arr, n, imap, baf_sd, x); }
-    kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &bdev);
+    f7_data_t *f7_data = f7_pack(baf_arr, n, imap, baf_sd);
+    kmin_brent(f7, 0.1, 0.2, f7_data, KMIN_EPS, &bdev);
+    free(f7_data);
     return (float)bdev < 1e-4 ? (float)NAN : (float)bdev;
 }
 
@@ -801,10 +871,41 @@ static double ad_log_lkl(const int16_t *ad0_arr, const
     return (double)ret * M_LOG10E;
 }
 
+typedef struct
+{
+    const int16_t *ad0_arr;
+    const int16_t *ad1_arr;
+    int n;
+    const int *imap;
+    float ad_rho;
+}   f5_data_t;
+
+double f5(double x, void *data)
+{
+    f5_data_t *d = data;
+
+    return -ad_log_lkl(d->ad0_arr, d->ad1_arr, d->n, d->imap, d->ad_rho, x);
+}
+
+static inline f5_data_t *f5_pack(const int16_t *ad0_arr,
+    const int16_t *ad1_arr, int n, const int *imap, float ad_rho)
+{
+    f5_data_t *d = malloc(sizeof(f5_data_t));
+
+    d->ad0_arr = ad0_arr;
+    d->ad1_arr = ad1_arr;
+    d->n = n;
+    d->imap = imap;
+    d->ad_rho = ad_rho;
+
+    return d;
+}
+
 static float get_ad_bdev(const int16_t *ad0_arr, const int16_t *ad1_arr, int n, const int *imap, float ad_rho) {
     double bdev = 0.0;
-    double f(double x, void *data) { return -ad_log_lkl(ad0_arr, ad1_arr, n, imap, ad_rho, x); }
-    kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &bdev);
+    f5_data_t *f5_data = f5_pack(ad0_arr, ad1_arr, n, imap, ad_rho);
+    kmin_brent(f5, 0.1, 0.2, f5_data, KMIN_EPS, &bdev);
+    free(f5_data);
     return (float)bdev < 1e-4 ? (float)NAN : (float)bdev;
 }
 
@@ -986,6 +1087,44 @@ static double ad_phase_lod(const int16_t *ad0_arr, con
     return (double)ret * M_LOG10E;
 }
 
+typedef struct
+{
+    const int16_t *ad0;
+    const int16_t *ad1;
+    const int8_t *gt_phase;
+    int n;
+    const int *imap;
+    int8_t *path;
+    float err_log_prb;
+    float ad_rho;
+}   f4_data_t;
+
+double f4(double x, void *data)
+{
+    f4_data_t *d = data;
+
+    return -ad_phase_lod(d->ad0, d->ad1, d->gt_phase, d->n, d->imap, d->path,
+        d->err_log_prb, d->ad_rho, x);
+}
+
+static inline f4_data_t *f4_pack(const int16_t *ad0, const int16_t *ad1,
+    const int8_t *gt_phase, int n, const int *imap, int8_t *path,
+    float err_log_prb, float ad_rho)
+{
+    f4_data_t *d = malloc(sizeof(f4_data_t));
+
+    d->ad0 = ad0;
+    d->ad1 = ad1;
+    d->gt_phase = gt_phase;
+    d->n = n;
+    d->imap = imap;
+    d->path = path;
+    d->err_log_prb = err_log_prb;
+    d->ad_rho = ad_rho;
+
+    return d;
+}
+
 // TODO find a better title for this function
 static float compare_wgs_models(const int16_t *ad0, const int16_t *ad1, const int8_t *gt_phase, int n, const int *imap,
                                 float xy_log_prb, float err_log_prb, float flip_log_prb, float tel_log_prb,
@@ -998,8 +1137,9 @@ static float compare_wgs_models(const int16_t *ad0, co
     int n_flips = 0;
     for (int i = 1; i < n; i++)
         if (path[i - 1] && path[i] && path[i - 1] != path[i]) n_flips++;
-    double f(double x, void *data) { return -ad_phase_lod(ad0, ad1, gt_phase, n, imap, path, err_log_prb, ad_rho, x); }
-    double x, fx = kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x);
+    f4_data_t *f4_data = f4_pack(ad0, ad1, gt_phase, n, imap, path, err_log_prb, ad_rho);
+    double x, fx = kmin_brent(f4, 0.1, 0.2, f4_data, KMIN_EPS, &x);
+    free(f4_data);
     free(path);
     return -(float)fx + (float)n_flips * flip_log_prb * (float)M_LOG10E;
 }
@@ -1485,6 +1625,129 @@ static float get_path_segs(const int8_t *path, const f
     return 0;
 }
 
+typedef struct
+{
+    float *lrr;
+    int a;
+    int16_t *ad0;
+    int16_t *ad1;
+    mocha_t *mocha;
+    const model_t *model;
+    sample_t *self;
+    float *baf;
+}   f3_data_t;
+    
+double f3(double x, void *data)
+{
+    f3_data_t *d = data;
+
+    if (d->model->flags & WGS_DATA)
+        return -lrr_ad_lod(d->lrr + d->a, d->ad0 + d->a, d->ad1 + d->a,
+            d->mocha->n_sites, NULL, NAN, d->model->lrr_bias,
+            d->model->lrr_hap2dip, d->self->adjlrr_sd,
+            d->self->stats.dispersion, x);
+    else
+        return -lrr_baf_lod(d->lrr + d->a, d->baf + d->a, d->mocha->n_sites,
+            NULL, NAN, d->model->lrr_bias, d->model->lrr_hap2dip,
+            d->self->adjlrr_sd, d->self->stats.dispersion, x);
+}
+
+static inline f3_data_t *f3_pack(float *lrr, int a, int16_t *ad0, int16_t *ad1,
+    mocha_t *mocha, const model_t *model, sample_t *self, float *baf)
+
+{
+    f3_data_t *d = malloc(sizeof(f3_data_t));
+
+    d->lrr = lrr;
+    d->a = a;
+    d->ad0 = ad0;
+    d->ad1 = ad1;
+    d->mocha = mocha;
+    d->model = model;
+    d->self = self;
+    d->baf = baf;
+
+    return d;
+}
+
+typedef struct
+{
+    int16_t *ad0;
+    int16_t *ad1;
+    int8_t *gt_phase;
+    mocha_t *mocha;
+    int *imap_arr;
+    int *beg;
+    int i;
+    int8_t *path;
+    sample_t *self;
+}   f6_data_t;
+
+double f6(double x, void *data)
+{
+    f6_data_t *d = data;
+
+    return -ad_phase_lod(d->ad0, d->ad1, d->gt_phase, d->mocha->n_hets,
+        d->imap_arr + d->beg[d->i], d->path + d->beg[d->i], NAN, d->self->stats.dispersion, x);
+}
+
+static inline f6_data_t *f6_pack(int16_t *ad0, int16_t *ad1, int8_t *gt_phase,
+    mocha_t *mocha, int *imap_arr, int *beg, int i, int8_t *path, sample_t *self)
+
+{
+    f6_data_t *d = malloc(sizeof(f6_data_t));
+
+    d->ad0 = ad0;
+    d->ad1 = ad1;
+    d->gt_phase = gt_phase;
+    d->mocha = mocha;
+    d->imap_arr = imap_arr;
+    d->beg = beg;
+    d->i = i;
+    d->path = path;
+    d->self = self;
+
+    return d;
+}
+
+typedef struct
+{
+    float *baf;
+    int8_t *gt_phase;
+    mocha_t *mocha;
+    int *imap_arr;
+    int *beg;
+    int i;
+    int8_t *path;
+    sample_t *self;
+}   f8_data_t;
+
+double f8(double x, void *data)
+{
+    f8_data_t *d = data;
+
+    return -baf_phase_lod(d->baf, d->gt_phase, d->mocha->n_hets,
+	d->imap_arr + d->beg[d->i], d->path + d->beg[d->i], NAN,
+	d->self->stats.dispersion, x);
+}
+
+static inline f8_data_t *f8_pack(float *baf, int8_t *gt_phase, mocha_t *mocha,
+    int *imap_arr, int *beg, int i, int8_t *path, sample_t *self)
+{
+    f8_data_t *d = malloc(sizeof(f8_data_t));
+
+    d->baf = baf;
+    d->gt_phase = gt_phase;
+    d->mocha = mocha;
+    d->imap_arr = imap_arr;
+    d->beg = beg;
+    d->i = i;
+    d->path = path;
+    d->self = self;
+
+    return d;
+}
+
 // process one contig for one sample
 static void sample_run(sample_t *self, mocha_table_t *mocha_table, const model_t *model) {
     // do nothing if chromosome Y or MT are being tested
@@ -1735,16 +1998,11 @@ static void sample_run(sample_t *self, mocha_table_t *
             mocha.ldev = get_median(lrr + a, b + 1 - a, NULL);
             get_mocha_stats(pos, lrr, baf, gt_phase, n, a, b, cen_beg, cen_end, length, self->stats.baf_conc, &mocha);
 
-            double f(double x, void *data) {
-                if (model->flags & WGS_DATA)
-                    return -lrr_ad_lod(lrr + a, ad0 + a, ad1 + a, mocha.n_sites, NULL, NAN, model->lrr_bias,
-                                       model->lrr_hap2dip, self->adjlrr_sd, self->stats.dispersion, x);
-                else
-                    return -lrr_baf_lod(lrr + a, baf + a, mocha.n_sites, NULL, NAN, model->lrr_bias, model->lrr_hap2dip,
-                                        self->adjlrr_sd, self->stats.dispersion, x);
-            }
             double bdev_lrr_baf;
-            kmin_brent(f, -0.15, 0.15, NULL, KMIN_EPS, &bdev_lrr_baf);
+            f3_data_t *f3_data = f3_pack(lrr, a, ad0, ad1, &mocha, model,
+                 self, baf);
+            kmin_brent(f3, -0.15, 0.15, f3_data, KMIN_EPS, &bdev_lrr_baf);
+	    free(f3_data);
             if (model->flags & WGS_DATA)
                 mocha.lod_lrr_baf =
                     lrr_ad_lod(lrr + a, ad0 + a, ad1 + a, mocha.n_sites, NULL, model->err_log_prb, model->lrr_bias,
@@ -1796,23 +2054,21 @@ static void sample_run(sample_t *self, mocha_table_t *
                     if (path[j] != path[j + 1]) mocha.n_flips++;
 
                 if (model->flags & WGS_DATA) {
-                    double f(double x, void *data) {
-                        return -ad_phase_lod(ad0, ad1, gt_phase, mocha.n_hets, imap_arr + beg[i], path + beg[i], NAN,
-                                             self->stats.dispersion, x);
-                    }
                     double bdev;
-                    kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &bdev);
+		    f6_data_t *f6_data = f6_pack(ad0, ad1, gt_phase, &mocha,
+                        imap_arr, beg, i, path, self);
+                    kmin_brent(f6, 0.1, 0.2, f6_data, KMIN_EPS, &bdev);
+		    free(f6_data);
                     mocha.bdev = fabsf((float)bdev);
                     mocha.lod_baf_phase =
                         ad_phase_lod(ad0, ad1, gt_phase, mocha.n_hets, imap_arr + beg[i], path + beg[i],
                                      model->err_log_prb, self->stats.dispersion, mocha.bdev);
                 } else {
-                    double f(double x, void *data) {
-                        return -baf_phase_lod(baf, gt_phase, mocha.n_hets, imap_arr + beg[i], path + beg[i], NAN,
-                                              self->stats.dispersion, x);
-                    }
                     double bdev;
-                    kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &bdev);
+		    f8_data_t *f8_data = f8_pack(baf, gt_phase, &mocha,
+			imap_arr, beg, i, path, self);
+                    kmin_brent(f8, 0.1, 0.2, f8_data, KMIN_EPS, &bdev);
+		    free(f8_data);
                     mocha.bdev = fabsf((float)bdev);
                     mocha.lod_baf_phase = baf_phase_lod(baf, gt_phase, mocha.n_hets, imap_arr + beg[i], path + beg[i],
                                                         model->err_log_prb, self->stats.dispersion, mocha.bdev);
@@ -1923,6 +2179,60 @@ static float get_lrr_cutoff(const float *v, int n) {
     return cutoff;
 }
 
+typedef struct
+{
+    int16_t *ad0;
+    int16_t *ad1;
+    int n;
+}   f2_data_t;
+
+double f2(double x, void *data)
+{
+    f2_data_t *d = data;
+
+    return -lod_lkl_beta_binomial(d->ad0, d->ad1, d->n, NULL, x);
+}
+
+static inline f2_data_t *f2_pack(int16_t *ad0, int16_t *ad1, int n)
+
+{
+    f2_data_t *d = malloc(sizeof(f2_data_t));
+
+    d->ad0 = ad0;
+    d->ad1 = ad1;
+    d->n = n;
+
+    return d;
+}
+
+typedef struct
+{
+    int16_t *ad0;
+    int16_t *ad1;
+    int n_imap;
+    int *imap_arr;
+}   f9_data_t;
+
+double f9(double x, void *data)
+{
+    f9_data_t *d = data;
+
+    return -lod_lkl_beta_binomial(d->ad0, d->ad1, d->n_imap, d->imap_arr, x);
+}
+
+static inline f9_data_t *f9_pack(int16_t *ad0, int16_t *ad1, int n_imap,
+    int *imap_arr)
+{
+    f9_data_t *d = malloc(sizeof(f9_data_t));
+
+    d->ad0 = ad0;
+    d->ad1 = ad1;
+    d->n_imap = n_imap;
+    d->imap_arr = imap_arr;
+
+    return d;
+}
+
 // this function computes several contig stats and then clears the contig data from the sample
 static void sample_stats(sample_t *self, const model_t *model) {
     int n = self->n;
@@ -1968,9 +2278,10 @@ static void sample_stats(sample_t *self, const model_t
         self->x_nonpar_lrr_median = get_median(lrr, n_imap, imap_arr);
 
         if (model->flags & WGS_DATA) {
-            double f(double x, void *data) { return -lod_lkl_beta_binomial(ad0, ad1, n_imap, imap_arr, x); }
+            f9_data_t *f9_data = f9_pack(ad0, ad1, n_imap, imap_arr);
             double x;
-            kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x); // dispersions above 0.5 are not allowed
+            kmin_brent(f9, 0.1, 0.2, f9_data, KMIN_EPS, &x); // dispersions above 0.5 are not allowed
+	    free(f9_data);
             self->x_nonpar_dispersion = (float)x;
         } else {
             self->x_nonpar_dispersion = get_sample_sd(baf, n_imap, imap_arr);
@@ -1995,9 +2306,10 @@ static void sample_stats(sample_t *self, const model_t
         hts_expand(stats_t, self->n_stats, self->m_stats, self->stats_arr);
 
         if (model->flags & WGS_DATA) {
-            double f(double x, void *data) { return -lod_lkl_beta_binomial(ad0, ad1, n, NULL, x); }
             double x;
-            kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x); // dispersions above 0.5 are not allowed
+	    f2_data_t *f2_data = f2_pack(ad0, ad1, n);
+            kmin_brent(f2, 0.1, 0.2, f2_data, KMIN_EPS, &x); // dispersions above 0.5 are not allowed
+	    free(f2_data);
             self->stats_arr[self->n_stats - 1].dispersion = (float)x;
         } else {
             self->stats_arr[self->n_stats - 1].dispersion = get_sample_sd(baf, n, NULL);
