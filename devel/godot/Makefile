# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	godot
DISTVERSION=	3.1.1
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	2
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Game runtime engine

LICENSE=		MIT CC-BY-3.0
LICENSE_COMB=		multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LOGO_LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt

BROKEN_armv6=		tries to build NEON files without -march=armv7-a -mfpu=neon
BROKEN_powerpc64=	fails to compile: inv_txfm_sse2.h:14:32: emmintrin.h: No such file or directory

BUILD_DEPENDS=	yasm:devel/yasm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	xdg-user-dir:devel/xdg-user-dirs \
		xdg-open:devel/xdg-utils \
		xmessage:x11/xmessage

USES=		compiler:c++14-lang gl pkgconfig scons ssl xorg
USE_XORG=	x11 xcursor xi xinerama xrandr xrender
USE_GL=		gl glew glu

USE_GITHUB=	yes
GH_ACCOUNT=	godotengine

MAKE_ARGS+=		platform=x11 builtin_libpng=False builtin_openssl=False verbose=True
MAKE_ARGS+=		${MAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS_clang=	use_llvm=True
CXXFLAGS+=		-DRTAUDIO_ENABLED
CXXFLAGS_i386=		${CXXFLAGS_i386_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_i386_gcc=	-march=i586

# option MONO doesn't build (needs 5.12+) so for now leave it out as an option
OPTIONS_DEFINE=		EXAMPLES TOOLS
OPTIONS_DEFAULT=	ALSA
# Moved to devel/godot-tools
OPTIONS_EXCLUDE?=	EXAMPLES TOOLS
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO

AUDIO_DESC=		Audio support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		alsa=True
EXAMPLES_GH_PROJECT=	godot-demo-projects:DEMOS
# master at 23/3
EXAMPLES_GH_TAGNAME=	17e80079e3fc:DEMOS
EXAMPLES_PORTEXAMPLES=	*
# mono support doesn't build at present
MONO_USES=		mono:nuget
NUGET_DEPENDS=		DotNet.Glob=2.1.1
MONO_MAKE_ARGS=		module_mono_enabled=True mono_glue=True NUGET_PATH=${NUGET_EXE}
MONO_MAKE_ENV=		NUGET_PATH=${NUGET_EXE}
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
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

pre-build-MONO-on: makenuget
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
