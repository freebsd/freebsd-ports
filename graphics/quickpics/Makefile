# New ports collection makefile for:	QuickPics
# Date Created:				10 March 2000
# Whom:					Stever <stever@transmission23.com>
#
# $FreeBSD$
#

PORTNAME=	quickpics
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://area23.org/QuickPics/
DISTNAME=	QuickPics-${PORTVERSION}

MAINTAINER=	bifrost@kizmiaz.dis.org
COMMENT=	A really handy tool for large image collections and digital cameras

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
ALL_TARGET=	qp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qp
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/qp
.endif

.include <bsd.port.mk>
