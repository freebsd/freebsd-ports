# New ports collection makefile for:	gemdropx
# Version required:			0.4
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	gemdropx.0.4
PKGNAME=	gemdropx-0.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/

MAINTAINER=	andy@icc.surw.chel.su

ALL_TARGET=	gemdropx
MAKEFILE=	makefile
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/gemdropx

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/gemdropx/gfx
	@ ${INSTALL_DATA} ${WRKSRC}/gfx/* ${PREFIX}/share/gemdropx/gfx
	@ ${MKDIR} ${PREFIX}/share/gemdropx/sounds
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/share/gemdropx/sounds
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gemdropx
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/gemdropx
.endif

.include <bsd.port.mk>
