# New ports collection makefile for:    tank
# Date created:         4 Mar 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tank
PORTVERSION=	0.4a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://step.polymtl.ca/~coyote/tank/
DISTFILES=	${DISTNAME}-src.tar.gz

MAINTAINER=	erik@smluc.org
COMMENT=	A 3-D network tank game that uses OpenGL/Mesa

BUILD_DEPENDS=	${X11BASE}/lib/libaux.a:${PORTSDIR}/graphics/libaux

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tga ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.au ${DATADIR}

.include <bsd.port.mk>
