# New ports collection makefile for:	bogged
# Version required:			1.0.0
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/07/12 23:53:06 steve Exp $
#

DISTNAME=		bogged-1.0.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=		.gz

MAINTAINER=		andy@icc.surw.chel.su

RUN_DEPENDS=		wish8.0:${PORTSDIR}/x11/tk80

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}

NO_BUILD=		yes
USE_X_PREFIX=		yes
WRKSRC=			${WRKDIR}

post-extract:
	@ ${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/bogged

.include <bsd.port.mk>
