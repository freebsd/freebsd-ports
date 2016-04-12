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
# MOZ_PIS_SCRIPTS		List of scripts residing in ${FILESDIR} to be
# 						filtered through MOZCONFIG_SED and installed along
# 						with our Pluggable Init Scripts (PIS)
#
# MOZ_SED_ARGS			sed(1) commands through which MOZ_PIS_SCRIPTS are
# 						filtered. There is a default set defined here, so
# 						you probably want to add to MOZ_SED_ARGS rather
# 						than clobber it
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
# MOZ_CHROME			A variable for the --enable-chrome-format= in
# 						CONFIGURE_ARGS. The default is omni.
#
# MOZ_TOOLKIT			A variable for the --enable-default-toolkit= in
# 						CONFIGURE_ARGS. The default is cairo-gtk2.
#
# MOZ_EXTENSIONS		A list of extensions to build
#
# MOZ_PROTOCOLS			A list of protocols to build (http, ftp, etc.)
#
# PORT_MOZCONFIG		Defaults to ${FILESDIR}/mozconfig.in, but can be
# 						set to a generic mozconfig included with the port
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
MOZ_RPATH?=	${MOZILLA}
USES+=		cpe compiler:c++11-lang gmake iconv perl5 pkgconfig \
			python:2.7,build desktop-file-utils
CPE_VENDOR?=mozilla
USE_PERL5=	build
USE_XORG=	xext xrender xt

.if ${MOZILLA} != "libxul"
BUNDLE_LIBS=	yes
.endif

MOZILLA_SUFX?=	none
MOZSRC?=	${WRKSRC}
WRKSRC?=	${WRKDIR}/mozilla
PLISTF?=	${WRKDIR}/plist_files

MOZ_OBJDIR?=	${WRKSRC}/obj-${CONFIGURE_TARGET}

MOZ_PIS_DIR?=		lib/${MOZILLA}/init.d

PORT_MOZCONFIG?=	${FILESDIR}/mozconfig.in
MOZCONFIG?=		${WRKSRC}/.mozconfig
# XXX Not ?= because fmake uses MAKEFILE internally
MAKEFILE=		${WRKSRC}/client.mk
MOZILLA_PLIST_DIRS?=	bin lib share/pixmaps share/applications
PKGINSTALL?=	${WRKDIR}/pkg-install
PKGDEINSTALL?=	${WRKDIR}/pkg-deinstall
PKGINSTALL_INC?=	${.CURDIR}/../../www/firefox/files/pkg-install.in
PKGDEINSTALL_INC?=	${.CURDIR}/../../www/firefox/files/pkg-deinstall.in

MOZ_PKGCONFIG_FILES?=	${MOZILLA}-gtkmozembed ${MOZILLA}-js \
			${MOZILLA}-xpcom ${MOZILLA}-plugin

ALL_TARGET?=	build

CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MOZ_EXPORT+=	${CONFIGURE_ENV} \
				PERL="${PERL}"
MOZ_OPTIONS+=	${CONFIGURE_TARGET} --prefix="${PREFIX}"
MOZ_MK_OPTIONS+=MOZ_OBJDIR="${MOZ_OBJDIR}"

CPPFLAGS+=		-isystem${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-rpath,${PREFIX}/lib/${MOZILLA}

.if ${OPSYS} != DragonFly # XXX xpcshell crash during install
# use jemalloc 3.0.0 (4.0 for firefox 43+) API for stats/tuning
MOZ_EXPORT+=	MOZ_JEMALLOC3=1 MOZ_JEMALLOC4=1
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100079
. if ${MOZILLA_VER:R:R} < 43
# system jemalloc 4.0.0 vs. bundled jemalloc 3.6.0-204-gb4acf73
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bug1125514
. endif
.elif ${OPSYS} != FreeBSD || ${OSVERSION} < 1000012 || ${MOZILLA_VER:R:R} >= 37
MOZ_OPTIONS+=	--enable-jemalloc
.endif
.endif # !DragonFly

# Standard depends
_ALL_DEPENDS=	cairo event ffi graphite harfbuzz hunspell icu jpeg nspr nss opus png pixman soundtouch sqlite vpx

.if ${PORT_OPTIONS:MINTEGER_SAMPLES}
MOZ_EXPORT+=	MOZ_INTEGER_SAMPLES=1
_ALL_DEPENDS+=	tremor
.else
_ALL_DEPENDS+=	vorbis
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_CAIRO}
cairo_BUILD_DEPENDS=cairo>=1.12.16_1,2:graphics/cairo
cairo_LIB_DEPENDS=	libcairo.so:graphics/cairo
cairo_MOZ_OPTIONS=	--enable-system-cairo
.endif

event_LIB_DEPENDS=	libevent.so:devel/libevent2
event_MOZ_OPTIONS=	--with-system-libevent

ffi_LIB_DEPENDS=	libffi.so:devel/libffi
ffi_MOZ_OPTIONS=	--enable-system-ffi

.if exists(${FILESDIR}/patch-bug847568)
graphite_LIB_DEPENDS=	libgraphite2.so:graphics/graphite2
graphite_MOZ_OPTIONS=	--with-system-graphite2

harfbuzz_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
harfbuzz_MOZ_OPTIONS=	--with-system-harfbuzz
.endif

hunspell_LIB_DEPENDS=	libhunspell-1.3.so:textproc/hunspell
hunspell_MOZ_OPTIONS=	--enable-system-hunspell

icu_LIB_DEPENDS=		libicui18n.so:devel/icu
icu_MOZ_OPTIONS=		--with-system-icu --with-intl-api

-jpeg_BUILD_DEPENDS=yasm:devel/yasm
# XXX Remove files/patch-ijg-libjpeg once -turbo is default
jpeg_USES=		jpeg
jpeg_MOZ_OPTIONS=	--with-system-jpeg=${LOCALBASE}

nspr_LIB_DEPENDS=	libnspr4.so:devel/nspr
nspr_MOZ_OPTIONS=	--with-system-nspr

nss_LIB_DEPENDS=	libnss3.so:security/nss
nss_MOZ_OPTIONS=	--with-system-nss

.if exists(${FILESDIR}/patch-z-bug517422) && ${MOZILLA_VER:R:R} < 45
opus_LIB_DEPENDS=	libopus.so:audio/opus
opus_MOZ_OPTIONS=	--with-system-opus
.endif

pixman_LIB_DEPENDS=	libpixman-1.so:x11/pixman
pixman_MOZ_OPTIONS=	--enable-system-pixman

png_LIB_DEPENDS=	libpng.so:graphics/png
png_MOZ_OPTIONS=	--with-system-png=${LOCALBASE}

.if exists(${FILESDIR}/patch-z-bug517422)
soundtouch_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch
soundtouch_MOZ_OPTIONS=	--with-system-soundtouch
.endif

sqlite_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
sqlite_MOZ_OPTIONS=	--enable-system-sqlite

.if exists(${FILESDIR}/patch-z-bug517422)
# XXX disabled: update to 1.2.x or review backported fixes
theora_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
theora_MOZ_OPTIONS=	--with-system-theora

tremor_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
tremor_MOZ_OPTIONS=	--with-system-tremor --with-system-ogg

vorbis_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
vorbis_MOZ_OPTIONS=	--with-system-vorbis --with-system-ogg
.endif

-vpx_BUILD_DEPENDS=	yasm:devel/yasm
vpx_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
vpx_MOZ_OPTIONS=	--with-system-libvpx

.for use in ${USE_MOZILLA}
${use:S/-/_WITHOUT_/}=	${TRUE}
.endfor

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
MOZ_CHROME?=	omni
MOZ_TOOLKIT?=	cairo-gtk2
MOZ_OPTIONS+=	\
		--enable-chrome-format=${MOZ_CHROME} \
		--enable-default-toolkit=${MOZ_TOOLKIT} \
		--enable-pie \
		--with-pthreads
# Configure options for install
.if !defined(MOZ_EXTENSIONS)
MOZ_OPTIONS+=	--enable-extensions=default
.else
MOZ_OPTIONS+=	--enable-extensions=${MOZ_EXTENSIONS}
.endif
.if !defined(MOZ_PROTOCOLS)
MOZ_OPTIONS+=	--enable-necko-protocols=default
.else
MOZ_OPTIONS+=	--enable-necko-protocols=${MOZ_PROTOCOLS}
.endif
# others
MOZ_OPTIONS+=	--with-system-zlib		\
		--with-system-bz2		\
		--enable-unified-compilation	\
		--disable-debug-symbols		\
		--disable-glibtest		\
		--disable-gtktest		\
		--disable-freetypetest		\
		--disable-installer		\
		--disable-updater		\
		--disable-pedantic

# API keys from www/chromium 
# http://www.chromium.org/developers/how-tos/api-keys
# Note: these are for FreeBSD use ONLY. For your own distribution,
# please get your own set of keys.
MOZ_EXPORT+=	MOZ_GOOGLE_API_KEY=AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8 \
				MOZ_GOOGLE_OAUTH_API_CLIENTID=996322985003.apps.googleusercontent.com \
				MOZ_GOOGLE_OAUTH_API_KEY=IR1za9-1VK0zZ0f_O8MVFicn

.if ${PORT_OPTIONS:MGTK3}
MOZ_TOOLKIT=	cairo-gtk3
.endif

.if ${MOZ_TOOLKIT:Mcairo-qt}
# don't use - transparent backgrounds (bug 521582),
USE_MOZILLA+=	-cairo # ports/169343
USE_DISPLAY=yes # install
USE_GNOME+=	pango
USE_QT5+=	qmake_build buildtools_build gui network quick printsupport
MOZ_EXPORT+=	HOST_QMAKE="${QMAKE}" HOST_MOC="${MOC}" HOST_RCC="${RCC}"
.elif ${MOZ_TOOLKIT:Mcairo-gtk3}
BUILD_DEPENDS+=	gtk3>=3.14.6:x11-toolkits/gtk30
USE_GNOME+=	gtk30
. if ${MOZILLA_VER:R:R} >= 32
USE_GNOME+= gtk20 # bug 624422
. endif
.else # gtk2, cairo-gtk2
USE_GNOME+=	gtk20
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=		-O3
MOZ_EXPORT+=	MOZ_OPTIMIZE_FLAGS="${CFLAGS:M-O*}"
MOZ_OPTIONS+=	--enable-optimize
.else
. if ${MOZILLA_VER:R:R} >= 45 && ${ARCH} == i386 && \
  (${OSVERSION} >= 1000000 && ${OSVERSION} < 1003501)
USES:=			compiler:c++14-lang ${USES:Ncompiler*c++11*} # XXX ports/207837
. endif
MOZ_OPTIONS+=	--disable-optimize
.endif

.if ${PORT_OPTIONS:MCANBERRA}
RUN_DEPENDS+=	libcanberra>0:audio/libcanberra
.endif

.if ${PORT_OPTIONS:MDBUS}
BUILD_DEPENDS+=	libnotify>0:devel/libnotify
LIB_DEPENDS+=	libdbus-glib-1.so:devel/dbus-glib \
				libstartup-notification-1.so:x11/startup-notification
MOZ_OPTIONS+=	--enable-startup-notification
.else
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.endif

.if ${PORT_OPTIONS:MFFMPEG}
# dom/media/platforms/ffmpeg/FFmpegRuntimeLinker.cpp
RUN_DEPENDS+=	ffmpeg>=0.8,1:multimedia/ffmpeg
.else
MOZ_OPTIONS+=	--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	gstreamer1-libav>=1.2.4_1:multimedia/gstreamer1-libav
USE_GSTREAMER1?=good libav
MOZ_OPTIONS+=	--enable-gstreamer=1.0
.else
MOZ_OPTIONS+=	--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MGCONF}
BUILD_DEPENDS+=	${gconf2_DETECT}:${gconf2_LIB_DEPENDS:C/.*://}
USE_GNOME+=		gconf2:build
MOZ_OPTIONS+=	--enable-gconf
.else
MOZ_OPTIONS+=	--disable-gconf
.endif

.if ${PORT_OPTIONS:MGIO} && ! ${MOZ_TOOLKIT:Mcairo-qt}
MOZ_OPTIONS+=	--enable-gio
.else
MOZ_OPTIONS+=	--disable-gio
.endif

.if ${PORT_OPTIONS:MGNOMEUI}
BUILD_DEPENDS+=	${libgnomeui_DETECT}:${libgnomeui_LIB_DEPENDS:C/.*://}
USE_GNOME+=		libgnomeui:build
MOZ_OPTIONS+=	--enable-gnomeui
.else
MOZ_OPTIONS+=	--disable-gnomeui
.endif

.if ${PORT_OPTIONS:MLIBPROXY}
LIB_DEPENDS+=	libproxy.so:net/libproxy
MOZ_OPTIONS+=	--enable-libproxy
.else
MOZ_OPTIONS+=	--disable-libproxy
.endif

.if ${PORT_OPTIONS:MPGO}
USES:=		compiler:gcc-c++11-lib ${USES:Ncompiler*c++11*}
USE_DISPLAY=yes

ALL_TARGET=	profiledbuild
MOZ_EXPORT+=MOZ_OPTIMIZE_FLAGS="-Os" MOZ_PGO_OPTIMIZE_FLAGS="${CFLAGS:M-O*}"
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
RUN_DEPENDS+=	alsa-lib>=1.0.27.2_1:audio/alsa-lib
MOZ_OPTIONS+=	--enable-alsa
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
. if ${PORT_OPTIONS:MALSA}
BUILD_DEPENDS+=	pulseaudio>0:audio/pulseaudio
. else
# pull pulse package if we cannot fallback to another backend
LIB_DEPENDS+=	libpulse.so:audio/pulseaudio
. endif
MOZ_OPTIONS+=	--enable-pulseaudio
.else
MOZ_OPTIONS+=	--disable-pulseaudio
.endif

.if ${MOZILLA_VER:R:R} >= 40
.if ${PORT_OPTIONS:MRUST}
BUILD_DEPENDS+=	rustc:${RUST_PORT}
RUST_PORT?=		lang/rust
MOZ_OPTIONS+=	--enable-rust
.else
MOZ_OPTIONS+=	--disable-rust
.endif
.endif

.if ${PORT_OPTIONS:MDEBUG}
MOZ_OPTIONS+=	--enable-debug --disable-release
STRIP=	# ports/184285
.else
MOZ_OPTIONS+=	--disable-debug --enable-release
.endif

.if ${PORT_OPTIONS:MDTRACE}
MOZ_OPTIONS+=	--enable-dtrace
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100061
LIBS+=			-lelf
. endif
STRIP=
.else
MOZ_OPTIONS+=	--disable-dtrace
.endif

.if ${MOZILLA_VER:R:R} < 40
. if ${PORT_OPTIONS:MLOGGING} || ${PORT_OPTIONS:MDEBUG}
MOZ_OPTIONS+=	--enable-logging
. else
MOZ_OPTIONS+=	--disable-logging
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

MOZ_SED_ARGS+=	-e's|@CPPFLAGS@|${CPPFLAGS}|g'		\
		-e 's|@CFLAGS@|${CFLAGS}|g'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|g'		\
		-e 's|@LIBS@|${LIBS}|g'			\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		-e 's|@PERL@|${PERL}|g'			\
		-e 's|@MOZDIR@|${PREFIX}/lib/${MOZILLA}|g'	\
		-e 's|%%PREFIX%%|${PREFIX}|g'		\
		-e 's|%%CFLAGS%%|${CFLAGS}|g'		\
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g'		\
		-e 's|%%LIBS%%|${LIBS}|g'		\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g'	\
		-e 's|%%PERL%%|${PERL}|g'		\
		-e 's|%%MOZILLA%%|${MOZILLA}|g'		\
		-e 's|%%MOZILLA_BIN%%|${MOZILLA_BIN}|g'	\
		-e 's|%%MOZDIR%%|${PREFIX}/lib/${MOZILLA}|g'
MOZCONFIG_SED?= ${SED} ${MOZ_SED_ARGS}

.if ${ARCH} == amd64
. if ${USE_MOZILLA:M-nss}
USE_BINUTILS=	# intel-gcm.s
CFLAGS+=	-B${LOCALBASE}/bin
LDFLAGS+=	-B${LOCALBASE}/bin
. endif
.elif ${ARCH:Mpowerpc*}
USES:=		compiler:gcc-c++11-lib ${USES:Ncompiler*c++11*}
. if ${ARCH} == "powerpc64"
MOZ_EXPORT+=	UNAME_m="${ARCH}"
CFLAGS+=	-mminimal-toc
. endif
.elif ${ARCH} == "sparc64"
# Work around miscompilation/mislinkage of the sCanonicalVTable hacks.
MOZ_OPTIONS+=	--disable-v1-string-abi
.endif

.else # bsd.port.post.mk

pre-extract: gecko-pre-extract

gecko-pre-extract:
.if ${PORT_OPTIONS:MPGO}
	@${ECHO} "*****************************************************************"
	@${ECHO} "**************************** attention **************************"
	@${ECHO} "*****************************************************************"
	@${ECHO} "To build ${MOZILLA} with PGO support you need a running X server and"
	@${ECHO} "   build this port with an user who could access the X server!   "
	@${ECHO} ""
	@${ECHO} "During the build a ${MOZILLA} instance will start and run some test."
	@${ECHO} "      Do not interrupt or close ${MOZILLA} during this tests!       "
	@${ECHO} "*****************************************************************"
	@sleep 10
.endif

post-patch: gecko-post-patch gecko-moz-pis-patch

gecko-post-patch:
.if exists(${PKGINSTALL_INC})
	@${MOZCONFIG_SED} < ${PKGINSTALL_INC} > ${PKGINSTALL}
.endif
.if exists(${PKGDEINSTALL_INC})
	@${MOZCONFIG_SED} < ${PKGDEINSTALL_INC} > ${PKGDEINSTALL}
.endif
	@${RM} -f ${MOZCONFIG}
.if !defined(NOMOZCONFIG)
	@if [ -e ${PORT_MOZCONFIG} ] ; then \
		${MOZCONFIG_SED} < ${PORT_MOZCONFIG} >> ${MOZCONFIG} ; \
	fi
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
.if exists(${MOZSRC}/build/unix/mozilla-config.in)
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g ; \
		s|"%FULL_NSPR_CFLAGS%"|`nspr-config --cflags`|g ; \
		s|"%FULL_NSPR_LIBS%"|`nspr-config --libs`|g' \
			${MOZSRC}/build/unix/mozilla-config.in
.endif
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
	@for f in \
			${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
			${WRKSRC}/directory/c-sdk/configure \
			${MOZSRC}/security/coreconf/FreeBSD.mk \
			${MOZSRC}/js/src/Makefile.in \
			${MOZSRC}/js/src/configure \
			${MOZSRC}/configure \
			${WRKSRC}/configure; do \
		if [ -f $$f ] ; then \
			${REINPLACE_CMD} -Ee 's|-lc_r|-pthread|g ; \
				s|-l?pthread|-pthread|g ; \
				s|echo aout|echo elf|g ; \
				s|/usr/X11R6|${LOCALBASE}|g' \
				$$f; \
		fi; \
	done
	@if [ -f ${WRKSRC}/config/baseconfig.mk ] ; then \
		${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${WRKSRC}/config/baseconfig.mk; \
	fi
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${MOZSRC}/config/baseconfig.mk
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${MOZSRC}/build/unix/run-mozilla.sh
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
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${MOZSRC}/extensions/spellcheck/hunspell/*/mozHunspell.cpp

# handles mozilla pis scripts.
gecko-moz-pis-patch:
.for moz in ${MOZ_PIS_SCRIPTS}
	@${MOZCONFIG_SED} < ${FILESDIR}/${moz} > ${WRKDIR}/${moz}
.endfor

do-configure: gecko-do-configure

gecko-do-configure:
		@(if ! ${CONFIGURE_ENV} ${DO_MAKE_BUILD} configure; then \
			 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)

pre-install: gecko-moz-pis-pre-install
post-install-script: gecko-create-plist

gecko-create-plist: port-post-install

.if !target(port-post-install)
port-post-install:
		@${DO_NADA}
.endif

gecko-create-plist:
# Create the plist
	${RM} -f ${PLISTF}
.for dir in ${MOZILLA_PLIST_DIRS}
	@cd ${STAGEDIR}${PREFIX}/${dir} && ${FIND} -H -s * ! -type d | \
		${SED} -e 's|^|${dir}/|' >> ${PLISTF}
.endfor
	${CAT} ${PLISTF} | ${SORT} >> ${TMPPLIST}

gecko-moz-pis-pre-install:
.if defined(MOZ_PIS_SCRIPTS)
	${MKDIR} ${STAGEDIR}${PREFIX}/${MOZ_PIS_DIR}
.for moz in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${moz} ${STAGEDIR}${PREFIX}/${MOZ_PIS_DIR}
.endfor
.endif

.endif
.endif
# HERE THERE BE TACOS -- adamw
