PORTNAME=	electron
DISTVERSIONPREFIX=	v
DISTVERSION=	${ELECTRON_VER}
PORTREVISION=	4
PULSEMV=	16
PULSEV=		${PULSEMV}.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tagattie/FreeBSD-Electron/releases/download/v34.3.2/:chromium \
		https://freedesktop.org/software/pulseaudio/releases/:pulseaudio
PKGNAMESUFFIX=	${ELECTRON_VER_MAJOR}
DISTFILES=	chromium-${CHROMIUM_VER}${EXTRACT_SUFX}.0:chromium \
		chromium-${CHROMIUM_VER}${EXTRACT_SUFX}.1:chromium \
		chromium-${CHROMIUM_VER}${EXTRACT_SUFX}.2:chromium \
		pulseaudio-${PULSEV}.tar.gz:pulseaudio \
		electron-yarn-cache-${ELECTRON_VER}${EXTRACT_SUFX}:prefetch
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	chromium-${CHROMIUM_VER}${EXTRACT_SUFX} \
		${DISTFILES:C/:[^:]+$//:C/chromium-${CHROMIUM_VER}${EXTRACT_SUFX}\.[0-9]//}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Build cross-platform desktop apps with JavaScript, HTML, and CSS
WWW=		https://electronjs.org/

LICENSE=	BSD3CLAUSE LGPL21 MPL11 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/electron/LICENSE

DEPRECATED=	EOLed upstream, switch to newer version
EXPIRATION_DATE=	2025-08-31

ONLY_FOR_ARCHS=	aarch64 amd64 i386

FETCH_DEPENDS=	yarn${NODEJS_SUFFIX}>0:www/yarn${NODEJS_SUFFIX}
EXTRACT_DEPENDS=yarn${NODEJS_SUFFIX}>0:www/yarn${NODEJS_SUFFIX}
PATCH_DEPENDS=	git:devel/git \
		jq:textproc/jq
BUILD_DEPENDS=	gperf:devel/gperf \
		bindgen:devel/rust-bindgen-cli \
		yasm:devel/yasm \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri \
		rustc:lang/rust \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		node${NODEJS_VERSION}>0:www/node${NODEJS_VERSION} \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libdbus-1.so:devel/dbus \
		libicuuc.so:devel/icu \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
		libnotify.so:devel/libnotify \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libre2.so:devel/re2 \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libdav1d.so:multimedia/dav1d \
		libva.so:multimedia/libva \
		libopenh264.so:multimedia/openh264 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils
TEST_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}python-dbusmock>0:devel/py-python-dbusmock@${PY_FLAVOR} \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}

USES=		bison compiler:c++17-lang cpe gettext-tools gl gmake gnome \
		iconv:wchar_t jpeg localbase:ldflags ninja nodejs:20,build \
		pkgconfig python:build,test shebangfix tar:xz xorg

CPE_VENDOR=	electronjs
USE_GITHUB=	yes
GH_TUPLE=	nodejs:node:v${NODE_VER}:node \
		nodejs:nan:${NAN_VER}:nan \
		Squirrel:Squirrel.Mac:${SQUIRREL_MAC_VER}:squirrel_mac \
		ReactiveCocoa:ReactiveObjC:${REACTIVEOBJC_VER}:reactiveobjc \
		Mantle:Mantle:${MANTLE_VER}:mantle \
		EngFlow:reclient-configs:${ENGFLOW_RECLIENT_CONFIGS_VER}:reclient_configs
USE_GL=		gbm gl glesv2
USE_GNOME=	atk cairo gdkpixbuf gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xrandr \
		xrender xscrnsaver xtst

SHEBANG_FILES=	chrome/tools/build/linux/chrome-wrapper buildtools/linux64/clang-format

MAKE_ARGS=	-C out/${BUILDTYPE}
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include
ALL_TARGET=	electron electron:node_headers
POST_BUILD_TARGETS=	licenses version
POST_BUILD_DIST_TARGETS=electron_dist_zip electron_chromedriver_zip \
			electron_mksnapshot_zip

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
BINARY_ALIAS=	python3=${PYTHON_CMD}
BUNDLE_LIBS=	yes

NO_WRKSUBDIR=	yes
WRKSRC_SUBDIR=	src

GN_ARGS+=	clang_use_chrome_plugins=false \
		enable_backup_ref_ptr_support=false \
		enable_hangout_services_extension=true \
		enable_nacl=false \
		enable_remoting=false \
		fatal_linker_warnings=false \
		icu_use_data_file=false \
		is_clang=true \
		optimize_webui=true \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_allocator_shim=false \
		use_aura=true \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_lld=true \
		use_partition_alloc=true \
		use_partition_alloc_as_malloc=false \
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_udev=false \
		chrome_pgo_phase=0 \
		extra_cflags="${CFLAGS}" \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim ${PINCLUDES}" \
		extra_ldflags="${LDFLAGS}" \
		ffmpeg_branding="${FFMPEG_BRAND}" \
		override_electron_version="${ELECTRON_VER}"

