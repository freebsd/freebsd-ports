# New ports collection makefile for:	Scourge
# Date created:		2005-10-08
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	scourge
PORTVERSION=	0.11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scourge

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	S.C.O.U.R.G.E. is a rogue-like game

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes
USE_GL=	yes
USE_SDL=	sdl mixer net
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

OPTIONS=	DEBUG	"Produce an executable with debugging symbols"	off \

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/data/* ${DATADIR}
	@${FIND} ${DATADIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif
.include <bsd.port.mk>
