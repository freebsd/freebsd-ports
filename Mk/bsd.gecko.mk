#-*- tab-width: 4; -*-
# ex:ts=4
#
# Date created:		12 Nov 2005
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#
# 4 column tabs prevent hair loss and tooth decay!

# bsd.gecko.mk abstracts the selection of gecko-based backends. It allows users
# and porters to support any available gecko backend without needing to build
# many conditional tests. ${USE_GECKO} is the list of backends that your port
# can handle, and ${GECKO} is set by bsd.gecko.mk to be the chosen backend.
# Users set ${WITH_GECKO} to the list of gecko backends they want on their
# system.

.if defined(USE_GECKO)
.if !defined(_POSTMKINCLUDED) && !defined(Gecko_Pre_Include)
Gecko_Pre_Include=	bsd.gecko.mk

# This file contains some reusable components for mozilla ports. It's of
# use primarily to apps from the mozilla project itself (such as Firefox,
# Thunderbird, etc.), and probably won't be of use for gecko-based ports
# like epiphany, galeon, etc.
#
# You need to make sure to add USE_GECKO=gecko to for your port can uses
# one of these options below.
#
# Ports can use the following:
#
# USE_MOZILLA			By default, it enables every system dependency
# 						listed in '_ALL_DEPENDS'. If your port doesn't
# 						need one of those then you can use '-' like
# 						'USE_MOZILLA= -png -vpx' to subtract the
# 						dependencies. Experimental deps use '+' like
# 						'USE_MOZILLA= +speex +theora'.
#
# MOZILLA_PLIST_DIRS	List of directories to descend into when installing
# 						and creating the plist
#
# MOZ_OPTIONS			configure arguments (added to .mozconfig). If
# 						NOMOZCONFIG is defined, you probably want to set
# 						CONFIGURE_ARGS+=${MOZ_OPTIONS}
#
# MOZ_MK_OPTIONS		The make(1) arguments (added to .mozconfig). If
# 						NOMOZCONFIG is defined, you probably want to set
# 						MAKE_ARGS+=${MOZ_MK_OPTIONS}
#
# MOZ_EXPORT			Environment variables for the build process (added
# 						to .mozconfig). If NOMOZCONFIG is defined, you
# 						probably want to set MAKE_ENV+=${MOZ_EXPORT}
#
# NOMOZCONFIG			Don't drop a customized .mozconfig into the build
# 						directory. Options will have to be specified in
# 						CONFIGURE_ARGS instead
#

MAINTAINER?=	gecko@FreeBSD.org

MOZILLA?=	${PORTNAME}
MOZILLA_VER?=	${PORTVERSION}
MOZILLA_BIN?=	${PORTNAME}-bin
MOZILLA_EXEC_NAME?=${MOZILLA}
USES+=		compiler:c++17-lang cpe gl gmake gnome iconv localbase perl5 pkgconfig \
			python:2.7,build desktop-file-utils
CPE_VENDOR?=mozilla
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk20 gtk30
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xrender xt
HAS_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
LDFLAGS+=		-Wl,--as-needed

BUNDLE_LIBS=	yes

BUILD_DEPENDS+=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
				rust-cbindgen>=0.13.1:devel/rust-cbindgen \
				${RUST_DEFAULT}>=1.41:lang/${RUST_DEFAULT} \
				${LOCALBASE}/bin/python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//g} \
				node:www/node
MOZ_EXPORT+=	${CONFIGURE_ENV} \
				LLVM_CONFIG=llvm-config${LLVM_DEFAULT} \
				PERL="${PERL}" \
				PYTHON3="${LOCALBASE}/bin/python${PYTHON3_DEFAULT}" \
				RUSTFLAGS="${RUSTFLAGS}"
MOZ_OPTIONS+=	--prefix="${PREFIX}"
MOZ_MK_OPTIONS+=MOZ_OBJDIR="${BUILD_WRKSRC}"

