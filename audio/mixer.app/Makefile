# New ports collection makefile for:  	mixer.app
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mixer.app
PORTVERSION=	1.4.1
CATEGORIES=	audio
MASTER_SITES=	http://www.fukt.hk-r.se/~per/mixer/	
DISTNAME=	Mixer.app-${PORTVERSION}

MAINTAINER=	cpiazza@FreeBSD.org

USE_IMAKE=	yes
USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer ${PREFIX}/bin

.include <bsd.port.mk>
