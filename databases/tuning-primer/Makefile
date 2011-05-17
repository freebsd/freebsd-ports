# New ports collection makefile for: tuning-primer
# Date created:		2009-11-18
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tuning-primer
PORTVERSION=	1.6.r0
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/71733465/
DISTNAME=	${PORTNAME}.sh
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	joehorn@gmail.com
COMMENT=	MySQL performance tuning primer script

LICENSE=	GPLv2

NO_BUILD=	yes
USE_MYSQL=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${CP} ${DISTDIR}/${PORTNAME}.sh \
		${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
