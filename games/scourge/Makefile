PORTNAME=	scourge
PORTVERSION=	0.21.1
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game
WWW=		https://scourge.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/config/scourge.cfg:games/scourge-data

USES=		autoreconf compiler gettext gl gmake localbase pkgconfig sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	sdl image mixer net ttf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

BINARY_ALIAS=	freetype-config=true
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} -e 's|GLvoid|void|g' ${WRKSRC}/src/sdlhandler.cpp ${WRKSRC}/src/sdlhandler.h
	@${REINPLACE_CMD} -e 's|\([^a-z_]\)type(|\1squirrel_type(|g' ${WRKSRC}/src/squirrel/*.cpp ${WRKSRC}/src/squirrel/*.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
