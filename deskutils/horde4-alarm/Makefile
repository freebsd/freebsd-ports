# Ports collection makefile for:  horde4-alarm
# Date created:			  Wed May 24, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	alarm
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	deskutils www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Alarm-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Horde interface to deal with reminders, alarms and notifications

USE_HORDE=	base
USE_GETTEXT=	yes
ALARMDIR=	Alarm
HORDIR=	${HORBAS}${ALARMDIR:S|^|/|:S|/horde||}

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Alarm.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Alarm/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
