# New ports collection makefile for:	phpicalednar
# Date created:		3 April 2004
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	phpicalendar
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Webbased calendar with iCal support

NO_BUILD=	yes
WWWDIR=		${PREFIX}/www/phpicalendar

do-install:
.if !exists(${WWWDIR})
	${MKDIR} ${WWWDIR}
.endif
.for dir in calendars functions images includes languages rss styles
	@${CP} -R ${WRKSRC}/${dir} ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/${dir}
.endfor
.for f in index.php TIMEZONES admin.php day.php preferences.php print.php search.php week.php month.php year.php README COPYING AUTHORS
	@${CP} ${WRKSRC}/${f} ${WWWDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/${f}
.endfor
	@${CP} ${WRKSRC}/config.inc.php ${WWWDIR}/config.inc.php-default
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/config.inc.php-default

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
