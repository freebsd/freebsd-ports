# New ports collection makefile for:  	mixer.app
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mixer.app
PORTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	http://www.fukt.bth.se/~per/mixer/
DISTNAME=	Mixer.app-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another mixer intended for the windowmaker dockapp

USE_XPM=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin

.include <bsd.port.post.mk>
