# New ports collection makefile for:    tank
# Date created:         4 Mar 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tank
PORTVERSION=	0.4a
CATEGORIES=	games
MASTER_SITES=	http://step.polymtl.ca/~coyote/tank/
DISTFILES=	${DISTNAME}-src.tar.gz

MAINTAINER=	dburr@FreeBSD.org

BROKEN=	can\'t find glaux.h

USE_MESA=	YES
USE_GMAKE=	YES
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.tga ${PREFIX}/lib/tank
	${INSTALL_DATA} ${WRKSRC}/*.au ${PREFIX}/lib/tank

.include <bsd.port.mk>
