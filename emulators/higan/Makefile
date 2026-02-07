PORTNAME=	higan
DISTVERSIONPREFIX=	v
DISTVERSION=	110
PORTREVISION=	1
CATEGORIES=	emulators games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo multi-system emulator
WWW=		https://github.com/higan-emu/higan

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++14-lang gettext gmake gnome pkgconfig xorg
USE_CSTD=	c99
USE_CXXSTD=	c++14

USE_GITHUB=	yes
GH_ACCOUNT=	higan-emu

USE_GNOME=	cairo gdkpixbuf gtk20 gtksourceview2
USE_XORG=	x11 xext xrandr

MAKEFILE=	GNUmakefile
MAKE_ENV=	compiler="${CXX}" hiro="gtk2"

OPTIONS_DEFINE=		DEBUG
OPTIONS_DEFAULT=	GLX INPUT_SDL OPENAL SDL XSHM XV
OPTIONS_MULTI=		INPUT SOUND VIDEO
OPTIONS_MULTI_INPUT=	INPUT_SDL
OPTIONS_MULTI_SOUND=	AO OPENAL PULSEAUDIO
OPTIONS_MULTI_VIDEO=	GLX SDL XSHM XV

INPUT_SDL_DESC=	Build SDL input driver
XSHM_DESC=	Build XShm video driver
XV_DESC=	Build Xv video driver

AO_LIB_DEPENDS=		libao.so:audio/libao
GLX_USES=		gl
GLX_USE=		GL=gl
INPUT_SDL_USES=		sdl
INPUT_SDL_USE=		SDL=sdl
OPENAL_USES=		openal:al
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
SDL_USES=		sdl
SDL_USE=		SDL=sdl2 XORG=xv
XSHM_USE=		XORG=xext
XV_USE=			XORG=xv

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|' \
		${WRKSRC}/nall/path.hpp

post-patch-DEBUG-on:
	${REINPLACE_CMD} -e 's|-O3|-g|g' \
		${WRKSRC}/higan/GNUmakefile \
		${WRKSRC}/icarus/GNUmakefile

do-build:
.for d in higan icarus
	@${DO_MAKE_BUILD} ${ALL_TARGET} -C${WRKSRC}/${d}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/higan/out/higan ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/icarus/out/icarus ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/higan/target-higan/resource/higan.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/higan/target-higan/resource/higan.desktop ${STAGEDIR}${PREFIX}/share/applications/
	(cd ${WRKSRC}/higan/System && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/)
	(cd ${WRKSRC}/icarus/Database && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icarus/Database/)

.include <bsd.port.mk>
