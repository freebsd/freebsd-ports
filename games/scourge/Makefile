# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	scourge
PORTVERSION=	0.21.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${DATADIR}/config/scourge.cfg:${PORTSDIR}/games/scourge-data

USE_AUTOTOOLS=	autoconf:env automake:env
USE_GL=		gl
USE_SDL=	sdl image mixer net ttf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|GLvoid|void|g' ${WRKSRC}/src/sdlhandler.cpp ${WRKSRC}/src/sdlhandler.h

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
