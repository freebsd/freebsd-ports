# New ports collection makefile for:	bogged
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		bogged
PORTVERSION=		1.0.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=		.gz

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Word game for X Window System

RUN_DEPENDS=		wish8.2:${PORTSDIR}/x11-toolkits/tk82

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}

NO_BUILD=		yes
PLIST_FILES=		bin/bogged
USE_X_PREFIX=		yes
WRKSRC=			${WRKDIR}

post-extract:
	@ ${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/bogged

.include <bsd.port.mk>
