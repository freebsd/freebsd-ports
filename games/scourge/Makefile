# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	scourge
PORTVERSION=	0.21.1
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${DATADIR}/config/scourge.cfg:${PORTSDIR}/games/scourge-data

USE_AUTOTOOLS=	autoconf:env automake:env
USE_GL=		gl
USE_SDL=	sdl image mixer net ttf
USES=		gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG
DEBUG_CONFIGURE_ENABLE=	debug

post-patch:
	@${REINPLACE_CMD} -e 's|GLvoid|void|g' ${WRKSRC}/src/sdlhandler.cpp ${WRKSRC}/src/sdlhandler.h

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
