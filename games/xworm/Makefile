# New ports collection makefile for:	xworm
# Version required:			1.02
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/05 11:41:43 asami Exp $
#

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
CATEGORIES=	games
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	andy@icc.surw.chel.su

ALL_TARGET=	freebsd
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/XWorm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xworm
.for file in font grid raw
	@ ${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include <bsd.port.mk>
