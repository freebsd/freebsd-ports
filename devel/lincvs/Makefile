# New ports collection makefile for:	lincvs
# Version required:			0.2.3
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	lincvs_0.2.3
PKGNAME=	lincvs-0.2.3
CATEGORIES=	devel kde
MASTER_SITES=	http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/

MAINTAINER=	jedgar@FreeBSD.org

USE_QT2=	yes
WRKSRC=		${WRKDIR}/LinCVS-0.2.3

do-configure:
	@${PERL} -pi.orig -e 's|__X11BASE__|${X11BASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LinCVS ${PREFIX}/bin/lincvs

.include <bsd.port.mk>
