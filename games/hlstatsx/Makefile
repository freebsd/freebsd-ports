# $FreeBSD$

PORTNAME=	hlstatsx
DISTVERSION=	1.20RC2
PORTREVISION=	1
CATEGORIES=	games www
MASTER_SITES=	http://striker.interhact.net/hlstatsx/
DISTNAME=	HLstatsX_V${DISTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Real-time player and clan rankings and statistics for HL2 and mods

NO_BUILD=	yes
USE_APACHE_RUN=	22+
USE_PHP=	gd mysql
USES=		perl5 zip
USE_PERL5=	run

WRKSRC=		${WRKDIR}/${PORTNAME}
HLSTATSX?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATSX=${HLSTATSX}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

NO_STAGE=	yes
do-install:
	@ ${MKDIR} ${PREFIX}/${HLSTATSX}
	@ ${CP} -R ${WRKSRC}/* ${PREFIX}/${HLSTATSX}
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${HLSTATSX}"
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
