# New ports collection makefile for:  	mixer.app
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mixer.app
PORTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another mixer intended for the windowmaker dockapp

PLIST_FILES=	bin/Mixer.app
WRKSRC=		${WRKDIR}/Mixer.app-${PORTVERSION}

USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin

.include <bsd.port.mk>
