--- ext/ripper/ripper.c.orig	2017-12-25 07:00:33 UTC
+++ ext/ripper/ripper.c
@@ -1564,61 +1564,61 @@ static const yytype_uint16 yyrline[] =
     1735,  1744,  1753,  1762,  1773,  1774,  1784,  1785,  1795,  1803,
     1811,  1819,  1828,  1836,  1845,  1853,  1862,  1870,  1881,  1882,
     1892,  1900,  1910,  1918,  1928,  1932,  1936,  1944,  1952,  1960,
-    1968,  1972,  1976,  1983,  1991,  1999,  2007,  2015,  2023,  2031,
-    2035,  2039,  2046,  2055,  2058,  2067,  2076,  2087,  2088,  2089,
-    2090,  2095,  2102,  2103,  2106,  2114,  2117,  2125,  2125,  2136,
-    2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,
-    2147,  2148,  2149,  2150,  2151,  2152,  2153,  2154,  2155,  2156,
-    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2168,
-    2168,  2168,  2169,  2169,  2170,  2170,  2170,  2171,  2171,  2171,
-    2171,  2172,  2172,  2172,  2172,  2173,  2173,  2173,  2174,  2174,
-    2174,  2174,  2175,  2175,  2175,  2175,  2176,  2176,  2176,  2176,
-    2177,  2177,  2177,  2177,  2178,  2178,  2178,  2178,  2179,  2179,
-    2182,  2186,  2190,  2218,  2223,  2228,  2233,  2244,  2249,  2254,
-    2265,  2276,  2280,  2284,  2288,  2292,  2296,  2300,  2304,  2308,
-    2312,  2316,  2320,  2324,  2328,  2329,  2333,  2337,  2341,  2345,
-    2349,  2353,  2357,  2361,  2365,  2369,  2373,  2373,  2378,  2388,
-    2394,  2395,  2396,  2397,  2400,  2404,  2411,  2423,  2424,  2428,
-    2436,  2446,  2454,  2468,  2478,  2479,  2482,  2483,  2484,  2488,
-    2496,  2506,  2515,  2523,  2533,  2542,  2551,  2551,  2563,  2574,
-    2578,  2584,  2592,  2601,  2615,  2631,  2632,  2635,  2649,  2664,
-    2675,  2676,  2677,  2678,  2679,  2680,  2681,  2682,  2683,  2684,
-    2685,  2694,  2693,  2720,  2720,  2729,  2733,  2728,  2742,  2750,
-    2759,  2768,  2776,  2785,  2794,  2802,  2811,  2820,  2820,  2825,
-    2829,  2833,  2844,  2845,  2856,  2860,  2872,  2884,  2884,  2884,
-    2896,  2896,  2896,  2908,  2920,  2931,  2933,  2930,  2984,  2983,
-    3011,  3010,  3035,  3034,  3062,  3067,  3061,  3090,  3091,  3090,
-    3118,  3127,  3136,  3145,  3156,  3168,  3174,  3180,  3186,  3192,
-    3198,  3208,  3214,  3220,  3226,  3236,  3242,  3249,  3254,  3255,
-    3262,  3267,  3270,  3271,  3284,  3285,  3295,  3296,  3299,  3306,
-    3316,  3324,  3334,  3342,  3351,  3361,  3369,  3378,  3387,  3397,
-    3405,  3417,  3421,  3425,  3429,  3435,  3440,  3445,  3449,  3453,
-    3457,  3461,  3465,  3473,  3477,  3481,  3485,  3489,  3493,  3497,
-    3501,  3505,  3511,  3512,  3518,  3528,  3537,  3549,  3553,  3563,
-    3570,  3579,  3587,  3593,  3596,  3601,  3604,  3593,  3625,  3633,
-    3639,  3644,  3651,  3650,  3667,  3684,  3688,  3701,  3716,  3727,
-    3726,  3738,  3737,  3748,  3753,  3752,  3764,  3763,  3774,  3783,
-    3792,  3807,  3806,  3822,  3821,  3838,  3839,  3838,  3848,  3849,
-    3848,  3858,  3871,  3872,  3875,  3897,  3900,  3908,  3916,  3919,
-    3923,  3926,  3934,  3937,  3938,  3946,  3949,  3966,  3973,  3974,
-    3984,  3994,  4000,  4006,  4017,  4024,  4034,  4042,  4052,  4063,
-    4070,  4088,  4098,  4109,  4116,  4128,  4135,  4151,  4158,  4169,
-    4176,  4187,  4194,  4235,  4243,  4242,  4260,  4266,  4271,  4275,
-    4279,  4259,  4301,  4309,  4317,  4326,  4329,  4340,  4341,  4342,
-    4343,  4346,  4357,  4358,  4369,  4376,  4383,  4390,  4399,  4400,
-    4401,  4402,  4403,  4406,  4407,  4408,  4409,  4410,  4411,  4412,
-    4415,  4428,  4438,  4442,  4448,  4455,  4465,  4464,  4474,  4483,
-    4493,  4493,  4507,  4511,  4515,  4519,  4525,  4530,  4535,  4539,
-    4543,  4547,  4551,  4555,  4559,  4563,  4567,  4571,  4575,  4579,
-    4583,  4587,  4592,  4598,  4608,  4618,  4628,  4640,  4641,  4648,
-    4657,  4666,  4691,  4698,  4712,  4721,  4731,  4743,  4752,  4763,
-    4771,  4782,  4790,  4800,  4801,  4804,  4813,  4824,  4837,  4850,
-    4858,  4868,  4876,  4886,  4887,  4890,  4903,  4914,  4915,  4918,
-    4935,  4939,  4949,  4959,  4959,  4989,  4990,  5000,  5007,  5031,
-    5043,  5051,  5062,  5076,  5077,  5078,  5081,  5082,  5083,  5084,
-    5087,  5088,  5089,  5092,  5093,  5096,  5100,  5106,  5107,  5113,
-    5114,  5117,  5118,  5121,  5124,  5127,  5128,  5129,  5132,  5133,
-    5136,  5137,  5141
+    1968,  1972,  1976,  1983,  1987,  1991,  1999,  2007,  2015,  2023,
+    2027,  2031,  2038,  2047,  2050,  2059,  2068,  2079,  2080,  2081,
+    2082,  2087,  2094,  2095,  2098,  2106,  2109,  2117,  2117,  2128,
+    2129,  2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,  2138,
+    2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,
+    2149,  2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2160,
+    2160,  2160,  2161,  2161,  2162,  2162,  2162,  2163,  2163,  2163,
+    2163,  2164,  2164,  2164,  2164,  2165,  2165,  2165,  2166,  2166,
+    2166,  2166,  2167,  2167,  2167,  2167,  2168,  2168,  2168,  2168,
+    2169,  2169,  2169,  2169,  2170,  2170,  2170,  2170,  2171,  2171,
+    2174,  2178,  2182,  2210,  2215,  2220,  2225,  2236,  2241,  2246,
+    2257,  2268,  2272,  2276,  2280,  2284,  2288,  2292,  2296,  2300,
+    2304,  2308,  2312,  2316,  2320,  2321,  2325,  2329,  2333,  2337,
+    2341,  2345,  2349,  2353,  2357,  2361,  2365,  2365,  2370,  2380,
+    2386,  2387,  2388,  2389,  2392,  2396,  2403,  2415,  2416,  2420,
+    2428,  2438,  2446,  2460,  2470,  2471,  2474,  2475,  2476,  2480,
+    2488,  2498,  2507,  2515,  2525,  2534,  2543,  2543,  2555,  2566,
+    2570,  2576,  2584,  2593,  2607,  2623,  2624,  2627,  2641,  2656,
+    2667,  2668,  2669,  2670,  2671,  2672,  2673,  2674,  2675,  2676,
+    2677,  2686,  2685,  2712,  2712,  2721,  2725,  2720,  2734,  2742,
+    2751,  2760,  2768,  2777,  2786,  2794,  2803,  2812,  2812,  2817,
+    2821,  2825,  2836,  2837,  2848,  2852,  2864,  2876,  2876,  2876,
+    2888,  2888,  2888,  2900,  2912,  2923,  2925,  2922,  2976,  2975,
+    3003,  3002,  3027,  3026,  3054,  3059,  3053,  3082,  3083,  3082,
+    3110,  3119,  3128,  3137,  3148,  3160,  3166,  3172,  3178,  3184,
+    3190,  3200,  3206,  3212,  3218,  3228,  3234,  3241,  3246,  3247,
+    3254,  3259,  3262,  3263,  3276,  3277,  3287,  3288,  3291,  3298,
+    3308,  3316,  3326,  3334,  3343,  3353,  3361,  3370,  3379,  3389,
+    3397,  3409,  3413,  3417,  3421,  3427,  3432,  3437,  3441,  3445,
+    3449,  3453,  3457,  3465,  3469,  3473,  3477,  3481,  3485,  3489,
+    3493,  3497,  3503,  3504,  3510,  3520,  3529,  3541,  3545,  3555,
+    3562,  3571,  3579,  3585,  3588,  3593,  3596,  3585,  3617,  3625,
+    3631,  3636,  3643,  3642,  3659,  3676,  3680,  3693,  3708,  3719,
+    3718,  3730,  3729,  3740,  3745,  3744,  3756,  3755,  3766,  3775,
+    3784,  3799,  3798,  3814,  3813,  3830,  3831,  3830,  3840,  3841,
+    3840,  3850,  3863,  3864,  3867,  3889,  3892,  3900,  3908,  3911,
+    3915,  3918,  3926,  3929,  3930,  3938,  3941,  3958,  3965,  3966,
+    3976,  3986,  3992,  3998,  4009,  4016,  4026,  4034,  4044,  4055,
+    4062,  4080,  4090,  4101,  4108,  4120,  4127,  4143,  4150,  4161,
+    4168,  4179,  4186,  4227,  4235,  4234,  4252,  4258,  4263,  4267,
+    4271,  4251,  4293,  4301,  4309,  4318,  4321,  4332,  4333,  4334,
+    4335,  4338,  4349,  4350,  4361,  4368,  4375,  4382,  4391,  4392,
+    4393,  4394,  4395,  4398,  4399,  4400,  4401,  4402,  4403,  4404,
+    4407,  4420,  4430,  4434,  4440,  4447,  4457,  4456,  4466,  4475,
+    4485,  4485,  4499,  4503,  4507,  4511,  4517,  4522,  4527,  4531,
+    4535,  4539,  4543,  4547,  4551,  4555,  4559,  4563,  4567,  4571,
+    4575,  4579,  4584,  4590,  4600,  4610,  4620,  4632,  4633,  4640,
+    4649,  4658,  4683,  4690,  4704,  4713,  4723,  4735,  4744,  4755,
+    4763,  4774,  4782,  4792,  4793,  4796,  4805,  4816,  4829,  4842,
+    4850,  4860,  4868,  4878,  4879,  4882,  4895,  4906,  4907,  4910,
+    4927,  4931,  4941,  4951,  4951,  4981,  4982,  4992,  4999,  5023,
+    5035,  5043,  5054,  5068,  5069,  5070,  5073,  5074,  5075,  5076,
+    5079,  5080,  5081,  5084,  5085,  5088,  5092,  5098,  5099,  5105,
+    5106,  5109,  5110,  5113,  5116,  5119,  5120,  5121,  5124,  5125,
+    5128,  5129,  5133
 };
 #endif
 
@@ -6590,28 +6590,20 @@ yyreduce:
 #line 1984 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable(var_field((yyvsp[0].val)), 0, &(yyloc));
-#if 0
-			if (!(yyval.val)) (yyval.val) = new_begin(0, &(yyloc));
-#endif
-
 		    }
-#line 6595 "ripper.c" /* yacc.c:1646  */
+#line 6591 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 104:
-#line 1992 "ripper.y" /* yacc.c:1646  */
+#line 1988 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable(var_field((yyvsp[0].val)), 0, &(yyloc));
-#if 0
-			if (!(yyval.val)) (yyval.val) = new_begin(0, &(yyloc));
-#endif
-
 		    }
