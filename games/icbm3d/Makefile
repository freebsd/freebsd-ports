# New ports collection makefile for:	icbm3d
# Version required:			0.4
# Date created:				20 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	icbm3d.0.4
PKGNAME=	icbm3d-0.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/icbm3d/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	icbm3d
MAKEFILE=	makefile
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/icbm3d

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/icbm3d ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/icbm3d
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d
.endif

.include <bsd.port.mk>
