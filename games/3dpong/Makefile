# New ports collection makefile for:	3dpong
# Version required:			0.3
# Date created:				10 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/08/05 09:30:51 asami Exp $
#

DISTNAME=	3dpong.0.3
PKGNAME=	3dpong-0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/3dpong/

MAINTAINER=	andy@icc.surw.chel.su

MAKEFILE=	makefile
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/3dpong

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/3dpong ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/share/3dpong
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/3dpong
.endif

.include <bsd.port.mk>
