# New ports collection makefile for:   sidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	sidplay
PORTVERSION=	1.36.35
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
DISTNAME=	${PORTNAME}-1_36_35
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/x11/XFree86

GNU_CONFIGURE=	YES

USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	strip ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav ${PREFIX}/bin/sidcon

.include <bsd.port.mk>
