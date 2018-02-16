--- parse.c.orig	2017-12-25 07:00:33 UTC
+++ parse.c
@@ -1567,61 +1567,61 @@ static const yytype_uint16 yyrline[] =
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
 
@@ -6593,28 +6593,20 @@ yyreduce:
 #line 1984 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable(var_field((yyvsp[0].id)), 0, &(yyloc));
-		    /*%%%*/
-			if (!(yyval.node)) (yyval.node) = new_begin(0, &(yyloc));
-		    /*%
-		    %*/
 		    }
-#line 6598 "parse.c" /* yacc.c:1646  */
+#line 6594 "parse.c" /* yacc.c:1646  */
     break;
 
   case 104:
-#line 1992 "parse.y" /* yacc.c:1646  */
+#line 1988 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable(var_field((yyvsp[0].id)), 0, &(yyloc));
-		    /*%%%*/
-			if (!(yyval.node)) (yyval.node) = new_begin(0, &(yyloc));
-		    /*%
-		    %*/
 		    }
-#line 6610 "parse.c" /* yacc.c:1646  */
+#line 6602 "parse.c" /* yacc.c:1646  */
     break;
 
   case 105:
-#line 2000 "parse.y" /* yacc.c:1646  */
+#line 1992 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node), &(yyloc));
@@ -6622,11 +6614,11 @@ yyreduce:
 			$$ = dispatch2(aref_field, $1, escape_Qundef($3));
 		    %*/
 		    }
-#line 6622 "parse.c" /* yacc.c:1646  */
+#line 6614 "parse.c" /* yacc.c:1646  */
     break;
 
   case 106:
-#line 2008 "parse.y" /* yacc.c:1646  */
+#line 2000 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id), &(yyloc));
@@ -6634,11 +6626,11 @@ yyreduce:
 			$$ = dispatch3(field, $1, $2, $3);
 		    %*/
 		    }
-#line 6634 "parse.c" /* yacc.c:1646  */
+#line 6626 "parse.c" /* yacc.c:1646  */
     break;
 
   case 107:
-#line 2016 "parse.y" /* yacc.c:1646  */
+#line 2008 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = attrset((yyvsp[-2].node), idCOLON2, (yyvsp[0].id), &(yyloc));
@@ -6646,11 +6638,11 @@ yyreduce:
 			$$ = dispatch3(field, $1, ID2VAL(idCOLON2), $3);
 		    %*/
 		    }
-#line 6646 "parse.c" /* yacc.c:1646  */
+#line 6638 "parse.c" /* yacc.c:1646  */
     break;
 
   case 108:
-#line 2024 "parse.y" /* yacc.c:1646  */
+#line 2016 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].id), &(yyloc));
@@ -6658,36 +6650,36 @@ yyreduce:
 			$$ = dispatch3(field, $1, $2, $3);
 		    %*/
 		    }
-#line 6658 "parse.c" /* yacc.c:1646  */
+#line 6650 "parse.c" /* yacc.c:1646  */
     break;
 
   case 109:
-#line 2032 "parse.y" /* yacc.c:1646  */
+#line 2024 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = const_decl(const_path_field((yyvsp[-2].node), (yyvsp[0].id), &(yyloc)), &(yyloc));
 		    }
-#line 6666 "parse.c" /* yacc.c:1646  */
+#line 6658 "parse.c" /* yacc.c:1646  */
     break;
 
   case 110:
-#line 2036 "parse.y" /* yacc.c:1646  */
+#line 2028 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = const_decl(top_const_field((yyvsp[0].id)), &(yyloc));
 		    }
-#line 6674 "parse.c" /* yacc.c:1646  */
+#line 6666 "parse.c" /* yacc.c:1646  */
     break;
 
   case 111:
-#line 2040 "parse.y" /* yacc.c:1646  */
+#line 2032 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].node) = var_field((yyvsp[0].node));
 			(yyval.node) = backref_assign_error((yyvsp[0].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 6683 "parse.c" /* yacc.c:1646  */
+#line 6675 "parse.c" /* yacc.c:1646  */
     break;
 
   case 112:
-#line 2047 "parse.y" /* yacc.c:1646  */
+#line 2039 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			yyerror0("class/module name must be CONSTANT");
@@ -6696,11 +6688,11 @@ yyreduce:
 			ripper_error();
 		    %*/
 		    }
-#line 6696 "parse.c" /* yacc.c:1646  */
+#line 6688 "parse.c" /* yacc.c:1646  */
     break;
 
   case 114:
-#line 2059 "parse.y" /* yacc.c:1646  */
+#line 2051 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_COLON3((yyvsp[0].id));
@@ -6709,11 +6701,11 @@ yyreduce:
 			$$ = dispatch1(top_const_ref, $2);
 		    %*/
 		    }
-#line 6709 "parse.c" /* yacc.c:1646  */
+#line 6701 "parse.c" /* yacc.c:1646  */
     break;
 
   case 115:
-#line 2068 "parse.y" /* yacc.c:1646  */
+#line 2060 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_COLON2(0, (yyval.node));
@@ -6722,11 +6714,11 @@ yyreduce:
 			$$ = dispatch1(const_ref, $1);
 		    %*/
 		    }
-#line 6722 "parse.c" /* yacc.c:1646  */
+#line 6714 "parse.c" /* yacc.c:1646  */
     break;
 
   case 116:
-#line 2077 "parse.y" /* yacc.c:1646  */
+#line 2069 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
@@ -6735,29 +6727,29 @@ yyreduce:
 			$$ = dispatch2(const_path_ref, $1, $3);
 		    %*/
 		    }
-#line 6735 "parse.c" /* yacc.c:1646  */
+#line 6727 "parse.c" /* yacc.c:1646  */
     break;
 
   case 120:
-#line 2091 "parse.y" /* yacc.c:1646  */
+#line 2083 "parse.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_ENDFN);
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 6744 "parse.c" /* yacc.c:1646  */
+#line 6736 "parse.c" /* yacc.c:1646  */
     break;
 
   case 121:
-#line 2096 "parse.y" /* yacc.c:1646  */
+#line 2088 "parse.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_ENDFN);
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 6753 "parse.c" /* yacc.c:1646  */
+#line 6745 "parse.c" /* yacc.c:1646  */
     break;
 
   case 124:
-#line 2107 "parse.y" /* yacc.c:1646  */
+#line 2099 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_lit(ID2SYM((yyvsp[0].id)), &(yyloc));
@@ -6765,11 +6757,11 @@ yyreduce:
 			$$ = dispatch1(symbol_literal, $1);
 		    %*/
 		    }
-#line 6765 "parse.c" /* yacc.c:1646  */
+#line 6757 "parse.c" /* yacc.c:1646  */
     break;
 
   case 126:
-#line 2118 "parse.y" /* yacc.c:1646  */
+#line 2110 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_undef((yyvsp[0].node), &(yyloc));
@@ -6777,17 +6769,17 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 6777 "parse.c" /* yacc.c:1646  */
+#line 6769 "parse.c" /* yacc.c:1646  */
     break;
 
   case 127:
-#line 2125 "parse.y" /* yacc.c:1646  */
+#line 2117 "parse.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_FNAME|EXPR_FITEM);}
-#line 6783 "parse.c" /* yacc.c:1646  */
+#line 6775 "parse.c" /* yacc.c:1646  */
     break;
 
   case 128:
-#line 2126 "parse.y" /* yacc.c:1646  */
+#line 2118 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *undef = new_undef((yyvsp[0].node), &(yyloc));
@@ -6796,207 +6788,207 @@ yyreduce:
 			rb_ary_push($1, get_value($4));
 		    %*/
 		    }
-#line 6796 "parse.c" /* yacc.c:1646  */
+#line 6788 "parse.c" /* yacc.c:1646  */
     break;
 
   case 129:
-#line 2136 "parse.y" /* yacc.c:1646  */
+#line 2128 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '|'); }
-#line 6802 "parse.c" /* yacc.c:1646  */
+#line 6794 "parse.c" /* yacc.c:1646  */
     break;
 
   case 130:
-#line 2137 "parse.y" /* yacc.c:1646  */
+#line 2129 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '^'); }
-#line 6808 "parse.c" /* yacc.c:1646  */
+#line 6800 "parse.c" /* yacc.c:1646  */
     break;
 
   case 131:
-#line 2138 "parse.y" /* yacc.c:1646  */
+#line 2130 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '&'); }
-#line 6814 "parse.c" /* yacc.c:1646  */
+#line 6806 "parse.c" /* yacc.c:1646  */
     break;
 
   case 132:
-#line 2139 "parse.y" /* yacc.c:1646  */
+#line 2131 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tCMP); }
-#line 6820 "parse.c" /* yacc.c:1646  */
+#line 6812 "parse.c" /* yacc.c:1646  */
     break;
 
   case 133:
-#line 2140 "parse.y" /* yacc.c:1646  */
+#line 2132 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tEQ); }
-#line 6826 "parse.c" /* yacc.c:1646  */
+#line 6818 "parse.c" /* yacc.c:1646  */
     break;
 
   case 134:
-#line 2141 "parse.y" /* yacc.c:1646  */
+#line 2133 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tEQQ); }
-#line 6832 "parse.c" /* yacc.c:1646  */
+#line 6824 "parse.c" /* yacc.c:1646  */
     break;
 
   case 135:
-#line 2142 "parse.y" /* yacc.c:1646  */
+#line 2134 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tMATCH); }
-#line 6838 "parse.c" /* yacc.c:1646  */
+#line 6830 "parse.c" /* yacc.c:1646  */
     break;
 
   case 136:
-#line 2143 "parse.y" /* yacc.c:1646  */
+#line 2135 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tNMATCH); }
-#line 6844 "parse.c" /* yacc.c:1646  */
+#line 6836 "parse.c" /* yacc.c:1646  */
     break;
 
   case 137:
-#line 2144 "parse.y" /* yacc.c:1646  */
+#line 2136 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '>'); }
-#line 6850 "parse.c" /* yacc.c:1646  */
+#line 6842 "parse.c" /* yacc.c:1646  */
     break;
 
   case 138:
-#line 2145 "parse.y" /* yacc.c:1646  */
+#line 2137 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tGEQ); }
-#line 6856 "parse.c" /* yacc.c:1646  */
+#line 6848 "parse.c" /* yacc.c:1646  */
     break;
 
   case 139:
-#line 2146 "parse.y" /* yacc.c:1646  */
+#line 2138 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '<'); }
-#line 6862 "parse.c" /* yacc.c:1646  */
+#line 6854 "parse.c" /* yacc.c:1646  */
     break;
 
   case 140:
-#line 2147 "parse.y" /* yacc.c:1646  */
+#line 2139 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tLEQ); }
-#line 6868 "parse.c" /* yacc.c:1646  */
+#line 6860 "parse.c" /* yacc.c:1646  */
     break;
 
   case 141:
-#line 2148 "parse.y" /* yacc.c:1646  */
+#line 2140 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tNEQ); }
-#line 6874 "parse.c" /* yacc.c:1646  */
+#line 6866 "parse.c" /* yacc.c:1646  */
     break;
 
   case 142:
-#line 2149 "parse.y" /* yacc.c:1646  */
+#line 2141 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tLSHFT); }
-#line 6880 "parse.c" /* yacc.c:1646  */
+#line 6872 "parse.c" /* yacc.c:1646  */
     break;
 
   case 143:
-#line 2150 "parse.y" /* yacc.c:1646  */
+#line 2142 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tRSHFT); }
-#line 6886 "parse.c" /* yacc.c:1646  */
+#line 6878 "parse.c" /* yacc.c:1646  */
     break;
 
   case 144:
-#line 2151 "parse.y" /* yacc.c:1646  */
+#line 2143 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '+'); }
-#line 6892 "parse.c" /* yacc.c:1646  */
+#line 6884 "parse.c" /* yacc.c:1646  */
     break;
 
   case 145:
-#line 2152 "parse.y" /* yacc.c:1646  */
+#line 2144 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '-'); }
-#line 6898 "parse.c" /* yacc.c:1646  */
+#line 6890 "parse.c" /* yacc.c:1646  */
     break;
 
   case 146:
-#line 2153 "parse.y" /* yacc.c:1646  */
+#line 2145 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '*'); }
-#line 6904 "parse.c" /* yacc.c:1646  */
+#line 6896 "parse.c" /* yacc.c:1646  */
     break;
 
   case 147:
-#line 2154 "parse.y" /* yacc.c:1646  */
+#line 2146 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '*'); }
-#line 6910 "parse.c" /* yacc.c:1646  */
+#line 6902 "parse.c" /* yacc.c:1646  */
     break;
 
   case 148:
-#line 2155 "parse.y" /* yacc.c:1646  */
+#line 2147 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '/'); }
-#line 6916 "parse.c" /* yacc.c:1646  */
+#line 6908 "parse.c" /* yacc.c:1646  */
     break;
 
   case 149:
-#line 2156 "parse.y" /* yacc.c:1646  */
+#line 2148 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '%'); }
-#line 6922 "parse.c" /* yacc.c:1646  */
+#line 6914 "parse.c" /* yacc.c:1646  */
     break;
 
   case 150:
-#line 2157 "parse.y" /* yacc.c:1646  */
+#line 2149 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tPOW); }
-#line 6928 "parse.c" /* yacc.c:1646  */
+#line 6920 "parse.c" /* yacc.c:1646  */
     break;
 
   case 151:
-#line 2158 "parse.y" /* yacc.c:1646  */
+#line 2150 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tDSTAR); }
-#line 6934 "parse.c" /* yacc.c:1646  */
+#line 6926 "parse.c" /* yacc.c:1646  */
     break;
 
   case 152:
-#line 2159 "parse.y" /* yacc.c:1646  */
+#line 2151 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '!'); }
-#line 6940 "parse.c" /* yacc.c:1646  */
+#line 6932 "parse.c" /* yacc.c:1646  */
     break;
 
   case 153:
-#line 2160 "parse.y" /* yacc.c:1646  */
+#line 2152 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '~'); }
-#line 6946 "parse.c" /* yacc.c:1646  */
+#line 6938 "parse.c" /* yacc.c:1646  */
     break;
 
   case 154:
-#line 2161 "parse.y" /* yacc.c:1646  */
+#line 2153 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tUPLUS); }
-#line 6952 "parse.c" /* yacc.c:1646  */
+#line 6944 "parse.c" /* yacc.c:1646  */
     break;
 
   case 155:
-#line 2162 "parse.y" /* yacc.c:1646  */
+#line 2154 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tUMINUS); }
-#line 6958 "parse.c" /* yacc.c:1646  */
+#line 6950 "parse.c" /* yacc.c:1646  */
     break;
 
   case 156:
-#line 2163 "parse.y" /* yacc.c:1646  */
+#line 2155 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tAREF); }
-#line 6964 "parse.c" /* yacc.c:1646  */
+#line 6956 "parse.c" /* yacc.c:1646  */
     break;
 
   case 157:
-#line 2164 "parse.y" /* yacc.c:1646  */
+#line 2156 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = tASET); }
-#line 6970 "parse.c" /* yacc.c:1646  */
+#line 6962 "parse.c" /* yacc.c:1646  */
     break;
 
   case 158:
-#line 2165 "parse.y" /* yacc.c:1646  */
+#line 2157 "parse.y" /* yacc.c:1646  */
     { ifndef_ripper((yyval.id) = '`'); }
-#line 6976 "parse.c" /* yacc.c:1646  */
+#line 6968 "parse.c" /* yacc.c:1646  */
     break;
 
   case 200:
-#line 2183 "parse.y" /* yacc.c:1646  */
+#line 2175 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 6984 "parse.c" /* yacc.c:1646  */
+#line 6976 "parse.c" /* yacc.c:1646  */
     break;
 
   case 201:
-#line 2187 "parse.y" /* yacc.c:1646  */
+#line 2179 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 6992 "parse.c" /* yacc.c:1646  */
+#line 6984 "parse.c" /* yacc.c:1646  */
     break;
 
   case 202:
-#line 2191 "parse.y" /* yacc.c:1646  */
+#line 2183 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *args;
@@ -7024,38 +7016,38 @@ yyreduce:
 			$$ = dispatch3(opassign, $1, $5, $6);
 		    %*/
 		    }
-#line 7024 "parse.c" /* yacc.c:1646  */
+#line 7016 "parse.c" /* yacc.c:1646  */
     break;
 
   case 203:
-#line 2219 "parse.y" /* yacc.c:1646  */
+#line 2211 "parse.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].node));
 			(yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 7033 "parse.c" /* yacc.c:1646  */
+#line 7025 "parse.c" /* yacc.c:1646  */
     break;
 
   case 204:
-#line 2224 "parse.y" /* yacc.c:1646  */
+#line 2216 "parse.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].node));
 			(yyval.node) = new_attr_op_assign((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 7042 "parse.c" /* yacc.c:1646  */
+#line 7034 "parse.c" /* yacc.c:1646  */
     break;
 
   case 205:
-#line 2229 "parse.y" /* yacc.c:1646  */
+#line 2221 "parse.y" /* yacc.c:1646  */
     {
 			value_expr((yyvsp[0].node));
 			(yyval.node) = new_attr_op_assign((yyvsp[-4].node), ID2VAL(idCOLON2), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 7051 "parse.c" /* yacc.c:1646  */
+#line 7043 "parse.c" /* yacc.c:1646  */
     break;
 
   case 206:
-#line 2234 "parse.y" /* yacc.c:1646  */
+#line 2226 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			YYLTYPE location;
@@ -7066,29 +7058,29 @@ yyreduce:
 			(yyval.node) = const_path_field((yyvsp[-4].node), (yyvsp[-2].id), &location);
 			(yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 7066 "parse.c" /* yacc.c:1646  */
+#line 7058 "parse.c" /* yacc.c:1646  */
     break;
 
   case 207:
-#line 2245 "parse.y" /* yacc.c:1646  */
+#line 2237 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = top_const_field((yyvsp[-2].id));
 			(yyval.node) = new_const_op_assign((yyval.node), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 7075 "parse.c" /* yacc.c:1646  */
+#line 7067 "parse.c" /* yacc.c:1646  */
     break;
 
   case 208:
-#line 2250 "parse.y" /* yacc.c:1646  */
+#line 2242 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[-2].node) = var_field((yyvsp[-2].node));
 			(yyval.node) = backref_assign_error((yyvsp[-2].node), new_op_assign((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc)), &(yyloc));
 		    }
-#line 7084 "parse.c" /* yacc.c:1646  */
+#line 7076 "parse.c" /* yacc.c:1646  */
     break;
 
   case 209:
-#line 2255 "parse.y" /* yacc.c:1646  */
+#line 2247 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[-2].node));
@@ -7099,11 +7091,11 @@ yyreduce:
 			$$ = dispatch2(dot2, $1, $3);
 		    %*/
 		    }
-#line 7099 "parse.c" /* yacc.c:1646  */
+#line 7091 "parse.c" /* yacc.c:1646  */
     break;
 
   case 210:
-#line 2266 "parse.y" /* yacc.c:1646  */
+#line 2258 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[-2].node));
@@ -7114,218 +7106,218 @@ yyreduce:
 			$$ = dispatch2(dot3, $1, $3);
 		    %*/
 		    }
-#line 7114 "parse.c" /* yacc.c:1646  */
+#line 7106 "parse.c" /* yacc.c:1646  */
     break;
 
   case 211:
-#line 2277 "parse.y" /* yacc.c:1646  */
+#line 2269 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '+', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7122 "parse.c" /* yacc.c:1646  */
+#line 7114 "parse.c" /* yacc.c:1646  */
     break;
 
   case 212:
-#line 2281 "parse.y" /* yacc.c:1646  */
+#line 2273 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '-', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7130 "parse.c" /* yacc.c:1646  */
+#line 7122 "parse.c" /* yacc.c:1646  */
     break;
 
   case 213:
-#line 2285 "parse.y" /* yacc.c:1646  */
+#line 2277 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '*', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7138 "parse.c" /* yacc.c:1646  */
+#line 7130 "parse.c" /* yacc.c:1646  */
     break;
 
   case 214:
-#line 2289 "parse.y" /* yacc.c:1646  */
+#line 2281 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '/', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7146 "parse.c" /* yacc.c:1646  */
+#line 7138 "parse.c" /* yacc.c:1646  */
     break;
 
   case 215:
-#line 2293 "parse.y" /* yacc.c:1646  */
+#line 2285 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '%', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7154 "parse.c" /* yacc.c:1646  */
+#line 7146 "parse.c" /* yacc.c:1646  */
     break;
 
   case 216:
-#line 2297 "parse.y" /* yacc.c:1646  */
+#line 2289 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idPow, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7162 "parse.c" /* yacc.c:1646  */
+#line 7154 "parse.c" /* yacc.c:1646  */
     break;
 
   case 217:
-#line 2301 "parse.y" /* yacc.c:1646  */
+#line 2293 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op(call_bin_op((yyvsp[-2].node), idPow, (yyvsp[0].node), &(yylsp[-2]), &(yyloc)), idUMinus, &(yylsp[-3]), &(yyloc));
 		    }
-#line 7170 "parse.c" /* yacc.c:1646  */
+#line 7162 "parse.c" /* yacc.c:1646  */
     break;
 
   case 218:
-#line 2305 "parse.y" /* yacc.c:1646  */
+#line 2297 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op((yyvsp[0].node), idUPlus, &(yylsp[-1]), &(yyloc));
 		    }
-#line 7178 "parse.c" /* yacc.c:1646  */
+#line 7170 "parse.c" /* yacc.c:1646  */
     break;
 
   case 219:
-#line 2309 "parse.y" /* yacc.c:1646  */
+#line 2301 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op((yyvsp[0].node), idUMinus, &(yylsp[-1]), &(yyloc));
 		    }
-#line 7186 "parse.c" /* yacc.c:1646  */
+#line 7178 "parse.c" /* yacc.c:1646  */
     break;
 
   case 220:
-#line 2313 "parse.y" /* yacc.c:1646  */
+#line 2305 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '|', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7194 "parse.c" /* yacc.c:1646  */
+#line 7186 "parse.c" /* yacc.c:1646  */
     break;
 
   case 221:
-#line 2317 "parse.y" /* yacc.c:1646  */
+#line 2309 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '^', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7202 "parse.c" /* yacc.c:1646  */
+#line 7194 "parse.c" /* yacc.c:1646  */
     break;
 
   case 222:
-#line 2321 "parse.y" /* yacc.c:1646  */
+#line 2313 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), '&', (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7210 "parse.c" /* yacc.c:1646  */
+#line 7202 "parse.c" /* yacc.c:1646  */
     break;
 
   case 223:
-#line 2325 "parse.y" /* yacc.c:1646  */
+#line 2317 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idCmp, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7218 "parse.c" /* yacc.c:1646  */
+#line 7210 "parse.c" /* yacc.c:1646  */
     break;
 
   case 225:
-#line 2330 "parse.y" /* yacc.c:1646  */
+#line 2322 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idEq, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7226 "parse.c" /* yacc.c:1646  */
+#line 7218 "parse.c" /* yacc.c:1646  */
     break;
 
   case 226:
-#line 2334 "parse.y" /* yacc.c:1646  */
+#line 2326 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idEqq, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7234 "parse.c" /* yacc.c:1646  */
+#line 7226 "parse.c" /* yacc.c:1646  */
     break;
 
   case 227:
-#line 2338 "parse.y" /* yacc.c:1646  */
+#line 2330 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idNeq, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7242 "parse.c" /* yacc.c:1646  */
+#line 7234 "parse.c" /* yacc.c:1646  */
     break;
 
   case 228:
-#line 2342 "parse.y" /* yacc.c:1646  */
+#line 2334 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7250 "parse.c" /* yacc.c:1646  */
+#line 7242 "parse.c" /* yacc.c:1646  */
     break;
 
   case 229:
-#line 2346 "parse.y" /* yacc.c:1646  */
+#line 2338 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idNeqTilde, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7258 "parse.c" /* yacc.c:1646  */
+#line 7250 "parse.c" /* yacc.c:1646  */
     break;
 
   case 230:
-#line 2350 "parse.y" /* yacc.c:1646  */
+#line 2342 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op(method_cond((yyvsp[0].node), &(yylsp[0])), '!', &(yylsp[-1]), &(yyloc));
 		    }
-#line 7266 "parse.c" /* yacc.c:1646  */
+#line 7258 "parse.c" /* yacc.c:1646  */
     break;
 
   case 231:
-#line 2354 "parse.y" /* yacc.c:1646  */
+#line 2346 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op((yyvsp[0].node), '~', &(yylsp[-1]), &(yyloc));
 		    }
-#line 7274 "parse.c" /* yacc.c:1646  */
+#line 7266 "parse.c" /* yacc.c:1646  */
     break;
 
   case 232:
-#line 2358 "parse.y" /* yacc.c:1646  */
+#line 2350 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idLTLT, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7282 "parse.c" /* yacc.c:1646  */
+#line 7274 "parse.c" /* yacc.c:1646  */
     break;
 
   case 233:
-#line 2362 "parse.y" /* yacc.c:1646  */
+#line 2354 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), idGTGT, (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7290 "parse.c" /* yacc.c:1646  */
+#line 7282 "parse.c" /* yacc.c:1646  */
     break;
 
   case 234:
-#line 2366 "parse.y" /* yacc.c:1646  */
+#line 2358 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = logop(idANDOP, (yyvsp[-2].node), (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7298 "parse.c" /* yacc.c:1646  */
+#line 7290 "parse.c" /* yacc.c:1646  */
     break;
 
   case 235:
-#line 2370 "parse.y" /* yacc.c:1646  */
+#line 2362 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = logop(idOROP, (yyvsp[-2].node), (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7306 "parse.c" /* yacc.c:1646  */
+#line 7298 "parse.c" /* yacc.c:1646  */
     break;
 
   case 236:
-#line 2373 "parse.y" /* yacc.c:1646  */
+#line 2365 "parse.y" /* yacc.c:1646  */
     {in_defined = 1;}
-#line 7312 "parse.c" /* yacc.c:1646  */
+#line 7304 "parse.c" /* yacc.c:1646  */
     break;
 
   case 237:
-#line 2374 "parse.y" /* yacc.c:1646  */
+#line 2366 "parse.y" /* yacc.c:1646  */
     {
 			in_defined = 0;
 			(yyval.node) = new_defined((yyvsp[0].node), &(yyloc));
 		    }
-#line 7321 "parse.c" /* yacc.c:1646  */
+#line 7313 "parse.c" /* yacc.c:1646  */
     break;
 
   case 238:
-#line 2379 "parse.y" /* yacc.c:1646  */
+#line 2371 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[-5].node));
@@ -7335,60 +7327,60 @@ yyreduce:
 			$$ = dispatch3(ifop, $1, $3, $6);
 		    %*/
 		    }
-#line 7335 "parse.c" /* yacc.c:1646  */
+#line 7327 "parse.c" /* yacc.c:1646  */
     break;
 
   case 239:
-#line 2389 "parse.y" /* yacc.c:1646  */
+#line 2381 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 7343 "parse.c" /* yacc.c:1646  */
+#line 7335 "parse.c" /* yacc.c:1646  */
     break;
 
   case 240:
-#line 2394 "parse.y" /* yacc.c:1646  */
+#line 2386 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = '>';}
-#line 7349 "parse.c" /* yacc.c:1646  */
+#line 7341 "parse.c" /* yacc.c:1646  */
     break;
 
   case 241:
-#line 2395 "parse.y" /* yacc.c:1646  */
+#line 2387 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = '<';}
-#line 7355 "parse.c" /* yacc.c:1646  */
+#line 7347 "parse.c" /* yacc.c:1646  */
     break;
 
   case 242:
-#line 2396 "parse.y" /* yacc.c:1646  */
+#line 2388 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = idGE;}
-#line 7361 "parse.c" /* yacc.c:1646  */
+#line 7353 "parse.c" /* yacc.c:1646  */
     break;
 
   case 243:
-#line 2397 "parse.y" /* yacc.c:1646  */
+#line 2389 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = idLE;}
-#line 7367 "parse.c" /* yacc.c:1646  */
+#line 7359 "parse.c" /* yacc.c:1646  */
     break;
 
   case 244:
-#line 2401 "parse.y" /* yacc.c:1646  */
+#line 2393 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_bin_op((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7375 "parse.c" /* yacc.c:1646  */
+#line 7367 "parse.c" /* yacc.c:1646  */
     break;
 
   case 245:
-#line 2405 "parse.y" /* yacc.c:1646  */
+#line 2397 "parse.y" /* yacc.c:1646  */
     {
 			rb_warning1("comparison '%s' after comparison", WARN_ID((yyvsp[-1].id)));
 			(yyval.node) = call_bin_op((yyvsp[-2].node), (yyvsp[-1].id), (yyvsp[0].node), &(yylsp[-1]), &(yyloc));
 		    }
-#line 7384 "parse.c" /* yacc.c:1646  */
+#line 7376 "parse.c" /* yacc.c:1646  */
     break;
 
   case 246:
-#line 2412 "parse.y" /* yacc.c:1646  */
+#line 2404 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[0].node));
@@ -7398,19 +7390,19 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 7398 "parse.c" /* yacc.c:1646  */
+#line 7390 "parse.c" /* yacc.c:1646  */
     break;
 
   case 248:
-#line 2425 "parse.y" /* yacc.c:1646  */
+#line 2417 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    }
-#line 7406 "parse.c" /* yacc.c:1646  */
+#line 7398 "parse.c" /* yacc.c:1646  */
     break;
 
   case 249:
-#line 2429 "parse.y" /* yacc.c:1646  */
+#line 2421 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? arg_append((yyvsp[-3].node), new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].node);
@@ -7418,11 +7410,11 @@ yyreduce:
 			$$ = arg_add_assocs($1, $3);
 		    %*/
 		    }
-#line 7418 "parse.c" /* yacc.c:1646  */
+#line 7410 "parse.c" /* yacc.c:1646  */
     break;
 
   case 250:
-#line 2437 "parse.y" /* yacc.c:1646  */
+#line 2429 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? new_list(new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yyloc)) : 0;
@@ -7430,11 +7422,11 @@ yyreduce:
 			$$ = arg_add_assocs(arg_new(), $1);
 		    %*/
 		    }
-#line 7430 "parse.c" /* yacc.c:1646  */
+#line 7422 "parse.c" /* yacc.c:1646  */
     break;
 
   case 251:
-#line 2447 "parse.y" /* yacc.c:1646  */
+#line 2439 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[0].node));
@@ -7442,11 +7434,11 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 7442 "parse.c" /* yacc.c:1646  */
+#line 7434 "parse.c" /* yacc.c:1646  */
     break;
 
   case 252:
-#line 2455 "parse.y" /* yacc.c:1646  */
+#line 2447 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			YYLTYPE location;
@@ -7458,11 +7450,11 @@ yyreduce:
 			$$ = dispatch2(rescue_mod, $1, $3);
 		    %*/
 		    }
-#line 7458 "parse.c" /* yacc.c:1646  */
+#line 7450 "parse.c" /* yacc.c:1646  */
     break;
 
   case 253:
-#line 2469 "parse.y" /* yacc.c:1646  */
+#line 2461 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -7470,19 +7462,19 @@ yyreduce:
 			$$ = dispatch1(arg_paren, escape_Qundef($2));
 		    %*/
 		    }
-#line 7470 "parse.c" /* yacc.c:1646  */
+#line 7462 "parse.c" /* yacc.c:1646  */
     break;
 
   case 258:
-#line 2485 "parse.y" /* yacc.c:1646  */
+#line 2477 "parse.y" /* yacc.c:1646  */
     {
 		      (yyval.node) = (yyvsp[-1].node);
 		    }
-#line 7478 "parse.c" /* yacc.c:1646  */
+#line 7470 "parse.c" /* yacc.c:1646  */
     break;
 
   case 259:
-#line 2489 "parse.y" /* yacc.c:1646  */
+#line 2481 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? arg_append((yyvsp[-3].node), new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].node);
@@ -7490,11 +7482,11 @@ yyreduce:
 			$$ = arg_add_assocs($1, $3);
 		    %*/
 		    }
-#line 7490 "parse.c" /* yacc.c:1646  */
+#line 7482 "parse.c" /* yacc.c:1646  */
     break;
 
   case 260:
-#line 2497 "parse.y" /* yacc.c:1646  */
+#line 2489 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? new_list(new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yylsp[-1])) : 0;
@@ -7502,11 +7494,11 @@ yyreduce:
 			$$ = arg_add_assocs(arg_new(), $1);
 		    %*/
 		    }
-#line 7502 "parse.c" /* yacc.c:1646  */
+#line 7494 "parse.c" /* yacc.c:1646  */
     break;
 
   case 261:
-#line 2507 "parse.y" /* yacc.c:1646  */
+#line 2499 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[0].node));
@@ -7515,11 +7507,11 @@ yyreduce:
 			$$ = arg_add(arg_new(), $1);
 		    %*/
 		    }
-#line 7515 "parse.c" /* yacc.c:1646  */
+#line 7507 "parse.c" /* yacc.c:1646  */
     break;
 
   case 262:
-#line 2516 "parse.y" /* yacc.c:1646  */
+#line 2508 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
@@ -7527,11 +7519,11 @@ yyreduce:
 			$$ = arg_add_optblock($1, $2);
 		    %*/
 		    }
-#line 7527 "parse.c" /* yacc.c:1646  */
+#line 7519 "parse.c" /* yacc.c:1646  */
     break;
 
   case 263:
-#line 2524 "parse.y" /* yacc.c:1646  */
+#line 2516 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? new_list(new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yylsp[-1])) : 0;
@@ -7541,11 +7533,11 @@ yyreduce:
 			$$ = arg_add_optblock($$, $2);
 		    %*/
 		    }
-#line 7541 "parse.c" /* yacc.c:1646  */
+#line 7533 "parse.c" /* yacc.c:1646  */
     break;
 
   case 264:
-#line 2534 "parse.y" /* yacc.c:1646  */
+#line 2526 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node) ? arg_append((yyvsp[-3].node), new_hash((yyvsp[-1].node), &(yylsp[-1])), &(yyloc)) : (yyvsp[-3].node);
@@ -7554,30 +7546,30 @@ yyreduce:
 			$$ = arg_add_optblock(arg_add_assocs($1, $3), $4);
 		    %*/
 		    }
-#line 7554 "parse.c" /* yacc.c:1646  */
+#line 7546 "parse.c" /* yacc.c:1646  */
     break;
 
   case 266:
-#line 2551 "parse.y" /* yacc.c:1646  */
+#line 2543 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.val) = cmdarg_stack;
 			CMDARG_PUSH(1);
 		    }
-#line 7563 "parse.c" /* yacc.c:1646  */
+#line 7555 "parse.c" /* yacc.c:1646  */
     break;
 
   case 267:
-#line 2556 "parse.y" /* yacc.c:1646  */
+#line 2548 "parse.y" /* yacc.c:1646  */
     {
 			/* CMDARG_POP() */
 			CMDARG_SET((yyvsp[-1].val));
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 7573 "parse.c" /* yacc.c:1646  */
+#line 7565 "parse.c" /* yacc.c:1646  */
     break;
 
   case 268:
-#line 2564 "parse.y" /* yacc.c:1646  */
+#line 2556 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
@@ -7586,27 +7578,27 @@ yyreduce:
 			$$ = $2;
 		    %*/
 		    }