# Require newer Clang than what's in base system unless user opted out
. if ${CC} == cc && ${CXX} == c++ && exists(/usr/lib/libc++.so)
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=			${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CC=				${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CXX=			${LOCALBASE}/bin/clang++${LLVM_DEFAULT}
USES:=			${USES:Ncompiler\:*} # XXX avoid warnings
. endif

MOZSRC?=	${WRKSRC}
PLISTF?=	${WRKDIR}/plist_files

MOZCONFIG?=		${WRKSRC}/.mozconfig
MOZILLA_PLIST_DIRS?=	bin lib share/pixmaps share/applications

# Adjust -C target-cpu if -march/-mcpu is set by bsd.cpu.mk
.if ${ARCH} == amd64 || ${ARCH} == i386
RUSTFLAGS+=	${CFLAGS:M-march=*:S/-march=/-C target-cpu=/}
.else
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/}
.endif

# Standard depends
_ALL_DEPENDS=	av1 event ffi graphite harfbuzz icu jpeg nspr nss png pixman sqlite vpx webp

.if exists(${FILESDIR}/patch-bug1559213)
av1_LIB_DEPENDS=	libaom.so:multimedia/aom libdav1d.so:multimedia/dav1d
av1_MOZ_OPTIONS=	--with-system-av1
.endif

event_LIB_DEPENDS=	libevent.so:devel/libevent
event_MOZ_OPTIONS=	--with-system-libevent

ffi_LIB_DEPENDS=	libffi.so:devel/libffi
ffi_MOZ_OPTIONS=	--enable-system-ffi

.if exists(${FILESDIR}/patch-bug847568)
graphite_LIB_DEPENDS=	libgraphite2.so:graphics/graphite2
graphite_MOZ_OPTIONS=	--with-system-graphite2

harfbuzz_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
harfbuzz_MOZ_OPTIONS=	--with-system-harfbuzz
.endif

icu_LIB_DEPENDS=		libicui18n.so:devel/icu
icu_MOZ_OPTIONS=		--with-system-icu --with-intl-api

-jpeg_BUILD_DEPENDS=yasm:devel/yasm
jpeg_USES=		jpeg
jpeg_MOZ_OPTIONS=	--with-system-jpeg=${LOCALBASE}

nspr_LIB_DEPENDS=	libnspr4.so:devel/nspr
nspr_MOZ_OPTIONS=	--with-system-nspr

nss_LIB_DEPENDS=	libnss3.so:security/nss
nss_MOZ_OPTIONS=	--with-system-nss

pixman_LIB_DEPENDS=	libpixman-1.so:x11/pixman
pixman_MOZ_OPTIONS=	--enable-system-pixman

png_LIB_DEPENDS=	libpng.so:graphics/png
png_MOZ_OPTIONS=	--with-system-png=${LOCALBASE}

sqlite_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
sqlite_MOZ_OPTIONS=	--enable-system-sqlite

-vpx_BUILD_DEPENDS=	yasm:devel/yasm
vpx_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
vpx_MOZ_OPTIONS=	--with-system-libvpx

webp_LIB_DEPENDS=	libwebp.so:graphics/webp
webp_MOZ_OPTIONS=	--with-system-webp

.for use in ${USE_MOZILLA}
${use:S/-/_WITHOUT_/}=	${TRUE}
.endfor

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

.for dep in ${_ALL_DEPENDS} ${USE_MOZILLA:M+*:S/+//}
.if !defined(_WITHOUT_${dep})
BUILD_DEPENDS+=	${${dep}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${dep}_LIB_DEPENDS}
RUN_DEPENDS+=	${${dep}_RUN_DEPENDS}
USES+=		${${dep}_USES}
MOZ_OPTIONS+=	${${dep}_MOZ_OPTIONS}
.else
BUILD_DEPENDS+=	${-${dep}_BUILD_DEPENDS}
.endif
.endfor

# Standard options
MOZ_OPTIONS+=	\
		--enable-update-channel=${PKGNAMESUFFIX:Urelease:S/^-//} \
		--disable-updater \
		--with-system-zlib \
		--with-system-bz2

# API keys from www/chromium 
# http://www.chromium.org/developers/how-tos/api-keys
# Note: these are for FreeBSD use ONLY. For your own distribution,
# please get your own set of keys.
MOZ_EXPORT+=	MOZ_GOOGLE_LOCATION_SERVICE_API_KEY=AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8
MOZ_EXPORT+=	MOZ_GOOGLE_SAFEBROWSING_API_KEY=AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=		-O3
MOZ_EXPORT+=	MOZ_OPTIMIZE_FLAGS="${CFLAGS:M-O*}"
MOZ_OPTIONS+=	--enable-optimize
.else
MOZ_OPTIONS+=	--disable-optimize
.  if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# ld 2.17 barfs on Stylo built with -C opt-level=0
USE_BINUTILS=	yes
LDFLAGS+=		-B${LOCALBASE}/bin
.  endif
.endif

.if ${PORT_OPTIONS:MCANBERRA}
RUN_DEPENDS+=	libcanberra>0:audio/libcanberra
.endif

.if ${PORT_OPTIONS:MDBUS}
BUILD_DEPENDS+=	libnotify>0:devel/libnotify
LIB_DEPENDS+=	libdbus-1.so:devel/dbus \
				libdbus-glib-1.so:devel/dbus-glib \
				libstartup-notification-1.so:x11/startup-notification
MOZ_OPTIONS+=	--enable-startup-notification
.else
MOZ_OPTIONS+=	--disable-dbus
.endif

.if ${PORT_OPTIONS:MFFMPEG}
# dom/media/platforms/ffmpeg/FFmpegRuntimeLinker.cpp
RUN_DEPENDS+=	ffmpeg>=0.8,1:multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MGCONF}
# XXX USE_GNOME+=gconf2:build is not supported
BUILD_DEPENDS+=	${LOCALBASE}/lib/libgconf-2.so:devel/gconf2
MOZ_OPTIONS+=	--enable-gconf
.else
MOZ_OPTIONS+=	--disable-gconf
.endif

.if ${PORT_OPTIONS:MLIBPROXY}
LIB_DEPENDS+=	libproxy.so:net/libproxy
MOZ_OPTIONS+=	--enable-libproxy
.else
MOZ_OPTIONS+=	--disable-libproxy
.endif

.if ${PORT_OPTIONS:MALSA}
BUILD_DEPENDS+=	${LOCALBASE}/include/alsa/asoundlib.h:audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
RUN_DEPENDS+=	alsa-lib>=1.1.1_1:audio/alsa-lib
MOZ_OPTIONS+=	--enable-alsa
.endif

.if ${PORT_OPTIONS:MJACK}
BUILD_DEPENDS+=	${LOCALBASE}/include/jack/jack.h:audio/jack
MOZ_OPTIONS+=	--enable-jack
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
BUILD_DEPENDS+=	${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio
MOZ_OPTIONS+=	--enable-pulseaudio
.else
MOZ_OPTIONS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MSNDIO}
BUILD_DEPENDS+=	${LOCALBASE}/include/sndio.h:audio/sndio
post-patch-SNDIO-on:
	@${REINPLACE_CMD} -e 's|OpenBSD|${OPSYS}|g' \
		-e '/DISABLE_LIBSNDIO_DLOPEN/d' \
		${MOZSRC}/media/libcubeb/src/moz.build
.endif

.if ${PORT_OPTIONS:MDEBUG}
MOZ_OPTIONS+=	--enable-debug --disable-release
STRIP=	# ports/184285
.else
MOZ_OPTIONS+=	--disable-debug --disable-debug-symbols --enable-release
. if ${ARCH:Maarch64} || ${MACHINE_CPU:Msse2}
MOZ_OPTIONS+=	--enable-rust-simd
. endif
.endif

.if ${PORT_OPTIONS:MPROFILE}
MOZ_OPTIONS+=	--enable-profiling
STRIP=
.else
MOZ_OPTIONS+=	--disable-profiling
.endif

.if ${PORT_OPTIONS:MTEST}
USE_XORG+=		xscrnsaver
MOZ_OPTIONS+=	--enable-tests
.else
MOZ_OPTIONS+=	--disable-tests
.endif

.if !defined(STRIP) || ${STRIP} == ""
MOZ_OPTIONS+=	--disable-strip --disable-install-strip
.else
MOZ_OPTIONS+=	--enable-strip --enable-install-strip
.endif

# _MAKE_JOBS is only available after bsd.port.post.mk, thus cannot be
# used in .mozconfig. And client.mk automatically uses -jN where N
# is what multiprocessing.cpu_count() returns.
.if defined(DISABLE_MAKE_JOBS) || defined(MAKE_JOBS_UNSAFE)
MAKE_JOBS_NUMBER=	1
.endif
.if defined(MAKE_JOBS_NUMBER)
MOZ_MAKE_FLAGS+=-j${MAKE_JOBS_NUMBER}
.endif

.if defined(MOZ_MAKE_FLAGS)
MOZ_MK_OPTIONS+=MOZ_MAKE_FLAGS="${MOZ_MAKE_FLAGS}"
.endif

.if ${ARCH} == amd64
. if ${USE_MOZILLA:M-nss}
USE_BINUTILS=	# intel-gcm.s
CFLAGS+=	-B${LOCALBASE}/bin
LDFLAGS+=	-B${LOCALBASE}/bin
. endif
.elif ${ARCH:Mpowerpc*}
. if ${ARCH} == "powerpc64"
MOZ_EXPORT+=	UNAME_m="${ARCH}"
. endif
.elif ${ARCH} == "sparc64"
# Work around miscompilation/mislinkage of the sCanonicalVTable hacks.
MOZ_OPTIONS+=	--disable-v1-string-abi
.endif

.else # bsd.port.post.mk

post-patch: gecko-post-patch

gecko-post-patch:
	@${RM} ${MOZCONFIG}
.if !defined(NOMOZCONFIG)
.for arg in ${MOZ_OPTIONS}
	@${ECHO_CMD} ac_add_options ${arg:Q} >> ${MOZCONFIG}
.endfor
.for arg in ${MOZ_MK_OPTIONS}
	@${ECHO_CMD} mk_add_options ${arg:Q} >> ${MOZCONFIG}
.endfor
.for var in ${MOZ_EXPORT}
	@${ECHO_CMD} export ${var:Q} >> ${MOZCONFIG}
.endfor
.endif # .if !defined(NOMOZCONFIG)
.if ${USE_MOZILLA:M-nspr}
	@${ECHO_MSG} "===>  Applying NSPR patches"
	@for i in ${.CURDIR}/../../devel/nspr/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} -d ${MOZSRC}/nsprpub < $$i; \
	done
.endif
.if ${USE_MOZILLA:M-nss}
	@${ECHO_MSG} "===>  Applying NSS patches"
	@for i in ${.CURDIR}/../../security/nss/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} -d ${MOZSRC}/security/nss < $$i; \
	done
.endif
	@if [ -f ${WRKSRC}/config/baseconfig.mk ] ; then \
		${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${WRKSRC}/config/baseconfig.mk; \
	fi
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${MOZSRC}/config/baseconfig.mk
	@${REINPLACE_CMD} -e 's|/usr/local/netscape|${LOCALBASE}|g ; \
		s|/usr/local/lib/netscape|${LOCALBASE}/lib|g' \
		${MOZSRC}/xpcom/io/SpecialSystemDirectory.cpp
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g' \
		${MOZSRC}/xpcom/build/nsXPCOMPrivate.h
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|mozilla/plugins|browser_plugins|g' \
		-e 's|share/mozilla/extensions|lib/xpi|g' \
		${MOZSRC}/xpcom/io/nsAppFileLocationProvider.cpp \
		${MOZSRC}/toolkit/xre/nsXREDirProvider.cpp
# Disable vendor checksums like lang/rust
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${MOZSRC}/third_party/rust/*/.cargo-checksum.json

pre-configure-script:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh

post-install-script: gecko-create-plist

gecko-create-plist:
# Create the plist
	${RM} ${PLISTF}
.for dir in ${MOZILLA_PLIST_DIRS}
	@cd ${STAGEDIR}${PREFIX}/${dir} && ${FIND} -H -s * ! -type d | \
		${SED} -e 's|^|${dir}/|' >> ${PLISTF}
.endfor
	${CAT} ${PLISTF} | ${SORT} >> ${TMPPLIST}

.endif
.endif
# HERE THERE BE TACOS -- adamw
