# New ports collection makefile for:   cingb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cingb
PORTVERSION=	0.22A
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/cingb

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	standard

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/cingb ${PREFIX}/bin

.include <bsd.port.mk>
