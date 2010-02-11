# New ports collection makefile for: tuning-primer
# Date created:		2009-11-18
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tuning-primer
PORTVERSION=	1.5.r5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://launchpadlibrarian.net/36004840/
DISTNAME=	${PORTNAME}.sh
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	joehorn@gmail.com
COMMENT=	MySQL performance tuning primer script

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
