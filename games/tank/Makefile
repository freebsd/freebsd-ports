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

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A 3-D network tank game that uses OpenGL/Mesa

BUILD_DEPENDS=	${X11BASE}/lib/libaux.a:${PORTSDIR}/graphics/libaux

USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/tank
	${INSTALL_DATA} ${WRKSRC}/*.tga ${PREFIX}/share/tank
	${INSTALL_DATA} ${WRKSRC}/*.au ${PREFIX}/share/tank

.include <bsd.port.mk>
