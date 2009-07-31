# New ports collection makefile for:	Scourge
# Date created:		2005-10-08
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	scourge
PORTVERSION=	0.21.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/.src/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E. is a rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${DATADIR}/config/scourge.cfg:${PORTSDIR}/games/scourge-data

USE_AUTOTOOLS=	autoconf:262:env automake:19:env
USE_GL=		gl
USE_SDL=	sdl image mixer net ttf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	DEBUG	"Produce an executable with debugging symbols"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
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

.include <bsd.port.post.mk>