-#line 6607 "ripper.c" /* yacc.c:1646  */
+#line 6599 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 105:
-#line 2000 "ripper.y" /* yacc.c:1646  */
+#line 1992 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = aryset((yyvsp[-3].val), (yyvsp[-1].val), &(yyloc));
@@ -6619,11 +6611,11 @@ yyreduce:
 			(yyval.val) = dispatch2(aref_field, (yyvsp[-3].val), escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 6619 "ripper.c" /* yacc.c:1646  */
+#line 6611 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 106:
-#line 2008 "ripper.y" /* yacc.c:1646  */
+#line 2000 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = attrset((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -6631,11 +6623,11 @@ yyreduce:
 			(yyval.val) = dispatch3(field, (yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 6631 "ripper.c" /* yacc.c:1646  */
+#line 6623 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 107:
-#line 2016 "ripper.y" /* yacc.c:1646  */
+#line 2008 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = attrset((yyvsp[-2].val), idCOLON2, (yyvsp[0].val), &(yyloc));
@@ -6643,11 +6635,11 @@ yyreduce:
 			(yyval.val) = dispatch3(field, (yyvsp[-2].val), ID2VAL(idCOLON2), (yyvsp[0].val));
 
 		    }
-#line 6643 "ripper.c" /* yacc.c:1646  */
+#line 6635 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 108:
-#line 2024 "ripper.y" /* yacc.c:1646  */
+#line 2016 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = attrset((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -6655,36 +6647,36 @@ yyreduce:
 			(yyval.val) = dispatch3(field, (yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 6655 "ripper.c" /* yacc.c:1646  */
+#line 6647 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 109:
-#line 2032 "ripper.y" /* yacc.c:1646  */
+#line 2024 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = const_decl(const_path_field((yyvsp[-2].val), (yyvsp[0].val), &(yyloc)), &(yyloc));
 		    }
-#line 6663 "ripper.c" /* yacc.c:1646  */
+#line 6655 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 110:
-#line 2036 "ripper.y" /* yacc.c:1646  */
+#line 2028 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = const_decl(top_const_field((yyvsp[0].val)), &(yyloc));
 		    }
-#line 6671 "ripper.c" /* yacc.c:1646  */
+#line 6663 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 111:
-#line 2040 "ripper.y" /* yacc.c:1646  */
+#line 2032 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = var_field((yyvsp[0].val));
 			(yyval.val) = backref_assign_error((yyvsp[0].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 6680 "ripper.c" /* yacc.c:1646  */
+#line 6672 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 112:
-#line 2047 "ripper.y" /* yacc.c:1646  */
+#line 2039 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			yyerror0("class/module name must be CONSTANT");
@@ -6693,11 +6685,11 @@ yyreduce:
 			ripper_error();
 
 		    }
-#line 6693 "ripper.c" /* yacc.c:1646  */
+#line 6685 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 114:
-#line 2059 "ripper.y" /* yacc.c:1646  */
+#line 2051 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_COLON3((yyvsp[0].val));
@@ -6706,11 +6698,11 @@ yyreduce:
 			(yyval.val) = dispatch1(top_const_ref, (yyvsp[0].val));
 
 		    }
-#line 6706 "ripper.c" /* yacc.c:1646  */
+#line 6698 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 115:
-#line 2068 "ripper.y" /* yacc.c:1646  */
+#line 2060 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_COLON2(0, (yyval.val));
@@ -6719,11 +6711,11 @@ yyreduce:
 			(yyval.val) = dispatch1(const_ref, (yyvsp[0].val));
 
 		    }
-#line 6719 "ripper.c" /* yacc.c:1646  */
+#line 6711 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 116:
-#line 2077 "ripper.y" /* yacc.c:1646  */
+#line 2069 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_COLON2((yyvsp[-2].val), (yyvsp[0].val));
@@ -6732,29 +6724,29 @@ yyreduce:
 			(yyval.val) = dispatch2(const_path_ref, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 6732 "ripper.c" /* yacc.c:1646  */
+#line 6724 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 120:
-#line 2091 "ripper.y" /* yacc.c:1646  */
+#line 2083 "ripper.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_ENDFN);
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 6741 "ripper.c" /* yacc.c:1646  */
+#line 6733 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 121:
-#line 2096 "ripper.y" /* yacc.c:1646  */
+#line 2088 "ripper.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_ENDFN);
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 6750 "ripper.c" /* yacc.c:1646  */
+#line 6742 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 124:
-#line 2107 "ripper.y" /* yacc.c:1646  */
+#line 2099 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_lit(ID2SYM((yyvsp[0].val)), &(yyloc));
@@ -6762,11 +6754,11 @@ yyreduce:
 			(yyval.val) = dispatch1(symbol_literal, (yyvsp[0].val));
 
 		    }
-#line 6762 "ripper.c" /* yacc.c:1646  */
+#line 6754 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 126:
-#line 2118 "ripper.y" /* yacc.c:1646  */
+#line 2110 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_undef((yyvsp[0].val), &(yyloc));
@@ -6774,17 +6766,17 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 6774 "ripper.c" /* yacc.c:1646  */
+#line 6766 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 127:
-#line 2125 "ripper.y" /* yacc.c:1646  */
+#line 2117 "ripper.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_FNAME|EXPR_FITEM);}
-#line 6780 "ripper.c" /* yacc.c:1646  */
+#line 6772 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 128:
-#line 2126 "ripper.y" /* yacc.c:1646  */
+#line 2118 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *undef = new_undef((yyvsp[0].val), &(yyloc));
@@ -6793,207 +6785,207 @@ yyreduce:
 			rb_ary_push((yyvsp[-3].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 6793 "ripper.c" /* yacc.c:1646  */
+#line 6785 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 129:
-#line 2136 "ripper.y" /* yacc.c:1646  */
+#line 2128 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '|'); }
-#line 6799 "ripper.c" /* yacc.c:1646  */
+#line 6791 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 130:
-#line 2137 "ripper.y" /* yacc.c:1646  */
+#line 2129 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '^'); }
-#line 6805 "ripper.c" /* yacc.c:1646  */
+#line 6797 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 131:
-#line 2138 "ripper.y" /* yacc.c:1646  */
+#line 2130 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '&'); }
-#line 6811 "ripper.c" /* yacc.c:1646  */
+#line 6803 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 132:
-#line 2139 "ripper.y" /* yacc.c:1646  */
+#line 2131 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tCMP); }
-#line 6817 "ripper.c" /* yacc.c:1646  */
+#line 6809 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 133:
-#line 2140 "ripper.y" /* yacc.c:1646  */
+#line 2132 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tEQ); }
-#line 6823 "ripper.c" /* yacc.c:1646  */
+#line 6815 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 134:
-#line 2141 "ripper.y" /* yacc.c:1646  */
+#line 2133 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tEQQ); }
-#line 6829 "ripper.c" /* yacc.c:1646  */
+#line 6821 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 135:
-#line 2142 "ripper.y" /* yacc.c:1646  */
+#line 2134 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tMATCH); }
-#line 6835 "ripper.c" /* yacc.c:1646  */
+#line 6827 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 136:
-#line 2143 "ripper.y" /* yacc.c:1646  */
+#line 2135 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tNMATCH); }
-#line 6841 "ripper.c" /* yacc.c:1646  */
+#line 6833 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 137:
-#line 2144 "ripper.y" /* yacc.c:1646  */
+#line 2136 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '>'); }
-#line 6847 "ripper.c" /* yacc.c:1646  */
+#line 6839 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 138:
-#line 2145 "ripper.y" /* yacc.c:1646  */
+#line 2137 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tGEQ); }
-#line 6853 "ripper.c" /* yacc.c:1646  */
+#line 6845 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 139:
-#line 2146 "ripper.y" /* yacc.c:1646  */
+#line 2138 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '<'); }
-#line 6859 "ripper.c" /* yacc.c:1646  */
+#line 6851 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 140:
-#line 2147 "ripper.y" /* yacc.c:1646  */
+#line 2139 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tLEQ); }
-#line 6865 "ripper.c" /* yacc.c:1646  */
+#line 6857 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 141:
-#line 2148 "ripper.y" /* yacc.c:1646  */
+#line 2140 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tNEQ); }
-#line 6871 "ripper.c" /* yacc.c:1646  */
+#line 6863 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 142:
-#line 2149 "ripper.y" /* yacc.c:1646  */
+#line 2141 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tLSHFT); }
-#line 6877 "ripper.c" /* yacc.c:1646  */
+#line 6869 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 143:
-#line 2150 "ripper.y" /* yacc.c:1646  */
+#line 2142 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tRSHFT); }
-#line 6883 "ripper.c" /* yacc.c:1646  */
+#line 6875 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 144:
-#line 2151 "ripper.y" /* yacc.c:1646  */
+#line 2143 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '+'); }
-#line 6889 "ripper.c" /* yacc.c:1646  */
+#line 6881 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 145:
-#line 2152 "ripper.y" /* yacc.c:1646  */
+#line 2144 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '-'); }
-#line 6895 "ripper.c" /* yacc.c:1646  */
+#line 6887 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 146:
-#line 2153 "ripper.y" /* yacc.c:1646  */
+#line 2145 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '*'); }
-#line 6901 "ripper.c" /* yacc.c:1646  */
+#line 6893 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 147:
-#line 2154 "ripper.y" /* yacc.c:1646  */
+#line 2146 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '*'); }
-#line 6907 "ripper.c" /* yacc.c:1646  */
+#line 6899 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 148:
-#line 2155 "ripper.y" /* yacc.c:1646  */
+#line 2147 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '/'); }
-#line 6913 "ripper.c" /* yacc.c:1646  */
+#line 6905 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 149:
-#line 2156 "ripper.y" /* yacc.c:1646  */
+#line 2148 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '%'); }
-#line 6919 "ripper.c" /* yacc.c:1646  */
+#line 6911 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 150:
-#line 2157 "ripper.y" /* yacc.c:1646  */
+#line 2149 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tPOW); }
-#line 6925 "ripper.c" /* yacc.c:1646  */
+#line 6917 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 151:
-#line 2158 "ripper.y" /* yacc.c:1646  */
+#line 2150 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tDSTAR); }
-#line 6931 "ripper.c" /* yacc.c:1646  */
+#line 6923 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 152:
-#line 2159 "ripper.y" /* yacc.c:1646  */
+#line 2151 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '!'); }
-#line 6937 "ripper.c" /* yacc.c:1646  */
+#line 6929 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 153:
-#line 2160 "ripper.y" /* yacc.c:1646  */
+#line 2152 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '~'); }
-#line 6943 "ripper.c" /* yacc.c:1646  */
+#line 6935 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 154:
-#line 2161 "ripper.y" /* yacc.c:1646  */
+#line 2153 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tUPLUS); }
-#line 6949 "ripper.c" /* yacc.c:1646  */
+#line 6941 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 155:
-#line 2162 "ripper.y" /* yacc.c:1646  */
+#line 2154 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tUMINUS); }
-#line 6955 "ripper.c" /* yacc.c:1646  */
+#line 6947 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 156:
-#line 2163 "ripper.y" /* yacc.c:1646  */
+#line 2155 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tAREF); }
-#line 6961 "ripper.c" /* yacc.c:1646  */
+#line 6953 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 157:
-#line 2164 "ripper.y" /* yacc.c:1646  */
+#line 2156 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = tASET); }
-#line 6967 "ripper.c" /* yacc.c:1646  */
+#line 6959 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 158:
-#line 2165 "ripper.y" /* yacc.c:1646  */
+#line 2157 "ripper.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.val) = '`'); }
-#line 6973 "ripper.c" /* yacc.c:1646  */
+#line 6965 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 200:
-#line 2183 "ripper.y" /* yacc.c:1646  */
+#line 2175 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = node_assign((yyvsp[-2].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 6981 "ripper.c" /* yacc.c:1646  */
+#line 6973 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 201:
-#line 2187 "ripper.y" /* yacc.c:1646  */
+#line 2179 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_op_assign((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 6989 "ripper.c" /* yacc.c:1646  */
+#line 6981 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 202:
-#line 2191 "ripper.y" /* yacc.c:1646  */
+#line 2183 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *args;
@@ -7021,38 +7013,38 @@ yyreduce:
 			(yyval.val) = dispatch3(opassign, (yyvsp[-5].val), (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 7021 "ripper.c" /* yacc.c:1646  */
+#line 7013 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 203:
-#line 2219 "ripper.y" /* yacc.c:1646  */
+#line 2211 "ripper.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].val));
 			(yyval.val) = new_attr_op_assign((yyvsp[-4].val), (yyvsp[-3].val), (yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 7030 "ripper.c" /* yacc.c:1646  */
+#line 7022 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 204:
-#line 2224 "ripper.y" /* yacc.c:1646  */
+#line 2216 "ripper.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].val));
 			(yyval.val) = new_attr_op_assign((yyvsp[-4].val), (yyvsp[-3].val), (yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 7039 "ripper.c" /* yacc.c:1646  */
+#line 7031 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 205:
-#line 2229 "ripper.y" /* yacc.c:1646  */
+#line 2221 "ripper.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].val));
 			(yyval.val) = new_attr_op_assign((yyvsp[-4].val), ID2VAL(idCOLON2), (yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 7048 "ripper.c" /* yacc.c:1646  */
+#line 7040 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 206:
-#line 2234 "ripper.y" /* yacc.c:1646  */
+#line 2226 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			YYLTYPE location;
@@ -7063,29 +7055,29 @@ yyreduce:
 			(yyval.val) = const_path_field((yyvsp[-4].val), (yyvsp[-2].val), &location);
 			(yyval.val) = new_const_op_assign((yyval.val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 7063 "ripper.c" /* yacc.c:1646  */
+#line 7055 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 207:
-#line 2245 "ripper.y" /* yacc.c:1646  */
+#line 2237 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = top_const_field((yyvsp[-2].val));
 			(yyval.val) = new_const_op_assign((yyval.val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 7072 "ripper.c" /* yacc.c:1646  */
+#line 7064 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 208:
-#line 2250 "ripper.y" /* yacc.c:1646  */
+#line 2242 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[-2].val) = var_field((yyvsp[-2].val));
 			(yyval.val) = backref_assign_error((yyvsp[-2].val), new_op_assign((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc)), &(yyloc));
 		    }
-#line 7081 "ripper.c" /* yacc.c:1646  */
+#line 7073 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 209:
-#line 2255 "ripper.y" /* yacc.c:1646  */
+#line 2247 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[-2].val));
@@ -7096,11 +7088,11 @@ yyreduce:
 			(yyval.val) = dispatch2(dot2, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 7096 "ripper.c" /* yacc.c:1646  */
+#line 7088 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 210:
-#line 2266 "ripper.y" /* yacc.c:1646  */
+#line 2258 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[-2].val));
@@ -7111,218 +7103,218 @@ yyreduce:
 			(yyval.val) = dispatch2(dot3, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 7111 "ripper.c" /* yacc.c:1646  */
+#line 7103 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 211:
-#line 2277 "ripper.y" /* yacc.c:1646  */
+#line 2269 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '+', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7119 "ripper.c" /* yacc.c:1646  */
+#line 7111 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 212:
-#line 2281 "ripper.y" /* yacc.c:1646  */
+#line 2273 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '-', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7127 "ripper.c" /* yacc.c:1646  */
+#line 7119 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 213:
-#line 2285 "ripper.y" /* yacc.c:1646  */
+#line 2277 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '*', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7135 "ripper.c" /* yacc.c:1646  */
+#line 7127 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 214:
-#line 2289 "ripper.y" /* yacc.c:1646  */
+#line 2281 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '/', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7143 "ripper.c" /* yacc.c:1646  */
+#line 7135 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 215:
-#line 2293 "ripper.y" /* yacc.c:1646  */
+#line 2285 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '%', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7151 "ripper.c" /* yacc.c:1646  */
+#line 7143 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 216:
-#line 2297 "ripper.y" /* yacc.c:1646  */
+#line 2289 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idPow, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7159 "ripper.c" /* yacc.c:1646  */
+#line 7151 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 217:
-#line 2301 "ripper.y" /* yacc.c:1646  */
+#line 2293 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op(call_bin_op((yyvsp[-2].val), idPow, (yyvsp[0].val), &(yylsp[-2]), &(yyloc)), idUMinus, &(yylsp[-3]), &(yyloc));
 		    }
-#line 7167 "ripper.c" /* yacc.c:1646  */
+#line 7159 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 218:
-#line 2305 "ripper.y" /* yacc.c:1646  */
+#line 2297 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op((yyvsp[0].val), idUPlus, &(yylsp[-1]), &(yyloc));
 		    }
-#line 7175 "ripper.c" /* yacc.c:1646  */
+#line 7167 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 219:
-#line 2309 "ripper.y" /* yacc.c:1646  */
+#line 2301 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op((yyvsp[0].val), idUMinus, &(yylsp[-1]), &(yyloc));
 		    }
-#line 7183 "ripper.c" /* yacc.c:1646  */
+#line 7175 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 220:
-#line 2313 "ripper.y" /* yacc.c:1646  */
+#line 2305 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '|', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7191 "ripper.c" /* yacc.c:1646  */
+#line 7183 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 221:
-#line 2317 "ripper.y" /* yacc.c:1646  */
+#line 2309 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '^', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7199 "ripper.c" /* yacc.c:1646  */
+#line 7191 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 222:
-#line 2321 "ripper.y" /* yacc.c:1646  */
+#line 2313 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), '&', (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7207 "ripper.c" /* yacc.c:1646  */
+#line 7199 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 223:
-#line 2325 "ripper.y" /* yacc.c:1646  */
+#line 2317 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idCmp, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7215 "ripper.c" /* yacc.c:1646  */
+#line 7207 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 225:
-#line 2330 "ripper.y" /* yacc.c:1646  */
+#line 2322 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idEq, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7223 "ripper.c" /* yacc.c:1646  */
+#line 7215 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 226:
-#line 2334 "ripper.y" /* yacc.c:1646  */
+#line 2326 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idEqq, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7231 "ripper.c" /* yacc.c:1646  */
+#line 7223 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 227:
-#line 2338 "ripper.y" /* yacc.c:1646  */
+#line 2330 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idNeq, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7239 "ripper.c" /* yacc.c:1646  */
+#line 7231 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 228:
-#line 2342 "ripper.y" /* yacc.c:1646  */
+#line 2334 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = match_op((yyvsp[-2].val), (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7247 "ripper.c" /* yacc.c:1646  */
+#line 7239 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 229:
-#line 2346 "ripper.y" /* yacc.c:1646  */
+#line 2338 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idNeqTilde, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7255 "ripper.c" /* yacc.c:1646  */
+#line 7247 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 230:
-#line 2350 "ripper.y" /* yacc.c:1646  */
+#line 2342 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op(method_cond((yyvsp[0].val), &(yylsp[0])), '!', &(yylsp[-1]), &(yyloc));
 		    }
-#line 7263 "ripper.c" /* yacc.c:1646  */
+#line 7255 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 231:
-#line 2354 "ripper.y" /* yacc.c:1646  */
+#line 2346 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op((yyvsp[0].val), '~', &(yylsp[-1]), &(yyloc));
 		    }
-#line 7271 "ripper.c" /* yacc.c:1646  */
+#line 7263 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 232:
-#line 2358 "ripper.y" /* yacc.c:1646  */
+#line 2350 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idLTLT, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7279 "ripper.c" /* yacc.c:1646  */
+#line 7271 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 233:
-#line 2362 "ripper.y" /* yacc.c:1646  */
+#line 2354 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), idGTGT, (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7287 "ripper.c" /* yacc.c:1646  */
+#line 7279 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 234:
-#line 2366 "ripper.y" /* yacc.c:1646  */
+#line 2358 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = logop(idANDOP, (yyvsp[-2].val), (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7295 "ripper.c" /* yacc.c:1646  */
+#line 7287 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 235:
-#line 2370 "ripper.y" /* yacc.c:1646  */
+#line 2362 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = logop(idOROP, (yyvsp[-2].val), (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7303 "ripper.c" /* yacc.c:1646  */
+#line 7295 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 236:
-#line 2373 "ripper.y" /* yacc.c:1646  */
+#line 2365 "ripper.y" /* yacc.c:1646  */
     {in_defined = 1;}
-#line 7309 "ripper.c" /* yacc.c:1646  */
+#line 7301 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 237:
-#line 2374 "ripper.y" /* yacc.c:1646  */
+#line 2366 "ripper.y" /* yacc.c:1646  */
     {
 			in_defined = 0;
 			(yyval.val) = new_defined((yyvsp[0].val), &(yyloc));
 		    }
-#line 7318 "ripper.c" /* yacc.c:1646  */
+#line 7310 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 238:
-#line 2379 "ripper.y" /* yacc.c:1646  */
+#line 2371 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[-5].val));
@@ -7332,60 +7324,60 @@ yyreduce:
 			(yyval.val) = dispatch3(ifop, (yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[0].val));
 
 		    }
-#line 7332 "ripper.c" /* yacc.c:1646  */
+#line 7324 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 239:
-#line 2389 "ripper.y" /* yacc.c:1646  */
+#line 2381 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 7340 "ripper.c" /* yacc.c:1646  */
+#line 7332 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 240:
-#line 2394 "ripper.y" /* yacc.c:1646  */
+#line 2386 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = '>';}
-#line 7346 "ripper.c" /* yacc.c:1646  */
+#line 7338 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 241:
-#line 2395 "ripper.y" /* yacc.c:1646  */
+#line 2387 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = '<';}
-#line 7352 "ripper.c" /* yacc.c:1646  */
+#line 7344 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 242:
-#line 2396 "ripper.y" /* yacc.c:1646  */
+#line 2388 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = idGE;}
-#line 7358 "ripper.c" /* yacc.c:1646  */
+#line 7350 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 243:
-#line 2397 "ripper.y" /* yacc.c:1646  */
+#line 2389 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = idLE;}
-#line 7364 "ripper.c" /* yacc.c:1646  */
+#line 7356 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 244:
-#line 2401 "ripper.y" /* yacc.c:1646  */
+#line 2393 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_bin_op((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7372 "ripper.c" /* yacc.c:1646  */
+#line 7364 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 245:
-#line 2405 "ripper.y" /* yacc.c:1646  */
+#line 2397 "ripper.y" /* yacc.c:1646  */
     {
 			rb_warning1("comparison '%s' after comparison", WARN_ID((yyvsp[-1].val)));
 			(yyval.val) = call_bin_op((yyvsp[-2].val), (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7381 "ripper.c" /* yacc.c:1646  */
+#line 7373 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 246:
-#line 2412 "ripper.y" /* yacc.c:1646  */
+#line 2404 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[0].val));
@@ -7395,19 +7387,19 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 7395 "ripper.c" /* yacc.c:1646  */
+#line 7387 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 248:
-#line 2425 "ripper.y" /* yacc.c:1646  */
+#line 2417 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 		    }
-#line 7403 "ripper.c" /* yacc.c:1646  */
+#line 7395 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 249:
-#line 2429 "ripper.y" /* yacc.c:1646  */
+#line 2421 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? arg_append((yyvsp[-3].val), new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].val);
@@ -7415,11 +7407,11 @@ yyreduce:
 			(yyval.val) = arg_add_assocs((yyvsp[-3].val), (yyvsp[-1].val));
 
 		    }
-#line 7415 "ripper.c" /* yacc.c:1646  */
+#line 7407 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 250:
-#line 2437 "ripper.y" /* yacc.c:1646  */
+#line 2429 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? new_list(new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yyloc)) : 0;
@@ -7427,11 +7419,11 @@ yyreduce:
 			(yyval.val) = arg_add_assocs(arg_new(), (yyvsp[-1].val));
 
 		    }
-#line 7427 "ripper.c" /* yacc.c:1646  */
+#line 7419 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 251:
-#line 2447 "ripper.y" /* yacc.c:1646  */
+#line 2439 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[0].val));
@@ -7439,11 +7431,11 @@ yyreduce:
 #endif
 
 		    }
-#line 7439 "ripper.c" /* yacc.c:1646  */
+#line 7431 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 252:
-#line 2455 "ripper.y" /* yacc.c:1646  */
+#line 2447 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			YYLTYPE location;
@@ -7455,11 +7447,11 @@ yyreduce:
 			(yyval.val) = dispatch2(rescue_mod, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 7455 "ripper.c" /* yacc.c:1646  */
+#line 7447 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 253:
-#line 2469 "ripper.y" /* yacc.c:1646  */
+#line 2461 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -7467,19 +7459,19 @@ yyreduce:
 			(yyval.val) = dispatch1(arg_paren, escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 7467 "ripper.c" /* yacc.c:1646  */
+#line 7459 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 258:
-#line 2485 "ripper.y" /* yacc.c:1646  */
+#line 2477 "ripper.y" /* yacc.c:1646  */
     {
 		      (yyval.val) = (yyvsp[-1].val);
 		    }
-#line 7475 "ripper.c" /* yacc.c:1646  */
+#line 7467 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 259:
-#line 2489 "ripper.y" /* yacc.c:1646  */
+#line 2481 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? arg_append((yyvsp[-3].val), new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].val);
@@ -7487,11 +7479,11 @@ yyreduce:
 			(yyval.val) = arg_add_assocs((yyvsp[-3].val), (yyvsp[-1].val));
 
 		    }
-#line 7487 "ripper.c" /* yacc.c:1646  */
+#line 7479 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 260:
-#line 2497 "ripper.y" /* yacc.c:1646  */
+#line 2489 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? new_list(new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yylsp[-1])) : 0;
@@ -7499,11 +7491,11 @@ yyreduce:
 			(yyval.val) = arg_add_assocs(arg_new(), (yyvsp[-1].val));
 
 		    }
-#line 7499 "ripper.c" /* yacc.c:1646  */
+#line 7491 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 261:
-#line 2507 "ripper.y" /* yacc.c:1646  */
+#line 2499 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[0].val));
@@ -7512,11 +7504,11 @@ yyreduce:
 			(yyval.val) = arg_add(arg_new(), (yyvsp[0].val));
 
 		    }
-#line 7512 "ripper.c" /* yacc.c:1646  */
+#line 7504 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 262:
-#line 2516 "ripper.y" /* yacc.c:1646  */
+#line 2508 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = arg_blk_pass((yyvsp[-1].val), (yyvsp[0].val));
@@ -7524,11 +7516,11 @@ yyreduce:
 			(yyval.val) = arg_add_optblock((yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 7524 "ripper.c" /* yacc.c:1646  */
+#line 7516 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 263:
-#line 2524 "ripper.y" /* yacc.c:1646  */
+#line 2516 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? new_list(new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yylsp[-1])) : 0;
@@ -7538,11 +7530,11 @@ yyreduce:
 			(yyval.val) = arg_add_optblock((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 7538 "ripper.c" /* yacc.c:1646  */
+#line 7530 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 264:
-#line 2534 "ripper.y" /* yacc.c:1646  */
+#line 2526 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val) ? arg_append((yyvsp[-3].val), new_hash((yyvsp[-1].val), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].val);
@@ -7551,38 +7543,38 @@ yyreduce:
 			(yyval.val) = arg_add_optblock(arg_add_assocs((yyvsp[-3].val), (yyvsp[-1].val)), (yyvsp[0].val));
 
 		    }
-#line 7551 "ripper.c" /* yacc.c:1646  */
+#line 7543 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 265:
-#line 2545 "ripper.y" /* yacc.c:1646  */
+#line 2537 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = arg_add_block(arg_new(), (yyvsp[0].val));
 		    }
-#line 7559 "ripper.c" /* yacc.c:1646  */
+#line 7551 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 266:
-#line 2551 "ripper.y" /* yacc.c:1646  */
+#line 2543 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = cmdarg_stack;
 			CMDARG_PUSH(1);
 		    }
-#line 7568 "ripper.c" /* yacc.c:1646  */
+#line 7560 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 267:
-#line 2556 "ripper.y" /* yacc.c:1646  */
+#line 2548 "ripper.y" /* yacc.c:1646  */
     {
 			/* CMDARG_POP() */
 			CMDARG_SET((yyvsp[-1].val));
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 7578 "ripper.c" /* yacc.c:1646  */
+#line 7570 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 268:
-#line 2564 "ripper.y" /* yacc.c:1646  */
+#line 2556 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_BLOCK_PASS((yyvsp[0].val));
@@ -7591,27 +7583,27 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 7591 "ripper.c" /* yacc.c:1646  */
+#line 7583 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 269:
-#line 2575 "ripper.y" /* yacc.c:1646  */
+#line 2567 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 7599 "ripper.c" /* yacc.c:1646  */
+#line 7591 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 270:
-#line 2579 "ripper.y" /* yacc.c:1646  */
+#line 2571 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = 0;
 		    }
-#line 7607 "ripper.c" /* yacc.c:1646  */
+#line 7599 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 271:
-#line 2585 "ripper.y" /* yacc.c:1646  */
+#line 2577 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_list((yyvsp[0].val), &(yyloc));
@@ -7619,11 +7611,11 @@ yyreduce:
 			(yyval.val) = arg_add(arg_new(), (yyvsp[0].val));
 
 		    }
-#line 7619 "ripper.c" /* yacc.c:1646  */
+#line 7611 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 272:
-#line 2593 "ripper.y" /* yacc.c:1646  */
+#line 2585 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_SPLAT((yyvsp[0].val));
@@ -7632,11 +7624,11 @@ yyreduce:
 			(yyval.val) = arg_add_star(arg_new(), (yyvsp[0].val));
 
 		    }
-#line 7632 "ripper.c" /* yacc.c:1646  */
+#line 7624 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 273:
-#line 2602 "ripper.y" /* yacc.c:1646  */
+#line 2594 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *n1;
@@ -7650,11 +7642,11 @@ yyreduce:
 			(yyval.val) = arg_add((yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 7650 "ripper.c" /* yacc.c:1646  */
+#line 7642 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 274:
-#line 2616 "ripper.y" /* yacc.c:1646  */
+#line 2608 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *n1;
@@ -7668,11 +7660,11 @@ yyreduce:
 			(yyval.val) = arg_add_star((yyvsp[-3].val), (yyvsp[0].val));
 
 		    }
-#line 7668 "ripper.c" /* yacc.c:1646  */
+#line 7660 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 277:
-#line 2636 "ripper.y" /* yacc.c:1646  */
+#line 2628 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *n1;
@@ -7686,11 +7678,11 @@ yyreduce:
 			(yyval.val) = mrhs_add(args2mrhs((yyvsp[-2].val)), (yyvsp[0].val));
 
 		    }
-#line 7686 "ripper.c" /* yacc.c:1646  */
+#line 7678 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 278:
-#line 2650 "ripper.y" /* yacc.c:1646  */
+#line 2642 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *n1;
@@ -7705,11 +7697,11 @@ yyreduce:
 			(yyval.val) = mrhs_add_star(args2mrhs((yyvsp[-3].val)), (yyvsp[0].val));
 
 		    }
-#line 7705 "ripper.c" /* yacc.c:1646  */
+#line 7697 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 279:
-#line 2665 "ripper.y" /* yacc.c:1646  */
+#line 2657 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_SPLAT((yyvsp[0].val));
@@ -7718,11 +7710,11 @@ yyreduce:
 			(yyval.val) = mrhs_add_star(mrhs_new(), (yyvsp[0].val));
 
 		    }
-#line 7718 "ripper.c" /* yacc.c:1646  */
+#line 7710 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 290:
-#line 2686 "ripper.y" /* yacc.c:1646  */
+#line 2678 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_fcall((yyvsp[0].val), 0, &(yyloc));
@@ -7730,11 +7722,11 @@ yyreduce:
 			(yyval.val) = method_arg(dispatch1(fcall, (yyvsp[0].val)), arg_new());
 
 		    }
-#line 7730 "ripper.c" /* yacc.c:1646  */
+#line 7722 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 291:
-#line 2694 "ripper.y" /* yacc.c:1646  */
+#line 2686 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cmdarg_stack;
 			CMDARG_SET(0);
@@ -7743,11 +7735,11 @@ yyreduce:
 #endif
 
 		    }
-#line 7743 "ripper.c" /* yacc.c:1646  */
+#line 7735 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 292:
-#line 2704 "ripper.y" /* yacc.c:1646  */
+#line 2696 "ripper.y" /* yacc.c:1646  */
     {
 			CMDARG_SET((yyvsp[-3].val));
 #if 0
@@ -7764,17 +7756,17 @@ yyreduce:
 			(yyval.val) = dispatch1(begin, (yyvsp[-1].val));
 
 		    }
-#line 7764 "ripper.c" /* yacc.c:1646  */
+#line 7756 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 293:
-#line 2720 "ripper.y" /* yacc.c:1646  */
+#line 2712 "ripper.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_ENDARG);}
-#line 7770 "ripper.c" /* yacc.c:1646  */
+#line 7762 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 294:
-#line 2721 "ripper.y" /* yacc.c:1646  */
+#line 2713 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_begin(0, &(yyloc));
@@ -7782,26 +7774,26 @@ yyreduce:
 			(yyval.val) = dispatch1(paren, 0);
 
 		    }
-#line 7782 "ripper.c" /* yacc.c:1646  */
+#line 7774 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 295:
-#line 2729 "ripper.y" /* yacc.c:1646  */
+#line 2721 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cmdarg_stack;
 			CMDARG_SET(0);
 		    }
-#line 7791 "ripper.c" /* yacc.c:1646  */
+#line 7783 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 296:
-#line 2733 "ripper.y" /* yacc.c:1646  */
+#line 2725 "ripper.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_ENDARG);}
-#line 7797 "ripper.c" /* yacc.c:1646  */
+#line 7789 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 297:
-#line 2734 "ripper.y" /* yacc.c:1646  */
+#line 2726 "ripper.y" /* yacc.c:1646  */
     {
 			CMDARG_SET((yyvsp[-4].val));
 #if 0
@@ -7810,11 +7802,11 @@ yyreduce:
 			(yyval.val) = dispatch1(paren, (yyvsp[-2].val));
 
 		    }
-#line 7810 "ripper.c" /* yacc.c:1646  */
+#line 7802 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 298:
-#line 2743 "ripper.y" /* yacc.c:1646  */
+#line 2735 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -7822,11 +7814,11 @@ yyreduce:
 			(yyval.val) = dispatch1(paren, (yyvsp[-1].val));
 
 		    }
-#line 7822 "ripper.c" /* yacc.c:1646  */
+#line 7814 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 299:
-#line 2751 "ripper.y" /* yacc.c:1646  */
+#line 2743 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_COLON2((yyvsp[-2].val), (yyvsp[0].val));
@@ -7835,11 +7827,11 @@ yyreduce:
 			(yyval.val) = dispatch2(const_path_ref, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 7835 "ripper.c" /* yacc.c:1646  */
+#line 7827 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 300:
-#line 2760 "ripper.y" /* yacc.c:1646  */
+#line 2752 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_COLON3((yyvsp[0].val));
@@ -7848,11 +7840,11 @@ yyreduce:
 			(yyval.val) = dispatch1(top_const_ref, (yyvsp[0].val));
 
 		    }
-#line 7848 "ripper.c" /* yacc.c:1646  */
+#line 7840 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 301:
-#line 2769 "ripper.y" /* yacc.c:1646  */
+#line 2761 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = make_array((yyvsp[-1].val), &(yyloc));
@@ -7860,11 +7852,11 @@ yyreduce:
 			(yyval.val) = dispatch1(array, escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 7860 "ripper.c" /* yacc.c:1646  */
+#line 7852 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 302:
-#line 2777 "ripper.y" /* yacc.c:1646  */
+#line 2769 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_hash((yyvsp[-1].val), &(yyloc));
@@ -7873,11 +7865,11 @@ yyreduce:
 			(yyval.val) = dispatch1(hash, escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 7873 "ripper.c" /* yacc.c:1646  */
+#line 7865 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 303:
-#line 2786 "ripper.y" /* yacc.c:1646  */
+#line 2778 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_RETURN(0);
@@ -7886,11 +7878,11 @@ yyreduce:
 			(yyval.val) = dispatch0(return0);
 
 		    }
-#line 7886 "ripper.c" /* yacc.c:1646  */
+#line 7878 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 304:
-#line 2795 "ripper.y" /* yacc.c:1646  */
+#line 2787 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_yield((yyvsp[-1].val), &(yyloc));
@@ -7898,11 +7890,11 @@ yyreduce:
 			(yyval.val) = dispatch1(yield, dispatch1(paren, (yyvsp[-1].val)));
 
 		    }
-#line 7898 "ripper.c" /* yacc.c:1646  */
+#line 7890 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 305:
-#line 2803 "ripper.y" /* yacc.c:1646  */
+#line 2795 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_YIELD(0);
@@ -7911,11 +7903,11 @@ yyreduce:
 			(yyval.val) = dispatch1(yield, dispatch1(paren, arg_new()));
 
 		    }
