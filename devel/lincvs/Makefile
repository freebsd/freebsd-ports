# New ports collection makefile for:	lincvs
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lincvs
PORTVERSION=	0.4.90
CATEGORIES=	devel kde
MASTER_SITES=	http://lincvs.sunsite.dk/download/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0-generic-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	jedgar@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_QT_VER=	2

.include <bsd.port.mk>
