# New ports collection makefile for:	ohugs
# Date created:				03.03.03
# Whom:					Steffen Mazanek <steffen.mazanek@unibw-muenchen.de>
# $FreeBSD$
#

PORTNAME=	ohugs
PORTVERSION=	0.5
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.math.chalmers.se/~nordland/ohugs/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	steffen.mazanek@unibw-muenchen.de
COMMENT=	Interpreter for Haskell with object-oriented features

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	tix4182:${PORTSDIR}/x11-toolkits/tix
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
USE_BISON=	yes

post-patch:
.if !defined(WITHOUT_X11)
	cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/extra-patch-graphics
.else
	cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/extra-patch-text
.endif

.include <bsd.port.mk>