# TODO: investigate building with these options:
# use_system_minigbm
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

PLIST_SUB=	ELECTRON_VER=${ELECTRON_VER} \
		ELECTRON_VER_MAJOR=${ELECTRON_VER_MAJOR}

OPTIONS_DEFINE=		CODECS CUPS DEBUG DIST DRIVER KERBEROS LTO PIPEWIRE
OPTIONS_DEFAULT=	CODECS CUPS DRIVER KERBEROS PIPEWIRE ALSA PULSEAUDIO SNDIO
OPTIONS_EXCLUDE_aarch64=LTO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	HEIMDAL HEIMDAL_BASE MIT
OPTIONS_SUB=		yes
CODECS_DESC=		Compile and enable patented codecs like H.264
DIST_DESC=		Build distribution zip files
DRIVER_DESC=		Install chromedriver
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
MIT_DESC=		MIT Kerberos (security/krb5)
PIPEWIRE_DESC=		Screen capture via PipeWire

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
			alsa-lib>=1.1.1_1:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		GN_ARGS+=proprietary_codecs=true \
			FFMPEG_BRAND="Chrome"
CODECS_VARS_OFF=	GN_ARGS+=proprietary_codecs=false \
			FFMPEG_BRAND="Chromium"

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

DEBUG_BUILD_DEPENDS=	esbuild:devel/esbuild
DEBUG_VARS=		BUILDTYPE=Debug \
			GN_FILE=testing.gn \
			GN_ARGS+=is_debug=true \
			GN_ARGS+=is_component_build=false \
			GN_ARGS+=symbol_level=1 \
			GN_BOOTSTRAP_FLAGS+=--debug \
			WANTSPACE="21 GB"
DEBUG_VARS_OFF=		BUILDTYPE=Release \
			GN_FILE=release.gn \
			GN_ARGS+=blink_symbol_level=0 \
			GN_ARGS+=is_debug=false \
			GN_ARGS+=is_official_build=true \
			GN_ARGS+=symbol_level=0 \
			WANTSPACE="14 GB"

DIST_IMPLIES=		DRIVER
DRIVER_MAKE_ARGS=	chromedriver

HEIMDAL_LIB_DEPENDS=	libkrb5.so.26:security/heimdal
KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

LTO_VARS=		GN_ARGS+=use_thin_lto=true \
			GN_ARGS+=thin_lto_enable_optimizations=true \
			WANTSPACE="14 GB"
LTO_VARS_OFF=		GN_ARGS+=use_thin_lto=false

MIT_LIB_DEPENDS=	libkrb5.so.3:security/krb5

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		GN_ARGS+=rtc_use_pipewire=true \
			GN_ARGS+=rtc_link_pipewire=true
PIPEWIRE_VARS_OFF=	GN_ARGS+=rtc_use_pipewire=false \
			GN_ARGS+=rtc_link_pipewire=false

PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true \
			PINCLUDES="-I${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/pulseaudio-${PULSEV}/src -DPA_MAJOR=${PULSEMV}"
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

# See ${WRKSRC}/electron/DEPS for CHROMIUM_VER
CHROMIUM_VER=			132.0.6834.210
# See ${WRKSRC}/electron/DEPS for NODE_VER
NODE_VER=			20.19.1
# See ${WRKSRC}/electron/DEPS for NAN_VER
NAN_VER=			e14bdcd1f72d62bca1d541b66da43130384ec213
# See ${WRKSRC}/electron/DEPS for SQUIRREL_MAC_VER
SQUIRREL_MAC_VER=		0e5d146ba13101a1302d59ea6e6e0b3cace4ae38
# See ${WRKSRC}/electron/DEPS for REACTIVEOBJC_VER
REACTIVEOBJC_VER=		74ab5baccc6f7202c8ac69a8d1e152c29dc1ea76
# See ${WRKSRC}/electron/DEPS for MANTLE_VER
MANTLE_VER=			78d3966b3c331292ea29ec38661b25df0a245948
# See ${WRKSRC}/electron/DEPS for ENGFLOW_RECLIENT_CONFIGS_VER
ENGFLOW_RECLIENT_CONFIGS_VER=	955335c30a752e9ef7bff375baab5e0819b6c00d

YARN_TIMESTAMP=	61171200

.include "Makefile.version"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && !exists(/usr/lib/libkrb5.so)
IGNORE=		you have selected HEIMDAL_BASE but do not have Heimdal installed in base
.endif

