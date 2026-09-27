PORTNAME=	pdfium
DISTVERSION=	8066
PDFIUM_COMMIT=	fc46361ce75055cd549cb938fae5d6a3fe3a1a05
CATEGORIES=	graphics
# Additional DEPS tarballs required for a full FreeBSD build.
# Hash of the test_fonts tarball in the chromium-fonts Google Storage bucket.
_TEST_FONTS_HASH=	cd96fc55dc243f6c6f4cb63ad117cad6cd48dceb
MASTER_SITES+=	https://pdfium.googlesource.com/pdfium/+archive/:pdfium_src \
		https://chromium.googlesource.com/chromium/src/base/allocator/partition_allocator/+archive/:pa \
		https://chromium.googlesource.com/chromium/src/build/+archive/:build \
		https://chromium.googlesource.com/chromium/src/buildtools/+archive/:buildtools \
		https://pdfium.googlesource.com/pdfium_tests/+archive/:corpus \
		https://chromium.googlesource.com/chromium/src/third_party/abseil-cpp/+archive/:absl \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/clang/tools/clang-format/+archive/:clangfmt \
		https://chromium.googlesource.com/chromium/tools/depot_tools/+archive/:depot \
		https://chromium.googlesource.com/external/github.com/jk-jeon/dragonbox/+archive/:dragonbox \
		https://chromium.googlesource.com/external/github.com/fastfloat/fast_float/+archive/:fastfloat \
		https://chromium.googlesource.com/external/github.com/Maratyszcza/FP16/+archive/:fp16 \
		https://chromium.googlesource.com/chromium/src/third_party/freetype2/+archive/:freetype \
		https://chromium.googlesource.com/external/github.com/google/googletest/+archive/:gtest \
		https://chromium.googlesource.com/external/github.com/harfbuzz/harfbuzz/+archive/:harfbuzz \
		https://chromium.googlesource.com/external/github.com/google/highway/+archive/:highway \
		https://chromium.googlesource.com/chromium/deps/icu/+archive/:icu \
		https://chromium.googlesource.com/chromium/third_party/instrumented_libraries/+archive/:instlib \
		https://chromium.googlesource.com/chromium/src/third_party/jinja2/+archive/:jinja2 \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxx/+archive/:libcxx \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libcxxabi/+archive/:libcxxabi \
		https://chromium.googlesource.com/chromium/deps/libjpeg_turbo/+archive/:jpeg \
		https://chromium.googlesource.com/chromium/src/third_party/libpng/+archive/:png \
		https://chromium.googlesource.com/external/github.com/llvm/llvm-project/libc/+archive/:llvm_libc \
		https://chromium.googlesource.com/chromium/src/third_party/markupsafe/+archive/:markupsafe \
		https://chromium.googlesource.com/chromium/deps/nasm/+archive/:nasm \
		https://chromium.googlesource.com/chromium/src/third_party/simdutf/+archive/:simdutf \
		https://skia.googlesource.com/skia/+archive/:skia \
		https://chromium.googlesource.com/chromium/src/third_party/test_fonts/+archive/:testfonts \
		https://chromium-fonts.storage.googleapis.com/:testfonts \
		https://chromium.googlesource.com/chromium/src/third_party/zlib/+archive/:zlib \
		https://chromium.googlesource.com/chromium/src/tools/clang/+archive/:tools_clang \
		https://chromium.googlesource.com/chromium/src/tools/code_coverage/+archive/:codecov \
		https://chromium.googlesource.com/chromium/src/tools/memory/+archive/:tools_mem \
		https://chromium.googlesource.com/v8/v8/+archive/:v8
