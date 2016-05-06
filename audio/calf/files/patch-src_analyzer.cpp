--- src/analyzer.cpp.orig	2014-10-14 18:53:15 UTC
+++ src/analyzer.cpp
@@ -471,12 +471,12 @@ void analyzer::draw(int subindex, float 
                                 //pumping up actual signal an erase surrounding
                                 // sounds
                                 fft_outL[_iter] = 0.25f * std::max(n * 0.6f * \
-                                    fabs(fft_outL[_iter]) - var1L , 1e-20);
+                                    fabsf(fft_outL[_iter]) - var1L , 1e-20f);
                                 if(_mode == 3 or _mode == 4) {
                                     // do the same with R channel if needed
                                     lastoutR = fft_outR[_iter];
                                     fft_outR[_iter] = 0.25f * std::max(n * \
-                                        0.6f * fabs(fft_outR[_iter]) - var1R , 1e-20);
+                                        0.6f * fabsf(fft_outR[_iter]) - var1R , 1e-20f);
                                 }
                                 break;
                         }