-#line 7911 "ripper.c" /* yacc.c:1646  */
+#line 7903 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 306:
-#line 2812 "ripper.y" /* yacc.c:1646  */
+#line 2804 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_YIELD(0);
@@ -7924,42 +7916,42 @@ yyreduce:
 			(yyval.val) = dispatch0(yield0);
 
 		    }
-#line 7924 "ripper.c" /* yacc.c:1646  */
+#line 7916 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 307:
-#line 2820 "ripper.y" /* yacc.c:1646  */
+#line 2812 "ripper.y" /* yacc.c:1646  */
     {in_defined = 1;}
-#line 7930 "ripper.c" /* yacc.c:1646  */
+#line 7922 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 308:
-#line 2821 "ripper.y" /* yacc.c:1646  */
+#line 2813 "ripper.y" /* yacc.c:1646  */
     {
 			in_defined = 0;
 			(yyval.val) = new_defined((yyvsp[-1].val), &(yyloc));
 		    }
-#line 7939 "ripper.c" /* yacc.c:1646  */
+#line 7931 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 309:
-#line 2826 "ripper.y" /* yacc.c:1646  */
+#line 2818 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op(method_cond((yyvsp[-1].val), &(yylsp[-1])), METHOD_NOT, &(yylsp[-3]), &(yyloc));
 		    }
