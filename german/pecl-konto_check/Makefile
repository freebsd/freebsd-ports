# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	konto_check
PORTVERSION=	2.98
CATEGORIES=	german
MASTER_SITES=	SF/kontocheck/konto_check-de/${PORTVERSION}
PKGNAMEPREFIX=	pecl-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP module to check German and Austrian Bank Account Numbers

USES=		zip:infozip
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}
DEFAULT_PHP_VER=53

WRKSRC=	${WRKDIR}/php

post-extract:
	@${UNZIP_CMD} -q -d ${WRKDIR} ${WRKDIR}/php.zip

post-patch:
	@${REINPLACE_CMD} -e "s|\"/etc|\"${ETCDIR}|g;" ${WRKSRC}/konto_check.c ${WRKSRC}/konto_check.lxx

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKDIR}/blz.lut ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKDIR}/blz.lut2 ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/00liesmich.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