DISTFILES+=	${PDFIUM_COMMIT}.tar.gz:pdfium_src \
		89615a645f0220fb03875111c2d9ae4dea9887d8.tar.gz:pa \
		2cd94c0abeada712aeea6906d99021913c9fc28d.tar.gz:build \
		6f6a5dbf04b734214f3b1f386567d101ec9d607e.tar.gz:buildtools \
		59ed3059c846ef5f92865d933fb705db55b1dc45.tar.gz:corpus \
		435e7d977fb36fb47854a4c552c0706dad0bd7cf.tar.gz:absl \
		70510081984cfcdb14a15b3e08dfe9776dc7ed37.tar.gz:clangfmt \
		36a8df4ad006eaa0572fb446edb8145fe5403592.tar.gz:depot \
		beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44.tar.gz:dragonbox \
		34164f547b7df3f5d794ff67e9f885c36819ebfc.tar.gz:fastfloat \
		782eea126dc5c755827be751a099eb01826175cf.tar.gz:fp16 \
		4800589f76dc62fbe523a74a59e0d4850a5dd7df.tar.gz:freetype \
		4fe3307fb2d9f86d19777c7eb0e4809e9694dde7.tar.gz:gtest \
		886fc1e645388080b72f6d9b06347533a0018045.tar.gz:harfbuzz \
		2607d3b5b0113992fe84d3848859eae13b3b52c1.tar.gz:highway \
		8cc91d9b6ab9991802fd208ee03a69714fd0251c.tar.gz:icu \
		d15c278eed5d38d9acf2d8054cf37baba93cef8e.tar.gz:instlib \
		c3027d884967773057bf74b957e3fea87e5df4d7.tar.gz:jinja2 \
		97b436da4c33663581d394f4ee0a5977fc38c2f4.tar.gz:libcxx \
		fc1897a2c12aa27e703c3ed48b62eba8abf4ce19.tar.gz:libcxxabi \
		640f254ad0fa03f6b1f29f89b7dd9366f2f6e533.tar.gz:jpeg \
		0179a807421cf96731cdfa10008bba04fda243c1.tar.gz:png \
		320824188c37e5c28738b9652a0ca8087c934bc9.tar.gz:llvm_libc \
		4256084ae14175d38a3ff7d739dca83ae49ccec6.tar.gz:markupsafe \
		525a09a813be0f75b646ee93fc2a31c27b87d722.tar.gz:nasm \
		f7356eed293f8208c40b3c1b344a50bd70971983.tar.gz:simdutf \
		5549c93c9a1c66137ceed424f08c86ce9988290c.tar.gz:skia \
		7f51783942943e965cd56facf786544ccfc07713.tar.gz:testfonts \
		${_TEST_FONTS_HASH}:testfonts \
		285e94b8fa95ad3b7d16b80798ec8dce6febb8c8.tar.gz:zlib \
		450d823868eaee61e2b2cb986e19aec287f16d58.tar.gz:tools_clang \
		e1878fbb1ff79de75d54b6b57caa19a92b90079b.tar.gz:codecov \
		0732f7097d066a81e673f90862994f76886fc638.tar.gz:tools_mem \
		df65d5c8f2932045c5af72cd7ecd0c8002fa631e.tar.gz:v8
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PDFIUM_COMMIT}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}

MAINTAINER=	matias@pizarro.net
COMMENT=	PDF rendering and manipulation library
WWW=		https://pdfium.googlesource.com/pdfium/

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gn:devel/gn \
		ninja:devel/ninja \
		glib>0:devel/glib20
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libopenjp2.so:graphics/openjpeg \
		libpng.so:graphics/png

USES=		compiler:c++20-lang jpeg llvm:${CLANG_VER} pkgconfig python:build

CLANG_VER=	${LLVM_DEFAULT}

# Main pdfium source tarball is fetched directly from the upstream
# googlesource mirror because the GitHub pdfium mirror does not carry
# the chromium/8066 branch commit.

GN_OUT=		out/Release
GN_ARGS=	is_debug=false \
		is_component_build=false \
		pdf_is_complete_lib=true \
		pdf_is_standalone=false \
		pdf_enable_v8=false \
		pdf_enable_xfa=false \
		use_siso=false \
		clang_use_chrome_plugins=false \
		use_sysroot=false \
		use_custom_libcxx=false \
		use_custom_libcxx_for_host=false \
		treat_warnings_as_errors=false \
		clang_base_path="${LOCALBASE}/llvm${CLANG_VER}" \
		clang_version=${CLANG_VER} \
		use_llvm_libatomic=false \
		use_allocator_shim=false \
		use_system_libpng=true \
		use_system_libjpeg=true \
		use_system_lcms2=true \
		use_system_libopenjpeg2=true
#GN_ARGS+=    concurrent_links=4
#GN_ARGS+=    pkg_config_path="/usr/local/bin/pkg-config"

