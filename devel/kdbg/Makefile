# New ports collection makefile for:	kdbg
# Date created:				02 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	kdbg
PORTVERSION=	1.2.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= kdbg/

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	kdehelp:${PORTSDIR}/x11/kdebase11

GNU_CONFIGURE=	yes
USE_QT=		yes

.include <bsd.port.mk>
