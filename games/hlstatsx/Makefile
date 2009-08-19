# New ports collection makefile for:   hlstatsx
# Date created:        2006-06-12
# Whom:                Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	hlstatsx
DISTVERSION=	1.20RC2
CATEGORIES=	games www
MASTER_SITES=	http://striker.interhact.net/hlstatsx/
DISTNAME=	HLstatsX_V${DISTVERSION}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Real-time player and clan rankings and statistics for HL2 and mods

NO_BUILD=	yes
USE_APACHE=	2.0+
USE_PHP=	gd mysql
USE_PERL5_RUN=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
HLSTATSX?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATSX=${HLSTATSX}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

do-install:
	@ ${MKDIR} ${PREFIX}/${HLSTATSX}
	@ ${CP} -R ${WRKSRC}/* ${PREFIX}/${HLSTATSX}
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${HLSTATSX}"
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
