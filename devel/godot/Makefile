# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	godot
PORTVERSION=	2.1.2
PORTREVISION=	3
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Game runtime engine

LICENSE=		MIT CC-BY-3.0
LICENSE_COMB=		multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/LOGO_LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

BROKEN_SSL=	openssl-devel
BROKEN_SSL_REASON_openssl-devel=	member access into incomplete type 'BIO' (aka 'bio_st')

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libmpcdec.so:audio/musepack \
		libspeex.so:audio/speex
RUN_DEPENDS=	xdg-user-dir:devel/xdg-user-dirs \
		xdg-open:devel/xdg-utils \
		xmessage:x11/xmessage

USE_GITHUB=	yes
GH_ACCOUNT=	godotengine

USES=		compiler:c++11-lib pkgconfig scons ssl
USE_XORG=	x11 xcursor xinerama xrandr
USE_GL=		gl

MAKE_ARGS+=	platform=x11 builtin_speex=no builtin_libmpcdec=no
MAKE_ARGS+=	${MAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS_clang=	use_llvm=yes
CXXFLAGS+=	-DGLEW_NO_GLU -DRTAUDIO_ENABLED
CXXFLAGS_i386=	${CXXFLAGS_i386_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_i386_gcc=	-march=i586
CXXFLAGS_aarch64=	-DNO_THREADS
CXXFLAGS_sparc64=	-DNO_THREADS
CXXFLAGS_mips=		-DNO_THREADS
CXXFLAGS_mips64=	-DNO_THREADS
LDFLAGS+=	-lspeex -lmpcdec

OPTIONS_DEFINE=	EXAMPLES TOOLS
OPTIONS_DEFAULT=	OSS
# Moved to devel/godot-tools
OPTIONS_EXCLUDE?=	EXAMPLES TOOLS
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA OSS PULSEAUDIO

AUDIO_DESC=		Audio support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		alsa=yes
EXAMPLES_GH_PROJECT=	godot-demo-projects:DEMOS
# Branch HEAD for PORTVERSION
EXAMPLES_GH_TAGNAME=	dfa1274:DEMOS
EXAMPLES_PORTEXAMPLES=	*
OSS_MAKE_ARGS=		oss=yes
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS=	pulseaudio=yes
TOOLS_DESC=	Include development tools (IDE)
TOOLS_MAKE_ARGS=	target=release_debug tools=yes
TOOLS_MAKE_ARGS_OFF=	target=release tools=no
TOOLS_DESKTOP_ENTRIES=	"Godot" "${COMMENT}" "${GODOTFILE}" \
			"${GODOTFILE}" "Development;IDE;" ""
TOOLS_PLIST_FILES=	share/pixmaps/${GODOTFILE}.png \
			share/pixmaps/${GODOTFILE}.svg

GODOTFILE=		${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	bin/${GODOTFILE}

.ifmake makesum
# Always include optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}" OPTIONS_EXCLUDE=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|custom_build|${OPSYS}_Ports_build|' \
		${WRKSRC}/methods.py
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/platform/x11/os_x11.cpp

# The official godot binary name reflects options used to compile
# We just want a simple name matching the portname
# This gives us bin/godot for runtime and bin/godot-tools for the IDE
do-install:
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
