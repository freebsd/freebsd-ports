https://github.com/spring/spring/pull/558

--- rts/System/GlobalRNG.h.orig	2021-01-01 16:12:22 UTC
+++ rts/System/GlobalRNG.h
@@ -100,6 +100,8 @@ template<typename RNG, bool synced> class CGlobalRNG {
 	typedef typename RNG::val_type rng_val_type;
 	typedef typename RNG::res_type rng_res_type;
 
+	using result_type = rng_res_type;
+
 	static_assert(std::numeric_limits<float>::digits == 24, "sign plus mantissa bits should be 24");
 
 	void Seed(rng_val_type seed) { SetSeed(seed); }