-#line 7586 "parse.c" /* yacc.c:1646  */
+#line 7578 "parse.c" /* yacc.c:1646  */
     break;
 
   case 269:
-#line 2575 "parse.y" /* yacc.c:1646  */
+#line 2567 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 7594 "parse.c" /* yacc.c:1646  */
+#line 7586 "parse.c" /* yacc.c:1646  */
     break;
 
   case 270:
-#line 2579 "parse.y" /* yacc.c:1646  */
+#line 2571 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = 0;
 		    }
-#line 7602 "parse.c" /* yacc.c:1646  */
+#line 7594 "parse.c" /* yacc.c:1646  */
     break;
 
   case 271:
-#line 2585 "parse.y" /* yacc.c:1646  */
+#line 2577 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_list((yyvsp[0].node), &(yyloc));
@@ -7614,11 +7606,11 @@ yyreduce:
 			$$ = arg_add(arg_new(), $1);
 		    %*/
 		    }
-#line 7614 "parse.c" /* yacc.c:1646  */
+#line 7606 "parse.c" /* yacc.c:1646  */
     break;
 
   case 272:
-#line 2593 "parse.y" /* yacc.c:1646  */
+#line 2585 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_SPLAT((yyvsp[0].node));
@@ -7627,11 +7619,11 @@ yyreduce:
 			$$ = arg_add_star(arg_new(), $2);
 		    %*/
 		    }
-#line 7627 "parse.c" /* yacc.c:1646  */
+#line 7619 "parse.c" /* yacc.c:1646  */
     break;
 
   case 273:
-#line 2602 "parse.y" /* yacc.c:1646  */
+#line 2594 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *n1;
@@ -7645,11 +7637,11 @@ yyreduce:
 			$$ = arg_add($1, $3);
 		    %*/
 		    }
-#line 7645 "parse.c" /* yacc.c:1646  */
+#line 7637 "parse.c" /* yacc.c:1646  */
     break;
 
   case 274:
-#line 2616 "parse.y" /* yacc.c:1646  */
+#line 2608 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *n1;
@@ -7663,11 +7655,11 @@ yyreduce:
 			$$ = arg_add_star($1, $4);
 		    %*/
 		    }
-#line 7663 "parse.c" /* yacc.c:1646  */
+#line 7655 "parse.c" /* yacc.c:1646  */
     break;
 
   case 277:
-#line 2636 "parse.y" /* yacc.c:1646  */
+#line 2628 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *n1;
@@ -7681,11 +7673,11 @@ yyreduce:
 			$$ = mrhs_add(args2mrhs($1), $3);
 		    %*/
 		    }
-#line 7681 "parse.c" /* yacc.c:1646  */
+#line 7673 "parse.c" /* yacc.c:1646  */
     break;
 
   case 278:
-#line 2650 "parse.y" /* yacc.c:1646  */
+#line 2642 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *n1;
@@ -7700,11 +7692,11 @@ yyreduce:
 			$$ = mrhs_add_star(args2mrhs($1), $4);
 		    %*/
 		    }
-#line 7700 "parse.c" /* yacc.c:1646  */
+#line 7692 "parse.c" /* yacc.c:1646  */
     break;
 
   case 279:
-#line 2665 "parse.y" /* yacc.c:1646  */
+#line 2657 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_SPLAT((yyvsp[0].node));
@@ -7713,11 +7705,11 @@ yyreduce:
 			$$ = mrhs_add_star(mrhs_new(), $2);
 		    %*/
 		    }
-#line 7713 "parse.c" /* yacc.c:1646  */
+#line 7705 "parse.c" /* yacc.c:1646  */
     break;
 
   case 290:
-#line 2686 "parse.y" /* yacc.c:1646  */
+#line 2678 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_fcall((yyvsp[0].id), 0, &(yyloc));
@@ -7725,11 +7717,11 @@ yyreduce:
 			$$ = method_arg(dispatch1(fcall, $1), arg_new());
 		    %*/
 		    }
-#line 7725 "parse.c" /* yacc.c:1646  */
+#line 7717 "parse.c" /* yacc.c:1646  */
     break;
 
   case 291:
-#line 2694 "parse.y" /* yacc.c:1646  */
+#line 2686 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cmdarg_stack;
 			CMDARG_SET(0);
@@ -7738,11 +7730,11 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 7738 "parse.c" /* yacc.c:1646  */
+#line 7730 "parse.c" /* yacc.c:1646  */
     break;
 
   case 292:
-#line 2704 "parse.y" /* yacc.c:1646  */
+#line 2696 "parse.y" /* yacc.c:1646  */
     {
 			CMDARG_SET((yyvsp[-3].val));
 		    /*%%%*/
@@ -7759,17 +7751,17 @@ yyreduce:
 			$$ = dispatch1(begin, $3);
 		    %*/
 		    }
-#line 7759 "parse.c" /* yacc.c:1646  */
+#line 7751 "parse.c" /* yacc.c:1646  */
     break;
 
   case 293:
-#line 2720 "parse.y" /* yacc.c:1646  */
+#line 2712 "parse.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_ENDARG);}
-#line 7765 "parse.c" /* yacc.c:1646  */
+#line 7757 "parse.c" /* yacc.c:1646  */
     break;
 
   case 294:
-#line 2721 "parse.y" /* yacc.c:1646  */
+#line 2713 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_begin(0, &(yyloc));
@@ -7777,26 +7769,26 @@ yyreduce:
 			$$ = dispatch1(paren, 0);
 		    %*/
 		    }
-#line 7777 "parse.c" /* yacc.c:1646  */
+#line 7769 "parse.c" /* yacc.c:1646  */
     break;
 
   case 295:
-#line 2729 "parse.y" /* yacc.c:1646  */
+#line 2721 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cmdarg_stack;
 			CMDARG_SET(0);
 		    }
-#line 7786 "parse.c" /* yacc.c:1646  */
+#line 7778 "parse.c" /* yacc.c:1646  */
     break;
 
   case 296:
-#line 2733 "parse.y" /* yacc.c:1646  */
+#line 2725 "parse.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_ENDARG);}
-#line 7792 "parse.c" /* yacc.c:1646  */
+#line 7784 "parse.c" /* yacc.c:1646  */
     break;
 
   case 297:
-#line 2734 "parse.y" /* yacc.c:1646  */
+#line 2726 "parse.y" /* yacc.c:1646  */
     {
 			CMDARG_SET((yyvsp[-4].val));
 		    /*%%%*/
@@ -7805,11 +7797,11 @@ yyreduce:
 			$$ = dispatch1(paren, $3);
 		    %*/
 		    }
-#line 7805 "parse.c" /* yacc.c:1646  */
+#line 7797 "parse.c" /* yacc.c:1646  */
     break;
 
   case 298:
-#line 2743 "parse.y" /* yacc.c:1646  */
+#line 2735 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -7817,11 +7809,11 @@ yyreduce:
 			$$ = dispatch1(paren, $2);
 		    %*/
 		    }
-#line 7817 "parse.c" /* yacc.c:1646  */
+#line 7809 "parse.c" /* yacc.c:1646  */
     break;
 
   case 299:
-#line 2751 "parse.y" /* yacc.c:1646  */
+#line 2743 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
@@ -7830,11 +7822,11 @@ yyreduce:
 			$$ = dispatch2(const_path_ref, $1, $3);
 		    %*/
 		    }
-#line 7830 "parse.c" /* yacc.c:1646  */
+#line 7822 "parse.c" /* yacc.c:1646  */
     break;
 
   case 300:
-#line 2760 "parse.y" /* yacc.c:1646  */
+#line 2752 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_COLON3((yyvsp[0].id));
@@ -7843,11 +7835,11 @@ yyreduce:
 			$$ = dispatch1(top_const_ref, $2);
 		    %*/
 		    }
-#line 7843 "parse.c" /* yacc.c:1646  */
+#line 7835 "parse.c" /* yacc.c:1646  */
     break;
 
   case 301:
-#line 2769 "parse.y" /* yacc.c:1646  */
+#line 2761 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = make_array((yyvsp[-1].node), &(yyloc));
@@ -7855,11 +7847,11 @@ yyreduce:
 			$$ = dispatch1(array, escape_Qundef($2));
 		    %*/
 		    }
-#line 7855 "parse.c" /* yacc.c:1646  */
+#line 7847 "parse.c" /* yacc.c:1646  */
     break;
 
   case 302:
-#line 2777 "parse.y" /* yacc.c:1646  */
+#line 2769 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_hash((yyvsp[-1].node), &(yyloc));
@@ -7868,11 +7860,11 @@ yyreduce:
 			$$ = dispatch1(hash, escape_Qundef($2));
 		    %*/
 		    }
-#line 7868 "parse.c" /* yacc.c:1646  */
+#line 7860 "parse.c" /* yacc.c:1646  */
     break;
 
   case 303:
-#line 2786 "parse.y" /* yacc.c:1646  */
+#line 2778 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_RETURN(0);
@@ -7881,11 +7873,11 @@ yyreduce:
 			$$ = dispatch0(return0);
 		    %*/
 		    }
-#line 7881 "parse.c" /* yacc.c:1646  */
+#line 7873 "parse.c" /* yacc.c:1646  */
     break;
 
   case 304:
-#line 2795 "parse.y" /* yacc.c:1646  */
+#line 2787 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_yield((yyvsp[-1].node), &(yyloc));
@@ -7893,11 +7885,11 @@ yyreduce:
 			$$ = dispatch1(yield, dispatch1(paren, $3));
 		    %*/
 		    }
-#line 7893 "parse.c" /* yacc.c:1646  */
+#line 7885 "parse.c" /* yacc.c:1646  */
     break;
 
   case 305:
-#line 2803 "parse.y" /* yacc.c:1646  */
+#line 2795 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_YIELD(0);
@@ -7906,11 +7898,11 @@ yyreduce:
 			$$ = dispatch1(yield, dispatch1(paren, arg_new()));
 		    %*/
 		    }
-#line 7906 "parse.c" /* yacc.c:1646  */
+#line 7898 "parse.c" /* yacc.c:1646  */
     break;
 
   case 306:
-#line 2812 "parse.y" /* yacc.c:1646  */
+#line 2804 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_YIELD(0);
@@ -7919,42 +7911,42 @@ yyreduce:
 			$$ = dispatch0(yield0);
 		    %*/
 		    }
-#line 7919 "parse.c" /* yacc.c:1646  */
+#line 7911 "parse.c" /* yacc.c:1646  */
     break;
 
   case 307:
-#line 2820 "parse.y" /* yacc.c:1646  */
+#line 2812 "parse.y" /* yacc.c:1646  */
     {in_defined = 1;}
-#line 7925 "parse.c" /* yacc.c:1646  */
+#line 7917 "parse.c" /* yacc.c:1646  */
     break;
 
   case 308:
-#line 2821 "parse.y" /* yacc.c:1646  */
+#line 2813 "parse.y" /* yacc.c:1646  */
     {
 			in_defined = 0;
 			(yyval.node) = new_defined((yyvsp[-1].node), &(yyloc));
 		    }
-#line 7934 "parse.c" /* yacc.c:1646  */
+#line 7926 "parse.c" /* yacc.c:1646  */
     break;
 
   case 309:
-#line 2826 "parse.y" /* yacc.c:1646  */
+#line 2818 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op(method_cond((yyvsp[-1].node), &(yylsp[-1])), METHOD_NOT, &(yylsp[-3]), &(yyloc));
 		    }
-#line 7942 "parse.c" /* yacc.c:1646  */
+#line 7934 "parse.c" /* yacc.c:1646  */
     break;
 
   case 310:
-#line 2830 "parse.y" /* yacc.c:1646  */
+#line 2822 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = call_uni_op(method_cond(new_nil(&(yylsp[-1])), &(yylsp[-1])), METHOD_NOT, &(yylsp[-2]), &(yyloc));
 		    }
-#line 7950 "parse.c" /* yacc.c:1646  */
+#line 7942 "parse.c" /* yacc.c:1646  */
     break;
 
   case 311:
-#line 2834 "parse.y" /* yacc.c:1646  */
+#line 2826 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
@@ -7965,11 +7957,11 @@ yyreduce:
 			$$ = method_add_block($$, $2);
 		    %*/
 		    }
-#line 7965 "parse.c" /* yacc.c:1646  */
+#line 7957 "parse.c" /* yacc.c:1646  */
     break;
 
   case 313:
-#line 2846 "parse.y" /* yacc.c:1646  */
+#line 2838 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
@@ -7980,19 +7972,19 @@ yyreduce:
 			$$ = method_add_block($1, $2);
 		    %*/
 		    }
-#line 7980 "parse.c" /* yacc.c:1646  */
+#line 7972 "parse.c" /* yacc.c:1646  */
     break;
 
   case 314:
-#line 2857 "parse.y" /* yacc.c:1646  */
+#line 2849 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 7988 "parse.c" /* yacc.c:1646  */
+#line 7980 "parse.c" /* yacc.c:1646  */
     break;
 
   case 315:
-#line 2864 "parse.y" /* yacc.c:1646  */
+#line 2856 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_if((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), &(yyloc));
@@ -8001,11 +7993,11 @@ yyreduce:
 			$$ = dispatch3(if, $2, $4, escape_Qundef($5));
 		    %*/
 		    }
-#line 8001 "parse.c" /* yacc.c:1646  */
+#line 7993 "parse.c" /* yacc.c:1646  */
     break;
 
   case 316:
-#line 2876 "parse.y" /* yacc.c:1646  */
+#line 2868 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_unless((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), &(yyloc));
@@ -8014,23 +8006,23 @@ yyreduce:
 			$$ = dispatch3(unless, $2, $4, escape_Qundef($5));
 		    %*/
 		    }
-#line 8014 "parse.c" /* yacc.c:1646  */
+#line 8006 "parse.c" /* yacc.c:1646  */
     break;
 
   case 317:
-#line 2884 "parse.y" /* yacc.c:1646  */
+#line 2876 "parse.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8020 "parse.c" /* yacc.c:1646  */
+#line 8012 "parse.c" /* yacc.c:1646  */
     break;
 
   case 318:
-#line 2884 "parse.y" /* yacc.c:1646  */
+#line 2876 "parse.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8026 "parse.c" /* yacc.c:1646  */
+#line 8018 "parse.c" /* yacc.c:1646  */
     break;
 
   case 319:
-#line 2887 "parse.y" /* yacc.c:1646  */
+#line 2879 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_WHILE(cond((yyvsp[-4].node), &(yylsp[-4])), (yyvsp[-1].node), 1);
@@ -8040,23 +8032,23 @@ yyreduce:
 			$$ = dispatch2(while, $3, $6);
 		    %*/
 		    }
-#line 8040 "parse.c" /* yacc.c:1646  */
+#line 8032 "parse.c" /* yacc.c:1646  */
     break;
 
   case 320:
-#line 2896 "parse.y" /* yacc.c:1646  */
+#line 2888 "parse.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8046 "parse.c" /* yacc.c:1646  */
+#line 8038 "parse.c" /* yacc.c:1646  */
     break;
 
   case 321:
-#line 2896 "parse.y" /* yacc.c:1646  */
+#line 2888 "parse.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8052 "parse.c" /* yacc.c:1646  */
+#line 8044 "parse.c" /* yacc.c:1646  */
     break;
 
   case 322:
-#line 2899 "parse.y" /* yacc.c:1646  */
+#line 2891 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node), &(yylsp[-4])), (yyvsp[-1].node), 1);
@@ -8066,11 +8058,11 @@ yyreduce:
 			$$ = dispatch2(until, $3, $6);
 		    %*/
 		    }
-#line 8066 "parse.c" /* yacc.c:1646  */
+#line 8058 "parse.c" /* yacc.c:1646  */
     break;
 
   case 323:
-#line 2911 "parse.y" /* yacc.c:1646  */
+#line 2903 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
@@ -8080,11 +8072,11 @@ yyreduce:
 			$$ = dispatch2(case, $2, $4);
 		    %*/
 		    }
-#line 8080 "parse.c" /* yacc.c:1646  */
+#line 8072 "parse.c" /* yacc.c:1646  */
     break;
 
   case 324:
-#line 2921 "parse.y" /* yacc.c:1646  */
+#line 2913 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_CASE2((yyvsp[-1].node));
@@ -8094,23 +8086,23 @@ yyreduce:
 			$$ = dispatch2(case, Qnil, $3);
 		    %*/
 		    }
-#line 8094 "parse.c" /* yacc.c:1646  */
+#line 8086 "parse.c" /* yacc.c:1646  */
     break;
 
   case 325:
-#line 2931 "parse.y" /* yacc.c:1646  */
+#line 2923 "parse.y" /* yacc.c:1646  */
     {COND_PUSH(1);}
-#line 8100 "parse.c" /* yacc.c:1646  */
+#line 8092 "parse.c" /* yacc.c:1646  */
     break;
 
   case 326:
-#line 2933 "parse.y" /* yacc.c:1646  */
+#line 2925 "parse.y" /* yacc.c:1646  */
     {COND_POP();}
-#line 8106 "parse.c" /* yacc.c:1646  */
+#line 8098 "parse.c" /* yacc.c:1646  */
     break;
 
   case 327:
-#line 2936 "parse.y" /* yacc.c:1646  */
+#line 2928 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			/*
@@ -8158,11 +8150,11 @@ yyreduce:
 			$$ = dispatch3(for, $2, $5, $8);
 		    %*/
 		    }
-#line 8158 "parse.c" /* yacc.c:1646  */
+#line 8150 "parse.c" /* yacc.c:1646  */
     break;
 
   case 328:
