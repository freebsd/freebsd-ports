# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prestashop
PORTVERSION=	1.6.0.14
CATEGORIES=	finance www
MASTER_SITES=	http://www.prestashop.com/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-Source e-Commerce Software for Web 2.0

BROKEN=		does not fetch
USES=		cpe zip
NO_BUILD=	yes
PRESTADIR=	www/${PORTNAME}
PLIST=		${WRKDIR}/plist
USE_PHP=	mysql gd
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${PRESTADIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${PRESTADIR}?g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