LLVM_DEFAULT=		20
BUILD_DEPENDS+=		clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
			cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
			c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
			ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
			nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
			ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
CFLAGS+=		-Wno-error=implicit-function-declaration

.if ${ARCH} == "aarch64"
PLIST_SUB+=	AARCH64="" \
		AMD64="@comment " \
		I386="@comment " \
		NOT_AARCH64="@comment "
FFMPEG_TARGET=	arm64
.elif ${ARCH} == "amd64"
BUILD_DEPENDS+=	nasm:devel/nasm
PLIST_SUB+=	AARCH64="@comment " \
		AMD64="" \
		I386="@comment " \
		NOT_AARCH64=""
FFMPEG_TARGET=	x64
.elif ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
PLIST_SUB+=	AARCH64="@comment " \
		AMD64="@comment " \
		I386="" \
		NOT_AARCH64=""
FFMPEG_TARGET=	ia32
.endif

FFMPEG_BDIR=	${WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

# Allow relocations against read-only segments (override lld default)
LDFLAGS_i386=	-Wl,-znotext

# TODO: -isystem, would be just as ugly as this approach, but more reliably
# build would fail without C_INCLUDE_PATH/CPLUS_INCLUDE_PATH env var set.
MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include

# rust
RUSTC_VERSION!=	rustc -V 2>/dev/null || true
MAKE_ENV+=	RUSTC_BOOTSTRAP=1
GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute="${LOCALBASE}" \
		rustc_version="${RUSTC_VERSION}"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build electron, you should have around 2GB of memory"
	@${ECHO_MSG} "and around ${WANTSPACE} of free disk space."
	@${ECHO_MSG}

pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/electron-yarn-cache-${ELECTRON_VER}${EXTRACT_SUFX} ]; \
		then ${MKDIR} ${WRKDIR}; \
		${ECHO_CMD} 'yarn-offline-mirror "./yarn-offline-cache"' >> \
			${WRKDIR}/.yarnrc; \
		${CP} ${FILESDIR}/package.json ${FILESDIR}/yarn.lock ${WRKDIR}; \
		cd ${WRKDIR} && ${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			yarn --frozen-lockfile --ignore-scripts; \
		${MTREE_CMD} -cbnSp yarn-offline-cache | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${YARN_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:mode=\([0-9]\)7[0-9][0-9]:mode=\1755:' \
			-e 's:mode=\([0-9]\)6[0-9][0-9]:mode=\1644:' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./yarn-offline-cache:' > yarn-offline-cache.mtree; \
		${TAR} cJf ${DISTDIR}/${DIST_SUBDIR}/electron-yarn-cache-${ELECTRON_VER}${EXTRACT_SUFX} \
			@yarn-offline-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-fetch:
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/chromium-${CHROMIUM_VER}${EXTRACT_SUFX} ]; then \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/chromium-${CHROMIUM_VER}${EXTRACT_SUFX}.? > \
			${DISTDIR}/${DIST_SUBDIR}/chromium-${CHROMIUM_VER}${EXTRACT_SUFX}; \
	fi

post-extract:
# Move extracted sources to appropriate locations
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/chromium-${CHROMIUM_VER} ${WRKSRC}
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${PORTNAME}-${ELECTRON_VER} ${WRKSRC}/electron
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_nan}-${NAN_VER} \
		${WRKSRC}/third_party/nan
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_node}-${NODE_VER} \
		${WRKSRC}/third_party/electron_node
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_squirrel_mac}-${SQUIRREL_MAC_VER} \
		${WRKSRC}/third_party/squirrel.mac
	${MKDIR} ${WRKSRC}/third_party/squirrel.mac/vendor
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_reactiveobjc}-${REACTIVEOBJC_VER} \
		${WRKSRC}/third_party/squirrel.mac/vendor/ReactiveObjC
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_mantle}-${MANTLE_VER} \
		${WRKSRC}/third_party/squirrel.mac/vendor/Mantle
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/${GH_PROJECT_reclient_configs}-${ENGFLOW_RECLIENT_CONFIGS_VER} \
		${WRKSRC}/third_party/engflow-reclient-configs
