# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	tuning-primer
PORTVERSION=	1.6.r1
CATEGORIES=	databases
MASTER_SITES=	http://launchpad.net/mysql-${PORTNAME}/trunk/1.6-r1/+download/
DISTNAME=	${PORTNAME}.sh
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	joehorn@gmail.com
COMMENT=	MySQL performance tuning primer script

LICENSE=	GPLv2

FETCH_ARGS=	-pRr
NO_BUILD=	yes
USE_MYSQL=	yes

PLIST_FILES=	bin/${PORTNAME}

pre-fetch:
	@if [ -f ${DISTDIR}/${PORTNAME}.sh ]; then \
		${RM} ${DISTDIR}/${PORTNAME}.sh; \
	fi

do-install:
	@${CP} ${DISTDIR}/${PORTNAME}.sh \
		${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
