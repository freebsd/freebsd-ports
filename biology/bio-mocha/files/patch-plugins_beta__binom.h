--- plugins/beta_binom.h.orig	2021-11-30 13:41:36 UTC
+++ plugins/beta_binom.h
@@ -137,14 +137,14 @@ void beta_binom_update(beta_binom_t *self, double p, d
  *  Returns the equivalent of dbeta_binom(a, a+b, p, (1 - rho) / rho, log=TRUE) from R package
  * rmutil
  */
-inline double beta_binom_log_unsafe(const beta_binom_t *self, int a, int b) {
+static inline double beta_binom_log_unsafe(const beta_binom_t *self, int a, int b) {
     return self->log_gamma_alpha[a] + self->log_gamma_beta[b] - self->log_gamma_alpha_beta[a + b];
 }
 
 /**
  *  Same as before but it performs boundary checking before computing the log likelihood
  */
-inline double beta_binom_log(beta_binom_t *self, int a, int b) {
+static inline double beta_binom_log(beta_binom_t *self, int a, int b) {
     if (a < 0 || b < 0) return NAN;
     if (a > self->n1 || b > self->n1 || a + b > self->n2)
         beta_binom_update(self, self->p, self->rho, a > b ? a : b, a + b);
