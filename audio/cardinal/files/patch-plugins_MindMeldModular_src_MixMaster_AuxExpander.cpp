- fix build error:
- /usr/include/c++/v1/__type_traits/promote.h:32:3: error: static assertion failed due to requirement 'is_arithmetic<rack::simd::Vector<float, 4>>::value'
-   static_assert((is_arithmetic<_Args>::value && ...));
-   ^              ~~~~~~~~~~~~~~~~~~~~~~~~~~~
- /usr/include/c++/v1/complex:1110:47: note: in instantiation of template class 'std::__promote<rack::simd::Vector<float, 4>, int>' requested here
- inline _LIBCPP_HIDE_FROM_ABI complex<typename __promote<_Tp, _Up>::type> pow(const complex<_Tp>& __x, const _Up& __y) {
-                                               ^
- MindMeldModular/src/MixMaster/AuxExpander.cpp:612:19: note: while substituting deduced template arguments into function template 'pow' [with _Tp = rack::simd::Vector<float, 4>, _Up = int, $2 = (no value)]
-                                 globalSends = simd::pow<simd::float_4>(globalSends, GlobalConst::globalAuxSendScalingExponent);
-                                               ^

--- plugins/MindMeldModular/src/MixMaster/AuxExpander.cpp.orig	2025-06-22 11:38:40 UTC
+++ plugins/MindMeldModular/src/MixMaster/AuxExpander.cpp
@@ -609,7 +609,7 @@ struct AuxExpander : Module {
 					globalSends = clamp(globalSends, 0.0f, maxAGGlobSendFader);
 					globalSendsWithCV = globalSends;// can put here since unused when cv disconnected
 				}
-				globalSends = simd::pow<simd::float_4>(globalSends, GlobalConst::globalAuxSendScalingExponent);
+				globalSends = simd::pow(globalSends, GlobalConst::globalAuxSendScalingExponent);
 			
 				//   Indiv mute sends (20 or 10 instances)				
 				for (int gi = 0; gi < (N_TRK + N_GRP); gi++) {
@@ -648,7 +648,7 @@ struct AuxExpander : Module {
 						}
 						trackSendVcaGains[trk][auxi] = val;
 					}
-					trackSendVcaGains[trk] = simd::pow<simd::float_4>(trackSendVcaGains[trk], GlobalConst::individualAuxSendScalingExponent);
+					trackSendVcaGains[trk] = simd::pow(trackSendVcaGains[trk], (float)GlobalConst::individualAuxSendScalingExponent);
 					trackSendVcaGains[trk] *= globalSends * simd::float_4(sendMuteSlewers[trk >> 2].out[trk & 0x3]);
 				}
 				// vca the aux send knobs with the track's sound
@@ -677,7 +677,7 @@ struct AuxExpander : Module {
 							groupSendVcaGains[grp][auxi] = 0.0f;
 						}
 					}
-					groupSendVcaGains[grp] = simd::pow<simd::float_4>(groupSendVcaGains[grp], GlobalConst::individualAuxSendScalingExponent);
+					groupSendVcaGains[grp] = simd::pow(groupSendVcaGains[grp], (float)GlobalConst::individualAuxSendScalingExponent);
 					groupSendVcaGains[grp] *= globalSends * simd::float_4(sendMuteSlewers[N_TRK >> 2].out[grp]);
 				}
 				// vca the aux send knobs with the group's sound
