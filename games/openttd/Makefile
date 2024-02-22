PORTNAME=	openttd
DISTVERSION=	13.4
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/openttd-releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open source clone of Microprose Transport Tycoon Deluxe
WWW=		https://www.openttd.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblzo2.so:archivers/lzo2

USES=		cmake compiler:c++17-lang cpe pkgconfig tar:xz
CMAKE_ARGS=	-DCMAKE_INSTALL_BINDIR:PATH=bin \
		-DCMAKE_INSTALL_DATADIR:PATH=share

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS FLUIDSYNTH SAVE_PASSWORDS SDL1 SERVER
SERVER_PREVENTS=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_ON=	-DWITH_FLUIDSYNTH:BOOL=ON

SAVE_PASSWORDS_DESC=	Save passwords between server restarts
SAVE_PASSWORDS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-save-passwords

SDL1_DESC=	Use SDL v1.2 instead of v2 for GUI
SDL1_VARS=	_SDL_VERSION=sdl
SDL1_CMAKE_OFF=	-DWITH_SDL2:BOOL=ON
SDL1_VARS_OFF=	_SDL_VERSION=sdl2

SERVER_DESC=		Build dedicated server only (no GUI)
SERVER_USES_OFF=	gnome sdl
SERVER_USE_OFF=		SDL=${_SDL_VERSION}
SERVER_CMAKE_ON=	-DOPTION_DEDICATED:BOOL=ON
SERVER_LIB_DEPENDS_OFF=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libicui18n.so:devel/icu \
			libicu-le-hb.so:devel/icu-le-hb \
			libiculx.so:devel/icu-lx
SERVER_VARS=		USE_RC_SUBR=${PORTNAME}

post-install-SERVER-on:
	@${REINPLACE_CMD} -E '/\.desktop|icons|pixmaps/d' ${TMPPLIST}

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
