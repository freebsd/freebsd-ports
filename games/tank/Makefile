# New ports collection makefile for:    tank
# Version required:     0.4a
# Date created:         4 Mar 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	tank-0.4a-src
PKGNAME=	tank-0.4a
CATEGORIES=	games
MASTER_SITES=	http://step.polymtl.ca/~coyote/tank/

MAINTAINER=	dburr@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

BROKEN=	can\'t find glaux.h

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_GMAKE=	YES
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.tga ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.au ${PREFIX}/lib/tank

.include <bsd.port.mk>
