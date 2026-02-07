PORTNAME=	openttd
DISTVERSION=	15.0
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/openttd-releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source clone of Microprose Transport Tycoon Deluxe
WWW=		https://www.openttd.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang cpe pkgconfig tar:xz
CMAKE_ARGS=	-DCMAKE_INSTALL_BINDIR:PATH=bin \
		-DCMAKE_INSTALL_DATADIR:PATH=share

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS FLUIDSYNTH SERVER
SERVER_PREVENTS=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_ON=	-DWITH_FLUIDSYNTH:BOOL=ON

SERVER_DESC=		Build dedicated server only (no GUI)
SERVER_USES_OFF=	sdl
SERVER_USE_OFF=		SDL=sdl2
SERVER_CMAKE_ON=	-DOPTION_DEDICATED:BOOL=ON
SERVER_LIB_DEPENDS_OFF=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicui18n.so:devel/icu \
			libopusfile.so:audio/opusfile
SERVER_VARS=		USE_RC_SUBR=${PORTNAME}

post-install-SERVER-on:
	@${REINPLACE_CMD} -E '/\.desktop|icons|pixmaps/d' ${TMPPLIST}

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