-#line 2984 "parse.y" /* yacc.c:1646  */
+#line 2976 "parse.y" /* yacc.c:1646  */
     {
 			if (in_def)
 			    yyerror0("class definition in method body");
@@ -8174,11 +8166,11 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 8174 "parse.c" /* yacc.c:1646  */
+#line 8166 "parse.c" /* yacc.c:1646  */
     break;
 
   case 329:
-#line 2997 "parse.y" /* yacc.c:1646  */
+#line 2989 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
@@ -8192,22 +8184,22 @@ yyreduce:
 			local_pop();
 			in_class = (yyvsp[-5].num) & 1;
 		    }
-#line 8192 "parse.c" /* yacc.c:1646  */
+#line 8184 "parse.c" /* yacc.c:1646  */
     break;
 
   case 330:
-#line 3011 "parse.y" /* yacc.c:1646  */
+#line 3003 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = (in_class << 1) | in_def;
 			in_def = 0;
 			in_class = 0;
 			local_push(0);
 		    }
-#line 8203 "parse.c" /* yacc.c:1646  */
+#line 8195 "parse.c" /* yacc.c:1646  */
     break;
 
   case 331:
-#line 3020 "parse.y" /* yacc.c:1646  */
+#line 3012 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_SCLASS((yyvsp[-4].node), (yyvsp[-1].node));
@@ -8222,11 +8214,11 @@ yyreduce:
 			in_def = (yyvsp[-3].num) & 1;
 			in_class = ((yyvsp[-3].num) >> 1) & 1;
 		    }
-#line 8222 "parse.c" /* yacc.c:1646  */
+#line 8214 "parse.c" /* yacc.c:1646  */
     break;
 
   case 332:
-#line 3035 "parse.y" /* yacc.c:1646  */
+#line 3027 "parse.y" /* yacc.c:1646  */
     {
 			if (in_def)
 			    yyerror0("module definition in method body");
@@ -8238,11 +8230,11 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 8238 "parse.c" /* yacc.c:1646  */
+#line 8230 "parse.c" /* yacc.c:1646  */
     break;
 
   case 333:
-#line 3048 "parse.y" /* yacc.c:1646  */
+#line 3040 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
@@ -8256,30 +8248,30 @@ yyreduce:
 			local_pop();
 			in_class = (yyvsp[-4].num) & 1;
 		    }
-#line 8256 "parse.c" /* yacc.c:1646  */
+#line 8248 "parse.c" /* yacc.c:1646  */
     break;
 
   case 334:
-#line 3062 "parse.y" /* yacc.c:1646  */
+#line 3054 "parse.y" /* yacc.c:1646  */
     {
 			local_push(0);
 			(yyval.id) = current_arg;
 			current_arg = 0;
 		    }
-#line 8266 "parse.c" /* yacc.c:1646  */
+#line 8258 "parse.c" /* yacc.c:1646  */
     break;
 
   case 335:
-#line 3067 "parse.y" /* yacc.c:1646  */
+#line 3059 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = in_def;
 			in_def = 1;
 		    }
-#line 8275 "parse.c" /* yacc.c:1646  */
+#line 8267 "parse.c" /* yacc.c:1646  */
     break;
 
   case 336:
-#line 3074 "parse.y" /* yacc.c:1646  */
+#line 3066 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *body = remove_begin((yyvsp[-1].node));
@@ -8296,17 +8288,17 @@ yyreduce:
 			in_def = (yyvsp[-3].num) & 1;
 			current_arg = (yyvsp[-4].id);
 		    }
-#line 8296 "parse.c" /* yacc.c:1646  */
+#line 8288 "parse.c" /* yacc.c:1646  */
     break;
 
   case 337:
-#line 3090 "parse.y" /* yacc.c:1646  */
+#line 3082 "parse.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_FNAME);}
-#line 8302 "parse.c" /* yacc.c:1646  */
+#line 8294 "parse.c" /* yacc.c:1646  */
     break;
 
   case 338:
-#line 3091 "parse.y" /* yacc.c:1646  */
+#line 3083 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[-1].num) = in_def;
 			in_def = 1;
@@ -8315,11 +8307,11 @@ yyreduce:
 			(yyval.id) = current_arg;
 			current_arg = 0;
 		    }
-#line 8315 "parse.c" /* yacc.c:1646  */
+#line 8307 "parse.c" /* yacc.c:1646  */
     break;
 
   case 339:
-#line 3102 "parse.y" /* yacc.c:1646  */
+#line 3094 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *body = remove_begin((yyvsp[-1].node));
@@ -8336,11 +8328,11 @@ yyreduce:
 			in_def = (yyvsp[-5].num) & 1;
 			current_arg = (yyvsp[-3].id);
 		    }
-#line 8336 "parse.c" /* yacc.c:1646  */
+#line 8328 "parse.c" /* yacc.c:1646  */
     break;
 
   case 340:
-#line 3119 "parse.y" /* yacc.c:1646  */
+#line 3111 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_BREAK(0);
@@ -8349,11 +8341,11 @@ yyreduce:
 			$$ = dispatch1(break, arg_new());
 		    %*/
 		    }
-#line 8349 "parse.c" /* yacc.c:1646  */
+#line 8341 "parse.c" /* yacc.c:1646  */
     break;
 
   case 341:
-#line 3128 "parse.y" /* yacc.c:1646  */
+#line 3120 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_NEXT(0);
@@ -8362,11 +8354,11 @@ yyreduce:
 			$$ = dispatch1(next, arg_new());
 		    %*/
 		    }
-#line 8362 "parse.c" /* yacc.c:1646  */
+#line 8354 "parse.c" /* yacc.c:1646  */
     break;
 
   case 342:
-#line 3137 "parse.y" /* yacc.c:1646  */
+#line 3129 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_REDO();
@@ -8375,11 +8367,11 @@ yyreduce:
 			$$ = dispatch0(redo);
 		    %*/
 		    }
-#line 8375 "parse.c" /* yacc.c:1646  */
+#line 8367 "parse.c" /* yacc.c:1646  */
     break;
 
   case 343:
-#line 3146 "parse.y" /* yacc.c:1646  */
+#line 3138 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_RETRY();
@@ -8388,11 +8380,11 @@ yyreduce:
 			$$ = dispatch0(retry);
 		    %*/
 		    }
-#line 8388 "parse.c" /* yacc.c:1646  */
+#line 8380 "parse.c" /* yacc.c:1646  */
     break;
 
   case 344:
-#line 3157 "parse.y" /* yacc.c:1646  */
+#line 3149 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[0].node));
@@ -8402,51 +8394,51 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 8402 "parse.c" /* yacc.c:1646  */
+#line 8394 "parse.c" /* yacc.c:1646  */
     break;
 
   case 345:
-#line 3169 "parse.y" /* yacc.c:1646  */
+#line 3161 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("begin");
 		    }
-#line 8410 "parse.c" /* yacc.c:1646  */
+#line 8402 "parse.c" /* yacc.c:1646  */
     break;
 
   case 346:
-#line 3175 "parse.y" /* yacc.c:1646  */
+#line 3167 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("if");
 		    }
-#line 8418 "parse.c" /* yacc.c:1646  */
+#line 8410 "parse.c" /* yacc.c:1646  */
     break;
 
   case 347:
-#line 3181 "parse.y" /* yacc.c:1646  */
+#line 3173 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("unless");
 		    }
-#line 8426 "parse.c" /* yacc.c:1646  */
+#line 8418 "parse.c" /* yacc.c:1646  */
     break;
 
   case 348:
-#line 3187 "parse.y" /* yacc.c:1646  */
+#line 3179 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("while");
 		    }
-#line 8434 "parse.c" /* yacc.c:1646  */
+#line 8426 "parse.c" /* yacc.c:1646  */
     break;
 
   case 349:
-#line 3193 "parse.y" /* yacc.c:1646  */
+#line 3185 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("until");
 		    }
-#line 8442 "parse.c" /* yacc.c:1646  */
+#line 8434 "parse.c" /* yacc.c:1646  */
     break;
 
   case 350:
-#line 3199 "parse.y" /* yacc.c:1646  */
+#line 3191 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("case");
 		    /*%%%*/
@@ -8454,35 +8446,35 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 8454 "parse.c" /* yacc.c:1646  */
+#line 8446 "parse.c" /* yacc.c:1646  */
     break;
 
   case 351:
-#line 3209 "parse.y" /* yacc.c:1646  */
+#line 3201 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("for");
 		    }
-#line 8462 "parse.c" /* yacc.c:1646  */
+#line 8454 "parse.c" /* yacc.c:1646  */
     break;
 
   case 352:
-#line 3215 "parse.y" /* yacc.c:1646  */
+#line 3207 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("class");
 		    }
-#line 8470 "parse.c" /* yacc.c:1646  */
+#line 8462 "parse.c" /* yacc.c:1646  */
     break;
 
   case 353:
-#line 3221 "parse.y" /* yacc.c:1646  */
+#line 3213 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("module");
 		    }
-#line 8478 "parse.c" /* yacc.c:1646  */
+#line 8470 "parse.c" /* yacc.c:1646  */
     break;
 
   case 354:
-#line 3227 "parse.y" /* yacc.c:1646  */
+#line 3219 "parse.y" /* yacc.c:1646  */
     {
 			token_info_push("def");
 		    /*%%%*/
@@ -8490,28 +8482,28 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 8490 "parse.c" /* yacc.c:1646  */
+#line 8482 "parse.c" /* yacc.c:1646  */
     break;
 
   case 355:
-#line 3237 "parse.y" /* yacc.c:1646  */
+#line 3229 "parse.y" /* yacc.c:1646  */
     {
 			token_info_pop("end");
 		    }
-#line 8498 "parse.c" /* yacc.c:1646  */
+#line 8490 "parse.c" /* yacc.c:1646  */
     break;
 
   case 356:
-#line 3243 "parse.y" /* yacc.c:1646  */
+#line 3235 "parse.y" /* yacc.c:1646  */
     {
 			if (in_class && !in_def && !dyna_in_block())
 			    yyerror0("Invalid return in class/module body");
 		    }
-#line 8507 "parse.c" /* yacc.c:1646  */
+#line 8499 "parse.c" /* yacc.c:1646  */
     break;
 
   case 363:
-#line 3274 "parse.y" /* yacc.c:1646  */
+#line 3266 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_if((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
@@ -8520,11 +8512,11 @@ yyreduce:
 			$$ = dispatch3(elsif, $2, $4, escape_Qundef($5));
 		    %*/
 		    }
-#line 8520 "parse.c" /* yacc.c:1646  */
+#line 8512 "parse.c" /* yacc.c:1646  */
     break;
 
   case 365:
-#line 3286 "parse.y" /* yacc.c:1646  */
+#line 3278 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -8532,22 +8524,22 @@ yyreduce:
 			$$ = dispatch1(else, $2);
 		    %*/
 		    }
-#line 8532 "parse.c" /* yacc.c:1646  */
+#line 8524 "parse.c" /* yacc.c:1646  */
     break;
 
   case 368:
-#line 3300 "parse.y" /* yacc.c:1646  */
+#line 3292 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[0].id), 0, &(yyloc));
 		    /*%%%*/
 		    /*%
 		    %*/
 		    }
-#line 8543 "parse.c" /* yacc.c:1646  */
+#line 8535 "parse.c" /* yacc.c:1646  */
     break;
 
   case 369:
-#line 3307 "parse.y" /* yacc.c:1646  */
+#line 3299 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -8555,11 +8547,11 @@ yyreduce:
 			$$ = dispatch1(mlhs_paren, $2);
 		    %*/
 		    }
-#line 8555 "parse.c" /* yacc.c:1646  */
+#line 8547 "parse.c" /* yacc.c:1646  */
     break;
 
   case 370:
-#line 3317 "parse.y" /* yacc.c:1646  */
+#line 3309 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_list((yyvsp[0].node), &(yyloc));
@@ -8567,11 +8559,11 @@ yyreduce:
 			$$ = mlhs_add(mlhs_new(), $1);
 		    %*/
 		    }
-#line 8567 "parse.c" /* yacc.c:1646  */
+#line 8559 "parse.c" /* yacc.c:1646  */
     break;
 
   case 371:
-#line 3325 "parse.y" /* yacc.c:1646  */
+#line 3317 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
@@ -8579,11 +8571,11 @@ yyreduce:
 			$$ = mlhs_add($1, $3);
 		    %*/
 		    }
-#line 8579 "parse.c" /* yacc.c:1646  */
+#line 8571 "parse.c" /* yacc.c:1646  */
     break;
 
   case 372:
-#line 3335 "parse.y" /* yacc.c:1646  */
+#line 3327 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_masgn((yyvsp[0].node), 0, &(yyloc));
@@ -8591,11 +8583,11 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 8591 "parse.c" /* yacc.c:1646  */
+#line 8583 "parse.c" /* yacc.c:1646  */
     break;
 
   case 373:
-#line 3343 "parse.y" /* yacc.c:1646  */
+#line 3335 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[0].id), 0, &(yyloc));
 		    /*%%%*/
@@ -8604,11 +8596,11 @@ yyreduce:
 			$$ = mlhs_add_star($1, $$);
 		    %*/
 		    }
-#line 8604 "parse.c" /* yacc.c:1646  */
+#line 8596 "parse.c" /* yacc.c:1646  */
     break;
 
   case 374:
-#line 3352 "parse.y" /* yacc.c:1646  */
+#line 3344 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[-2].id), 0, &(yyloc));
 		    /*%%%*/
@@ -8618,11 +8610,11 @@ yyreduce:
 			$$ = mlhs_add_post($$, $6);
 		    %*/
 		    }
-#line 8618 "parse.c" /* yacc.c:1646  */
+#line 8610 "parse.c" /* yacc.c:1646  */
     break;
 
   case 375:
-#line 3362 "parse.y" /* yacc.c:1646  */
+#line 3354 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_masgn((yyvsp[-2].node), NODE_SPECIAL_NO_NAME_REST, &(yyloc));
@@ -8630,11 +8622,11 @@ yyreduce:
 			$$ = mlhs_add_star($1, Qnil);
 		    %*/
 		    }
-#line 8630 "parse.c" /* yacc.c:1646  */
+#line 8622 "parse.c" /* yacc.c:1646  */
     break;
 
   case 376:
-#line 3370 "parse.y" /* yacc.c:1646  */
+#line 3362 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_masgn((yyvsp[-4].node), new_postarg(NODE_SPECIAL_NO_NAME_REST, (yyvsp[0].node), &(yyloc)), &(yyloc));
@@ -8643,11 +8635,11 @@ yyreduce:
 			$$ = mlhs_add_post($$, $5);
 		    %*/
 		    }
-#line 8643 "parse.c" /* yacc.c:1646  */
+#line 8635 "parse.c" /* yacc.c:1646  */
     break;
 
   case 377:
-#line 3379 "parse.y" /* yacc.c:1646  */
+#line 3371 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[0].id), 0, &(yyloc));
 		    /*%%%*/
@@ -8656,11 +8648,11 @@ yyreduce:
 			$$ = mlhs_add_star(mlhs_new(), $$);
 		    %*/
 		    }
-#line 8656 "parse.c" /* yacc.c:1646  */
+#line 8648 "parse.c" /* yacc.c:1646  */
     break;
 
   case 378:
-#line 3388 "parse.y" /* yacc.c:1646  */
+#line 3380 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[-2].id), 0, &(yyloc));
 		    /*%%%*/
@@ -8670,11 +8662,11 @@ yyreduce:
 			$$ = mlhs_add_post($$, $4);
 		    %*/
 		    }
-#line 8670 "parse.c" /* yacc.c:1646  */
+#line 8662 "parse.c" /* yacc.c:1646  */
     break;
 
   case 379:
-#line 3398 "parse.y" /* yacc.c:1646  */
+#line 3390 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_masgn(0, NODE_SPECIAL_NO_NAME_REST, &(yyloc));
@@ -8682,11 +8674,11 @@ yyreduce:
 			$$ = mlhs_add_star(mlhs_new(), Qnil);
 		    %*/
 		    }
-#line 8682 "parse.c" /* yacc.c:1646  */
+#line 8674 "parse.c" /* yacc.c:1646  */
     break;
 
   case 380:
-#line 3406 "parse.y" /* yacc.c:1646  */
+#line 3398 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_masgn(0, new_postarg(NODE_SPECIAL_NO_NAME_REST, (yyvsp[0].node), &(yyloc)), &(yyloc));
@@ -8695,99 +8687,99 @@ yyreduce:
 			$$ = mlhs_add_post($$, $3);
 		    %*/
 		    }
-#line 8695 "parse.c" /* yacc.c:1646  */
+#line 8687 "parse.c" /* yacc.c:1646  */
     break;
 
   case 381:
-#line 3418 "parse.y" /* yacc.c:1646  */
+#line 3410 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 8703 "parse.c" /* yacc.c:1646  */
+#line 8695 "parse.c" /* yacc.c:1646  */
     break;
 
   case 382:
-#line 3422 "parse.y" /* yacc.c:1646  */
+#line 3414 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail((yyvsp[-1].node), Qnone, (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 8711 "parse.c" /* yacc.c:1646  */
+#line 8703 "parse.c" /* yacc.c:1646  */
     break;
 
   case 383:
-#line 3426 "parse.y" /* yacc.c:1646  */
+#line 3418 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, (yyvsp[-1].id), (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 8719 "parse.c" /* yacc.c:1646  */
+#line 8711 "parse.c" /* yacc.c:1646  */
     break;
 
   case 384:
-#line 3430 "parse.y" /* yacc.c:1646  */
+#line 3422 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, Qnone, (yyvsp[0].id), &(yylsp[0]));
 		    }
-#line 8727 "parse.c" /* yacc.c:1646  */
+#line 8719 "parse.c" /* yacc.c:1646  */
     break;
 
   case 385:
-#line 3436 "parse.y" /* yacc.c:1646  */
+#line 3428 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 8735 "parse.c" /* yacc.c:1646  */
+#line 8727 "parse.c" /* yacc.c:1646  */
     break;
 
   case 386:
