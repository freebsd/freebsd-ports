# New ports collection makefile for:	phpicalednar
# Date created:		3 April 2004
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	phpicalendar
PORTVERSION=	2.22
CATEGORIES=	deskutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Webbased calendar with iCal support

NO_BUILD=	yes
PHPICALENDAR=	www/phpicalendar
WWWDIR=		${PREFIX}/${PHPICALENDAR}
PLIST_SUB+=	PHPICALENDAR=${PHPICALENDAR}
USE_PHP=	yes
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}/

post-extract:
	${RM} -r ${WRKSRC}/templates/default/images/CVS
	${FIND} ${WRKDIR} -name .DS_Store -delete

do-install:
.if !exists(${WWWDIR})
	${MKDIR} ${WWWDIR}
.endif
.for dir in admin calendars functions images includes languages rss templates
	@${CP} -Rv ${WRKSRC}/${dir} ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/${dir}
.endfor
.for f in index.php TIMEZONES error.php day.php preferences.php print.php search.php week.php month.php year.php README COPYING AUTHORS
	@${CP} -v ${WRKSRC}/${f} ${WWWDIR}
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/${f}
.endfor
	@${CP} -v ${WRKSRC}/config.inc.php ${WWWDIR}/config.inc.php-default
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/config.inc.php-default

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
