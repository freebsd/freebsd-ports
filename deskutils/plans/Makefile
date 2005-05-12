#
# New ports collection makefile for:	plans
# Date created:				2004-12-17
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	plans
PORTVERSION=	6.7.3
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.planscalendar.com/release/:plans \
		http://www.freebsd.org/gifs/:logo
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}:plans \
		powerani.gif:logo
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	edwin@mavetju.org
COMMENT=	A Good Web Calendar

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

DIR=		www/data/plans
PLIST_SUB+=	DIR=${DIR}

post-extract:
	${CP} ${DISTDIR}/powerani.gif ${WRKSRC}/theme/graphics/freebsd.gif

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/${DIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DIR}
	@${FIND} ${PREFIX}/${DIR} -type f -exec ${CHMOD} +x {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
