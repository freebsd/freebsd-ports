# New ports collection makefile for:    tank
# Version required:     0.4a
# Date created:         4 Mar 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/05/30 12:36:17 dburr Exp $
#

DISTNAME=	tank-0.4a-src
PKGNAME=	tank-0.4a
CATEGORIES=	games
MASTER_SITES=	http://www.info.polymtl.ca/~coyote/tank/

MAINTAINER=	dburr@FreeBSD.ORG

LIB_DEPENDS=	MesaGL\\.13\\.:${PORTSDIR}/graphics/Mesa2

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_GMAKE=	YES
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.tga ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.au ${PREFIX}/lib/tank

.include <bsd.port.mk>