_DEPS_DIRS=	base/allocator/partition_allocator:89615a645f0220fb03875111c2d9ae4dea9887d8 \
		build:2cd94c0abeada712aeea6906d99021913c9fc28d \
		buildtools:6f6a5dbf04b734214f3b1f386567d101ec9d607e \
		testing/corpus:59ed3059c846ef5f92865d933fb705db55b1dc45 \
		third_party/abseil-cpp:435e7d977fb36fb47854a4c552c0706dad0bd7cf \
		third_party/clang-format/script:70510081984cfcdb14a15b3e08dfe9776dc7ed37 \
		third_party/depot_tools:36a8df4ad006eaa0572fb446edb8145fe5403592 \
		third_party/dragonbox/src:beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44 \
		third_party/fast_float/src:34164f547b7df3f5d794ff67e9f885c36819ebfc \
		third_party/fp16/src:782eea126dc5c755827be751a099eb01826175cf \
		third_party/freetype/src:4800589f76dc62fbe523a74a59e0d4850a5dd7df \
		third_party/googletest/src:4fe3307fb2d9f86d19777c7eb0e4809e9694dde7 \
		third_party/harfbuzz/src:886fc1e645388080b72f6d9b06347533a0018045 \
		third_party/highway/src:2607d3b5b0113992fe84d3848859eae13b3b52c1 \
		third_party/icu:8cc91d9b6ab9991802fd208ee03a69714fd0251c \
		third_party/instrumented_libs:d15c278eed5d38d9acf2d8054cf37baba93cef8e \
		third_party/jinja2:c3027d884967773057bf74b957e3fea87e5df4d7 \
		third_party/libc++/src:97b436da4c33663581d394f4ee0a5977fc38c2f4 \
		third_party/libc++abi/src:fc1897a2c12aa27e703c3ed48b62eba8abf4ce19 \
		third_party/libjpeg_turbo:640f254ad0fa03f6b1f29f89b7dd9366f2f6e533 \
		third_party/libpng:0179a807421cf96731cdfa10008bba04fda243c1 \
		third_party/llvm-libc/src:320824188c37e5c28738b9652a0ca8087c934bc9 \
		third_party/markupsafe:4256084ae14175d38a3ff7d739dca83ae49ccec6 \
		third_party/nasm:525a09a813be0f75b646ee93fc2a31c27b87d722 \
		third_party/simdutf:f7356eed293f8208c40b3c1b344a50bd70971983 \
		third_party/skia:5549c93c9a1c66137ceed424f08c86ce9988290c \
		third_party/test_fonts:7f51783942943e965cd56facf786544ccfc07713 \
		third_party/zlib:285e94b8fa95ad3b7d16b80798ec8dce6febb8c8 \
		tools/clang:450d823868eaee61e2b2cb986e19aec287f16d58 \
		tools/code_coverage:e1878fbb1ff79de75d54b6b57caa19a92b90079b \
		tools/memory:0732f7097d066a81e673f90862994f76886fc638 \
		v8:df65d5c8f2932045c5af72cd7ecd0c8002fa631e

BINARY_ALIAS=	python3=${PYTHON_CMD}

pre-checksum:
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/${PDFIUM_COMMIT}.tar.gz | ${GZIP_CMD} -n > ${DISTDIR}/${DIST_SUBDIR}/${PDFIUM_COMMIT}.tar.gz.tmp
	@${MV} ${DISTDIR}/${DIST_SUBDIR}/${PDFIUM_COMMIT}.tar.gz.tmp ${DISTDIR}/${DIST_SUBDIR}/${PDFIUM_COMMIT}.tar.gz
.for dep in ${_DEPS_DIRS}
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz | ${GZIP_CMD} -n > ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz.tmp
	@${MV} ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz.tmp ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz
.endfor