# Install node modules for electron
	${MV} ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/yarn-offline-cache ${WRKDIR}
	${ECHO_CMD} 'yarn-offline-mirror "../../../yarn-offline-cache"' >> ${WRKSRC}/electron/.yarnrc
	${MV} ${WRKSRC}/electron/package.json ${WRKSRC}/electron/package.json.bak
	${CP} ${FILESDIR}/package.json ${WRKSRC}/electron
	cd ${WRKSRC}/electron && \
		${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache yarn --frozen-lockfile --offline

pre-patch:
	${SH} ${FILESDIR}/apply-electron-patches.sh ${WRKSRC}
	# ${FIND} ${WRKSRC} -type f -name '*.orig' -print -delete
	# ${FIND} ${WRKSRC} -type f -name '*~' -print -delete

pre-configure:
	# We used to remove bundled libraries to be sure that chromium uses
	# system libraries and not shipped ones.
	# cd ${WRKSRC} && ${PYTHON_CMD} \
	#./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig harfbuzz-ng libdrm libevent libpng \
		libusb libwebp libxml libxslt openh264 opus || ${FALSE}
	# Chromium uses an unreleased version of FFmpeg, so configure it
	cd ${WRKSRC}/media/ffmpeg && \
		${PYTHON_CMD} scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${MKDIR} ${FFMPEG_CDIR}
.for _e in config.h config.asm config_components.h libavcodec libavformat libavutil
	-${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor
	touch ${WRKDIR}/${PORTNAME}-${ELECTRON_VER}/pulseaudio-${PULSEV}/src/pulse/version.h
	@${REINPLACE_CMD} -e 's|$${LOCALBASE}|${LOCALBASE}|;s|$${MODCLANG_VERSION}|${LLVM_DEFAULT}|' \
		${WRKSRC}/build/rust/rust_bindgen.gni \
		${WRKSRC}/build/rust/rust_bindgen_generator.gni

do-configure:
	# GN generator bootstrapping and generating ninja files
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
		READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./out/${BUILDTYPE}/gn gen out/${BUILDTYPE} \
		--args='import("//electron/build/args/${GN_FILE}") ${GN_ARGS}'

	# Setup nodejs dependency
	@${MKDIR} ${WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node ${WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node

	# Setup buildtools/freebsd
	@${MKDIR} ${WRKSRC}/buildtools/freebsd
	${LN} -sf ${WRKSRC}/buildtools/linux64/clang-format ${WRKSRC}/buildtools/freebsd
	${LN} -sf ${WRKSRC}/out/${BUILDTYPE}/gn ${WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${WRKSRC}/buildtools/freebsd/strip

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${POST_BUILD_TARGETS}

post-build-DIST-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${POST_BUILD_DIST_TARGETS}
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${CP} chromedriver.zip chromedriver-v${ELECTRON_VER}-freebsd-${ARCH:S/amd64/x64/:S/i386/ia32/}.zip && \
		${CP} dist.zip electron-v${ELECTRON_VER}-freebsd-${ARCH:S/amd64/x64/:S/i386/ia32/}.zip && \
		${CP} mksnapshot.zip mksnapshot-v${ELECTRON_VER}-freebsd-${ARCH:S/amd64/x64/:S/i386/ia32/}.zip && \
		${SHA256} -r *-v${ELECTRON_VER}-freebsd-*.zip | ${SED} -e 's/ / */' > SHASUMS256.txt

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in electron mksnapshot v8_context_snapshot_generator
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
.for f in libEGL.so libGLESv2.so libffmpeg.so libvk_swiftshader.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 ${STAGEDIR}${DATADIR}/libvulkan.so
.for f in LICENSE LICENSES.chromium.html snapshot_blob.bin v8_context_snapshot.bin version vk_swiftshader_icd.json
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
.for f in chrome_100_percent.pak chrome_200_percent.pak resources.pak
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/locales
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/locales/*.pak ${STAGEDIR}${DATADIR}/locales
	${MKDIR} ${STAGEDIR}${DATADIR}/resources
.for f in default_app.asar
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/resources/${f} ${STAGEDIR}${DATADIR}/resources
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE}/gen && ${COPYTREE_SHARE} node_headers ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/out/${BUILDTYPE} && ${COPYTREE_SHARE} gen/electron/buildflags ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/out/${BUILDTYPE} && ${COPYTREE_SHARE} gen/v8/embedded.S ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/electron ${STAGEDIR}${PREFIX}/bin/electron${PKGNAMESUFFIX}

post-install-DIST-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/releases
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/SHASUMS256.txt ${STAGEDIR}${DATADIR}/releases
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/*-v${ELECTRON_VER}-freebsd-*.zip ${STAGEDIR}${DATADIR}/releases

post-install-DRIVER-on:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chromedriver.unstripped \
		${STAGEDIR}${DATADIR}/chromedriver

do-test:
# Note 1: "npm install" will run before actual tests are executed
# Note 2: Xvfb or something similar is necessary for headless testing
	cd ${WRKSRC}/electron && \
		${SETENV} ${TEST_ENV} ELECTRON_OUT_DIR=${BUILDTYPE} LOCAL_GIT_DIRECTORY=${LOCALBASE} \
		npm run test -- --ci

.include <bsd.port.post.mk>
