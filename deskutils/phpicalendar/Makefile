# New ports collection makefile for:	phpicalednar
# Date created:		3 April 2004
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	phpicalendar
PORTVERSION=	2.24
CATEGORIES=	deskutils www
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Webbased calendar with iCal support

NO_BUILD=	yes
USE_PHP=	session pcre
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}/

post-extract:
	${FIND} ${WRKDIR} -name .DS_Store -delete
	${FIND} ${WRKDIR} -name '._*' -delete

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
	@${CP} -v ${WRKSRC}/config.inc-dist.php ${WWWDIR}/config.inc.php-default
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/config.inc.php-default

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