-#line 7947 "ripper.c" /* yacc.c:1646  */
+#line 7939 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 310:
-#line 2830 "ripper.y" /* yacc.c:1646  */
+#line 2822 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = call_uni_op(method_cond(new_nil(&(yylsp[-1])), &(yylsp[-1])), METHOD_NOT, &(yylsp[-2]), &(yyloc));
 		    }
-#line 7955 "ripper.c" /* yacc.c:1646  */
+#line 7947 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 311:
-#line 2834 "ripper.y" /* yacc.c:1646  */
+#line 2826 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyvsp[0].val)->nd_iter = (yyvsp[-1].val);
@@ -7970,11 +7962,11 @@ yyreduce:
 			(yyval.val) = method_add_block((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 7970 "ripper.c" /* yacc.c:1646  */
+#line 7962 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 313:
-#line 2846 "ripper.y" /* yacc.c:1646  */
+#line 2838 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			block_dup_check((yyvsp[-1].val)->nd_args, (yyvsp[0].val));
@@ -7985,19 +7977,19 @@ yyreduce:
 			(yyval.val) = method_add_block((yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 7985 "ripper.c" /* yacc.c:1646  */
+#line 7977 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 314:
-#line 2857 "ripper.y" /* yacc.c:1646  */
+#line 2849 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 7993 "ripper.c" /* yacc.c:1646  */
+#line 7985 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 315:
-#line 2864 "ripper.y" /* yacc.c:1646  */
+#line 2856 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_if((yyvsp[-4].val), (yyvsp[-2].val), (yyvsp[-1].val), &(yyloc));
@@ -8006,11 +7998,11 @@ yyreduce:
 			(yyval.val) = dispatch3(if, (yyvsp[-4].val), (yyvsp[-2].val), escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 8006 "ripper.c" /* yacc.c:1646  */
+#line 7998 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 316:
-#line 2876 "ripper.y" /* yacc.c:1646  */
+#line 2868 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_unless((yyvsp[-4].val), (yyvsp[-2].val), (yyvsp[-1].val), &(yyloc));
@@ -8019,23 +8011,23 @@ yyreduce:
 			(yyval.val) = dispatch3(unless, (yyvsp[-4].val), (yyvsp[-2].val), escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 8019 "ripper.c" /* yacc.c:1646  */
+#line 8011 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 317:
-#line 2884 "ripper.y" /* yacc.c:1646  */
+#line 2876 "ripper.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8025 "ripper.c" /* yacc.c:1646  */
+#line 8017 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 318:
-#line 2884 "ripper.y" /* yacc.c:1646  */
+#line 2876 "ripper.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8031 "ripper.c" /* yacc.c:1646  */
+#line 8023 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 319:
-#line 2887 "ripper.y" /* yacc.c:1646  */
+#line 2879 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_WHILE(cond((yyvsp[-4].val), &(yylsp[-4])), (yyvsp[-1].val), 1);
@@ -8045,23 +8037,23 @@ yyreduce:
 			(yyval.val) = dispatch2(while, (yyvsp[-4].val), (yyvsp[-1].val));
 
 		    }
-#line 8045 "ripper.c" /* yacc.c:1646  */
+#line 8037 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 320:
-#line 2896 "ripper.y" /* yacc.c:1646  */
+#line 2888 "ripper.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8051 "ripper.c" /* yacc.c:1646  */
+#line 8043 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 321:
-#line 2896 "ripper.y" /* yacc.c:1646  */
+#line 2888 "ripper.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8057 "ripper.c" /* yacc.c:1646  */
+#line 8049 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 322:
-#line 2899 "ripper.y" /* yacc.c:1646  */
+#line 2891 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_UNTIL(cond((yyvsp[-4].val), &(yylsp[-4])), (yyvsp[-1].val), 1);
@@ -8071,11 +8063,11 @@ yyreduce:
 			(yyval.val) = dispatch2(until, (yyvsp[-4].val), (yyvsp[-1].val));
 
 		    }
-#line 8071 "ripper.c" /* yacc.c:1646  */
+#line 8063 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 323:
-#line 2911 "ripper.y" /* yacc.c:1646  */
+#line 2903 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_CASE((yyvsp[-3].val), (yyvsp[-1].val));
@@ -8085,11 +8077,11 @@ yyreduce:
 			(yyval.val) = dispatch2(case, (yyvsp[-3].val), (yyvsp[-1].val));
 
 		    }
-#line 8085 "ripper.c" /* yacc.c:1646  */
+#line 8077 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 324:
-#line 2921 "ripper.y" /* yacc.c:1646  */
+#line 2913 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_CASE2((yyvsp[-1].val));
@@ -8099,23 +8091,23 @@ yyreduce:
 			(yyval.val) = dispatch2(case, Qnil, (yyvsp[-1].val));
 
 		    }
-#line 8099 "ripper.c" /* yacc.c:1646  */
+#line 8091 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 325:
-#line 2931 "ripper.y" /* yacc.c:1646  */
+#line 2923 "ripper.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8105 "ripper.c" /* yacc.c:1646  */
+#line 8097 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 326:
-#line 2933 "ripper.y" /* yacc.c:1646  */
+#line 2925 "ripper.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8111 "ripper.c" /* yacc.c:1646  */
+#line 8103 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 327:
-#line 2936 "ripper.y" /* yacc.c:1646  */
+#line 2928 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			/*
@@ -8163,11 +8155,11 @@ yyreduce:
 			(yyval.val) = dispatch3(for, (yyvsp[-7].val), (yyvsp[-4].val), (yyvsp[-1].val));
 
 		    }
-#line 8163 "ripper.c" /* yacc.c:1646  */
+#line 8155 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 328:
-#line 2984 "ripper.y" /* yacc.c:1646  */
+#line 2976 "ripper.y" /* yacc.c:1646  */
     {
 			if (in_def)
 			    yyerror0("class definition in method body");
@@ -8179,11 +8171,11 @@ yyreduce:
 #endif
 
 		    }
-#line 8179 "ripper.c" /* yacc.c:1646  */
+#line 8171 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 329:
-#line 2997 "ripper.y" /* yacc.c:1646  */
+#line 2989 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_CLASS((yyvsp[-4].val), (yyvsp[-1].val), (yyvsp[-3].val));
@@ -8197,22 +8189,22 @@ yyreduce:
 			local_pop();
 			in_class = (yyvsp[-5].num) & 1;
 		    }
-#line 8197 "ripper.c" /* yacc.c:1646  */
+#line 8189 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 330:
-#line 3011 "ripper.y" /* yacc.c:1646  */
+#line 3003 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = (in_class << 1) | in_def;
 			in_def = 0;
 			in_class = 0;
 			local_push(0);
 		    }
-#line 8208 "ripper.c" /* yacc.c:1646  */
+#line 8200 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 331:
-#line 3020 "ripper.y" /* yacc.c:1646  */
+#line 3012 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_SCLASS((yyvsp[-4].val), (yyvsp[-1].val));
@@ -8227,11 +8219,11 @@ yyreduce:
 			in_def = (yyvsp[-3].num) & 1;
 			in_class = ((yyvsp[-3].num) >> 1) & 1;
 		    }
-#line 8227 "ripper.c" /* yacc.c:1646  */
+#line 8219 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 332:
-#line 3035 "ripper.y" /* yacc.c:1646  */
+#line 3027 "ripper.y" /* yacc.c:1646  */
     {
 			if (in_def)
 			    yyerror0("module definition in method body");
@@ -8243,11 +8235,11 @@ yyreduce:
 #endif
 
 		    }
-#line 8243 "ripper.c" /* yacc.c:1646  */
+#line 8235 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 333:
-#line 3048 "ripper.y" /* yacc.c:1646  */
+#line 3040 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_MODULE((yyvsp[-3].val), (yyvsp[-1].val));
@@ -8261,30 +8253,30 @@ yyreduce:
 			local_pop();
 			in_class = (yyvsp[-4].num) & 1;
 		    }
-#line 8261 "ripper.c" /* yacc.c:1646  */
+#line 8253 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 334:
-#line 3062 "ripper.y" /* yacc.c:1646  */
+#line 3054 "ripper.y" /* yacc.c:1646  */
     {
 			local_push(0);
 			(yyval.id) = current_arg;
 			current_arg = 0;
 		    }
-#line 8271 "ripper.c" /* yacc.c:1646  */
+#line 8263 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 335:
-#line 3067 "ripper.y" /* yacc.c:1646  */
+#line 3059 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = in_def;
 			in_def = 1;
 		    }
-#line 8280 "ripper.c" /* yacc.c:1646  */
+#line 8272 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 336:
-#line 3074 "ripper.y" /* yacc.c:1646  */
+#line 3066 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *body = remove_begin((yyvsp[-1].val));
@@ -8301,17 +8293,17 @@ yyreduce:
 			in_def = (yyvsp[-3].num) & 1;
 			current_arg = (yyvsp[-4].id);
 		    }
-#line 8301 "ripper.c" /* yacc.c:1646  */
+#line 8293 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 337:
-#line 3090 "ripper.y" /* yacc.c:1646  */
+#line 3082 "ripper.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_FNAME);}
-#line 8307 "ripper.c" /* yacc.c:1646  */
+#line 8299 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 338:
-#line 3091 "ripper.y" /* yacc.c:1646  */
+#line 3083 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[-1].num) = in_def;
 			in_def = 1;
@@ -8320,11 +8312,11 @@ yyreduce:
 			(yyval.id) = current_arg;
 			current_arg = 0;
 		    }
-#line 8320 "ripper.c" /* yacc.c:1646  */
+#line 8312 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 339:
-#line 3102 "ripper.y" /* yacc.c:1646  */
+#line 3094 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *body = remove_begin((yyvsp[-1].val));
@@ -8341,11 +8333,11 @@ yyreduce:
 			in_def = (yyvsp[-5].num) & 1;
 			current_arg = (yyvsp[-3].id);
 		    }
-#line 8341 "ripper.c" /* yacc.c:1646  */
+#line 8333 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 340:
-#line 3119 "ripper.y" /* yacc.c:1646  */
+#line 3111 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_BREAK(0);
@@ -8354,11 +8346,11 @@ yyreduce:
 			(yyval.val) = dispatch1(break, arg_new());
 
 		    }
-#line 8354 "ripper.c" /* yacc.c:1646  */
+#line 8346 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 341:
-#line 3128 "ripper.y" /* yacc.c:1646  */
+#line 3120 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_NEXT(0);
@@ -8367,11 +8359,11 @@ yyreduce:
 			(yyval.val) = dispatch1(next, arg_new());
 
 		    }
-#line 8367 "ripper.c" /* yacc.c:1646  */
+#line 8359 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 342:
-#line 3137 "ripper.y" /* yacc.c:1646  */
+#line 3129 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_REDO();
@@ -8380,11 +8372,11 @@ yyreduce:
 			(yyval.val) = dispatch0(redo);
 
 		    }
-#line 8380 "ripper.c" /* yacc.c:1646  */
+#line 8372 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 343:
-#line 3146 "ripper.y" /* yacc.c:1646  */
+#line 3138 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_RETRY();
@@ -8393,11 +8385,11 @@ yyreduce:
 			(yyval.val) = dispatch0(retry);
 
 		    }
-#line 8393 "ripper.c" /* yacc.c:1646  */
+#line 8385 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 344:
-#line 3157 "ripper.y" /* yacc.c:1646  */
+#line 3149 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[0].val));
@@ -8407,51 +8399,51 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 8407 "ripper.c" /* yacc.c:1646  */
+#line 8399 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 345:
-#line 3169 "ripper.y" /* yacc.c:1646  */
+#line 3161 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("begin");
 		    }
-#line 8415 "ripper.c" /* yacc.c:1646  */
+#line 8407 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 346:
-#line 3175 "ripper.y" /* yacc.c:1646  */
+#line 3167 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("if");
 		    }
-#line 8423 "ripper.c" /* yacc.c:1646  */
+#line 8415 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 347:
-#line 3181 "ripper.y" /* yacc.c:1646  */
+#line 3173 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("unless");
 		    }
-#line 8431 "ripper.c" /* yacc.c:1646  */
+#line 8423 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 348:
-#line 3187 "ripper.y" /* yacc.c:1646  */
+#line 3179 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("while");
 		    }
-#line 8439 "ripper.c" /* yacc.c:1646  */
+#line 8431 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 349:
-#line 3193 "ripper.y" /* yacc.c:1646  */
+#line 3185 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("until");
 		    }
-#line 8447 "ripper.c" /* yacc.c:1646  */
+#line 8439 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 350:
-#line 3199 "ripper.y" /* yacc.c:1646  */
+#line 3191 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("case");
 #if 0
@@ -8459,35 +8451,35 @@ yyreduce:
 #endif
 
 		    }
-#line 8459 "ripper.c" /* yacc.c:1646  */
+#line 8451 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 351:
-#line 3209 "ripper.y" /* yacc.c:1646  */
+#line 3201 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("for");
 		    }
-#line 8467 "ripper.c" /* yacc.c:1646  */
+#line 8459 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 352:
-#line 3215 "ripper.y" /* yacc.c:1646  */
+#line 3207 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("class");
 		    }
-#line 8475 "ripper.c" /* yacc.c:1646  */
+#line 8467 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 353:
-#line 3221 "ripper.y" /* yacc.c:1646  */
+#line 3213 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("module");
 		    }
-#line 8483 "ripper.c" /* yacc.c:1646  */
+#line 8475 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 354:
-#line 3227 "ripper.y" /* yacc.c:1646  */
+#line 3219 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_push("def");
 #if 0
@@ -8495,46 +8487,46 @@ yyreduce:
 #endif
 
 		    }
-#line 8495 "ripper.c" /* yacc.c:1646  */
+#line 8487 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 355:
-#line 3237 "ripper.y" /* yacc.c:1646  */
+#line 3229 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_pop("end");
 		    }
-#line 8503 "ripper.c" /* yacc.c:1646  */
+#line 8495 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 356:
-#line 3243 "ripper.y" /* yacc.c:1646  */
+#line 3235 "ripper.y" /* yacc.c:1646  */
     {
 			if (in_class && !in_def && !dyna_in_block())
 			    yyerror0("Invalid return in class/module body");
 		    }
-#line 8512 "ripper.c" /* yacc.c:1646  */
+#line 8504 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 357:
-#line 3252 "ripper.y" /* yacc.c:1646  */
+#line 3244 "ripper.y" /* yacc.c:1646  */
     { (yyval.val) = Qnil; }
-#line 8518 "ripper.c" /* yacc.c:1646  */
+#line 8510 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 359:
-#line 3258 "ripper.y" /* yacc.c:1646  */
+#line 3250 "ripper.y" /* yacc.c:1646  */
     { (yyval.val) = (yyvsp[0].val); }
-#line 8524 "ripper.c" /* yacc.c:1646  */
+#line 8516 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 360:
-#line 3265 "ripper.y" /* yacc.c:1646  */
+#line 3257 "ripper.y" /* yacc.c:1646  */
     { (yyval.val) = Qnil; }
-#line 8530 "ripper.c" /* yacc.c:1646  */
+#line 8522 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 363:
-#line 3274 "ripper.y" /* yacc.c:1646  */
+#line 3266 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_if((yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -8543,11 +8535,11 @@ yyreduce:
 			(yyval.val) = dispatch3(elsif, (yyvsp[-3].val), (yyvsp[-1].val), escape_Qundef((yyvsp[0].val)));
 
 		    }
-#line 8543 "ripper.c" /* yacc.c:1646  */
+#line 8535 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 365:
-#line 3286 "ripper.y" /* yacc.c:1646  */
+#line 3278 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -8555,22 +8547,22 @@ yyreduce:
 			(yyval.val) = dispatch1(else, (yyvsp[0].val));
 
 		    }
-#line 8555 "ripper.c" /* yacc.c:1646  */
+#line 8547 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 368:
-#line 3300 "ripper.y" /* yacc.c:1646  */
+#line 3292 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[0].val), 0, &(yyloc));
 #if 0
 #endif
 
 		    }
-#line 8566 "ripper.c" /* yacc.c:1646  */
+#line 8558 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 369:
-#line 3307 "ripper.y" /* yacc.c:1646  */
+#line 3299 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -8578,11 +8570,11 @@ yyreduce:
 			(yyval.val) = dispatch1(mlhs_paren, (yyvsp[-1].val));
 
 		    }
