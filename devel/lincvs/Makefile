# New ports collection makefile for:	lincvs
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lincvs
PORTVERSION=	0.2.3
CATEGORIES=	devel kde
MASTER_SITES=	http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

USE_QT_VER=	2
WRKSRC=		${WRKDIR}/LinCVS-0.2.3

do-configure:
	@${PERL} -pi.orig -e 's|__X11BASE__|${X11BASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LinCVS ${PREFIX}/bin/lincvs

.include <bsd.port.mk>
