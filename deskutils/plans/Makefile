#
# New ports collection makefile for:	plans
# Date created:				2004-12-17
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	plans
PORTVERSION=	7.5.1
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.planscalendar.com/release/:plans \
		http://www.freebsd.org/gifs/:logo
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}:plans \
		powerani.gif:logo
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	infofarmer@gmail.com
COMMENT=	A Good Web Calendar

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

WWWDOCROOT?=	www/data
PLANSSUBDIR?=	plans
PLANSDIR?=	${WWWDOCROOT}/${PLANSSUBDIR}
PLIST_SUB+=	DIR=${PLANSDIR}
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
DIR=		${PREFIX}/${PLANSDIR}

post-extract:
	${CP} ${DISTDIR}/powerani.gif ${WRKSRC}/theme/graphics/freebsd.gif

post-patch:
	@${RM} -f ${WRKSRC}/theme/plans.template.orig

do-install:
	@${INSTALL} -d ${DIR}
	@${CP} -nR ${WRKSRC}/ ${DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DIR}
	@${FIND} ${DIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${DIR} -name '*.cgi' -exec ${CHMOD} 755 {} \;
	@${FIND} ${DIR} -name '*.xml' -exec ${CHMOD} 664 {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