post-extract:
.for dep in ${_DEPS_DIRS}
	@${MKDIR} ${WRKSRC}/${dep:C/:.*//}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz -C ${WRKSRC}/${dep:C/:.*//}
.endfor
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${_TEST_FONTS_HASH} -C ${WRKSRC}/third_party/test_fonts
	@${SED} -i '' -e 's|script_executable = "//third_party/cpython3/host/bin/python3"|script_executable = "python3"|' ${WRKSRC}/.gn
	@${SED} -i '' -e '/^expand_directory_allowlist = build_dotfile_settings[.]expand_directory_allowlist$$/d' ${WRKSRC}/.gn
	@${ECHO_CMD} '# Generated for FreeBSD port build' > ${WRKSRC}/build/config/gclient_args.gni
	@${ECHO_CMD} 'build_with_chromium = false' >> ${WRKSRC}/build/config/gclient_args.gni
	@${ECHO_CMD} 'checkout_google_benchmark = false' >> ${WRKSRC}/build/config/gclient_args.gni
	@${ECHO_CMD} 'checkout_src_internal = false' >> ${WRKSRC}/build/config/gclient_args.gni
	@${MKDIR} ${WRKSRC}/build/modules/freebsd
	@${ECHO_CMD} '# Stub for FreeBSD C++ modules support' > ${WRKSRC}/build/modules/freebsd/BUILD.gn
	@${MKDIR} ${WRKDIR}/pkgconfig
	@${ECHO_CMD} 'Name: zlib' > ${WRKDIR}/pkgconfig/zlib.pc
	@${ECHO_CMD} 'Version: 1.3' >> ${WRKDIR}/pkgconfig/zlib.pc
	@${ECHO_CMD} 'Description: zlib compression library' >> ${WRKDIR}/pkgconfig/zlib.pc
	@${ECHO_CMD} 'Libs: -lz' >> ${WRKDIR}/pkgconfig/zlib.pc
	@${ECHO_CMD} 'Cflags:' >> ${WRKDIR}/pkgconfig/zlib.pc
	@${ECHO_CMD} 'Name: bzip2' > ${WRKDIR}/pkgconfig/bzip2.pc
	@${ECHO_CMD} 'Version: 1.0.8' >> ${WRKDIR}/pkgconfig/bzip2.pc
	@${ECHO_CMD} 'Description: bzip2 compression library' >> ${WRKDIR}/pkgconfig/bzip2.pc
	@${ECHO_CMD} 'Libs: -lbz2' >> ${WRKDIR}/pkgconfig/bzip2.pc
	@${ECHO_CMD} 'Cflags:' >> ${WRKDIR}/pkgconfig/bzip2.pc

do-configure:
	@clang_rt_dir=$$(${LOCALBASE}/llvm${CLANG_VER}/bin/clang -print-file-name=libclang_rt.builtins.a | ${SED} -e 's|.*/lib/clang/[0-9]*/lib/||' -e 's|/libclang_rt.builtins.a||'); \
		${ECHO_CMD} "FreeBSD clang runtime dir: $$clang_rt_dir"; \
		${ECHO_CMD} "$$clang_rt_dir" > ${WRKSRC}/.freebsd_clang_rt_dir
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		PKG_CONFIG_PATH="${WRKDIR}/pkgconfig:${LOCALBASE}/libdata/pkgconfig" \
		${LOCALBASE}/bin/gn gen ${GN_OUT} --args='${GN_ARGS}'

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		PKG_CONFIG_PATH="${WRKDIR}/pkgconfig:${LOCALBASE}/libdata/pkgconfig" \
		${LOCALBASE}/bin/ninja -C ${GN_OUT} pdfium
	@${ECHO_MSG} "===> Building shared library from static archive"
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/llvm${CLANG_VER}/bin/clang++ -shared \
		-o ${GN_OUT}/obj/libpdfium.so \
		-Wl,--whole-archive ${GN_OUT}/obj/libpdfium.a \
		-Wl,--no-whole-archive -lc++ -lm \
		-L${LOCALBASE}/lib -lpng -ljpeg -llcms2 -lopenjp2

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pdfium/cpp
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/public/*.h ${STAGEDIR}${PREFIX}/include/pdfium/
	${INSTALL_DATA} ${WRKSRC}/public/cpp/*.h ${STAGEDIR}${PREFIX}/include/pdfium/cpp/

_GTEST_FILTER=	-FPDFEditEmbedderTest.GetRenderedBitmapHandlesSMask:FPDFEditEmbedderTest.GetRenderedBitmapHandlesClipPath:FPDFEditEmbedderTest.GetRenderedBitmapForHelloWorldText:FPDFEditEmbedderTest.GetRenderedBitmapForRotatedText:FPDFEditEmbedderTest.GetRenderedBitmapForNewlyCreatedText:FPDFEditEmbedderTest.GetRenderedFillPattern:FPDFEditEmbedderTest.GetRenderedFillPatternUncolored:FPDFViewEmbedderTest.RenderAnnotsGrayScale

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		${LOCALBASE}/bin/ninja -C ${GN_OUT} pdfium_unittests pdfium_embeddertests
	@cd ${WRKSRC}/${GN_OUT} && ${SETENV} ${TEST_ENV} ./pdfium_unittests --gtest_filter='${_GTEST_FILTER}'
	@cd ${WRKSRC}/${GN_OUT} && ${SETENV} ${TEST_ENV} ./pdfium_embeddertests --gtest_filter='${_GTEST_FILTER}'

# tests as of 8066: pdfium_unittests [  PASSED  ] 1099 tests.; pdfium_embeddertests [  PASSED  ] 871 tests.

.include <bsd.port.mk>
