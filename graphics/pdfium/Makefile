PORTNAME=	pdfium
DISTVERSION=	8152
PDFIUM_COMMIT=	6688c576fd851f4159c6fae39396da50939de110
CATEGORIES=	graphics
# Additional DEPS tarballs required for a full FreeBSD build.
# Hash of the test_fonts tarball in the chromium-fonts Google Storage bucket.
_TEST_FONTS_HASH=	cd96fc55dc243f6c6f4cb63ad117cad6cd48dceb
MASTER_SITES+=	https://pdfium.googlesource.com/pdfium/+archive/:pdfium_src \
		https://chromium.googlesource.com/chromium/src/base/allocator/partition_allocator/+archive/:pa \
		https://chromium.googlesource.com/chromium/src/build/+archive/:build \
		https://chromium.googlesource.com/chromium/src/buildtools/+archive/:buildtools \
		https://pdfium.googlesource.com/pdfium_tests/+archive/:corpus \
		https://chromium.googlesource.com/chromium/src/third_party/brotli/+archive/:brotli \
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
		https://chromium.googlesource.com/libyuv/libyuv/+archive/:libyuv \
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
		2b864a17731ee7ae5a994ea308178da1e444ba29.tar.gz:pa \
		0c62137b8623a3fab2c6aa5d7c94f719b3aa31f6.tar.gz:build \
		d0d4c192e3c718016b3a0c5d44ccec632bccfe96.tar.gz:buildtools \
		f7a1d03ba45e874b7d3cdf722959a2b8ba4dbfa5.tar.gz:corpus \
		803ac71664ad62af1de39ff55e63ebbe07006fc8.tar.gz:brotli \
		56722f9eb6f40fb1a140caffd36e8f1f61b57aaf.tar.gz:absl \
		9f796802e5d633c96dbe97e0b6683d5e62594f9f.tar.gz:clangfmt \
		a03dfbf7f2d1cefa2795d81d59ca4f16c8616a8f.tar.gz:depot \
		beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44.tar.gz:dragonbox \
		42f254836ee416ffcf2f4e6576260003ac33d48c.tar.gz:fastfloat \
		782eea126dc5c755827be751a099eb01826175cf.tar.gz:fp16 \
		25167984d2435930f9178e8d9d2ca3bdfa71a4e7.tar.gz:freetype \
		0b656495436f57212be8700794a3d5fb14000c5f.tar.gz:gtest \
		ff36703b95013ec1d437e6038e1aa7c881275f4e.tar.gz:harfbuzz \
		2607d3b5b0113992fe84d3848859eae13b3b52c1.tar.gz:highway \
		a0ea93436c528ca316a6e698e483e258839101a5.tar.gz:icu \
		83128b60913a82a39d01055312687a27bb959b59.tar.gz:instlib \
		fde3c16799bd5937e4f15aedc9037c89f96236b9.tar.gz:jinja2 \
		9ba7713d3a0f1e179904c984bb626748b15e57d6.tar.gz:libcxx \
		ce814c994055b107c631c310b1c668e3714c0704.tar.gz:libcxxabi \
		640f254ad0fa03f6b1f29f89b7dd9366f2f6e533.tar.gz:jpeg \
		0179a807421cf96731cdfa10008bba04fda243c1.tar.gz:png \
		1e2e3a35993609da1d89ac170b907719d555f4b3.tar.gz:libyuv \
		d8f2045008e230f3c5f50095d918c11f1997e477.tar.gz:llvm_libc \
		4256084ae14175d38a3ff7d739dca83ae49ccec6.tar.gz:markupsafe \
		525a09a813be0f75b646ee93fc2a31c27b87d722.tar.gz:nasm \
		f7356eed293f8208c40b3c1b344a50bd70971983.tar.gz:simdutf \
		607de4b035dcf7fdbaafb66c6cc04f22009ff4d4.tar.gz:skia \
		7f51783942943e965cd56facf786544ccfc07713.tar.gz:testfonts \
		${_TEST_FONTS_HASH}:testfonts \
		9f9f52c60a14e8e772fb561029ae0a121fef7609.tar.gz:zlib \
		7ea1bdeeaf498a513c77b66667e56f6f41f9f0b3.tar.gz:tools_clang \
		084f00efb99dc9a1726ed68cc2e05d25bc52802b.tar.gz:codecov \
		3d4610fc0dd49053c0395bc2825dfc6ac72ab64e.tar.gz:tools_mem \
		bb54fc4e853a1ef1640b160e5e854d0a3b514e29.tar.gz:v8
DIST_SUBDIR=	${PORTNAME}
# Googlesource archives are not reproducible; normalize them right after fetching
FETCH_CMD=	${SH} ${PORTSDIR}/Tools/scripts/fetch-normalize.sh
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
# the chromium/8152 branch commit.

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

