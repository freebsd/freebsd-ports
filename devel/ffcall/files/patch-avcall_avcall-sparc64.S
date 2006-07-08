--- avcall/avcall-sparc64.S.orig	Fri Nov 26 15:28:33 1999
+++ avcall/avcall-sparc64.S	Thu Jul  6 21:53:11 2006
@@ -24,98 +24,98 @@
 	cmp	%g3, 0
 	be,pn	%icc, .LL161
 	and	%o7, 2, %g3
-	ld 72(%i0),%f1
+	ld [72+%i0],%f1
 	and	%o7, 2, %g3
 .LL161:
 	cmp	%g3, 0
 	be,pn	%icc, .LL162
 	and	%o7, 4, %g3
-	ld 80(%i0),%f3
+	ld [80+%i0],%f3
 	and	%o7, 4, %g3
 .LL162:
 	cmp	%g3, 0
 	be,pn	%icc, .LL163
 	and	%o7, 8, %g3
-	ld 88(%i0),%f5
+	ld [88+%i0],%f5
 	and	%o7, 8, %g3
 .LL163:
 	cmp	%g3, 0
 	be,pn	%icc, .LL164
 	and	%o7, 16, %g3
-	ld 96(%i0),%f7
+	ld [96+%i0],%f7
 	and	%o7, 16, %g3
 .LL164:
 	cmp	%g3, 0
 	be,pn	%icc, .LL165
 	and	%o7, 32, %g3
-	ld 104(%i0),%f9
+	ld [104+%i0],%f9
 	and	%o7, 32, %g3
 .LL165:
 	cmp	%g3, 0
 	be,pn	%icc, .LL166
 	and	%o7, 64, %g3
-	ld 112(%i0),%f11
+	ld [112+%i0],%f11
 	and	%o7, 64, %g3
 .LL166:
 	cmp	%g3, 0
 	be,pn	%icc, .LL167
 	and	%o7, 128, %g3
-	ld 120(%i0),%f13
+	ld [120+%i0],%f13
 	and	%o7, 128, %g3
 .LL167:
 	cmp	%g3, 0
 	be,pn	%icc, .LL168
 	and	%o7, 256, %g3
-	ld 128(%i0),%f15
+	ld [128+%i0],%f15
 	and	%o7, 256, %g3
 .LL168:
 	cmp	%g3, 0
 	be,pn	%icc, .LL169
 	and	%o7, 512, %g3
-	ld 136(%i0),%f17
+	ld [136+%i0],%f17
 	and	%o7, 512, %g3
 .LL169:
 	cmp	%g3, 0
 	be,a,pn	%icc, .LL170
 	ld	[%i0+60], %o7
-	ld 144(%i0),%f19
+	ld 	[144+%i0],%f19
 	ld	[%i0+60], %o7
 .LL170:
 	and	%o7, 1024, %g3
 	cmp	%g3, 0
 	be,pn	%icc, .LL171
 	and	%o7, 2048, %g3
-	ld 152(%i0),%f21
+	ld [152+%i0],%f21
 	and	%o7, 2048, %g3
 .LL171:
 	cmp	%g3, 0
 	be,pn	%icc, .LL172
 	sethi	%hi(4096), %g3
-	ld 160(%i0),%f23
+	ld [160+%i0],%f23
 	sethi	%hi(4096), %g3
 .LL172:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL173
 	sethi	%hi(8192), %g3
-	ld 168(%i0),%f25
+	ld [168+%i0],%f25
 	sethi	%hi(8192), %g3
 .LL173:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL174
 	sethi	%hi(16384), %g3
-	ld 176(%i0),%f27
+	ld [176+%i0],%f27
 	sethi	%hi(16384), %g3
 .LL174:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL175
 	sethi	%hi(32768), %g3
-	ld 184(%i0),%f29
+	ld [184+%i0],%f29
 	sethi	%hi(32768), %g3
 .LL175:
 	andcc	%o7, %g3, %g0
 	be,a,pn	%icc, .LL176
 	ld	[%i0+64], %g3
