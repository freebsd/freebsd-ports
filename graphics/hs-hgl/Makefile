# New ports collection makefile for:	hgl
# Date created:		22 January 2002
# Whom:			octaphial
#
# $FreeBSD$
#

PORTNAME=	hgl
PORTVERSION=	2.0.4
CATEGORIES=	graphics haskell
MASTER_SITES=	http://haskell.org/graphics/downloads/
DISTNAME=	graphics-${PORTVERSION}.src
PKGNAMEPREFIX=	hs-

MAINTAINER=	octaphial@yahoo.com

RUN_DEPENDS=	hugs:${PORTSDIR}/lang/hugs

WRKSRC=		${WRKDIR}/graphics-${PORTVERSION}
USE_GMAKE=	yes
USE_XLIB=	yes

BUILD_WRKSRC=	${WRKSRC}/lib/x11
MAKE_ENV=	system=FreeBSD \
		hugs_install=${PREFIX}/share/hugs
ALL_TARGET=	all

do-install:
	${MKDIR} ${PREFIX}/share/hugs/lib/x11
	${MKDIR} ${PREFIX}/share/hugs/demos/hgl
	${INSTALL_SCRIPT} ${PKGDIR}/scripts/hugs-hgl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/x11/*.hs ${PREFIX}/share/hugs/lib/x11
	${INSTALL_PROGRAM} ${WRKSRC}/lib/x11/*.o ${PREFIX}/share/hugs/lib/x11
	${INSTALL_PROGRAM} ${WRKSRC}/lib/x11/*.so ${PREFIX}/share/hugs/lib/x11
	${INSTALL_DATA} ${WRKSRC}/demos/* ${PREFIX}/share/hugs/demos/hgl
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/hugs/demos/hgl

post-install:
	${MKDIR} ${PREFIX}/share/doc/hgl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/hgl
	${INSTALL_DATA} ${WRKSRC}/License ${PREFIX}/share/doc/hgl
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/hgl
	${INSTALL_DATA} ${WRKSRC}/Version ${PREFIX}/share/doc/hgl
	${INSTALL_DATA} ${WRKSRC}/Version-2.0.4 ${PREFIX}/share/doc/hgl

.include <bsd.port.mk>