-#line 3440 "parse.y" /* yacc.c:1646  */
+#line 3432 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 		    }
-#line 8743 "parse.c" /* yacc.c:1646  */
+#line 8735 "parse.c" /* yacc.c:1646  */
     break;
 
   case 387:
-#line 3446 "parse.y" /* yacc.c:1646  */
+#line 3438 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8751 "parse.c" /* yacc.c:1646  */
+#line 8743 "parse.c" /* yacc.c:1646  */
     break;
 
   case 388:
-#line 3450 "parse.y" /* yacc.c:1646  */
+#line 3442 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8759 "parse.c" /* yacc.c:1646  */
+#line 8751 "parse.c" /* yacc.c:1646  */
     break;
 
   case 389:
-#line 3454 "parse.y" /* yacc.c:1646  */
+#line 3446 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8767 "parse.c" /* yacc.c:1646  */
+#line 8759 "parse.c" /* yacc.c:1646  */
     break;
 
   case 390:
-#line 3458 "parse.y" /* yacc.c:1646  */
+#line 3450 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), Qnone, (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8775 "parse.c" /* yacc.c:1646  */
+#line 8767 "parse.c" /* yacc.c:1646  */
     break;
 
   case 391:
-#line 3462 "parse.y" /* yacc.c:1646  */
+#line 3454 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-3].node), Qnone, (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8783 "parse.c" /* yacc.c:1646  */
+#line 8775 "parse.c" /* yacc.c:1646  */
     break;
 
   case 392:
-#line 3466 "parse.y" /* yacc.c:1646  */
+#line 3458 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-1].node), Qnone, 1, Qnone, new_args_tail(Qnone, Qnone, Qnone, &(yylsp[-1])), &(yyloc));
 		    /*%%%*/
@@ -8795,91 +8787,91 @@ yyreduce:
                         dispatch1(excessed_comma, $$);
 		    %*/
 		    }
-#line 8795 "parse.c" /* yacc.c:1646  */
+#line 8787 "parse.c" /* yacc.c:1646  */
     break;
 
   case 393:
-#line 3474 "parse.y" /* yacc.c:1646  */
+#line 3466 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), Qnone, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8803 "parse.c" /* yacc.c:1646  */
+#line 8795 "parse.c" /* yacc.c:1646  */
     break;
 
   case 394:
-#line 3478 "parse.y" /* yacc.c:1646  */
+#line 3470 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-1].node), Qnone, Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8811 "parse.c" /* yacc.c:1646  */
+#line 8803 "parse.c" /* yacc.c:1646  */
     break;
 
   case 395:
-#line 3482 "parse.y" /* yacc.c:1646  */
+#line 3474 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-3].node), (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8819 "parse.c" /* yacc.c:1646  */
+#line 8811 "parse.c" /* yacc.c:1646  */
     break;
 
   case 396:
-#line 3486 "parse.y" /* yacc.c:1646  */
+#line 3478 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8827 "parse.c" /* yacc.c:1646  */
+#line 8819 "parse.c" /* yacc.c:1646  */
     break;
 
   case 397:
-#line 3490 "parse.y" /* yacc.c:1646  */
+#line 3482 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-1].node), Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8835 "parse.c" /* yacc.c:1646  */
+#line 8827 "parse.c" /* yacc.c:1646  */
     break;
 
   case 398:
-#line 3494 "parse.y" /* yacc.c:1646  */
+#line 3486 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-3].node), Qnone, (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8843 "parse.c" /* yacc.c:1646  */
+#line 8835 "parse.c" /* yacc.c:1646  */
     break;
 
   case 399:
-#line 3498 "parse.y" /* yacc.c:1646  */
+#line 3490 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8851 "parse.c" /* yacc.c:1646  */
+#line 8843 "parse.c" /* yacc.c:1646  */
     break;
 
   case 400:
-#line 3502 "parse.y" /* yacc.c:1646  */
+#line 3494 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 8859 "parse.c" /* yacc.c:1646  */
+#line 8851 "parse.c" /* yacc.c:1646  */
     break;
 
   case 401:
-#line 3506 "parse.y" /* yacc.c:1646  */
+#line 3498 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 8867 "parse.c" /* yacc.c:1646  */
+#line 8859 "parse.c" /* yacc.c:1646  */
     break;
 
   case 403:
-#line 3513 "parse.y" /* yacc.c:1646  */
+#line 3505 "parse.y" /* yacc.c:1646  */
     {
 			command_start = TRUE;
 		    }
-#line 8875 "parse.c" /* yacc.c:1646  */
+#line 8867 "parse.c" /* yacc.c:1646  */
     break;
 
   case 404:
-#line 3519 "parse.y" /* yacc.c:1646  */
+#line 3511 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 		    /*%%%*/
@@ -8889,11 +8881,11 @@ yyreduce:
                                           escape_Qundef($2));
 		    %*/
 		    }
-#line 8889 "parse.c" /* yacc.c:1646  */
+#line 8881 "parse.c" /* yacc.c:1646  */
     break;
 
   case 405:
-#line 3529 "parse.y" /* yacc.c:1646  */
+#line 3521 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -8902,11 +8894,11 @@ yyreduce:
                                           Qnil);
 		    %*/
 		    }
-#line 8902 "parse.c" /* yacc.c:1646  */
+#line 8894 "parse.c" /* yacc.c:1646  */
     break;
 
   case 406:
-#line 3538 "parse.y" /* yacc.c:1646  */
+#line 3530 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 		    /*%%%*/
@@ -8915,19 +8907,19 @@ yyreduce:
 			$$ = blockvar_new(escape_Qundef($2), escape_Qundef($3));
 		    %*/
 		    }
-#line 8915 "parse.c" /* yacc.c:1646  */
+#line 8907 "parse.c" /* yacc.c:1646  */
     break;
 
   case 407:
-#line 3550 "parse.y" /* yacc.c:1646  */
+#line 3542 "parse.y" /* yacc.c:1646  */
     {
 		      (yyval.node) = 0;
 		    }
-#line 8923 "parse.c" /* yacc.c:1646  */
+#line 8915 "parse.c" /* yacc.c:1646  */
     break;
 
   case 408:
-#line 3554 "parse.y" /* yacc.c:1646  */
+#line 3546 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -8935,11 +8927,11 @@ yyreduce:
 			$$ = $3;
 		    %*/
 		    }
-#line 8935 "parse.c" /* yacc.c:1646  */
+#line 8927 "parse.c" /* yacc.c:1646  */
     break;
 
   case 411:
-#line 3580 "parse.y" /* yacc.c:1646  */
+#line 3572 "parse.y" /* yacc.c:1646  */
     {
 			new_bv(get_id((yyvsp[0].id)));
 		    /*%%%*/
@@ -8947,53 +8939,53 @@ yyreduce:
 			$$ = get_value($1);
 		    %*/
 		    }
-#line 8947 "parse.c" /* yacc.c:1646  */
+#line 8939 "parse.c" /* yacc.c:1646  */
     break;
 
   case 412:
-#line 3588 "parse.y" /* yacc.c:1646  */
+#line 3580 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = 0;
 		    }
-#line 8955 "parse.c" /* yacc.c:1646  */
+#line 8947 "parse.c" /* yacc.c:1646  */
     break;
 
   case 413:
-#line 3593 "parse.y" /* yacc.c:1646  */
+#line 3585 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.vars) = dyna_push();
 		    }
-#line 8963 "parse.c" /* yacc.c:1646  */
+#line 8955 "parse.c" /* yacc.c:1646  */
     break;
 
   case 414:
-#line 3596 "parse.y" /* yacc.c:1646  */
+#line 3588 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = lpar_beg;
 			lpar_beg = ++paren_nest;
 		    }
-#line 8972 "parse.c" /* yacc.c:1646  */
+#line 8964 "parse.c" /* yacc.c:1646  */
     break;
 
   case 415:
-#line 3601 "parse.y" /* yacc.c:1646  */
+#line 3593 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = ruby_sourceline;
 		    }
-#line 8980 "parse.c" /* yacc.c:1646  */
+#line 8972 "parse.c" /* yacc.c:1646  */
     break;
 
   case 416:
-#line 3604 "parse.y" /* yacc.c:1646  */
+#line 3596 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.val) = cmdarg_stack;
 			CMDARG_SET(0);
 		    }
-#line 8989 "parse.c" /* yacc.c:1646  */
+#line 8981 "parse.c" /* yacc.c:1646  */
     break;
 
   case 417:
-#line 3609 "parse.y" /* yacc.c:1646  */
+#line 3601 "parse.y" /* yacc.c:1646  */
     {
 			lpar_beg = (yyvsp[-4].num);
 			CMDARG_SET((yyvsp[-1].val));
@@ -9008,11 +9000,11 @@ yyreduce:
 		    %*/
 			dyna_pop((yyvsp[-5].vars));
 		    }
-#line 9008 "parse.c" /* yacc.c:1646  */
+#line 9000 "parse.c" /* yacc.c:1646  */
     break;
 
   case 418:
-#line 3626 "parse.y" /* yacc.c:1646  */
+#line 3618 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-2].node);
@@ -9020,46 +9012,46 @@ yyreduce:
 			$$ = dispatch1(paren, $2);
 		    %*/
 		    }
-#line 9020 "parse.c" /* yacc.c:1646  */
+#line 9012 "parse.c" /* yacc.c:1646  */
     break;
 
   case 419:
-#line 3634 "parse.y" /* yacc.c:1646  */
+#line 3626 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 9028 "parse.c" /* yacc.c:1646  */
+#line 9020 "parse.c" /* yacc.c:1646  */
     break;
 
   case 420:
-#line 3640 "parse.y" /* yacc.c:1646  */
+#line 3632 "parse.y" /* yacc.c:1646  */
     {
 			token_info_pop("}");
 			(yyval.node) = (yyvsp[-1].node);
 		    }
-#line 9037 "parse.c" /* yacc.c:1646  */
+#line 9029 "parse.c" /* yacc.c:1646  */
     break;
 
   case 421:
-#line 3645 "parse.y" /* yacc.c:1646  */
+#line 3637 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    }
-#line 9045 "parse.c" /* yacc.c:1646  */
+#line 9037 "parse.c" /* yacc.c:1646  */
     break;
 
   case 422:
-#line 3651 "parse.y" /* yacc.c:1646  */
+#line 3643 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9055 "parse.c" /* yacc.c:1646  */
+#line 9047 "parse.c" /* yacc.c:1646  */
     break;
 
   case 423:
-#line 3657 "parse.y" /* yacc.c:1646  */
+#line 3649 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    /*%%%*/
@@ -9068,11 +9060,11 @@ yyreduce:
 			nd_set_line((yyval.node), (yyvsp[-2].num));
 		    /*% %*/
 		    }
-#line 9068 "parse.c" /* yacc.c:1646  */
+#line 9060 "parse.c" /* yacc.c:1646  */
     break;
 
   case 424:
-#line 3668 "parse.y" /* yacc.c:1646  */
+#line 3660 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (nd_type((yyvsp[-1].node)) == NODE_YIELD) {
@@ -9089,19 +9081,19 @@ yyreduce:
 			$$ = method_add_block($1, $2);
 		    %*/
 		    }
-#line 9089 "parse.c" /* yacc.c:1646  */
+#line 9081 "parse.c" /* yacc.c:1646  */
     break;
 
   case 425:
-#line 3685 "parse.y" /* yacc.c:1646  */
+#line 3677 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall((yyvsp[-2].id), (yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    }
-#line 9097 "parse.c" /* yacc.c:1646  */
+#line 9089 "parse.c" /* yacc.c:1646  */
     break;
 
   case 426:
-#line 3689 "parse.y" /* yacc.c:1646  */
+#line 3681 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
@@ -9114,11 +9106,11 @@ yyreduce:
 			$$ = method_add_block($$, $5);
 		    %*/
 		    }
-#line 9114 "parse.c" /* yacc.c:1646  */
+#line 9106 "parse.c" /* yacc.c:1646  */
     break;
 
   case 427:
-#line 3702 "parse.y" /* yacc.c:1646  */
+#line 3694 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			block_dup_check((yyvsp[-1].node), (yyvsp[0].node));
@@ -9131,11 +9123,11 @@ yyreduce:
 			$$ = method_add_block($$, $5);
 		    %*/
 		    }
-#line 9131 "parse.c" /* yacc.c:1646  */
+#line 9123 "parse.c" /* yacc.c:1646  */
     break;
 
   case 428:
-#line 3717 "parse.y" /* yacc.c:1646  */
+#line 3709 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -9145,95 +9137,95 @@ yyreduce:
 			$$ = method_arg(dispatch1(fcall, $1), $2);
 		    %*/
 		    }
-#line 9145 "parse.c" /* yacc.c:1646  */
+#line 9137 "parse.c" /* yacc.c:1646  */
     break;
 
   case 429:
-#line 3727 "parse.y" /* yacc.c:1646  */
+#line 3719 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9155 "parse.c" /* yacc.c:1646  */
+#line 9147 "parse.c" /* yacc.c:1646  */
     break;
 
   case 430:
-#line 3733 "parse.y" /* yacc.c:1646  */
+#line 3725 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall((yyvsp[-3].id), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node), &(yyloc));
 			nd_set_line((yyval.node), (yyvsp[-1].num));
 		    }
-#line 9164 "parse.c" /* yacc.c:1646  */
+#line 9156 "parse.c" /* yacc.c:1646  */
     break;
 
   case 431:
-#line 3738 "parse.y" /* yacc.c:1646  */
+#line 3730 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9174 "parse.c" /* yacc.c:1646  */
+#line 9166 "parse.c" /* yacc.c:1646  */
     break;
 
   case 432:
-#line 3744 "parse.y" /* yacc.c:1646  */
+#line 3736 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[0].node), &(yyloc));
 			nd_set_line((yyval.node), (yyvsp[-1].num));
 		    }
-#line 9183 "parse.c" /* yacc.c:1646  */
+#line 9175 "parse.c" /* yacc.c:1646  */
     break;
 
   case 433:
-#line 3749 "parse.y" /* yacc.c:1646  */
+#line 3741 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-2].node), (yyvsp[0].id), Qnull, &(yyloc));
 		    }
-#line 9191 "parse.c" /* yacc.c:1646  */
+#line 9183 "parse.c" /* yacc.c:1646  */
     break;
 
   case 434:
-#line 3753 "parse.y" /* yacc.c:1646  */
+#line 3745 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9201 "parse.c" /* yacc.c:1646  */
+#line 9193 "parse.c" /* yacc.c:1646  */
     break;
 
   case 435:
-#line 3759 "parse.y" /* yacc.c:1646  */
+#line 3751 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall((yyvsp[-2].id), (yyvsp[-3].node), ID2VAL(idCall), (yyvsp[0].node), &(yyloc));
 			nd_set_line((yyval.node), (yyvsp[-1].num));
 		    }
-#line 9210 "parse.c" /* yacc.c:1646  */
+#line 9202 "parse.c" /* yacc.c:1646  */
     break;
 
   case 436:
-#line 3764 "parse.y" /* yacc.c:1646  */
+#line 3756 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9220 "parse.c" /* yacc.c:1646  */
+#line 9212 "parse.c" /* yacc.c:1646  */
     break;
 
   case 437:
-#line 3770 "parse.y" /* yacc.c:1646  */
+#line 3762 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_qcall(ID2VAL(idCOLON2), (yyvsp[-3].node), ID2VAL(idCall), (yyvsp[0].node), &(yyloc));
 			nd_set_line((yyval.node), (yyvsp[-1].num));
 		    }
-#line 9229 "parse.c" /* yacc.c:1646  */
+#line 9221 "parse.c" /* yacc.c:1646  */
     break;
 
   case 438:
-#line 3775 "parse.y" /* yacc.c:1646  */
+#line 3767 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_SUPER((yyvsp[0].node));
@@ -9242,11 +9234,11 @@ yyreduce:
 			$$ = dispatch1(super, $2);
 		    %*/
 		    }
-#line 9242 "parse.c" /* yacc.c:1646  */
+#line 9234 "parse.c" /* yacc.c:1646  */
     break;
 
   case 439:
-#line 3784 "parse.y" /* yacc.c:1646  */
+#line 3776 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_ZSUPER();
@@ -9255,11 +9247,11 @@ yyreduce:
 			$$ = dispatch0(zsuper);
 		    %*/
 		    }
-#line 9255 "parse.c" /* yacc.c:1646  */
+#line 9247 "parse.c" /* yacc.c:1646  */
     break;
 
   case 440:
-#line 3793 "parse.y" /* yacc.c:1646  */
+#line 3785 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if ((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF)
@@ -9271,21 +9263,21 @@ yyreduce:
 			$$ = dispatch2(aref, $1, escape_Qundef($3));
 		    %*/
 		    }
-#line 9271 "parse.c" /* yacc.c:1646  */
+#line 9263 "parse.c" /* yacc.c:1646  */
     break;
 
   case 441:
-#line 3807 "parse.y" /* yacc.c:1646  */
+#line 3799 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9281 "parse.c" /* yacc.c:1646  */
+#line 9273 "parse.c" /* yacc.c:1646  */
     break;
 
   case 442:
-#line 3813 "parse.y" /* yacc.c:1646  */
+#line 3805 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    /*%%%*/
@@ -9294,21 +9286,21 @@ yyreduce:
 			nd_set_line((yyval.node), (yyvsp[-2].num));
 		    /*% %*/
 		    }
-#line 9294 "parse.c" /* yacc.c:1646  */
+#line 9286 "parse.c" /* yacc.c:1646  */
     break;
 
   case 443:
-#line 3822 "parse.y" /* yacc.c:1646  */
+#line 3814 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.num) = ruby_sourceline;
 		    /*% %*/
 		    }
-#line 9304 "parse.c" /* yacc.c:1646  */
+#line 9296 "parse.c" /* yacc.c:1646  */
     break;
 
   case 444:
