# New ports collection makefile for:  staticcharge
# Date created:        26 October 2001
# Whom:                Mahlon <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	staticcharge
PORTVERSION=	0.4
CATEGORIES=	net misc
MASTER_SITES=	http://www.staticcling.org/clients/
DISTNAME=	ChargeGTK-${PORTVERSION}

MAINTAINER=	mahlon@martini.nu

BUILD_DEPENDS=	lynx:${PORTSDIR}/www/lynx

WRKSRC=		${WRKDIR}/staticcharge
USE_GTK=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
