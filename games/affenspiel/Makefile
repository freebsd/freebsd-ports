# New ports collection makefile for:	affenspiel
# Date created:				2 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	affenspiel
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/affenspiel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little puzzle game with monkey for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xt

MAKE_ARGS=	CC="${CC}" LIBS="-L${LOCALBASE}/lib -lX11" \
		DEBUG="${CFLAGS} -I${LOCALBASE}/include" \
		FILE_CONFIG=-DSAVED_GAME_NAME='\"affenspiel.saved\"'

PORTDOCS=	COPYRIGHT README
PLIST_FILES=	bin/affenspiel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/affenspiel ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
