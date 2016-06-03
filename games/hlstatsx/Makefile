# $FreeBSD$

PORTNAME=	hlstatsx
DISTVERSION=	1.20RC2
PORTREVISION=	1
CATEGORIES=	games www
MASTER_SITES=	http://striker.interhact.net/hlstatsx/
DISTNAME=	HLstatsX_V${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time player and clan rankings and statistics for HL2 and mods

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_BUILD=	yes
USE_APACHE_RUN=	22+
USE_PHP=	gd mysql
USES=		perl5 zip
USE_PERL5=	run
IGNORE_WITH_PHP=	70

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}
HLSTATSX?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATSX=${HLSTATSX}
SUB_LIST+=	HLSTATSX=${HLSTATSX}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

do-install:
	@ ${MKDIR} ${STAGEDIR}${PREFIX}/${HLSTATSX}
	@ ${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/${HLSTATSX}

.include <bsd.port.mk>
