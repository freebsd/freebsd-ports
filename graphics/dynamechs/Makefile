# ex:ts=8
# New ports collection makefile for:	dynamechs
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dynamechs
PORTVERSION=	4.0p1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/p/pre/}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Multibody Dynamic Simulation Library

USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	OPENGLINCDIR="${X11BASE}/include" \
		OPENGLLIBDIR="${X11BASE}/lib" \
		CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
ALL_TARGET=	freebsd

do-install:
.for dir in dm dmu dmGL
	@${MKDIR} ${PREFIX}/include/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.h* ${PREFIX}/include/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/lib/platform.freebsd/lib${dir}.so ${PREFIX}/lib
.endfor

.include <bsd.port.mk>