-#line 8578 "ripper.c" /* yacc.c:1646  */
+#line 8570 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 370:
-#line 3317 "ripper.y" /* yacc.c:1646  */
+#line 3309 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_list((yyvsp[0].val), &(yyloc));
@@ -8590,11 +8582,11 @@ yyreduce:
 			(yyval.val) = mlhs_add(mlhs_new(), (yyvsp[0].val));
 
 		    }
-#line 8590 "ripper.c" /* yacc.c:1646  */
+#line 8582 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 371:
-#line 3325 "ripper.y" /* yacc.c:1646  */
+#line 3317 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = list_append((yyvsp[-2].val), (yyvsp[0].val));
@@ -8602,11 +8594,11 @@ yyreduce:
 			(yyval.val) = mlhs_add((yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 8602 "ripper.c" /* yacc.c:1646  */
+#line 8594 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 372:
-#line 3335 "ripper.y" /* yacc.c:1646  */
+#line 3327 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_masgn((yyvsp[0].val), 0, &(yyloc));
@@ -8614,11 +8606,11 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 8614 "ripper.c" /* yacc.c:1646  */
+#line 8606 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 373:
-#line 3343 "ripper.y" /* yacc.c:1646  */
+#line 3335 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[0].val), 0, &(yyloc));
 #if 0
@@ -8627,11 +8619,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_star((yyvsp[-3].val), (yyval.val));
 
 		    }
-#line 8627 "ripper.c" /* yacc.c:1646  */
+#line 8619 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 374:
-#line 3352 "ripper.y" /* yacc.c:1646  */
+#line 3344 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[-2].val), 0, &(yyloc));
 #if 0
@@ -8641,11 +8633,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_post((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 8641 "ripper.c" /* yacc.c:1646  */
+#line 8633 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 375:
-#line 3362 "ripper.y" /* yacc.c:1646  */
+#line 3354 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_masgn((yyvsp[-2].val), NODE_SPECIAL_NO_NAME_REST, &(yyloc));
@@ -8653,11 +8645,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_star((yyvsp[-2].val), Qnil);
 
 		    }
-#line 8653 "ripper.c" /* yacc.c:1646  */
+#line 8645 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 376:
-#line 3370 "ripper.y" /* yacc.c:1646  */
+#line 3362 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_masgn((yyvsp[-4].val), new_postarg(NODE_SPECIAL_NO_NAME_REST, (yyvsp[0].val), &(yyloc)), &(yyloc));
@@ -8666,11 +8658,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_post((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 8666 "ripper.c" /* yacc.c:1646  */
+#line 8658 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 377:
-#line 3379 "ripper.y" /* yacc.c:1646  */
+#line 3371 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[0].val), 0, &(yyloc));
 #if 0
@@ -8679,11 +8671,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_star(mlhs_new(), (yyval.val));
 
 		    }
-#line 8679 "ripper.c" /* yacc.c:1646  */
+#line 8671 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 378:
-#line 3388 "ripper.y" /* yacc.c:1646  */
+#line 3380 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[-2].val), 0, &(yyloc));
 #if 0
@@ -8693,11 +8685,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_post((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 8693 "ripper.c" /* yacc.c:1646  */
+#line 8685 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 379:
-#line 3398 "ripper.y" /* yacc.c:1646  */
+#line 3390 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_masgn(0, NODE_SPECIAL_NO_NAME_REST, &(yyloc));
@@ -8705,11 +8697,11 @@ yyreduce:
 			(yyval.val) = mlhs_add_star(mlhs_new(), Qnil);
 
 		    }
-#line 8705 "ripper.c" /* yacc.c:1646  */
+#line 8697 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 380:
-#line 3406 "ripper.y" /* yacc.c:1646  */
+#line 3398 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_masgn(0, new_postarg(NODE_SPECIAL_NO_NAME_REST, (yyvsp[0].val), &(yyloc)), &(yyloc));
@@ -8718,99 +8710,99 @@ yyreduce:
 			(yyval.val) = mlhs_add_post((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 8718 "ripper.c" /* yacc.c:1646  */
+#line 8710 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 381:
-#line 3418 "ripper.y" /* yacc.c:1646  */
+#line 3410 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail((yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 8726 "ripper.c" /* yacc.c:1646  */
+#line 8718 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 382:
-#line 3422 "ripper.y" /* yacc.c:1646  */
+#line 3414 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail((yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 8734 "ripper.c" /* yacc.c:1646  */
+#line 8726 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 383:
-#line 3426 "ripper.y" /* yacc.c:1646  */
+#line 3418 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 8742 "ripper.c" /* yacc.c:1646  */
+#line 8734 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 384:
-#line 3430 "ripper.y" /* yacc.c:1646  */
+#line 3422 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, Qnone, (yyvsp[0].val), &(yylsp[0]));
 		    }
-#line 8750 "ripper.c" /* yacc.c:1646  */
+#line 8742 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 385:
-#line 3436 "ripper.y" /* yacc.c:1646  */
+#line 3428 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 8758 "ripper.c" /* yacc.c:1646  */
+#line 8750 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 386:
-#line 3440 "ripper.y" /* yacc.c:1646  */
+#line 3432 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 		    }
-#line 8766 "ripper.c" /* yacc.c:1646  */
+#line 8758 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 387:
-#line 3446 "ripper.y" /* yacc.c:1646  */
+#line 3438 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8774 "ripper.c" /* yacc.c:1646  */
+#line 8766 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 388:
-#line 3450 "ripper.y" /* yacc.c:1646  */
+#line 3442 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-7].val), (yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8782 "ripper.c" /* yacc.c:1646  */
+#line 8774 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 389:
-#line 3454 "ripper.y" /* yacc.c:1646  */
+#line 3446 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-3].val), (yyvsp[-1].val), Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8790 "ripper.c" /* yacc.c:1646  */
+#line 8782 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 390:
-#line 3458 "ripper.y" /* yacc.c:1646  */
+#line 3450 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), (yyvsp[-3].val), Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8798 "ripper.c" /* yacc.c:1646  */
+#line 8790 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 391:
-#line 3462 "ripper.y" /* yacc.c:1646  */
+#line 3454 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-3].val), Qnone, (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8806 "ripper.c" /* yacc.c:1646  */
+#line 8798 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 392:
-#line 3466 "ripper.y" /* yacc.c:1646  */
+#line 3458 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-1].val), Qnone, 1, Qnone, new_args_tail(Qnone, Qnone, Qnone, &(yylsp[-1])), &(yyloc));
 #if 0
@@ -8818,91 +8810,91 @@ yyreduce:
                         dispatch1(excessed_comma, (yyval.val));
 
 		    }
-#line 8818 "ripper.c" /* yacc.c:1646  */
+#line 8810 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 393:
-#line 3474 "ripper.y" /* yacc.c:1646  */
+#line 3466 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), Qnone, (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8826 "ripper.c" /* yacc.c:1646  */
+#line 8818 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 394:
-#line 3478 "ripper.y" /* yacc.c:1646  */
+#line 3470 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-1].val), Qnone, Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8834 "ripper.c" /* yacc.c:1646  */
+#line 8826 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 395:
-#line 3482 "ripper.y" /* yacc.c:1646  */
+#line 3474 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-3].val), (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8842 "ripper.c" /* yacc.c:1646  */
+#line 8834 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 396:
-#line 3486 "ripper.y" /* yacc.c:1646  */
+#line 3478 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8850 "ripper.c" /* yacc.c:1646  */
+#line 8842 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 397:
-#line 3490 "ripper.y" /* yacc.c:1646  */
+#line 3482 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-1].val), Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8858 "ripper.c" /* yacc.c:1646  */
+#line 8850 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 398:
-#line 3494 "ripper.y" /* yacc.c:1646  */
+#line 3486 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-3].val), Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8866 "ripper.c" /* yacc.c:1646  */
+#line 8858 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 399:
-#line 3498 "ripper.y" /* yacc.c:1646  */
+#line 3490 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8874 "ripper.c" /* yacc.c:1646  */
+#line 8866 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 400:
-#line 3502 "ripper.y" /* yacc.c:1646  */
+#line 3494 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 8882 "ripper.c" /* yacc.c:1646  */
+#line 8874 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 401:
-#line 3506 "ripper.y" /* yacc.c:1646  */
+#line 3498 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 8890 "ripper.c" /* yacc.c:1646  */
+#line 8882 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 403:
-#line 3513 "ripper.y" /* yacc.c:1646  */
+#line 3505 "ripper.y" /* yacc.c:1646  */
     {
 			command_start = TRUE;
 		    }
-#line 8898 "ripper.c" /* yacc.c:1646  */
+#line 8890 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 404:
-#line 3519 "ripper.y" /* yacc.c:1646  */
+#line 3511 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 #if 0
@@ -8912,11 +8904,11 @@ yyreduce:
                                           escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 8912 "ripper.c" /* yacc.c:1646  */
+#line 8904 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 405:
-#line 3529 "ripper.y" /* yacc.c:1646  */
+#line 3521 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -8925,11 +8917,11 @@ yyreduce:
                                           Qnil);
 
 		    }
-#line 8925 "ripper.c" /* yacc.c:1646  */
+#line 8917 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 406:
-#line 3538 "ripper.y" /* yacc.c:1646  */
+#line 3530 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 #if 0
@@ -8938,19 +8930,19 @@ yyreduce:
 			(yyval.val) = blockvar_new(escape_Qundef((yyvsp[-2].val)), escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 8938 "ripper.c" /* yacc.c:1646  */
+#line 8930 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 407:
-#line 3550 "ripper.y" /* yacc.c:1646  */
+#line 3542 "ripper.y" /* yacc.c:1646  */
     {
 		      (yyval.val) = 0;
 		    }
-#line 8946 "ripper.c" /* yacc.c:1646  */
+#line 8938 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 408:
-#line 3554 "ripper.y" /* yacc.c:1646  */
+#line 3546 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -8958,27 +8950,27 @@ yyreduce:
 			(yyval.val) = (yyvsp[-1].val);
 
 		    }
-#line 8958 "ripper.c" /* yacc.c:1646  */
+#line 8950 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 409:
-#line 3566 "ripper.y" /* yacc.c:1646  */
+#line 3558 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 		    }
-#line 8966 "ripper.c" /* yacc.c:1646  */
+#line 8958 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 410:
-#line 3573 "ripper.y" /* yacc.c:1646  */
+#line 3565 "ripper.y" /* yacc.c:1646  */
     {
 			rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 		    }
-#line 8974 "ripper.c" /* yacc.c:1646  */
+#line 8966 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 411:
-#line 3580 "ripper.y" /* yacc.c:1646  */
+#line 3572 "ripper.y" /* yacc.c:1646  */
     {
 			new_bv(get_id((yyvsp[0].val)));
 #if 0
@@ -8986,53 +8978,53 @@ yyreduce:
 			(yyval.val) = get_value((yyvsp[0].val));
 
 		    }
-#line 8986 "ripper.c" /* yacc.c:1646  */
+#line 8978 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 412:
-#line 3588 "ripper.y" /* yacc.c:1646  */
+#line 3580 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = 0;
 		    }
-#line 8994 "ripper.c" /* yacc.c:1646  */
+#line 8986 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 413:
-#line 3593 "ripper.y" /* yacc.c:1646  */
+#line 3585 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.vars) = dyna_push();
 		    }
-#line 9002 "ripper.c" /* yacc.c:1646  */
+#line 8994 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 414:
-#line 3596 "ripper.y" /* yacc.c:1646  */
+#line 3588 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = lpar_beg;
 			lpar_beg = ++paren_nest;
 		    }
-#line 9011 "ripper.c" /* yacc.c:1646  */
+#line 9003 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 415:
-#line 3601 "ripper.y" /* yacc.c:1646  */
+#line 3593 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = ruby_sourceline;
 		    }
-#line 9019 "ripper.c" /* yacc.c:1646  */
+#line 9011 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 416:
-#line 3604 "ripper.y" /* yacc.c:1646  */
+#line 3596 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = cmdarg_stack;
 			CMDARG_SET(0);
 		    }
-#line 9028 "ripper.c" /* yacc.c:1646  */
+#line 9020 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 417:
-#line 3609 "ripper.y" /* yacc.c:1646  */
+#line 3601 "ripper.y" /* yacc.c:1646  */
     {
 			lpar_beg = (yyvsp[-4].num);
 			CMDARG_SET((yyvsp[-1].val));
@@ -9047,11 +9039,11 @@ yyreduce:
 
 			dyna_pop((yyvsp[-5].vars));
 		    }
-#line 9047 "ripper.c" /* yacc.c:1646  */
+#line 9039 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 418:
-#line 3626 "ripper.y" /* yacc.c:1646  */
+#line 3618 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-2].val);
@@ -9059,46 +9051,46 @@ yyreduce:
 			(yyval.val) = dispatch1(paren, (yyvsp[-2].val));
 
 		    }
-#line 9059 "ripper.c" /* yacc.c:1646  */
+#line 9051 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 419:
-#line 3634 "ripper.y" /* yacc.c:1646  */
+#line 3626 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 9067 "ripper.c" /* yacc.c:1646  */
+#line 9059 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 420:
-#line 3640 "ripper.y" /* yacc.c:1646  */
+#line 3632 "ripper.y" /* yacc.c:1646  */
     {
 			token_info_pop("}");
 			(yyval.val) = (yyvsp[-1].val);
 		    }
-#line 9076 "ripper.c" /* yacc.c:1646  */
+#line 9068 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 421:
-#line 3645 "ripper.y" /* yacc.c:1646  */
+#line 3637 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 		    }
-#line 9084 "ripper.c" /* yacc.c:1646  */
+#line 9076 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 422:
-#line 3651 "ripper.y" /* yacc.c:1646  */
+#line 3643 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9094 "ripper.c" /* yacc.c:1646  */
+#line 9086 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 423:
-#line 3657 "ripper.y" /* yacc.c:1646  */
+#line 3649 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 #if 0
@@ -9107,11 +9099,11 @@ yyreduce:
 			nd_set_line((yyval.val), (yyvsp[-2].num));
 #endif
 		    }
-#line 9107 "ripper.c" /* yacc.c:1646  */
+#line 9099 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 424:
-#line 3668 "ripper.y" /* yacc.c:1646  */
+#line 3660 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (nd_type((yyvsp[-1].val)) == NODE_YIELD) {
@@ -9128,19 +9120,19 @@ yyreduce:
 			(yyval.val) = method_add_block((yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 9128 "ripper.c" /* yacc.c:1646  */
+#line 9120 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 425:
-#line 3685 "ripper.y" /* yacc.c:1646  */
+#line 3677 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall((yyvsp[-2].val), (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 9136 "ripper.c" /* yacc.c:1646  */
+#line 9128 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 426:
-#line 3689 "ripper.y" /* yacc.c:1646  */
+#line 3681 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			block_dup_check((yyvsp[-1].val), (yyvsp[0].val));
@@ -9153,11 +9145,11 @@ yyreduce:
 			(yyval.val) = method_add_block((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 9153 "ripper.c" /* yacc.c:1646  */
+#line 9145 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 427:
-#line 3702 "ripper.y" /* yacc.c:1646  */
+#line 3694 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			block_dup_check((yyvsp[-1].val), (yyvsp[0].val));
@@ -9170,11 +9162,11 @@ yyreduce:
 			(yyval.val) = method_add_block((yyval.val), (yyvsp[0].val));
 
 		    }
-#line 9170 "ripper.c" /* yacc.c:1646  */
+#line 9162 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 428:
-#line 3717 "ripper.y" /* yacc.c:1646  */
+#line 3709 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -9184,95 +9176,95 @@ yyreduce:
 			(yyval.val) = method_arg(dispatch1(fcall, (yyvsp[-1].val)), (yyvsp[0].val));
 
 		    }
-#line 9184 "ripper.c" /* yacc.c:1646  */
+#line 9176 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 429:
-#line 3727 "ripper.y" /* yacc.c:1646  */
+#line 3719 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9194 "ripper.c" /* yacc.c:1646  */
+#line 9186 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 430:
-#line 3733 "ripper.y" /* yacc.c:1646  */
+#line 3725 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall((yyvsp[-3].val), (yyvsp[-4].val), (yyvsp[-2].val), (yyvsp[0].val), &(yyloc));
 			nd_set_line((yyval.val), (yyvsp[-1].num));
 		    }
-#line 9203 "ripper.c" /* yacc.c:1646  */
+#line 9195 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 431:
-#line 3738 "ripper.y" /* yacc.c:1646  */
+#line 3730 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9213 "ripper.c" /* yacc.c:1646  */
+#line 9205 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 432:
-#line 3744 "ripper.y" /* yacc.c:1646  */
+#line 3736 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-4].val), (yyvsp[-2].val), (yyvsp[0].val), &(yyloc));
 			nd_set_line((yyval.val), (yyvsp[-1].num));
 		    }