_DEPS_DIRS=	base/allocator/partition_allocator:2b864a17731ee7ae5a994ea308178da1e444ba29 \
		build:0c62137b8623a3fab2c6aa5d7c94f719b3aa31f6 \
		buildtools:d0d4c192e3c718016b3a0c5d44ccec632bccfe96 \
		testing/corpus:f7a1d03ba45e874b7d3cdf722959a2b8ba4dbfa5 \
		third_party/brotli:803ac71664ad62af1de39ff55e63ebbe07006fc8 \
		third_party/abseil-cpp:56722f9eb6f40fb1a140caffd36e8f1f61b57aaf \
		third_party/clang-format/script:9f796802e5d633c96dbe97e0b6683d5e62594f9f \
		third_party/depot_tools:a03dfbf7f2d1cefa2795d81d59ca4f16c8616a8f \
		third_party/dragonbox/src:beeeef91cf6fef89a4d4ba5e95d47ca64ccb3a44 \
		third_party/fast_float/src:42f254836ee416ffcf2f4e6576260003ac33d48c \
		third_party/fp16/src:782eea126dc5c755827be751a099eb01826175cf \
		third_party/freetype/src:25167984d2435930f9178e8d9d2ca3bdfa71a4e7 \
		third_party/googletest/src:0b656495436f57212be8700794a3d5fb14000c5f \
		third_party/harfbuzz/src:ff36703b95013ec1d437e6038e1aa7c881275f4e \
		third_party/highway/src:2607d3b5b0113992fe84d3848859eae13b3b52c1 \
		third_party/icu:a0ea93436c528ca316a6e698e483e258839101a5 \
		third_party/instrumented_libs:83128b60913a82a39d01055312687a27bb959b59 \
		third_party/jinja2:fde3c16799bd5937e4f15aedc9037c89f96236b9 \
		third_party/libc++/src:9ba7713d3a0f1e179904c984bb626748b15e57d6 \
		third_party/libc++abi/src:ce814c994055b107c631c310b1c668e3714c0704 \
		third_party/libjpeg_turbo:640f254ad0fa03f6b1f29f89b7dd9366f2f6e533 \
		third_party/libpng:0179a807421cf96731cdfa10008bba04fda243c1 \
		third_party/libyuv:1e2e3a35993609da1d89ac170b907719d555f4b3 \
		third_party/llvm-libc/src:d8f2045008e230f3c5f50095d918c11f1997e477 \
		third_party/markupsafe:4256084ae14175d38a3ff7d739dca83ae49ccec6 \
		third_party/nasm:525a09a813be0f75b646ee93fc2a31c27b87d722 \
		third_party/simdutf:f7356eed293f8208c40b3c1b344a50bd70971983 \
		third_party/skia:607de4b035dcf7fdbaafb66c6cc04f22009ff4d4 \
		third_party/test_fonts:7f51783942943e965cd56facf786544ccfc07713 \
		third_party/zlib:9f9f52c60a14e8e772fb561029ae0a121fef7609 \
		tools/clang:7ea1bdeeaf498a513c77b66667e56f6f41f9f0b3 \
		tools/code_coverage:084f00efb99dc9a1726ed68cc2e05d25bc52802b \
		tools/memory:3d4610fc0dd49053c0395bc2825dfc6ac72ab64e \
		v8:bb54fc4e853a1ef1640b160e5e854d0a3b514e29

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-extract:
.for dep in ${_DEPS_DIRS}
	@${MKDIR} ${WRKSRC}/${dep:C/:.*//}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${dep:C/^.*://}.tar.gz -C ${WRKSRC}/${dep:C/:.*//}
.endfor
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${_TEST_FONTS_HASH} -C ${WRKSRC}/third_party/test_fonts
	@${LN} -sf ${WRKSRC}/core/fxcrt/scoped_locale.h ${WRKSRC}/testing/scoped_locale.h
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
	${INSTALL_DATA} ${WRKSRC}/${GN_OUT}/obj/libpdfium.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/${GN_OUT}/obj/libpdfium.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/public/*.h ${STAGEDIR}${PREFIX}/include/pdfium/
	${INSTALL_DATA} ${WRKSRC}/public/cpp/*.h ${STAGEDIR}${PREFIX}/include/pdfium/cpp/

_GTEST_FILTER=	-FPDFEditEmbedderTest.GetRenderedBitmapHandlesSMask:FPDFEditEmbedderTest.GetRenderedBitmapHandlesClipPath:FPDFEditEmbedderTest.GetRenderedBitmapForHelloWorldText:FPDFEditEmbedderTest.GetRenderedBitmapForRotatedText:FPDFEditEmbedderTest.GetRenderedBitmapForNewlyCreatedText:FPDFEditEmbedderTest.GetRenderedFillPattern:FPDFEditEmbedderTest.GetRenderedFillPatternUncolored:FPDFViewEmbedderTest.RenderAnnotsGrayScale:WideString.FormatString

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		${LOCALBASE}/bin/ninja -C ${GN_OUT} pdfium_unittests pdfium_embeddertests
	@cd ${WRKSRC}/${GN_OUT} && ${SETENV} ${TEST_ENV} ./pdfium_unittests --gtest_filter='${_GTEST_FILTER}'
	@cd ${WRKSRC}/${GN_OUT} && ${SETENV} ${TEST_ENV} ./pdfium_embeddertests --gtest_filter='${_GTEST_FILTER}'

# tests as of 8152: pdfium_unittests [  PASSED  ] 1200 tests.; pdfium_embeddertests [  PASSED  ] 890 tests.

.include <bsd.port.mk>