-#line 3828 "parse.y" /* yacc.c:1646  */
+#line 3820 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    /*%%%*/
@@ -9317,55 +9309,55 @@ yyreduce:
 			nd_set_line((yyval.node), (yyvsp[-2].num));
 		    /*% %*/
 		    }
-#line 9317 "parse.c" /* yacc.c:1646  */
+#line 9309 "parse.c" /* yacc.c:1646  */
     break;
 
   case 445:
-#line 3838 "parse.y" /* yacc.c:1646  */
+#line 3830 "parse.y" /* yacc.c:1646  */
     {(yyval.vars) = dyna_push();}
-#line 9323 "parse.c" /* yacc.c:1646  */
+#line 9315 "parse.c" /* yacc.c:1646  */
     break;
 
   case 446:
-#line 3839 "parse.y" /* yacc.c:1646  */
+#line 3831 "parse.y" /* yacc.c:1646  */
     {(yyval.val) = cmdarg_stack >> 1; CMDARG_SET(0);}
-#line 9329 "parse.c" /* yacc.c:1646  */
+#line 9321 "parse.c" /* yacc.c:1646  */
     break;
 
   case 447:
-#line 3841 "parse.y" /* yacc.c:1646  */
+#line 3833 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_brace_body((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 			dyna_pop((yyvsp[-3].vars));
 			CMDARG_SET((yyvsp[-2].val));
 		    }
-#line 9339 "parse.c" /* yacc.c:1646  */
+#line 9331 "parse.c" /* yacc.c:1646  */
     break;
 
   case 448:
-#line 3848 "parse.y" /* yacc.c:1646  */
+#line 3840 "parse.y" /* yacc.c:1646  */
     {(yyval.vars) = dyna_push();}
-#line 9345 "parse.c" /* yacc.c:1646  */
+#line 9337 "parse.c" /* yacc.c:1646  */
     break;
 
   case 449:
-#line 3849 "parse.y" /* yacc.c:1646  */
+#line 3841 "parse.y" /* yacc.c:1646  */
     {(yyval.val) = cmdarg_stack; CMDARG_SET(0);}
-#line 9351 "parse.c" /* yacc.c:1646  */
+#line 9343 "parse.c" /* yacc.c:1646  */
     break;
 
   case 450:
-#line 3851 "parse.y" /* yacc.c:1646  */
+#line 3843 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_do_body((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 			dyna_pop((yyvsp[-3].vars));
 			CMDARG_SET((yyvsp[-2].val));
 		    }
-#line 9361 "parse.c" /* yacc.c:1646  */
+#line 9353 "parse.c" /* yacc.c:1646  */
     break;
 
   case 451:
-#line 3861 "parse.y" /* yacc.c:1646  */
+#line 3853 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
@@ -9374,11 +9366,11 @@ yyreduce:
 			$$ = dispatch3(when, $2, $4, escape_Qundef($5));
 		    %*/
 		    }
-#line 9374 "parse.c" /* yacc.c:1646  */
+#line 9366 "parse.c" /* yacc.c:1646  */
     break;
 
   case 454:
-#line 3878 "parse.y" /* yacc.c:1646  */
+#line 3870 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if ((yyvsp[-3].node)) {
@@ -9398,11 +9390,11 @@ yyreduce:
 				       escape_Qundef($6));
 		    %*/
 		    }
-#line 9398 "parse.c" /* yacc.c:1646  */
+#line 9390 "parse.c" /* yacc.c:1646  */
     break;
 
   case 456:
-#line 3901 "parse.y" /* yacc.c:1646  */
+#line 3893 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_list((yyvsp[0].node), &(yyloc));
@@ -9410,11 +9402,11 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 9410 "parse.c" /* yacc.c:1646  */
+#line 9402 "parse.c" /* yacc.c:1646  */
     break;
 
   case 457:
-#line 3909 "parse.y" /* yacc.c:1646  */
+#line 3901 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (!((yyval.node) = splat_array((yyvsp[0].node)))) (yyval.node) = (yyvsp[0].node);
@@ -9422,19 +9414,19 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 9422 "parse.c" /* yacc.c:1646  */
+#line 9414 "parse.c" /* yacc.c:1646  */
     break;
 
   case 459:
-#line 3920 "parse.y" /* yacc.c:1646  */
+#line 3912 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 9430 "parse.c" /* yacc.c:1646  */
+#line 9422 "parse.c" /* yacc.c:1646  */
     break;
 
   case 461:
-#line 3927 "parse.y" /* yacc.c:1646  */
+#line 3919 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -9442,11 +9434,11 @@ yyreduce:
 			$$ = dispatch1(ensure, $2);
 		    %*/
 		    }
-#line 9442 "parse.c" /* yacc.c:1646  */
+#line 9434 "parse.c" /* yacc.c:1646  */
     break;
 
   case 464:
-#line 3939 "parse.y" /* yacc.c:1646  */
+#line 3931 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_lit(ID2SYM((yyvsp[0].id)), &(yyloc));
@@ -9454,11 +9446,11 @@ yyreduce:
 			$$ = dispatch1(symbol_literal, $1);
 		    %*/
 		    }
-#line 9454 "parse.c" /* yacc.c:1646  */
+#line 9446 "parse.c" /* yacc.c:1646  */
     break;
 
   case 466:
-#line 3950 "parse.y" /* yacc.c:1646  */
+#line 3942 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *node = (yyvsp[0].node);
@@ -9473,22 +9465,22 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 9473 "parse.c" /* yacc.c:1646  */
+#line 9465 "parse.c" /* yacc.c:1646  */
     break;
 
   case 467:
-#line 3967 "parse.y" /* yacc.c:1646  */
+#line 3959 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 9484 "parse.c" /* yacc.c:1646  */
+#line 9476 "parse.c" /* yacc.c:1646  */
     break;
 
   case 469:
-#line 3975 "parse.y" /* yacc.c:1646  */
+#line 3967 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
@@ -9496,11 +9488,11 @@ yyreduce:
 			$$ = dispatch2(string_concat, $1, $2);
 		    %*/
 		    }
-#line 9496 "parse.c" /* yacc.c:1646  */
+#line 9488 "parse.c" /* yacc.c:1646  */
     break;
 
   case 470:
-#line 3985 "parse.y" /* yacc.c:1646  */
+#line 3977 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_string1(heredoc_dedent((yyvsp[-1].node)));
 		    /*%%%*/
@@ -9508,27 +9500,27 @@ yyreduce:
 		    /*%
 		    %*/
 		    }
-#line 9508 "parse.c" /* yacc.c:1646  */
+#line 9500 "parse.c" /* yacc.c:1646  */
     break;
 
   case 471:
-#line 3995 "parse.y" /* yacc.c:1646  */
+#line 3987 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_xstring(heredoc_dedent((yyvsp[-1].node)), &(yyloc));
 		    }
-#line 9516 "parse.c" /* yacc.c:1646  */
+#line 9508 "parse.c" /* yacc.c:1646  */
     break;
 
   case 472:
-#line 4001 "parse.y" /* yacc.c:1646  */
+#line 3993 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_regexp((yyvsp[-1].node), (yyvsp[0].num), &(yyloc));
 		    }
-#line 9524 "parse.c" /* yacc.c:1646  */
+#line 9516 "parse.c" /* yacc.c:1646  */
     break;
 
   case 473:
-#line 4007 "parse.y" /* yacc.c:1646  */
+#line 3999 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = make_array((yyvsp[-1].node), &(yyloc));
@@ -9536,11 +9528,11 @@ yyreduce:
 			$$ = dispatch1(array, $3);
 		    %*/
 		    }
-#line 9536 "parse.c" /* yacc.c:1646  */
+#line 9528 "parse.c" /* yacc.c:1646  */
     break;
 
   case 474:
-#line 4017 "parse.y" /* yacc.c:1646  */
+#line 4009 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9548,11 +9540,11 @@ yyreduce:
 			$$ = dispatch0(words_new);
 		    %*/
 		    }
-#line 9548 "parse.c" /* yacc.c:1646  */
+#line 9540 "parse.c" /* yacc.c:1646  */
     break;
 
   case 475:
-#line 4025 "parse.y" /* yacc.c:1646  */
+#line 4017 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
@@ -9560,11 +9552,11 @@ yyreduce:
 			$$ = dispatch2(words_add, $1, $2);
 		    %*/
 		    }
-#line 9560 "parse.c" /* yacc.c:1646  */
+#line 9552 "parse.c" /* yacc.c:1646  */
     break;
 
   case 477:
-#line 4043 "parse.y" /* yacc.c:1646  */
+#line 4035 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
@@ -9572,11 +9564,11 @@ yyreduce:
 			$$ = dispatch2(word_add, $1, $2);
 		    %*/
 		    }
-#line 9572 "parse.c" /* yacc.c:1646  */
+#line 9564 "parse.c" /* yacc.c:1646  */
     break;
 
   case 478:
-#line 4053 "parse.y" /* yacc.c:1646  */
+#line 4045 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = make_array((yyvsp[-1].node), &(yyloc));
@@ -9584,11 +9576,11 @@ yyreduce:
 			$$ = dispatch1(array, $3);
 		    %*/
 		    }
-#line 9584 "parse.c" /* yacc.c:1646  */
+#line 9576 "parse.c" /* yacc.c:1646  */
     break;
 
   case 479:
-#line 4063 "parse.y" /* yacc.c:1646  */
+#line 4055 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9596,11 +9588,11 @@ yyreduce:
 			$$ = dispatch0(symbols_new);
 		    %*/
 		    }
-#line 9596 "parse.c" /* yacc.c:1646  */
+#line 9588 "parse.c" /* yacc.c:1646  */
     break;
 
   case 480:
-#line 4071 "parse.y" /* yacc.c:1646  */
+#line 4063 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyvsp[-1].node) = evstr2dstr((yyvsp[-1].node));
@@ -9616,11 +9608,11 @@ yyreduce:
 			$$ = dispatch2(symbols_add, $1, $2);
 		    %*/
 		    }
-#line 9616 "parse.c" /* yacc.c:1646  */
+#line 9608 "parse.c" /* yacc.c:1646  */
     break;
 
   case 481:
-#line 4089 "parse.y" /* yacc.c:1646  */
+#line 4081 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = make_array((yyvsp[-1].node), &(yyloc));
@@ -9628,11 +9620,11 @@ yyreduce:
 			$$ = dispatch1(array, $3);
 		    %*/
 		    }
-#line 9628 "parse.c" /* yacc.c:1646  */
+#line 9620 "parse.c" /* yacc.c:1646  */
     break;
 
   case 482:
-#line 4099 "parse.y" /* yacc.c:1646  */
+#line 4091 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = make_array((yyvsp[-1].node), &(yyloc));
@@ -9640,11 +9632,11 @@ yyreduce:
 			$$ = dispatch1(array, $3);
 		    %*/
 		    }
-#line 9640 "parse.c" /* yacc.c:1646  */
+#line 9632 "parse.c" /* yacc.c:1646  */
     break;
 
   case 483:
-#line 4109 "parse.y" /* yacc.c:1646  */
+#line 4101 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9652,11 +9644,11 @@ yyreduce:
 			$$ = dispatch0(qwords_new);
 		    %*/
 		    }
-#line 9652 "parse.c" /* yacc.c:1646  */
+#line 9644 "parse.c" /* yacc.c:1646  */
     break;
 
   case 484:
-#line 4117 "parse.y" /* yacc.c:1646  */
+#line 4109 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyvsp[-1].node)->nd_loc = (yylsp[-1]);
@@ -9665,11 +9657,11 @@ yyreduce:
 			$$ = dispatch2(qwords_add, $1, $2);
 		    %*/
 		    }
-#line 9665 "parse.c" /* yacc.c:1646  */
+#line 9657 "parse.c" /* yacc.c:1646  */
     break;
 
   case 485:
-#line 4128 "parse.y" /* yacc.c:1646  */
+#line 4120 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9677,11 +9669,11 @@ yyreduce:
 			$$ = dispatch0(qsymbols_new);
 		    %*/
 		    }
-#line 9677 "parse.c" /* yacc.c:1646  */
+#line 9669 "parse.c" /* yacc.c:1646  */
     break;
 
   case 486:
-#line 4136 "parse.y" /* yacc.c:1646  */
+#line 4128 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			VALUE lit;
@@ -9694,11 +9686,11 @@ yyreduce:
 			$$ = dispatch2(qsymbols_add, $1, $2);
 		    %*/
 		    }
-#line 9694 "parse.c" /* yacc.c:1646  */
+#line 9686 "parse.c" /* yacc.c:1646  */
     break;
 
   case 487:
-#line 4151 "parse.y" /* yacc.c:1646  */
+#line 4143 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9706,11 +9698,11 @@ yyreduce:
 			$$ = dispatch0(string_content);
 		    %*/
 		    }
-#line 9706 "parse.c" /* yacc.c:1646  */
+#line 9698 "parse.c" /* yacc.c:1646  */
     break;
 
   case 488:
-#line 4159 "parse.y" /* yacc.c:1646  */
+#line 4151 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
@@ -9718,11 +9710,11 @@ yyreduce:
 			$$ = dispatch2(string_add, $1, $2);
 		    %*/
 		    }
-#line 9718 "parse.c" /* yacc.c:1646  */
+#line 9710 "parse.c" /* yacc.c:1646  */
     break;
 
   case 489:
-#line 4169 "parse.y" /* yacc.c:1646  */
+#line 4161 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9730,11 +9722,11 @@ yyreduce:
 			$$ = dispatch0(xstring_new);
 		    %*/
 		    }
-#line 9730 "parse.c" /* yacc.c:1646  */
+#line 9722 "parse.c" /* yacc.c:1646  */
     break;
 
   case 490:
-#line 4177 "parse.y" /* yacc.c:1646  */
+#line 4169 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
@@ -9742,11 +9734,11 @@ yyreduce:
 			$$ = dispatch2(xstring_add, $1, $2);
 		    %*/
 		    }
-#line 9742 "parse.c" /* yacc.c:1646  */
+#line 9734 "parse.c" /* yacc.c:1646  */
     break;
 
   case 491:
-#line 4187 "parse.y" /* yacc.c:1646  */
+#line 4179 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -9754,11 +9746,11 @@ yyreduce:
 			$$ = ripper_new_yylval(0, dispatch0(regexp_new), 0);
 		    %*/
 		    }
-#line 9754 "parse.c" /* yacc.c:1646  */
+#line 9746 "parse.c" /* yacc.c:1646  */
     break;
 
   case 492:
-#line 4195 "parse.y" /* yacc.c:1646  */
+#line 4187 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *head = (yyvsp[-1].node), *tail = (yyvsp[0].node);
@@ -9797,33 +9789,33 @@ yyreduce:
 			}
 		    %*/
 		    }
-#line 9797 "parse.c" /* yacc.c:1646  */
+#line 9789 "parse.c" /* yacc.c:1646  */
     break;
 
   case 493:
-#line 4236 "parse.y" /* yacc.c:1646  */
+#line 4228 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 9808 "parse.c" /* yacc.c:1646  */
+#line 9800 "parse.c" /* yacc.c:1646  */
     break;
 
   case 494:
-#line 4243 "parse.y" /* yacc.c:1646  */
+#line 4235 "parse.y" /* yacc.c:1646  */
     {
 			/* need to backup lex_strterm so that a string literal `%&foo,#$&,bar&` can be parsed */
 			(yyval.strterm) = lex_strterm;
 			lex_strterm = 0;
 			SET_LEX_STATE(EXPR_BEG);
 		    }
-#line 9819 "parse.c" /* yacc.c:1646  */
+#line 9811 "parse.c" /* yacc.c:1646  */
     break;
 
   case 495:
-#line 4250 "parse.y" /* yacc.c:1646  */
+#line 4242 "parse.y" /* yacc.c:1646  */
     {
 			lex_strterm = (yyvsp[-1].strterm);
 		    /*%%%*/
@@ -9833,59 +9825,59 @@ yyreduce:
 			$$ = dispatch1(string_dvar, $3);
 		    %*/
 		    }
-#line 9833 "parse.c" /* yacc.c:1646  */
+#line 9825 "parse.c" /* yacc.c:1646  */
     break;
 
   case 496:
-#line 4260 "parse.y" /* yacc.c:1646  */
+#line 4252 "parse.y" /* yacc.c:1646  */
     {
 			(yyvsp[0].val) = cond_stack;
 			(yyval.val) = cmdarg_stack;
 			COND_SET(0);
 			CMDARG_SET(0);
 		    }
-#line 9844 "parse.c" /* yacc.c:1646  */
+#line 9836 "parse.c" /* yacc.c:1646  */
     break;
 
   case 497:
-#line 4266 "parse.y" /* yacc.c:1646  */
+#line 4258 "parse.y" /* yacc.c:1646  */
     {
 			/* need to backup lex_strterm so that a string literal `%!foo,#{ !0 },bar!` can be parsed */
 			(yyval.strterm) = lex_strterm;
 			lex_strterm = 0;
 		    }
-#line 9854 "parse.c" /* yacc.c:1646  */
+#line 9846 "parse.c" /* yacc.c:1646  */
     break;
 
   case 498:
-#line 4271 "parse.y" /* yacc.c:1646  */
+#line 4263 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = lex_state;
 			SET_LEX_STATE(EXPR_BEG);
 		    }
-#line 9863 "parse.c" /* yacc.c:1646  */
+#line 9855 "parse.c" /* yacc.c:1646  */
     break;
 
   case 499:
-#line 4275 "parse.y" /* yacc.c:1646  */
+#line 4267 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = brace_nest;
 			brace_nest = 0;
 		    }
-#line 9872 "parse.c" /* yacc.c:1646  */
+#line 9864 "parse.c" /* yacc.c:1646  */
     break;
 
   case 500:
