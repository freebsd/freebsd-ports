# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	scourge
PORTVERSION=	0.21.1
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/config/scourge.cfg:games/scourge-data

USES=		autoreconf gettext gmake
USE_GL=		gl
USE_SDL=	sdl image mixer net ttf
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} -e 's|GLvoid|void|g' ${WRKSRC}/src/sdlhandler.cpp ${WRKSRC}/src/sdlhandler.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
