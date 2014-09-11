# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	phpicalendar
PORTVERSION=	2.24
PORTREVISION=	2
CATEGORIES=	deskutils www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	edwin@mavetju.org
COMMENT=	Webbased calendar with iCal support

USES=		tar:tgz
NO_BUILD=	yes
USE_PHP=	session pcre
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

post-extract:
	${FIND} ${WRKDIR} -name .DS_Store -delete
	${FIND} ${WRKDIR} -name '._*' -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for dir in admin calendars functions images includes languages rss templates
	@${CP} -Rv ${WRKSRC}/${dir} ${STAGEDIR}${WWWDIR}
.endfor
.for f in index.php TIMEZONES error.php day.php preferences.php print.php search.php week.php month.php year.php README COPYING AUTHORS
	@${CP} -v ${WRKSRC}/${f} ${STAGEDIR}${WWWDIR}
.endfor
	@${CP} -v ${WRKSRC}/config.inc-dist.php ${STAGEDIR}${WWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
