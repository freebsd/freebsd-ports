# New ports collection makefile for:	knapster
# Version required:			0.2
# Date created:				06 January 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	knapster-0.2
CATEGORIES=	audio kde
MASTER_SITES=	http://www.chariot.net.au/~donoghue/

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	${LOCALBASE}/bin/kdehelp:${PORTSDIR}/x11/kdebase11

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT=		yes

.include <bsd.port.mk>
