# New ports collection makefile for:	kplot3d
# Version required:			0.70
# Date created:				30 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	kplot3d-0.70
CATEGORIES=	graphics kde
MASTER_SITES=	http://members.xoom.com/kplot3d/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11

FETCH_BEFORE_ARGS=	-b  # members.xoom.com is broken
USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