-#line 4279 "parse.y" /* yacc.c:1646  */
+#line 4271 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = heredoc_indent;
 			heredoc_indent = 0;
 		    }
-#line 9881 "parse.c" /* yacc.c:1646  */
+#line 9873 "parse.c" /* yacc.c:1646  */
     break;
 
   case 501:
-#line 4284 "parse.y" /* yacc.c:1646  */
+#line 4276 "parse.y" /* yacc.c:1646  */
     {
 			COND_SET((yyvsp[-7].val));
 			CMDARG_SET((yyvsp[-6].val));
@@ -9901,11 +9893,11 @@ yyreduce:
 			$$ = dispatch1(string_embexpr, $7);
 		    %*/
 		    }
-#line 9901 "parse.c" /* yacc.c:1646  */
+#line 9893 "parse.c" /* yacc.c:1646  */
     break;
 
   case 502:
-#line 4302 "parse.y" /* yacc.c:1646  */
+#line 4294 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_gvar((yyvsp[0].id), &(yyloc));
@@ -9913,11 +9905,11 @@ yyreduce:
 			$$ = dispatch1(var_ref, $1);
 		    %*/
 		    }
-#line 9913 "parse.c" /* yacc.c:1646  */
+#line 9905 "parse.c" /* yacc.c:1646  */
     break;
 
   case 503:
-#line 4310 "parse.y" /* yacc.c:1646  */
+#line 4302 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = new_ivar((yyvsp[0].id), &(yyloc));
@@ -9925,11 +9917,11 @@ yyreduce:
 			$$ = dispatch1(var_ref, $1);
 		    %*/
 		    }
-#line 9925 "parse.c" /* yacc.c:1646  */
+#line 9917 "parse.c" /* yacc.c:1646  */
     break;
 
   case 504:
-#line 4318 "parse.y" /* yacc.c:1646  */
+#line 4310 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = NEW_CVAR((yyvsp[0].id));
@@ -9938,11 +9930,11 @@ yyreduce:
 			$$ = dispatch1(var_ref, $1);
 		    %*/
 		    }
-#line 9938 "parse.c" /* yacc.c:1646  */
+#line 9930 "parse.c" /* yacc.c:1646  */
     break;
 
   case 506:
-#line 4330 "parse.y" /* yacc.c:1646  */
+#line 4322 "parse.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_END|EXPR_ENDARG);
 		    /*%%%*/
@@ -9951,11 +9943,11 @@ yyreduce:
 			$$ = dispatch1(symbol, $2);
 		    %*/
 		    }
-#line 9951 "parse.c" /* yacc.c:1646  */
+#line 9943 "parse.c" /* yacc.c:1646  */
     break;
 
   case 511:
-#line 4347 "parse.y" /* yacc.c:1646  */
+#line 4339 "parse.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_END|EXPR_ENDARG);
 		    /*%%%*/
@@ -9964,11 +9956,11 @@ yyreduce:
 			$$ = dispatch1(dyna_symbol, $2);
 		    %*/
 		    }
-#line 9964 "parse.c" /* yacc.c:1646  */
+#line 9956 "parse.c" /* yacc.c:1646  */
     break;
 
   case 513:
-#line 4359 "parse.y" /* yacc.c:1646  */
+#line 4351 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -9977,97 +9969,97 @@ yyreduce:
 			$$ = dispatch2(unary, ID2VAL(idUMinus), $2);
 		    %*/
 		    }
-#line 9977 "parse.c" /* yacc.c:1646  */
+#line 9969 "parse.c" /* yacc.c:1646  */
     break;
 
   case 514:
-#line 4370 "parse.y" /* yacc.c:1646  */
+#line 4362 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 9988 "parse.c" /* yacc.c:1646  */
+#line 9980 "parse.c" /* yacc.c:1646  */
     break;
 
   case 515:
-#line 4377 "parse.y" /* yacc.c:1646  */
+#line 4369 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 9999 "parse.c" /* yacc.c:1646  */
+#line 9991 "parse.c" /* yacc.c:1646  */
     break;
 
   case 516:
-#line 4384 "parse.y" /* yacc.c:1646  */
+#line 4376 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 10010 "parse.c" /* yacc.c:1646  */
+#line 10002 "parse.c" /* yacc.c:1646  */
     break;
 
   case 517:
-#line 4391 "parse.y" /* yacc.c:1646  */
+#line 4383 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 10021 "parse.c" /* yacc.c:1646  */
+#line 10013 "parse.c" /* yacc.c:1646  */
     break;
 
   case 523:
-#line 4406 "parse.y" /* yacc.c:1646  */
+#line 4398 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(nil, (yyvsp[0].id));}
-#line 10027 "parse.c" /* yacc.c:1646  */
+#line 10019 "parse.c" /* yacc.c:1646  */
     break;
 
   case 524:
-#line 4407 "parse.y" /* yacc.c:1646  */
+#line 4399 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(self, (yyvsp[0].id));}
-#line 10033 "parse.c" /* yacc.c:1646  */
+#line 10025 "parse.c" /* yacc.c:1646  */
     break;
 
   case 525:
-#line 4408 "parse.y" /* yacc.c:1646  */
+#line 4400 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(true, (yyvsp[0].id));}
-#line 10039 "parse.c" /* yacc.c:1646  */
+#line 10031 "parse.c" /* yacc.c:1646  */
     break;
 
   case 526:
-#line 4409 "parse.y" /* yacc.c:1646  */
+#line 4401 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(false, (yyvsp[0].id));}
-#line 10045 "parse.c" /* yacc.c:1646  */
+#line 10037 "parse.c" /* yacc.c:1646  */
     break;
 
   case 527:
-#line 4410 "parse.y" /* yacc.c:1646  */
+#line 4402 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(_FILE__, (yyvsp[0].id));}
-#line 10051 "parse.c" /* yacc.c:1646  */
+#line 10043 "parse.c" /* yacc.c:1646  */
     break;
 
   case 528:
-#line 4411 "parse.y" /* yacc.c:1646  */
+#line 4403 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(_LINE__, (yyvsp[0].id));}
-#line 10057 "parse.c" /* yacc.c:1646  */
+#line 10049 "parse.c" /* yacc.c:1646  */
     break;
 
   case 529:
-#line 4412 "parse.y" /* yacc.c:1646  */
+#line 4404 "parse.y" /* yacc.c:1646  */
     {(yyval.id) = KWD2EID(_ENCODING__, (yyvsp[0].id));}
-#line 10063 "parse.c" /* yacc.c:1646  */
+#line 10055 "parse.c" /* yacc.c:1646  */
     break;
 
   case 530:
-#line 4416 "parse.y" /* yacc.c:1646  */
+#line 4408 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (!((yyval.node) = gettable((yyvsp[0].id), &(yyloc)))) (yyval.node) = new_begin(0, &(yyloc));
@@ -10080,11 +10072,11 @@ yyreduce:
 			}
 		    %*/
 		    }
-#line 10080 "parse.c" /* yacc.c:1646  */
+#line 10072 "parse.c" /* yacc.c:1646  */
     break;
 
   case 531:
-#line 4429 "parse.y" /* yacc.c:1646  */
+#line 4421 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (!((yyval.node) = gettable((yyvsp[0].id), &(yyloc)))) (yyval.node) = new_begin(0, &(yyloc));
@@ -10092,66 +10084,66 @@ yyreduce:
 			$$ = dispatch1(var_ref, $1);
 		    %*/
 		    }
-#line 10092 "parse.c" /* yacc.c:1646  */
+#line 10084 "parse.c" /* yacc.c:1646  */
     break;
 
   case 532:
-#line 4439 "parse.y" /* yacc.c:1646  */
+#line 4431 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable(var_field((yyvsp[0].id)), 0, &(yyloc));
 		    }
-#line 10100 "parse.c" /* yacc.c:1646  */
+#line 10092 "parse.c" /* yacc.c:1646  */
     break;
 
   case 533:
-#line 4443 "parse.y" /* yacc.c:1646  */
+#line 4435 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable(var_field((yyvsp[0].id)), 0, &(yyloc));
 		    }
-#line 10108 "parse.c" /* yacc.c:1646  */
+#line 10100 "parse.c" /* yacc.c:1646  */
     break;
 
   case 534:
-#line 4449 "parse.y" /* yacc.c:1646  */
+#line 4441 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 10119 "parse.c" /* yacc.c:1646  */
+#line 10111 "parse.c" /* yacc.c:1646  */
     break;
 
   case 535:
-#line 4456 "parse.y" /* yacc.c:1646  */
+#line 4448 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node)->nd_loc = (yyloc);
 		    /*%
 		    %*/
 		    }
-#line 10130 "parse.c" /* yacc.c:1646  */
+#line 10122 "parse.c" /* yacc.c:1646  */
     break;
 
   case 536:
-#line 4465 "parse.y" /* yacc.c:1646  */
+#line 4457 "parse.y" /* yacc.c:1646  */
     {
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10139 "parse.c" /* yacc.c:1646  */
+#line 10131 "parse.c" /* yacc.c:1646  */
     break;
 
   case 537:
-#line 4470 "parse.y" /* yacc.c:1646  */
+#line 4462 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[-1].node);
 		    }
-#line 10147 "parse.c" /* yacc.c:1646  */
+#line 10139 "parse.c" /* yacc.c:1646  */
     break;
 
   case 538:
-#line 4474 "parse.y" /* yacc.c:1646  */
+#line 4466 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = 0;
@@ -10159,11 +10151,11 @@ yyreduce:
 			$$ = Qnil;
 		    %*/
 		    }
-#line 10159 "parse.c" /* yacc.c:1646  */
+#line 10151 "parse.c" /* yacc.c:1646  */
     break;
 
   case 539:
-#line 4484 "parse.y" /* yacc.c:1646  */
+#line 4476 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -10173,201 +10165,201 @@ yyreduce:
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10173 "parse.c" /* yacc.c:1646  */
+#line 10165 "parse.c" /* yacc.c:1646  */
     break;
 
   case 540:
-#line 4493 "parse.y" /* yacc.c:1646  */
+#line 4485 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.num) = parser->in_kwarg;
 			parser->in_kwarg = 1;
 			SET_LEX_STATE(lex_state|EXPR_LABEL); /* force for args */
 		    }
-#line 10183 "parse.c" /* yacc.c:1646  */
+#line 10175 "parse.c" /* yacc.c:1646  */
     break;
 
   case 541:
-#line 4499 "parse.y" /* yacc.c:1646  */
+#line 4491 "parse.y" /* yacc.c:1646  */
     {
 			parser->in_kwarg = !!(yyvsp[-2].num);
 			(yyval.node) = (yyvsp[-1].node);
 			SET_LEX_STATE(EXPR_BEG);
 			command_start = TRUE;
 		    }
-#line 10194 "parse.c" /* yacc.c:1646  */
+#line 10186 "parse.c" /* yacc.c:1646  */
     break;
 
   case 542:
-#line 4508 "parse.y" /* yacc.c:1646  */
+#line 4500 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 10202 "parse.c" /* yacc.c:1646  */
+#line 10194 "parse.c" /* yacc.c:1646  */
     break;
 
   case 543:
-#line 4512 "parse.y" /* yacc.c:1646  */
+#line 4504 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail((yyvsp[-1].node), Qnone, (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 10210 "parse.c" /* yacc.c:1646  */
+#line 10202 "parse.c" /* yacc.c:1646  */
     break;
 
   case 544:
-#line 4516 "parse.y" /* yacc.c:1646  */
+#line 4508 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, (yyvsp[-1].id), (yyvsp[0].id), &(yylsp[-1]));
 		    }
-#line 10218 "parse.c" /* yacc.c:1646  */
+#line 10210 "parse.c" /* yacc.c:1646  */
     break;
 
   case 545:
-#line 4520 "parse.y" /* yacc.c:1646  */
+#line 4512 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, Qnone, (yyvsp[0].id), &(yylsp[0]));
 		    }
-#line 10226 "parse.c" /* yacc.c:1646  */
+#line 10218 "parse.c" /* yacc.c:1646  */
     break;
 
   case 546:
-#line 4526 "parse.y" /* yacc.c:1646  */
+#line 4518 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = (yyvsp[0].node);
 		    }
-#line 10234 "parse.c" /* yacc.c:1646  */
+#line 10226 "parse.c" /* yacc.c:1646  */
     break;
 
   case 547:
-#line 4530 "parse.y" /* yacc.c:1646  */
+#line 4522 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 		    }
-#line 10242 "parse.c" /* yacc.c:1646  */
+#line 10234 "parse.c" /* yacc.c:1646  */
     break;
 
   case 548:
-#line 4536 "parse.y" /* yacc.c:1646  */
+#line 4528 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10250 "parse.c" /* yacc.c:1646  */
+#line 10242 "parse.c" /* yacc.c:1646  */
     break;
 
   case 549:
-#line 4540 "parse.y" /* yacc.c:1646  */
+#line 4532 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10258 "parse.c" /* yacc.c:1646  */
+#line 10250 "parse.c" /* yacc.c:1646  */
     break;
 
   case 550:
-#line 4544 "parse.y" /* yacc.c:1646  */
+#line 4536 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-3].node), (yyvsp[-1].node), Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10266 "parse.c" /* yacc.c:1646  */
+#line 10258 "parse.c" /* yacc.c:1646  */
     break;
 
   case 551:
-#line 4548 "parse.y" /* yacc.c:1646  */
+#line 4540 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), (yyvsp[-3].node), Qnone, (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10274 "parse.c" /* yacc.c:1646  */
+#line 10266 "parse.c" /* yacc.c:1646  */
     break;
 
   case 552:
-#line 4552 "parse.y" /* yacc.c:1646  */
+#line 4544 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-3].node), Qnone, (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10282 "parse.c" /* yacc.c:1646  */
+#line 10274 "parse.c" /* yacc.c:1646  */
     break;
 
   case 553:
-#line 4556 "parse.y" /* yacc.c:1646  */
+#line 4548 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-5].node), Qnone, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10290 "parse.c" /* yacc.c:1646  */
+#line 10282 "parse.c" /* yacc.c:1646  */
     break;
 
   case 554:
-#line 4560 "parse.y" /* yacc.c:1646  */
+#line 4552 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args((yyvsp[-1].node), Qnone, Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10298 "parse.c" /* yacc.c:1646  */
+#line 10290 "parse.c" /* yacc.c:1646  */
     break;
 
   case 555:
-#line 4564 "parse.y" /* yacc.c:1646  */
+#line 4556 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-3].node), (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10306 "parse.c" /* yacc.c:1646  */
+#line 10298 "parse.c" /* yacc.c:1646  */
     break;
 
   case 556:
-#line 4568 "parse.y" /* yacc.c:1646  */
+#line 4560 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10314 "parse.c" /* yacc.c:1646  */
+#line 10306 "parse.c" /* yacc.c:1646  */
     break;
 
   case 557:
-#line 4572 "parse.y" /* yacc.c:1646  */
+#line 4564 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-1].node), Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10322 "parse.c" /* yacc.c:1646  */
+#line 10314 "parse.c" /* yacc.c:1646  */
     break;
 
   case 558:
-#line 4576 "parse.y" /* yacc.c:1646  */
+#line 4568 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, (yyvsp[-3].node), Qnone, (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10330 "parse.c" /* yacc.c:1646  */
+#line 10322 "parse.c" /* yacc.c:1646  */
     break;
 
   case 559:
-#line 4580 "parse.y" /* yacc.c:1646  */
+#line 4572 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, (yyvsp[-1].id), Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10338 "parse.c" /* yacc.c:1646  */
+#line 10330 "parse.c" /* yacc.c:1646  */
     break;
 
   case 560:
-#line 4584 "parse.y" /* yacc.c:1646  */
+#line 4576 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].node), &(yyloc));
 		    }
-#line 10346 "parse.c" /* yacc.c:1646  */
+#line 10338 "parse.c" /* yacc.c:1646  */
     break;
 
   case 561:
-#line 4588 "parse.y" /* yacc.c:1646  */
+#line 4580 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args(Qnone, Qnone, Qnone, Qnone, (yyvsp[0].node), &(yyloc));
 		    }
-#line 10354 "parse.c" /* yacc.c:1646  */
+#line 10346 "parse.c" /* yacc.c:1646  */
     break;
 
   case 562:
-#line 4592 "parse.y" /* yacc.c:1646  */
+#line 4584 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = new_args_tail(Qnone, Qnone, Qnone, &(yylsp[0]));
 			(yyval.node) = new_args(Qnone, Qnone, Qnone, Qnone, (yyval.node), &(yylsp[0]));
 		    }
-#line 10363 "parse.c" /* yacc.c:1646  */
+#line 10355 "parse.c" /* yacc.c:1646  */
     break;
 
   case 563:
-#line 4599 "parse.y" /* yacc.c:1646  */
+#line 4591 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			yyerror0("formal argument cannot be a constant");
@@ -10377,11 +10369,11 @@ yyreduce:
 			ripper_error();
 		    %*/
 		    }
-#line 10377 "parse.c" /* yacc.c:1646  */
+#line 10369 "parse.c" /* yacc.c:1646  */
     break;
 
   case 564:
-#line 4609 "parse.y" /* yacc.c:1646  */
+#line 4601 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			yyerror0("formal argument cannot be an instance variable");
@@ -10391,11 +10383,11 @@ yyreduce:
 			ripper_error();
 		    %*/
 		    }
-#line 10391 "parse.c" /* yacc.c:1646  */
+#line 10383 "parse.c" /* yacc.c:1646  */
     break;
 
   case 565:
-#line 4619 "parse.y" /* yacc.c:1646  */
+#line 4611 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			yyerror0("formal argument cannot be a global variable");
@@ -10405,11 +10397,11 @@ yyreduce:
 			ripper_error();
 		    %*/
 		    }
-#line 10405 "parse.c" /* yacc.c:1646  */
+#line 10397 "parse.c" /* yacc.c:1646  */
     break;
 
   case 566:
-#line 4629 "parse.y" /* yacc.c:1646  */
+#line 4621 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			yyerror0("formal argument cannot be a class variable");
@@ -10419,31 +10411,31 @@ yyreduce:
 			ripper_error();
 		    %*/
 		    }
-#line 10419 "parse.c" /* yacc.c:1646  */
+#line 10411 "parse.c" /* yacc.c:1646  */
     break;
 
   case 568:
-#line 4642 "parse.y" /* yacc.c:1646  */
+#line 4634 "parse.y" /* yacc.c:1646  */
     {
 			formal_argument(get_id((yyvsp[0].id)));
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 10428 "parse.c" /* yacc.c:1646  */
+#line 10420 "parse.c" /* yacc.c:1646  */
     break;
 
   case 569:
-#line 4649 "parse.y" /* yacc.c:1646  */
+#line 4641 "parse.y" /* yacc.c:1646  */
     {
 			ID id = get_id((yyvsp[0].id));
 			arg_var(id);
 			current_arg = id;
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 10439 "parse.c" /* yacc.c:1646  */
+#line 10431 "parse.c" /* yacc.c:1646  */
     break;
 
   case 570:
-#line 4658 "parse.y" /* yacc.c:1646  */
+#line 4650 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 		    /*%%%*/
@@ -10452,11 +10444,11 @@ yyreduce:
 			$$ = get_value($1);
 		    %*/
 		    }
-#line 10452 "parse.c" /* yacc.c:1646  */
+#line 10444 "parse.c" /* yacc.c:1646  */
     break;
 
   case 571:
-#line 4667 "parse.y" /* yacc.c:1646  */
+#line 4659 "parse.y" /* yacc.c:1646  */
     {
 			ID tid = internal_id();
 		    /*%%%*/
@@ -10479,11 +10471,11 @@ yyreduce:
 			$$ = dispatch1(mlhs_paren, $2);
 		    %*/
 		    }
-#line 10479 "parse.c" /* yacc.c:1646  */
+#line 10471 "parse.c" /* yacc.c:1646  */
     break;
 
   case 573:
-#line 4699 "parse.y" /* yacc.c:1646  */
+#line 4691 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-2].node);
@@ -10494,22 +10486,22 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10494 "parse.c" /* yacc.c:1646  */
+#line 10486 "parse.c" /* yacc.c:1646  */
     break;
 
   case 574:
-#line 4713 "parse.y" /* yacc.c:1646  */
+#line 4705 "parse.y" /* yacc.c:1646  */
     {
 			ID id = get_id((yyvsp[0].id));
 			arg_var(formal_argument(id));
 			current_arg = id;
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 10505 "parse.c" /* yacc.c:1646  */
+#line 10497 "parse.c" /* yacc.c:1646  */
     break;
 
   case 575:
-#line 4722 "parse.y" /* yacc.c:1646  */
+#line 4714 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
@@ -10519,11 +10511,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), get_value($2));
 		    %*/
 		    }
-#line 10519 "parse.c" /* yacc.c:1646  */
+#line 10511 "parse.c" /* yacc.c:1646  */
     break;
 
   case 576:
-#line 4732 "parse.y" /* yacc.c:1646  */
+#line 4724 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.node) = assignable((yyvsp[0].id), NODE_SPECIAL_REQUIRED_KEYWORD, &(yyloc));
@@ -10533,11 +10525,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), 0);
 		    %*/
 		    }
-#line 10533 "parse.c" /* yacc.c:1646  */
+#line 10525 "parse.c" /* yacc.c:1646  */
     break;
 
   case 577:
-#line 4744 "parse.y" /* yacc.c:1646  */
+#line 4736 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[-1].id), (yyvsp[0].node), &(yyloc));
 		    /*%%%*/
@@ -10546,11 +10538,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), get_value($2));
 		    %*/
 		    }
-#line 10546 "parse.c" /* yacc.c:1646  */
+#line 10538 "parse.c" /* yacc.c:1646  */
     break;
 
   case 578:
-#line 4753 "parse.y" /* yacc.c:1646  */
+#line 4745 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = assignable((yyvsp[0].id), NODE_SPECIAL_REQUIRED_KEYWORD, &(yyloc));
 		    /*%%%*/
@@ -10559,11 +10551,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), 0);
 		    %*/
 		    }
-#line 10559 "parse.c" /* yacc.c:1646  */
+#line 10551 "parse.c" /* yacc.c:1646  */
     break;
 
   case 579:
-#line 4764 "parse.y" /* yacc.c:1646  */
+#line 4756 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -10571,11 +10563,11 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 10571 "parse.c" /* yacc.c:1646  */
+#line 10563 "parse.c" /* yacc.c:1646  */
     break;
 
   case 580:
-#line 4772 "parse.y" /* yacc.c:1646  */
+#line 4764 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = kwd_append((yyvsp[-2].node), (yyvsp[0].node));
@@ -10583,11 +10575,11 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10583 "parse.c" /* yacc.c:1646  */
+#line 10575 "parse.c" /* yacc.c:1646  */
     break;
 
   case 581:
-#line 4783 "parse.y" /* yacc.c:1646  */
+#line 4775 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -10595,11 +10587,11 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 10595 "parse.c" /* yacc.c:1646  */
+#line 10587 "parse.c" /* yacc.c:1646  */
     break;
 
   case 582:
-#line 4791 "parse.y" /* yacc.c:1646  */
+#line 4783 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = kwd_append((yyvsp[-2].node), (yyvsp[0].node));
@@ -10607,11 +10599,11 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10607 "parse.c" /* yacc.c:1646  */
+#line 10599 "parse.c" /* yacc.c:1646  */
     break;
 
   case 585:
-#line 4805 "parse.y" /* yacc.c:1646  */
+#line 4797 "parse.y" /* yacc.c:1646  */
     {
 			shadowing_lvar(get_id((yyvsp[0].id)));
 		    /*%%%*/
@@ -10620,11 +10612,11 @@ yyreduce:
 			$$ = dispatch1(kwrest_param, $2);
 		    %*/
 		    }
-#line 10620 "parse.c" /* yacc.c:1646  */
+#line 10612 "parse.c" /* yacc.c:1646  */
     break;
 
   case 586:
-#line 4814 "parse.y" /* yacc.c:1646  */
+#line 4806 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.id) = internal_id();
@@ -10633,11 +10625,11 @@ yyreduce:
 			$$ = dispatch1(kwrest_param, Qnil);
 		    %*/
 		    }
-#line 10633 "parse.c" /* yacc.c:1646  */
+#line 10625 "parse.c" /* yacc.c:1646  */
     break;
 
   case 587:
-#line 4825 "parse.y" /* yacc.c:1646  */
+#line 4817 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node), &(yyloc));
@@ -10648,11 +10640,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), get_value($3));
 		    %*/
 		    }
-#line 10648 "parse.c" /* yacc.c:1646  */
+#line 10640 "parse.c" /* yacc.c:1646  */
     break;
 
   case 588:
-#line 4838 "parse.y" /* yacc.c:1646  */
+#line 4830 "parse.y" /* yacc.c:1646  */
     {
 			current_arg = 0;
 			(yyval.node) = assignable((yyvsp[-2].id), (yyvsp[0].node), &(yyloc));
@@ -10663,11 +10655,11 @@ yyreduce:
 			$$ = rb_assoc_new(get_value($$), get_value($3));
 		    %*/
 		    }
-#line 10663 "parse.c" /* yacc.c:1646  */
+#line 10655 "parse.c" /* yacc.c:1646  */
     break;
 
   case 589:
-#line 4851 "parse.y" /* yacc.c:1646  */
+#line 4843 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -10675,11 +10667,11 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 10675 "parse.c" /* yacc.c:1646  */
+#line 10667 "parse.c" /* yacc.c:1646  */
     break;
 
   case 590:
-#line 4859 "parse.y" /* yacc.c:1646  */
+#line 4851 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = opt_arg_append((yyvsp[-2].node), (yyvsp[0].node));
@@ -10687,11 +10679,11 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10687 "parse.c" /* yacc.c:1646  */
+#line 10679 "parse.c" /* yacc.c:1646  */
     break;
 
   case 591:
-#line 4869 "parse.y" /* yacc.c:1646  */
+#line 4861 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[0].node);
@@ -10699,11 +10691,11 @@ yyreduce:
 			$$ = rb_ary_new3(1, get_value($1));
 		    %*/
 		    }
-#line 10699 "parse.c" /* yacc.c:1646  */
+#line 10691 "parse.c" /* yacc.c:1646  */
     break;
 
   case 592:
-#line 4877 "parse.y" /* yacc.c:1646  */
+#line 4869 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = opt_arg_append((yyvsp[-2].node), (yyvsp[0].node));
@@ -10711,11 +10703,11 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10711 "parse.c" /* yacc.c:1646  */
+#line 10703 "parse.c" /* yacc.c:1646  */
     break;
 
   case 595:
-#line 4891 "parse.y" /* yacc.c:1646  */
+#line 4883 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (!is_local_id((yyvsp[0].id)))
@@ -10728,11 +10720,11 @@ yyreduce:
 			$$ = dispatch1(rest_param, $2);
 		    %*/
 		    }
-#line 10728 "parse.c" /* yacc.c:1646  */
+#line 10720 "parse.c" /* yacc.c:1646  */
     break;
 
   case 596:
-#line 4904 "parse.y" /* yacc.c:1646  */
+#line 4896 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.id) = internal_id();
@@ -10741,11 +10733,11 @@ yyreduce:
 			$$ = dispatch1(rest_param, Qnil);
 		    %*/
 		    }
-#line 10741 "parse.c" /* yacc.c:1646  */
+#line 10733 "parse.c" /* yacc.c:1646  */
     break;
 
   case 599:
-#line 4919 "parse.y" /* yacc.c:1646  */
+#line 4911 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (!is_local_id((yyvsp[0].id)))
@@ -10760,19 +10752,19 @@ yyreduce:
 			$$ = dispatch1(blockarg, $2);
 		    %*/
 		    }
-#line 10760 "parse.c" /* yacc.c:1646  */
+#line 10752 "parse.c" /* yacc.c:1646  */
     break;
 
   case 600:
-#line 4936 "parse.y" /* yacc.c:1646  */
+#line 4928 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.id) = (yyvsp[0].id);
 		    }
-#line 10768 "parse.c" /* yacc.c:1646  */
+#line 10760 "parse.c" /* yacc.c:1646  */
     break;
 
   case 601:
-#line 4940 "parse.y" /* yacc.c:1646  */
+#line 4932 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.id) = 0;
@@ -10780,11 +10772,11 @@ yyreduce:
 			$$ = Qundef;
 		    %*/
 		    }
-#line 10780 "parse.c" /* yacc.c:1646  */
+#line 10772 "parse.c" /* yacc.c:1646  */
     break;
 
   case 602:
-#line 4950 "parse.y" /* yacc.c:1646  */
+#line 4942 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			value_expr((yyvsp[0].node));
@@ -10794,17 +10786,17 @@ yyreduce:
 			$$ = $1;
 		    %*/
 		    }
-#line 10794 "parse.c" /* yacc.c:1646  */
+#line 10786 "parse.c" /* yacc.c:1646  */
     break;
 
   case 603:
-#line 4959 "parse.y" /* yacc.c:1646  */
+#line 4951 "parse.y" /* yacc.c:1646  */
     {SET_LEX_STATE(EXPR_BEG);}
-#line 10800 "parse.c" /* yacc.c:1646  */
+#line 10792 "parse.c" /* yacc.c:1646  */
     break;
 
   case 604:
-#line 4960 "parse.y" /* yacc.c:1646  */
+#line 4952 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if ((yyvsp[-1].node) == 0) {
@@ -10832,11 +10824,11 @@ yyreduce:
 			$$ = dispatch1(paren, $3);
 		    %*/
 		    }
-#line 10832 "parse.c" /* yacc.c:1646  */
+#line 10824 "parse.c" /* yacc.c:1646  */
     break;
 
   case 606:
-#line 4991 "parse.y" /* yacc.c:1646  */
+#line 4983 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = (yyvsp[-1].node);
@@ -10844,11 +10836,11 @@ yyreduce:
 			$$ = dispatch1(assoclist_from_args, $1);
 		    %*/
 		    }
-#line 10844 "parse.c" /* yacc.c:1646  */
+#line 10836 "parse.c" /* yacc.c:1646  */
     break;
 
   case 608:
-#line 5008 "parse.y" /* yacc.c:1646  */
+#line 5000 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			NODE *assocs = (yyvsp[-2].node);
@@ -10870,11 +10862,11 @@ yyreduce:
 			$$ = rb_ary_push($1, get_value($3));
 		    %*/
 		    }
-#line 10870 "parse.c" /* yacc.c:1646  */
+#line 10862 "parse.c" /* yacc.c:1646  */
     break;
 
   case 609:
-#line 5032 "parse.y" /* yacc.c:1646  */
+#line 5024 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (nd_type((yyvsp[-2].node)) == NODE_STR) {
@@ -10886,11 +10878,11 @@ yyreduce:
 			$$ = dispatch2(assoc_new, $1, $3);
 		    %*/
 		    }
-#line 10886 "parse.c" /* yacc.c:1646  */
+#line 10878 "parse.c" /* yacc.c:1646  */
     break;
 
   case 610:
-#line 5044 "parse.y" /* yacc.c:1646  */
+#line 5036 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			(yyval.node) = list_append(new_list(new_lit(ID2SYM((yyvsp[-1].id)), &(yylsp[-1])), &(yyloc)), (yyvsp[0].node));
@@ -10898,11 +10890,11 @@ yyreduce:
 			$$ = dispatch2(assoc_new, $1, $2);
 		    %*/
 		    }
-#line 10898 "parse.c" /* yacc.c:1646  */
+#line 10890 "parse.c" /* yacc.c:1646  */
     break;
 
   case 611:
-#line 5052 "parse.y" /* yacc.c:1646  */
+#line 5044 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			YYLTYPE location;
@@ -10913,11 +10905,11 @@ yyreduce:
 			$$ = dispatch2(assoc_new, dispatch1(dyna_symbol, $2), $4);
 		    %*/
 		    }
-#line 10913 "parse.c" /* yacc.c:1646  */
+#line 10905 "parse.c" /* yacc.c:1646  */
     break;
 
   case 612:
-#line 5063 "parse.y" /* yacc.c:1646  */
+#line 5055 "parse.y" /* yacc.c:1646  */
     {
 		    /*%%%*/
 			if (nd_type((yyvsp[0].node)) == NODE_HASH &&
@@ -10929,61 +10921,61 @@ yyreduce:
 			$$ = dispatch1(assoc_splat, $2);
 		    %*/
 		    }
-#line 10929 "parse.c" /* yacc.c:1646  */
+#line 10921 "parse.c" /* yacc.c:1646  */
     break;
 
   case 625:
-#line 5097 "parse.y" /* yacc.c:1646  */
+#line 5089 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.id) = TOKEN2VAL('.');
 		    }
-#line 10937 "parse.c" /* yacc.c:1646  */
+#line 10929 "parse.c" /* yacc.c:1646  */
     break;
 
   case 626:
-#line 5101 "parse.y" /* yacc.c:1646  */
+#line 5093 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.id) = ID2VAL(idANDDOT);
 		    }
-#line 10945 "parse.c" /* yacc.c:1646  */
+#line 10937 "parse.c" /* yacc.c:1646  */
     break;
 
   case 628:
-#line 5108 "parse.y" /* yacc.c:1646  */
+#line 5100 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.id) = ID2VAL(idCOLON2);
 		    }
-#line 10953 "parse.c" /* yacc.c:1646  */
+#line 10945 "parse.c" /* yacc.c:1646  */
     break;
 
   case 638:
-#line 5132 "parse.y" /* yacc.c:1646  */
+#line 5124 "parse.y" /* yacc.c:1646  */
     {yyerrok;token_flush(parser);}
-#line 10959 "parse.c" /* yacc.c:1646  */
+#line 10951 "parse.c" /* yacc.c:1646  */
     break;
 
   case 639:
-#line 5133 "parse.y" /* yacc.c:1646  */
+#line 5125 "parse.y" /* yacc.c:1646  */
     {token_flush(parser);}
-#line 10965 "parse.c" /* yacc.c:1646  */
+#line 10957 "parse.c" /* yacc.c:1646  */
     break;
 
   case 641:
-#line 5137 "parse.y" /* yacc.c:1646  */
+#line 5129 "parse.y" /* yacc.c:1646  */
     {yyerrok;}
-#line 10971 "parse.c" /* yacc.c:1646  */
+#line 10963 "parse.c" /* yacc.c:1646  */
     break;
 
   case 642:
-#line 5141 "parse.y" /* yacc.c:1646  */
+#line 5133 "parse.y" /* yacc.c:1646  */
     {
 			(yyval.node) = Qnull;
 		    }
-#line 10979 "parse.c" /* yacc.c:1646  */
+#line 10971 "parse.c" /* yacc.c:1646  */
     break;
 
 
-#line 10983 "parse.c" /* yacc.c:1646  */
+#line 10975 "parse.c" /* yacc.c:1646  */
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -11218,7 +11210,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 5145 "parse.y" /* yacc.c:1906  */
+#line 5137 "parse.y" /* yacc.c:1906  */
 
 # undef parser
 # undef yylex
@@ -16034,11 +16026,13 @@ assignable_gen(struct parser_params *parser, ID id, NO
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
@@ -16101,7 +16095,7 @@ assignable_gen(struct parser_params *parser, ID id, NO
 	compile_error(PARSER_ARG "identifier %"PRIsVALUE" is not valid to set", rb_id2str(id));
     }
   error:
-    return assignable_result(0);
+    return assignable_error();
 #undef assignable_result
 #undef parser_yyerror
 }