-#line 9222 "ripper.c" /* yacc.c:1646  */
+#line 9214 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 433:
-#line 3749 "ripper.y" /* yacc.c:1646  */
+#line 3741 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-2].val), (yyvsp[0].val), Qnull, &(yyloc));
 		    }
-#line 9230 "ripper.c" /* yacc.c:1646  */
+#line 9222 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 434:
-#line 3753 "ripper.y" /* yacc.c:1646  */
+#line 3745 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9240 "ripper.c" /* yacc.c:1646  */
+#line 9232 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 435:
-#line 3759 "ripper.y" /* yacc.c:1646  */
+#line 3751 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall((yyvsp[-2].val), (yyvsp[-3].val), ID2VAL(idCall), (yyvsp[0].val), &(yyloc));
 			nd_set_line((yyval.val), (yyvsp[-1].num));
 		    }
-#line 9249 "ripper.c" /* yacc.c:1646  */
+#line 9241 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 436:
-#line 3764 "ripper.y" /* yacc.c:1646  */
+#line 3756 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9259 "ripper.c" /* yacc.c:1646  */
+#line 9251 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 437:
-#line 3770 "ripper.y" /* yacc.c:1646  */
+#line 3762 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-3].val), ID2VAL(idCall), (yyvsp[0].val), &(yyloc));
 			nd_set_line((yyval.val), (yyvsp[-1].num));
 		    }
-#line 9268 "ripper.c" /* yacc.c:1646  */
+#line 9260 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 438:
-#line 3775 "ripper.y" /* yacc.c:1646  */
+#line 3767 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_SUPER((yyvsp[0].val));
@@ -9281,11 +9273,11 @@ yyreduce:
 			(yyval.val) = dispatch1(super, (yyvsp[0].val));
 
 		    }
-#line 9281 "ripper.c" /* yacc.c:1646  */
+#line 9273 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 439:
-#line 3784 "ripper.y" /* yacc.c:1646  */
+#line 3776 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_ZSUPER();
@@ -9294,11 +9286,11 @@ yyreduce:
 			(yyval.val) = dispatch0(zsuper);
 
 		    }
-#line 9294 "ripper.c" /* yacc.c:1646  */
+#line 9286 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 440:
-#line 3793 "ripper.y" /* yacc.c:1646  */
+#line 3785 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if ((yyvsp[-3].val) && nd_type((yyvsp[-3].val)) == NODE_SELF)
@@ -9310,21 +9302,21 @@ yyreduce:
 			(yyval.val) = dispatch2(aref, (yyvsp[-3].val), escape_Qundef((yyvsp[-1].val)));
 
 		    }
-#line 9310 "ripper.c" /* yacc.c:1646  */
+#line 9302 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 441:
-#line 3807 "ripper.y" /* yacc.c:1646  */
+#line 3799 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9320 "ripper.c" /* yacc.c:1646  */
+#line 9312 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 442:
-#line 3813 "ripper.y" /* yacc.c:1646  */
+#line 3805 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 #if 0
@@ -9333,21 +9325,21 @@ yyreduce:
 			nd_set_line((yyval.val), (yyvsp[-2].num));
 #endif
 		    }
-#line 9333 "ripper.c" /* yacc.c:1646  */
+#line 9325 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 443:
-#line 3822 "ripper.y" /* yacc.c:1646  */
+#line 3814 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.num) = ruby_sourceline;
 #endif
 		    }
-#line 9343 "ripper.c" /* yacc.c:1646  */
+#line 9335 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 444:
-#line 3828 "ripper.y" /* yacc.c:1646  */
+#line 3820 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 #if 0
@@ -9356,55 +9348,55 @@ yyreduce:
 			nd_set_line((yyval.val), (yyvsp[-2].num));
 #endif
 		    }
-#line 9356 "ripper.c" /* yacc.c:1646  */
+#line 9348 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 445:
-#line 3838 "ripper.y" /* yacc.c:1646  */
+#line 3830 "ripper.y" /* yacc.c:1646  */
     {(yyval.vars) = dyna_push();}
-#line 9362 "ripper.c" /* yacc.c:1646  */
+#line 9354 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 446:
-#line 3839 "ripper.y" /* yacc.c:1646  */
+#line 3831 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = cmdarg_stack >> 1; CMDARG_SET(0);}
-#line 9368 "ripper.c" /* yacc.c:1646  */
+#line 9360 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 447:
-#line 3841 "ripper.y" /* yacc.c:1646  */
+#line 3833 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_brace_body((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 			dyna_pop((yyvsp[-3].vars));
 			CMDARG_SET((yyvsp[-2].val));
 		    }
-#line 9378 "ripper.c" /* yacc.c:1646  */
+#line 9370 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 448:
-#line 3848 "ripper.y" /* yacc.c:1646  */
+#line 3840 "ripper.y" /* yacc.c:1646  */
     {(yyval.vars) = dyna_push();}
-#line 9384 "ripper.c" /* yacc.c:1646  */
+#line 9376 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 449:
-#line 3849 "ripper.y" /* yacc.c:1646  */
+#line 3841 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = cmdarg_stack; CMDARG_SET(0);}
-#line 9390 "ripper.c" /* yacc.c:1646  */
+#line 9382 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 450:
-#line 3851 "ripper.y" /* yacc.c:1646  */
+#line 3843 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_do_body((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 			dyna_pop((yyvsp[-3].vars));
 			CMDARG_SET((yyvsp[-2].val));
 		    }
-#line 9400 "ripper.c" /* yacc.c:1646  */
+#line 9392 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 451:
-#line 3861 "ripper.y" /* yacc.c:1646  */
+#line 3853 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_WHEN((yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val));
@@ -9413,11 +9405,11 @@ yyreduce:
 			(yyval.val) = dispatch3(when, (yyvsp[-3].val), (yyvsp[-1].val), escape_Qundef((yyvsp[0].val)));
 
 		    }
-#line 9413 "ripper.c" /* yacc.c:1646  */
+#line 9405 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 454:
-#line 3878 "ripper.y" /* yacc.c:1646  */
+#line 3870 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if ((yyvsp[-3].val)) {
@@ -9437,11 +9429,11 @@ yyreduce:
 				       escape_Qundef((yyvsp[0].val)));
 
 		    }
-#line 9437 "ripper.c" /* yacc.c:1646  */
+#line 9429 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 456:
-#line 3901 "ripper.y" /* yacc.c:1646  */
+#line 3893 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_list((yyvsp[0].val), &(yyloc));
@@ -9449,11 +9441,11 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 9449 "ripper.c" /* yacc.c:1646  */
+#line 9441 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 457:
-#line 3909 "ripper.y" /* yacc.c:1646  */
+#line 3901 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (!((yyval.val) = splat_array((yyvsp[0].val)))) (yyval.val) = (yyvsp[0].val);
@@ -9461,19 +9453,19 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 9461 "ripper.c" /* yacc.c:1646  */
+#line 9453 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 459:
-#line 3920 "ripper.y" /* yacc.c:1646  */
+#line 3912 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 9469 "ripper.c" /* yacc.c:1646  */
+#line 9461 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 461:
-#line 3927 "ripper.y" /* yacc.c:1646  */
+#line 3919 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -9481,11 +9473,11 @@ yyreduce:
 			(yyval.val) = dispatch1(ensure, (yyvsp[0].val));
 
 		    }
-#line 9481 "ripper.c" /* yacc.c:1646  */
+#line 9473 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 464:
-#line 3939 "ripper.y" /* yacc.c:1646  */
+#line 3931 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_lit(ID2SYM((yyvsp[0].val)), &(yyloc));
@@ -9493,11 +9485,11 @@ yyreduce:
 			(yyval.val) = dispatch1(symbol_literal, (yyvsp[0].val));
 
 		    }
-#line 9493 "ripper.c" /* yacc.c:1646  */
+#line 9485 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 466:
-#line 3950 "ripper.y" /* yacc.c:1646  */
+#line 3942 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *node = (yyvsp[0].val);
@@ -9512,22 +9504,22 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 9512 "ripper.c" /* yacc.c:1646  */
+#line 9504 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 467:
-#line 3967 "ripper.y" /* yacc.c:1646  */
+#line 3959 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 9523 "ripper.c" /* yacc.c:1646  */
+#line 9515 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 469:
-#line 3975 "ripper.y" /* yacc.c:1646  */
+#line 3967 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = literal_concat((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -9535,11 +9527,11 @@ yyreduce:
 			(yyval.val) = dispatch2(string_concat, (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 9535 "ripper.c" /* yacc.c:1646  */
+#line 9527 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 470:
-#line 3985 "ripper.y" /* yacc.c:1646  */
+#line 3977 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_string1(heredoc_dedent((yyvsp[-1].val)));
 #if 0
@@ -9547,27 +9539,27 @@ yyreduce:
 #endif
 
 		    }
-#line 9547 "ripper.c" /* yacc.c:1646  */
+#line 9539 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 471:
-#line 3995 "ripper.y" /* yacc.c:1646  */
+#line 3987 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_xstring(heredoc_dedent((yyvsp[-1].val)), &(yyloc));
 		    }
-#line 9555 "ripper.c" /* yacc.c:1646  */
+#line 9547 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 472:
-#line 4001 "ripper.y" /* yacc.c:1646  */
+#line 3993 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_regexp((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 9563 "ripper.c" /* yacc.c:1646  */
+#line 9555 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 473:
-#line 4007 "ripper.y" /* yacc.c:1646  */
+#line 3999 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = make_array((yyvsp[-1].val), &(yyloc));
@@ -9575,11 +9567,11 @@ yyreduce:
 			(yyval.val) = dispatch1(array, (yyvsp[-1].val));
 
 		    }
-#line 9575 "ripper.c" /* yacc.c:1646  */
+#line 9567 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 474:
-#line 4017 "ripper.y" /* yacc.c:1646  */
+#line 4009 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9587,11 +9579,11 @@ yyreduce:
 			(yyval.val) = dispatch0(words_new);
 
 		    }
-#line 9587 "ripper.c" /* yacc.c:1646  */
+#line 9579 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 475:
-#line 4025 "ripper.y" /* yacc.c:1646  */
+#line 4017 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = list_append((yyvsp[-2].val), evstr2dstr((yyvsp[-1].val)));
@@ -9599,20 +9591,20 @@ yyreduce:
 			(yyval.val) = dispatch2(words_add, (yyvsp[-2].val), (yyvsp[-1].val));
 
 		    }
-#line 9599 "ripper.c" /* yacc.c:1646  */
+#line 9591 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 476:
-#line 4037 "ripper.y" /* yacc.c:1646  */
+#line 4029 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = dispatch0(word_new);
 			(yyval.val) = dispatch2(word_add, (yyval.val), (yyvsp[0].val));
 		    }
-#line 9608 "ripper.c" /* yacc.c:1646  */
+#line 9600 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 477:
-#line 4043 "ripper.y" /* yacc.c:1646  */
+#line 4035 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = literal_concat((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -9620,11 +9612,11 @@ yyreduce:
 			(yyval.val) = dispatch2(word_add, (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 9620 "ripper.c" /* yacc.c:1646  */
+#line 9612 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 478:
-#line 4053 "ripper.y" /* yacc.c:1646  */
+#line 4045 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = make_array((yyvsp[-1].val), &(yyloc));
@@ -9632,11 +9624,11 @@ yyreduce:
 			(yyval.val) = dispatch1(array, (yyvsp[-1].val));
 
 		    }
-#line 9632 "ripper.c" /* yacc.c:1646  */
+#line 9624 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 479:
-#line 4063 "ripper.y" /* yacc.c:1646  */
+#line 4055 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9644,11 +9636,11 @@ yyreduce:
 			(yyval.val) = dispatch0(symbols_new);
 
 		    }
-#line 9644 "ripper.c" /* yacc.c:1646  */
+#line 9636 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 480:
-#line 4071 "ripper.y" /* yacc.c:1646  */
+#line 4063 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyvsp[-1].val) = evstr2dstr((yyvsp[-1].val));
@@ -9664,11 +9656,11 @@ yyreduce:
 			(yyval.val) = dispatch2(symbols_add, (yyvsp[-2].val), (yyvsp[-1].val));
 
 		    }
-#line 9664 "ripper.c" /* yacc.c:1646  */
+#line 9656 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 481:
-#line 4089 "ripper.y" /* yacc.c:1646  */
+#line 4081 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = make_array((yyvsp[-1].val), &(yyloc));
@@ -9676,11 +9668,11 @@ yyreduce:
 			(yyval.val) = dispatch1(array, (yyvsp[-1].val));
 
 		    }
-#line 9676 "ripper.c" /* yacc.c:1646  */
+#line 9668 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 482:
-#line 4099 "ripper.y" /* yacc.c:1646  */
+#line 4091 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = make_array((yyvsp[-1].val), &(yyloc));
@@ -9688,11 +9680,11 @@ yyreduce:
 			(yyval.val) = dispatch1(array, (yyvsp[-1].val));
 
 		    }
-#line 9688 "ripper.c" /* yacc.c:1646  */
+#line 9680 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 483:
-#line 4109 "ripper.y" /* yacc.c:1646  */
+#line 4101 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9700,11 +9692,11 @@ yyreduce:
 			(yyval.val) = dispatch0(qwords_new);
 
 		    }
-#line 9700 "ripper.c" /* yacc.c:1646  */
+#line 9692 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 484:
-#line 4117 "ripper.y" /* yacc.c:1646  */
+#line 4109 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyvsp[-1].val)->nd_loc = (yylsp[-1]);
@@ -9713,11 +9705,11 @@ yyreduce:
 			(yyval.val) = dispatch2(qwords_add, (yyvsp[-2].val), (yyvsp[-1].val));
 
 		    }
-#line 9713 "ripper.c" /* yacc.c:1646  */
+#line 9705 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 485:
-#line 4128 "ripper.y" /* yacc.c:1646  */
+#line 4120 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9725,11 +9717,11 @@ yyreduce:
 			(yyval.val) = dispatch0(qsymbols_new);
 
 		    }
-#line 9725 "ripper.c" /* yacc.c:1646  */
+#line 9717 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 486:
-#line 4136 "ripper.y" /* yacc.c:1646  */
+#line 4128 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			VALUE lit;
@@ -9742,11 +9734,11 @@ yyreduce:
 			(yyval.val) = dispatch2(qsymbols_add, (yyvsp[-2].val), (yyvsp[-1].val));
 
 		    }
-#line 9742 "ripper.c" /* yacc.c:1646  */
+#line 9734 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 487:
-#line 4151 "ripper.y" /* yacc.c:1646  */
+#line 4143 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9754,11 +9746,11 @@ yyreduce:
 			(yyval.val) = dispatch0(string_content);
 
 		    }
-#line 9754 "ripper.c" /* yacc.c:1646  */
+#line 9746 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 488:
-#line 4159 "ripper.y" /* yacc.c:1646  */
+#line 4151 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = literal_concat((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -9766,11 +9758,11 @@ yyreduce:
 			(yyval.val) = dispatch2(string_add, (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 9766 "ripper.c" /* yacc.c:1646  */
+#line 9758 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 489:
-#line 4169 "ripper.y" /* yacc.c:1646  */
+#line 4161 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9778,11 +9770,11 @@ yyreduce:
 			(yyval.val) = dispatch0(xstring_new);
 
 		    }
-#line 9778 "ripper.c" /* yacc.c:1646  */
+#line 9770 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 490:
-#line 4177 "ripper.y" /* yacc.c:1646  */
+#line 4169 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = literal_concat((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -9790,11 +9782,11 @@ yyreduce:
 			(yyval.val) = dispatch2(xstring_add, (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 9790 "ripper.c" /* yacc.c:1646  */
+#line 9782 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 491:
-#line 4187 "ripper.y" /* yacc.c:1646  */
+#line 4179 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -9802,11 +9794,11 @@ yyreduce:
 			(yyval.val) = ripper_new_yylval(0, dispatch0(regexp_new), 0);
 
 		    }
-#line 9802 "ripper.c" /* yacc.c:1646  */
+#line 9794 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 492:
-#line 4195 "ripper.y" /* yacc.c:1646  */
+#line 4187 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *head = (yyvsp[-1].val), *tail = (yyvsp[0].val);
@@ -9845,33 +9837,33 @@ yyreduce:
 			}
 
 		    }