-	ld 192(%i0),%f31
+	ld [192+%i0],%f31
 .LL3:
 	ld	[%i0+64], %g3
 .LL176:
@@ -126,97 +126,97 @@
 	cmp	%g3, 0
 	be,pn	%icc, .LL177
 	and	%o7, 2, %g3
-	ldd 72(%i0),%f0
+	ldd [72+%i0],%f0
 	and	%o7, 2, %g3
 .LL177:
 	cmp	%g3, 0
 	be,pn	%icc, .LL178
 	and	%o7, 4, %g3
-	ldd 80(%i0),%f2
+	ldd [80+%i0],%f2
 	and	%o7, 4, %g3
 .LL178:
 	cmp	%g3, 0
 	be,pn	%icc, .LL179
 	and	%o7, 8, %g3
-	ldd 88(%i0),%f4
+	ldd [88+%i0],%f4
 	and	%o7, 8, %g3
 .LL179:
 	cmp	%g3, 0
 	be,pn	%icc, .LL180
 	and	%o7, 16, %g3
-	ldd 96(%i0),%f6
+	ldd [96+%i0],%f6
 	and	%o7, 16, %g3
 .LL180:
 	cmp	%g3, 0
 	be,pn	%icc, .LL181
 	and	%o7, 32, %g3
-	ldd 104(%i0),%f8
+	ldd [104+%i0],%f8
 	and	%o7, 32, %g3
 .LL181:
 	cmp	%g3, 0
 	be,pn	%icc, .LL182
 	and	%o7, 64, %g3
-	ldd 112(%i0),%f10
+	ldd [112+%i0],%f10
 	and	%o7, 64, %g3
 .LL182:
 	cmp	%g3, 0
 	be,pn	%icc, .LL183
 	and	%o7, 128, %g3
-	ldd 120(%i0),%f12
+	ldd [120+%i0],%f12
 	and	%o7, 128, %g3
 .LL183:
 	cmp	%g3, 0
 	be,pn	%icc, .LL184
 	and	%o7, 256, %g3
-	ldd 128(%i0),%f14
+	ldd [128+%i0],%f14
 	and	%o7, 256, %g3
 .LL184:
 	cmp	%g3, 0
 	be,pn	%icc, .LL185
 	and	%o7, 512, %g3
-	ldd 136(%i0),%f16
+	ldd [136+%i0],%f16
 	and	%o7, 512, %g3
 .LL185:
 	cmp	%g3, 0
 	be,pn	%icc, .LL186
 	and	%o7, 1024, %g3
-	ldd 144(%i0),%f18
+	ldd [144+%i0],%f18
 	and	%o7, 1024, %g3
 .LL186:
 	cmp	%g3, 0
 	be,pn	%icc, .LL187
 	and	%o7, 2048, %g3
-	ldd 152(%i0),%f20
+	ldd [152+%i0],%f20
 	and	%o7, 2048, %g3
 .LL187:
 	cmp	%g3, 0
 	be,pn	%icc, .LL188
 	sethi	%hi(4096), %g3
-	ldd 160(%i0),%f22
+	ldd [160+%i0],%f22
 	sethi	%hi(4096), %g3
 .LL188:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL189
 	sethi	%hi(8192), %g3
-	ldd 168(%i0),%f24
+	ldd [168+%i0],%f24
 	sethi	%hi(8192), %g3
 .LL189:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL190
 	sethi	%hi(16384), %g3
-	ldd 176(%i0),%f26
+	ldd [176+%i0],%f26
 	sethi	%hi(16384), %g3
 .LL190:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL191
 	sethi	%hi(32768), %g3
-	ldd 184(%i0),%f28
+	ldd [184+%i0],%f28
 	sethi	%hi(32768), %g3
 .LL191:
 	andcc	%o7, %g3, %g0
 	be,pn	%icc, .LL192
 	mov	6, %l1
-	ldd 192(%i0),%f30
+	ldd [192+%i0],%f30
 .LL20:
 	mov	6, %l1
 .LL192:
