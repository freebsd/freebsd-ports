# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	godot
PORTVERSION=	3.0.6
PORTREVISION=	1
DISTVERSIONSUFFIX= -stable
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Game runtime engine

LICENSE=		MIT CC-BY-3.0
LICENSE_COMB=		multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LOGO_LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to build: KeyError: 'android_arch'
BROKEN_armv6=		fails to build: KeyError: 'android_arch'
BROKEN_armv7=		fails to build: KeyError: 'android_arch'
BROKEN_powerpc64=	fails to compile: inv_txfm_sse2.h:14:32: emmintrin.h: No such file or directory

BUILD_DEPENDS=	yasm:devel/yasm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	xdg-user-dir:devel/xdg-user-dirs \
		xdg-open:devel/xdg-utils \
		xmessage:x11/xmessage

# on 10.4 using clang34 fails - so we want to use clang60
# gl already needs clang60 so this shouldn't add any overhead
USES=		compiler:c++14-lang pkgconfig scons ssl
USE_XORG=	x11 xcursor xi xinerama xrandr
USE_GL=		gl glew glu

USE_GITHUB=	yes
GH_ACCOUNT=	godotengine

MAKE_ARGS+=		platform=x11 builtin_libpng=False builtin_openssl=False
MAKE_ARGS+=		${MAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS_clang=	use_llvm=True
CXXFLAGS+=		-DRTAUDIO_ENABLED
CXXFLAGS_i386=		${CXXFLAGS_i386_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_i386_gcc=	-march=i586
CXXFLAGS_aarch64=	-DNO_THREADS
CXXFLAGS_sparc64=	-DNO_THREADS
CXXFLAGS_mips=		-DNO_THREADS
CXXFLAGS_mips64=	-DNO_THREADS

# option MONO can be built but is not stable enough to use yet
# for now leave it out as an option
OPTIONS_DEFINE=		EXAMPLES TOOLS
OPTIONS_DEFAULT=	OSS
# Moved to devel/godot-tools
OPTIONS_EXCLUDE?=	EXAMPLES TOOLS
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA OSS PULSEAUDIO

AUDIO_DESC=		Audio support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		alsa=True
EXAMPLES_GH_PROJECT=	godot-demo-projects:DEMOS
# master at 31/1
EXAMPLES_GH_TAGNAME=	d69cc10a0b8a:DEMOS
EXAMPLES_PORTEXAMPLES=	*
# while mono support can build it isn't stable enough to be used yet
MONO_LIB_DEPENDS=	libmonosgen-2.0.so:lang/mono
MONO_MAKE_ARGS=		module_mono_enabled=True
OSS_MAKE_ARGS=		oss=True
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS=	pulseaudio=True
TOOLS_DESC=		Include development tools (IDE)
TOOLS_MAKE_ARGS=	target=release_debug tools=True
TOOLS_MAKE_ARGS_OFF=	target=release tools=False
TOOLS_DESKTOP_ENTRIES=	"Godot" "${COMMENT}" "${GODOTFILE}" \
			"${GODOTFILE}" "Development;IDE;" ""
TOOLS_PLIST_FILES=	share/pixmaps/${GODOTFILE}.png \
			share/pixmaps/${GODOTFILE}.svg

GODOTFILE=		${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=		bin/${GODOTFILE}

.ifmake makesum
# Always include optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}" OPTIONS_EXCLUDE=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|custom_build|${OPSYS}_Ports_build|' \
		${WRKSRC}/methods.py
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/platform/x11/os_x11.cpp

pre-build-MONO-on:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} \
		target=release_debug tools=True mono_glue=False)
	@(cd ${WRKSRC} && ${FIND} ${WRKSRC}/bin -name 'godot*' -exec {} \
		--generate-mono-glue modules/mono/glue \; && \
		${FIND} ${WRKSRC}/bin -name 'godot*' -delete)

# The official godot binary name reflects options used to compile
# We just want a simple name matching the portname
# This gives us bin/godot for runtime and bin/godot-tools for the IDE
do-install:
	@${RM} ${WRKSRC}/bin/*.debugsymbols
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} godot.x11* \
		${STAGEDIR}/${PREFIX}/bin/${GODOTFILE}

do-install-EXAMPLES-on:
	(cd ${WRKSRC_DEMOS} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

do-install-TOOLS-on:
	${INSTALL_DATA} ${WRKSRC}/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${GODOTFILE}.png
	${INSTALL_DATA} ${WRKSRC}/icon.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/${GODOTFILE}.svg

.include <bsd.port.mk>