-#line 9845 "ripper.c" /* yacc.c:1646  */
+#line 9837 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 493:
-#line 4236 "ripper.y" /* yacc.c:1646  */
+#line 4228 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 9856 "ripper.c" /* yacc.c:1646  */
+#line 9848 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 494:
-#line 4243 "ripper.y" /* yacc.c:1646  */
+#line 4235 "ripper.y" /* yacc.c:1646  */
     {
 			/* need to backup lex_strterm so that a string literal `%&foo,#$&,bar&` can be parsed */
 			(yyval.strterm) = lex_strterm;
 			lex_strterm = 0;
 			SET_LEX_STATE(EXPR_BEG);
 		    }
-#line 9867 "ripper.c" /* yacc.c:1646  */
+#line 9859 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 495:
-#line 4250 "ripper.y" /* yacc.c:1646  */
+#line 4242 "ripper.y" /* yacc.c:1646  */
     {
 			lex_strterm = (yyvsp[-1].strterm);
 #if 0
@@ -9881,59 +9873,59 @@ yyreduce:
 			(yyval.val) = dispatch1(string_dvar, (yyvsp[0].val));
 
 		    }
-#line 9881 "ripper.c" /* yacc.c:1646  */
+#line 9873 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 496:
-#line 4260 "ripper.y" /* yacc.c:1646  */
+#line 4252 "ripper.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cond_stack;
 			(yyval.val) = cmdarg_stack;
 			COND_SET(0);
 			CMDARG_SET(0);
 		    }
-#line 9892 "ripper.c" /* yacc.c:1646  */
+#line 9884 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 497:
-#line 4266 "ripper.y" /* yacc.c:1646  */
+#line 4258 "ripper.y" /* yacc.c:1646  */
     {
 			/* need to backup lex_strterm so that a string literal `%!foo,#{ !0 },bar!` can be parsed */
 			(yyval.strterm) = lex_strterm;
 			lex_strterm = 0;
 		    }
-#line 9902 "ripper.c" /* yacc.c:1646  */
+#line 9894 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 498:
-#line 4271 "ripper.y" /* yacc.c:1646  */
+#line 4263 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = lex_state;
 			SET_LEX_STATE(EXPR_BEG);
 		    }
-#line 9911 "ripper.c" /* yacc.c:1646  */
+#line 9903 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 499:
-#line 4275 "ripper.y" /* yacc.c:1646  */
+#line 4267 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = brace_nest;
 			brace_nest = 0;
 		    }
-#line 9920 "ripper.c" /* yacc.c:1646  */
+#line 9912 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 500:
-#line 4279 "ripper.y" /* yacc.c:1646  */
+#line 4271 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = heredoc_indent;
 			heredoc_indent = 0;
 		    }
-#line 9929 "ripper.c" /* yacc.c:1646  */
+#line 9921 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 501:
-#line 4284 "ripper.y" /* yacc.c:1646  */
+#line 4276 "ripper.y" /* yacc.c:1646  */
     {
 			COND_SET((yyvsp[-7].val));
 			CMDARG_SET((yyvsp[-6].val));
@@ -9949,11 +9941,11 @@ yyreduce:
 			(yyval.val) = dispatch1(string_embexpr, (yyvsp[-1].val));
 
 		    }
-#line 9949 "ripper.c" /* yacc.c:1646  */
+#line 9941 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 502:
-#line 4302 "ripper.y" /* yacc.c:1646  */
+#line 4294 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_gvar((yyvsp[0].val), &(yyloc));
@@ -9961,11 +9953,11 @@ yyreduce:
 			(yyval.val) = dispatch1(var_ref, (yyvsp[0].val));
 
 		    }
-#line 9961 "ripper.c" /* yacc.c:1646  */
+#line 9953 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 503:
-#line 4310 "ripper.y" /* yacc.c:1646  */
+#line 4302 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = new_ivar((yyvsp[0].val), &(yyloc));
@@ -9973,11 +9965,11 @@ yyreduce:
 			(yyval.val) = dispatch1(var_ref, (yyvsp[0].val));
 
 		    }
-#line 9973 "ripper.c" /* yacc.c:1646  */
+#line 9965 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 504:
-#line 4318 "ripper.y" /* yacc.c:1646  */
+#line 4310 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = NEW_CVAR((yyvsp[0].val));
@@ -9986,11 +9978,11 @@ yyreduce:
 			(yyval.val) = dispatch1(var_ref, (yyvsp[0].val));
 
 		    }
-#line 9986 "ripper.c" /* yacc.c:1646  */
+#line 9978 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 506:
-#line 4330 "ripper.y" /* yacc.c:1646  */
+#line 4322 "ripper.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_END|EXPR_ENDARG);
 #if 0
@@ -9999,11 +9991,11 @@ yyreduce:
 			(yyval.val) = dispatch1(symbol, (yyvsp[0].val));
 
 		    }
-#line 9999 "ripper.c" /* yacc.c:1646  */
+#line 9991 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 511:
-#line 4347 "ripper.y" /* yacc.c:1646  */
+#line 4339 "ripper.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_END|EXPR_ENDARG);
 #if 0
@@ -10012,11 +10004,11 @@ yyreduce:
 			(yyval.val) = dispatch1(dyna_symbol, (yyvsp[-1].val));
 
 		    }
-#line 10012 "ripper.c" /* yacc.c:1646  */
+#line 10004 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 513:
-#line 4359 "ripper.y" /* yacc.c:1646  */
+#line 4351 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -10025,97 +10017,97 @@ yyreduce:
 			(yyval.val) = dispatch2(unary, ID2VAL(idUMinus), (yyvsp[0].val));
 
 		    }
-#line 10025 "ripper.c" /* yacc.c:1646  */
+#line 10017 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 514:
-#line 4370 "ripper.y" /* yacc.c:1646  */
+#line 4362 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10036 "ripper.c" /* yacc.c:1646  */
+#line 10028 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 515:
-#line 4377 "ripper.y" /* yacc.c:1646  */
+#line 4369 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10047 "ripper.c" /* yacc.c:1646  */
+#line 10039 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 516:
-#line 4384 "ripper.y" /* yacc.c:1646  */
+#line 4376 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10058 "ripper.c" /* yacc.c:1646  */
+#line 10050 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 517:
-#line 4391 "ripper.y" /* yacc.c:1646  */
+#line 4383 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10069 "ripper.c" /* yacc.c:1646  */
+#line 10061 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 523:
-#line 4406 "ripper.y" /* yacc.c:1646  */
+#line 4398 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(nil, (yyvsp[0].val));}
-#line 10075 "ripper.c" /* yacc.c:1646  */
+#line 10067 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 524:
-#line 4407 "ripper.y" /* yacc.c:1646  */
+#line 4399 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(self, (yyvsp[0].val));}
-#line 10081 "ripper.c" /* yacc.c:1646  */
+#line 10073 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 525:
-#line 4408 "ripper.y" /* yacc.c:1646  */
+#line 4400 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(true, (yyvsp[0].val));}
-#line 10087 "ripper.c" /* yacc.c:1646  */
+#line 10079 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 526:
-#line 4409 "ripper.y" /* yacc.c:1646  */
+#line 4401 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(false, (yyvsp[0].val));}
-#line 10093 "ripper.c" /* yacc.c:1646  */
+#line 10085 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 527:
-#line 4410 "ripper.y" /* yacc.c:1646  */
+#line 4402 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(_FILE__, (yyvsp[0].val));}
-#line 10099 "ripper.c" /* yacc.c:1646  */
+#line 10091 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 528:
-#line 4411 "ripper.y" /* yacc.c:1646  */
+#line 4403 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(_LINE__, (yyvsp[0].val));}
-#line 10105 "ripper.c" /* yacc.c:1646  */
+#line 10097 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 529:
-#line 4412 "ripper.y" /* yacc.c:1646  */
+#line 4404 "ripper.y" /* yacc.c:1646  */
     {(yyval.val) = KWD2EID(_ENCODING__, (yyvsp[0].val));}
-#line 10111 "ripper.c" /* yacc.c:1646  */
+#line 10103 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 530:
-#line 4416 "ripper.y" /* yacc.c:1646  */
+#line 4408 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (!((yyval.val) = gettable((yyvsp[0].val), &(yyloc)))) (yyval.val) = new_begin(0, &(yyloc));
@@ -10128,11 +10120,11 @@ yyreduce:
 			}
 
 		    }
-#line 10128 "ripper.c" /* yacc.c:1646  */
+#line 10120 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 531:
-#line 4429 "ripper.y" /* yacc.c:1646  */
+#line 4421 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (!((yyval.val) = gettable((yyvsp[0].val), &(yyloc)))) (yyval.val) = new_begin(0, &(yyloc));
@@ -10140,66 +10132,66 @@ yyreduce:
 			(yyval.val) = dispatch1(var_ref, (yyvsp[0].val));
 
 		    }
-#line 10140 "ripper.c" /* yacc.c:1646  */
+#line 10132 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 532:
-#line 4439 "ripper.y" /* yacc.c:1646  */
+#line 4431 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable(var_field((yyvsp[0].val)), 0, &(yyloc));
 		    }
-#line 10148 "ripper.c" /* yacc.c:1646  */
+#line 10140 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 533:
-#line 4443 "ripper.y" /* yacc.c:1646  */
+#line 4435 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable(var_field((yyvsp[0].val)), 0, &(yyloc));
 		    }
-#line 10156 "ripper.c" /* yacc.c:1646  */
+#line 10148 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 534:
-#line 4449 "ripper.y" /* yacc.c:1646  */
+#line 4441 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10167 "ripper.c" /* yacc.c:1646  */
+#line 10159 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 535:
-#line 4456 "ripper.y" /* yacc.c:1646  */
+#line 4448 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val)->nd_loc = (yyloc);
 #endif
 
 		    }
-#line 10178 "ripper.c" /* yacc.c:1646  */
+#line 10170 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 536:
-#line 4465 "ripper.y" /* yacc.c:1646  */
+#line 4457 "ripper.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10187 "ripper.c" /* yacc.c:1646  */
+#line 10179 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 537:
-#line 4470 "ripper.y" /* yacc.c:1646  */
+#line 4462 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[-1].val);
 		    }
-#line 10195 "ripper.c" /* yacc.c:1646  */
+#line 10187 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 538:
-#line 4474 "ripper.y" /* yacc.c:1646  */
+#line 4466 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -10207,11 +10199,11 @@ yyreduce:
 			(yyval.val) = Qnil;
 
 		    }
-#line 10207 "ripper.c" /* yacc.c:1646  */
+#line 10199 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 539:
-#line 4484 "ripper.y" /* yacc.c:1646  */
+#line 4476 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -10221,201 +10213,201 @@ yyreduce:
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10221 "ripper.c" /* yacc.c:1646  */
+#line 10213 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 540:
-#line 4493 "ripper.y" /* yacc.c:1646  */
+#line 4485 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.num) = parser->in_kwarg;
 			parser->in_kwarg = 1;
 			SET_LEX_STATE(lex_state|EXPR_LABEL); /* force for args */
 		    }
-#line 10231 "ripper.c" /* yacc.c:1646  */
+#line 10223 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 541:
-#line 4499 "ripper.y" /* yacc.c:1646  */
+#line 4491 "ripper.y" /* yacc.c:1646  */
     {
 			parser->in_kwarg = !!(yyvsp[-2].num);
 			(yyval.val) = (yyvsp[-1].val);
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10242 "ripper.c" /* yacc.c:1646  */
+#line 10234 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 542:
-#line 4508 "ripper.y" /* yacc.c:1646  */
+#line 4500 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail((yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 10250 "ripper.c" /* yacc.c:1646  */
+#line 10242 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 543:
-#line 4512 "ripper.y" /* yacc.c:1646  */
+#line 4504 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail((yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 10258 "ripper.c" /* yacc.c:1646  */
+#line 10250 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 544:
-#line 4516 "ripper.y" /* yacc.c:1646  */
+#line 4508 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yylsp[-1]));
 		    }
-#line 10266 "ripper.c" /* yacc.c:1646  */
+#line 10258 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 545:
-#line 4520 "ripper.y" /* yacc.c:1646  */
+#line 4512 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, Qnone, (yyvsp[0].val), &(yylsp[0]));
 		    }
-#line 10274 "ripper.c" /* yacc.c:1646  */
+#line 10266 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 546:
-#line 4526 "ripper.y" /* yacc.c:1646  */
+#line 4518 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 10282 "ripper.c" /* yacc.c:1646  */
+#line 10274 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 547:
-#line 4530 "ripper.y" /* yacc.c:1646  */
+#line 4522 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 		    }
-#line 10290 "ripper.c" /* yacc.c:1646  */
+#line 10282 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 548:
-#line 4536 "ripper.y" /* yacc.c:1646  */
+#line 4528 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10298 "ripper.c" /* yacc.c:1646  */
+#line 10290 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 549:
-#line 4540 "ripper.y" /* yacc.c:1646  */
+#line 4532 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-7].val), (yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10306 "ripper.c" /* yacc.c:1646  */
+#line 10298 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 550:
-#line 4544 "ripper.y" /* yacc.c:1646  */
+#line 4536 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-3].val), (yyvsp[-1].val), Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10314 "ripper.c" /* yacc.c:1646  */
+#line 10306 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 551:
-#line 4548 "ripper.y" /* yacc.c:1646  */
+#line 4540 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), (yyvsp[-3].val), Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10322 "ripper.c" /* yacc.c:1646  */
+#line 10314 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 552:
-#line 4552 "ripper.y" /* yacc.c:1646  */
+#line 4544 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-3].val), Qnone, (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10330 "ripper.c" /* yacc.c:1646  */
+#line 10322 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 553:
-#line 4556 "ripper.y" /* yacc.c:1646  */
+#line 4548 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-5].val), Qnone, (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10338 "ripper.c" /* yacc.c:1646  */
+#line 10330 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 554:
-#line 4560 "ripper.y" /* yacc.c:1646  */
+#line 4552 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args((yyvsp[-1].val), Qnone, Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10346 "ripper.c" /* yacc.c:1646  */
+#line 10338 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 555:
-#line 4564 "ripper.y" /* yacc.c:1646  */
+#line 4556 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-3].val), (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10354 "ripper.c" /* yacc.c:1646  */
+#line 10346 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 556:
-#line 4568 "ripper.y" /* yacc.c:1646  */
+#line 4560 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-5].val), (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10362 "ripper.c" /* yacc.c:1646  */
+#line 10354 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 557:
-#line 4572 "ripper.y" /* yacc.c:1646  */
+#line 4564 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-1].val), Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10370 "ripper.c" /* yacc.c:1646  */
+#line 10362 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 558:
-#line 4576 "ripper.y" /* yacc.c:1646  */
+#line 4568 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, (yyvsp[-3].val), Qnone, (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10378 "ripper.c" /* yacc.c:1646  */
+#line 10370 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 559:
-#line 4580 "ripper.y" /* yacc.c:1646  */
+#line 4572 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, (yyvsp[-1].val), Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10386 "ripper.c" /* yacc.c:1646  */
+#line 10378 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 560:
-#line 4584 "ripper.y" /* yacc.c:1646  */
+#line 4576 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, (yyvsp[-3].val), (yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 		    }
-#line 10394 "ripper.c" /* yacc.c:1646  */
+#line 10386 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 561:
-#line 4588 "ripper.y" /* yacc.c:1646  */
+#line 4580 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args(Qnone, Qnone, Qnone, Qnone, (yyvsp[0].val), &(yyloc));
 		    }
-#line 10402 "ripper.c" /* yacc.c:1646  */
+#line 10394 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 562:
-#line 4592 "ripper.y" /* yacc.c:1646  */
+#line 4584 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 			(yyval.val) = new_args(Qnone, Qnone, Qnone, Qnone, (yyval.val), &(yylsp[0]));
 		    }
-#line 10411 "ripper.c" /* yacc.c:1646  */
+#line 10403 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 563:
-#line 4599 "ripper.y" /* yacc.c:1646  */
+#line 4591 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			yyerror0("formal argument cannot be a constant");
@@ -10425,11 +10417,11 @@ yyreduce:
 			ripper_error();
 
 		    }
-#line 10425 "ripper.c" /* yacc.c:1646  */
+#line 10417 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 564:
-#line 4609 "ripper.y" /* yacc.c:1646  */
+#line 4601 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			yyerror0("formal argument cannot be an instance variable");
@@ -10439,11 +10431,11 @@ yyreduce:
 			ripper_error();
 
 		    }
-#line 10439 "ripper.c" /* yacc.c:1646  */
+#line 10431 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 565:
-#line 4619 "ripper.y" /* yacc.c:1646  */
+#line 4611 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			yyerror0("formal argument cannot be a global variable");
@@ -10453,11 +10445,11 @@ yyreduce:
 			ripper_error();
 
 		    }
-#line 10453 "ripper.c" /* yacc.c:1646  */
+#line 10445 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 566:
-#line 4629 "ripper.y" /* yacc.c:1646  */
+#line 4621 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			yyerror0("formal argument cannot be a class variable");
@@ -10467,31 +10459,31 @@ yyreduce:
 			ripper_error();
 
 		    }
-#line 10467 "ripper.c" /* yacc.c:1646  */
+#line 10459 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 568:
-#line 4642 "ripper.y" /* yacc.c:1646  */
+#line 4634 "ripper.y" /* yacc.c:1646  */
     {
 			formal_argument(get_id((yyvsp[0].val)));
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 10476 "ripper.c" /* yacc.c:1646  */
+#line 10468 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 569:
-#line 4649 "ripper.y" /* yacc.c:1646  */
+#line 4641 "ripper.y" /* yacc.c:1646  */
     {
 			ID id = get_id((yyvsp[0].val));
 			arg_var(id);
 			current_arg = id;
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 10487 "ripper.c" /* yacc.c:1646  */
+#line 10479 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 570:
-#line 4658 "ripper.y" /* yacc.c:1646  */
+#line 4650 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 #if 0
@@ -10500,11 +10492,11 @@ yyreduce:
 			(yyval.val) = get_value((yyvsp[0].val));
 
 		    }
-#line 10500 "ripper.c" /* yacc.c:1646  */
+#line 10492 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 571:
-#line 4667 "ripper.y" /* yacc.c:1646  */
+#line 4659 "ripper.y" /* yacc.c:1646  */
     {
 			ID tid = internal_id();
 #if 0
@@ -10527,19 +10519,19 @@ yyreduce:
 			(yyval.val) = dispatch1(mlhs_paren, (yyvsp[-1].val));
 
 		    }
-#line 10527 "ripper.c" /* yacc.c:1646  */
+#line 10519 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 572:
-#line 4694 "ripper.y" /* yacc.c:1646  */
+#line 4686 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 		    }
-#line 10535 "ripper.c" /* yacc.c:1646  */
+#line 10527 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 573:
-#line 4699 "ripper.y" /* yacc.c:1646  */
+#line 4691 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-2].val);
@@ -10550,22 +10542,22 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10550 "ripper.c" /* yacc.c:1646  */
+#line 10542 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 574:
-#line 4713 "ripper.y" /* yacc.c:1646  */
+#line 4705 "ripper.y" /* yacc.c:1646  */
     {
 			ID id = get_id((yyvsp[0].val));
 			arg_var(formal_argument(id));
 			current_arg = id;
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 10561 "ripper.c" /* yacc.c:1646  */
+#line 10553 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 575:
-#line 4722 "ripper.y" /* yacc.c:1646  */
+#line 4714 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.val) = assignable((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
@@ -10575,11 +10567,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), get_value((yyvsp[0].val)));
 
 		    }
-#line 10575 "ripper.c" /* yacc.c:1646  */
+#line 10567 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 576:
-#line 4732 "ripper.y" /* yacc.c:1646  */
+#line 4724 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.val) = assignable((yyvsp[0].val), NODE_SPECIAL_REQUIRED_KEYWORD, &(yyloc));
@@ -10589,11 +10581,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), 0);
 
 		    }
-#line 10589 "ripper.c" /* yacc.c:1646  */
+#line 10581 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 577:
-#line 4744 "ripper.y" /* yacc.c:1646  */
+#line 4736 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[-1].val), (yyvsp[0].val), &(yyloc));
 #if 0
@@ -10602,11 +10594,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), get_value((yyvsp[0].val)));
 
 		    }
-#line 10602 "ripper.c" /* yacc.c:1646  */
+#line 10594 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 578:
-#line 4753 "ripper.y" /* yacc.c:1646  */
+#line 4745 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = assignable((yyvsp[0].val), NODE_SPECIAL_REQUIRED_KEYWORD, &(yyloc));
 #if 0
@@ -10615,11 +10607,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), 0);
 
 		    }
-#line 10615 "ripper.c" /* yacc.c:1646  */
+#line 10607 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 579:
-#line 4764 "ripper.y" /* yacc.c:1646  */
+#line 4756 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -10627,11 +10619,11 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 10627 "ripper.c" /* yacc.c:1646  */
+#line 10619 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 580:
-#line 4772 "ripper.y" /* yacc.c:1646  */
+#line 4764 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = kwd_append((yyvsp[-2].val), (yyvsp[0].val));
@@ -10639,11 +10631,11 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10639 "ripper.c" /* yacc.c:1646  */
+#line 10631 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 581:
-#line 4783 "ripper.y" /* yacc.c:1646  */
+#line 4775 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -10651,11 +10643,11 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 10651 "ripper.c" /* yacc.c:1646  */
+#line 10643 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 582:
-#line 4791 "ripper.y" /* yacc.c:1646  */
+#line 4783 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = kwd_append((yyvsp[-2].val), (yyvsp[0].val));
@@ -10663,11 +10655,11 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10663 "ripper.c" /* yacc.c:1646  */
+#line 10655 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 585:
-#line 4805 "ripper.y" /* yacc.c:1646  */
+#line 4797 "ripper.y" /* yacc.c:1646  */
     {
 			shadowing_lvar(get_id((yyvsp[0].val)));
 #if 0
@@ -10676,11 +10668,11 @@ yyreduce:
 			(yyval.val) = dispatch1(kwrest_param, (yyvsp[0].val));
 
 		    }
-#line 10676 "ripper.c" /* yacc.c:1646  */
+#line 10668 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 586:
-#line 4814 "ripper.y" /* yacc.c:1646  */
+#line 4806 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = internal_id();
@@ -10689,11 +10681,11 @@ yyreduce:
 			(yyval.val) = dispatch1(kwrest_param, Qnil);
 
 		    }
-#line 10689 "ripper.c" /* yacc.c:1646  */
+#line 10681 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 587:
-#line 4825 "ripper.y" /* yacc.c:1646  */
+#line 4817 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.val) = assignable((yyvsp[-2].val), (yyvsp[0].val), &(yyloc));
@@ -10704,11 +10696,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), get_value((yyvsp[0].val)));
 
 		    }
-#line 10704 "ripper.c" /* yacc.c:1646  */
+#line 10696 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 588:
-#line 4838 "ripper.y" /* yacc.c:1646  */
+#line 4830 "ripper.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.val) = assignable((yyvsp[-2].val), (yyvsp[0].val), &(yyloc));
@@ -10719,11 +10711,11 @@ yyreduce:
 			(yyval.val) = rb_assoc_new(get_value((yyval.val)), get_value((yyvsp[0].val)));
 
 		    }
-#line 10719 "ripper.c" /* yacc.c:1646  */
+#line 10711 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 589:
-#line 4851 "ripper.y" /* yacc.c:1646  */
+#line 4843 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -10731,11 +10723,11 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 10731 "ripper.c" /* yacc.c:1646  */
+#line 10723 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 590:
-#line 4859 "ripper.y" /* yacc.c:1646  */
+#line 4851 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = opt_arg_append((yyvsp[-2].val), (yyvsp[0].val));
@@ -10743,11 +10735,11 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10743 "ripper.c" /* yacc.c:1646  */
+#line 10735 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 591:
-#line 4869 "ripper.y" /* yacc.c:1646  */
+#line 4861 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[0].val);
@@ -10755,11 +10747,11 @@ yyreduce:
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 
 		    }
-#line 10755 "ripper.c" /* yacc.c:1646  */
+#line 10747 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 592:
-#line 4877 "ripper.y" /* yacc.c:1646  */
+#line 4869 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = opt_arg_append((yyvsp[-2].val), (yyvsp[0].val));
@@ -10767,11 +10759,11 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10767 "ripper.c" /* yacc.c:1646  */
+#line 10759 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 595:
-#line 4891 "ripper.y" /* yacc.c:1646  */
+#line 4883 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (!is_local_id((yyvsp[0].val)))
@@ -10784,11 +10776,11 @@ yyreduce:
 			(yyval.val) = dispatch1(rest_param, (yyvsp[0].val));
 
 		    }
-#line 10784 "ripper.c" /* yacc.c:1646  */
+#line 10776 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 596:
-#line 4904 "ripper.y" /* yacc.c:1646  */
+#line 4896 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = internal_id();
@@ -10797,11 +10789,11 @@ yyreduce:
 			(yyval.val) = dispatch1(rest_param, Qnil);
 
 		    }
-#line 10797 "ripper.c" /* yacc.c:1646  */
+#line 10789 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 599:
-#line 4919 "ripper.y" /* yacc.c:1646  */
+#line 4911 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (!is_local_id((yyvsp[0].val)))
@@ -10816,19 +10808,19 @@ yyreduce:
 			(yyval.val) = dispatch1(blockarg, (yyvsp[0].val));
 
 		    }
-#line 10816 "ripper.c" /* yacc.c:1646  */
+#line 10808 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 600:
-#line 4936 "ripper.y" /* yacc.c:1646  */
+#line 4928 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = (yyvsp[0].val);
 		    }
-#line 10824 "ripper.c" /* yacc.c:1646  */
+#line 10816 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 601:
-#line 4940 "ripper.y" /* yacc.c:1646  */
+#line 4932 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = 0;
@@ -10836,11 +10828,11 @@ yyreduce:
 			(yyval.val) = Qundef;
 
 		    }
-#line 10836 "ripper.c" /* yacc.c:1646  */
+#line 10828 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 602:
-#line 4950 "ripper.y" /* yacc.c:1646  */
+#line 4942 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			value_expr((yyvsp[0].val));
@@ -10850,17 +10842,17 @@ yyreduce:
 			(yyval.val) = (yyvsp[0].val);
 
 		    }
-#line 10850 "ripper.c" /* yacc.c:1646  */
+#line 10842 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 603:
-#line 4959 "ripper.y" /* yacc.c:1646  */
+#line 4951 "ripper.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_BEG);}
-#line 10856 "ripper.c" /* yacc.c:1646  */
+#line 10848 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 604:
-#line 4960 "ripper.y" /* yacc.c:1646  */
+#line 4952 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if ((yyvsp[-1].val) == 0) {
@@ -10888,11 +10880,11 @@ yyreduce:
 			(yyval.val) = dispatch1(paren, (yyvsp[-1].val));
 
 		    }
-#line 10888 "ripper.c" /* yacc.c:1646  */
+#line 10880 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 606:
-#line 4991 "ripper.y" /* yacc.c:1646  */
+#line 4983 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = (yyvsp[-1].val);
@@ -10900,19 +10892,19 @@ yyreduce:
 			(yyval.val) = dispatch1(assoclist_from_args, (yyvsp[-1].val));
 
 		    }
-#line 10900 "ripper.c" /* yacc.c:1646  */
+#line 10892 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 607:
-#line 5003 "ripper.y" /* yacc.c:1646  */
+#line 4995 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = rb_ary_new3(1, get_value((yyvsp[0].val)));
 		    }
-#line 10908 "ripper.c" /* yacc.c:1646  */
+#line 10900 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 608:
-#line 5008 "ripper.y" /* yacc.c:1646  */
+#line 5000 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			NODE *assocs = (yyvsp[-2].val);
@@ -10934,11 +10926,11 @@ yyreduce:
 			(yyval.val) = rb_ary_push((yyvsp[-2].val), get_value((yyvsp[0].val)));
 
 		    }
-#line 10934 "ripper.c" /* yacc.c:1646  */
+#line 10926 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 609:
-#line 5032 "ripper.y" /* yacc.c:1646  */
+#line 5024 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (nd_type((yyvsp[-2].val)) == NODE_STR) {
@@ -10950,11 +10942,11 @@ yyreduce:
 			(yyval.val) = dispatch2(assoc_new, (yyvsp[-2].val), (yyvsp[0].val));
 
 		    }
-#line 10950 "ripper.c" /* yacc.c:1646  */
+#line 10942 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 610:
-#line 5044 "ripper.y" /* yacc.c:1646  */
+#line 5036 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			(yyval.val) = list_append(new_list(new_lit(ID2SYM((yyvsp[-1].val)), &(yylsp[-1])), &(yyloc)), (yyvsp[0].val));
@@ -10962,11 +10954,11 @@ yyreduce:
 			(yyval.val) = dispatch2(assoc_new, (yyvsp[-1].val), (yyvsp[0].val));
 
 		    }
-#line 10962 "ripper.c" /* yacc.c:1646  */
+#line 10954 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 611:
-#line 5052 "ripper.y" /* yacc.c:1646  */
+#line 5044 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			YYLTYPE location;
@@ -10977,11 +10969,11 @@ yyreduce:
 			(yyval.val) = dispatch2(assoc_new, dispatch1(dyna_symbol, (yyvsp[-2].val)), (yyvsp[0].val));
 
 		    }
-#line 10977 "ripper.c" /* yacc.c:1646  */
+#line 10969 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 612:
-#line 5063 "ripper.y" /* yacc.c:1646  */
+#line 5055 "ripper.y" /* yacc.c:1646  */
     {
 #if 0
 			if (nd_type((yyvsp[0].val)) == NODE_HASH &&
@@ -10993,61 +10985,61 @@ yyreduce:
 			(yyval.val) = dispatch1(assoc_splat, (yyvsp[0].val));
 
 		    }
-#line 10993 "ripper.c" /* yacc.c:1646  */
+#line 10985 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 625:
-#line 5097 "ripper.y" /* yacc.c:1646  */
+#line 5089 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = TOKEN2VAL('.');
 		    }
-#line 11001 "ripper.c" /* yacc.c:1646  */
+#line 10993 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 626:
-#line 5101 "ripper.y" /* yacc.c:1646  */
+#line 5093 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = ID2VAL(idANDDOT);
 		    }
-#line 11009 "ripper.c" /* yacc.c:1646  */
+#line 11001 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 628:
-#line 5108 "ripper.y" /* yacc.c:1646  */
+#line 5100 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = ID2VAL(idCOLON2);
 		    }
-#line 11017 "ripper.c" /* yacc.c:1646  */
+#line 11009 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 638:
-#line 5132 "ripper.y" /* yacc.c:1646  */
+#line 5124 "ripper.y" /* yacc.c:1646  */
     {yyerrok;token_flush(parser);}
-#line 11023 "ripper.c" /* yacc.c:1646  */
+#line 11015 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 639:
-#line 5133 "ripper.y" /* yacc.c:1646  */
+#line 5125 "ripper.y" /* yacc.c:1646  */
     {token_flush(parser);}
-#line 11029 "ripper.c" /* yacc.c:1646  */
+#line 11021 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 641:
-#line 5137 "ripper.y" /* yacc.c:1646  */
+#line 5129 "ripper.y" /* yacc.c:1646  */
     {yyerrok;}
-#line 11035 "ripper.c" /* yacc.c:1646  */
+#line 11027 "ripper.c" /* yacc.c:1646  */
     break;
 
   case 642:
-#line 5141 "ripper.y" /* yacc.c:1646  */
+#line 5133 "ripper.y" /* yacc.c:1646  */
     {
 			(yyval.val) = Qnull;
 		    }
-#line 11043 "ripper.c" /* yacc.c:1646  */
+#line 11035 "ripper.c" /* yacc.c:1646  */
     break;
 
 
-#line 11047 "ripper.c" /* yacc.c:1646  */
+#line 11039 "ripper.c" /* yacc.c:1646  */
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -11282,7 +11274,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 5145 "ripper.y" /* yacc.c:1906  */
+#line 5137 "ripper.y" /* yacc.c:1906  */
 
 # undef parser
 # undef yylex
@@ -16098,11 +16090,13 @@ assignable_gen(struct parser_params *parser, ID id, NO
 #ifdef RIPPER
     ID id = get_id(lhs);
 # define assignable_result(x) (lhs)
+# define assignable_error() (lhs)
 # define parser_yyerror(parser, x) (lhs = assign_error_gen(parser, lhs))
 #else
 # define assignable_result(x) assignable_result0(x, location)
+# define assignable_error() new_begin(0, location)
 #endif
-    if (!id) return assignable_result(0);
+    if (!id) return assignable_error();
     switch (id) {
       case keyword_self:
 	yyerror0("Can't change the value of self");
@@ -16165,7 +16159,7 @@ assignable_gen(struct parser_params *parser, ID id, NO
 	compile_error(PARSER_ARG "identifier %"PRIsVALUE" is not valid to set", rb_id2str(id));
     }
   error:
-    return assignable_result(0);
+    return assignable_error();
 #undef assignable_result
 #undef parser_yyerror
 }
