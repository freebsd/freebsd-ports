# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	konto_check
PORTVERSION=	2.98
CATEGORIES=	german
MASTER_SITES=	SF/kontocheck/konto_check-de/${PORTVERSION}
PKGNAMEPREFIX=	pecl-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP module to check German and Austrian Bank Account Numbers

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

IGNORE_WITH_PHP=5 55 56
USES=		zip:infozip
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}

WRKSRC=	${WRKDIR}/php

OPTIONS_DEFINE=	DOCS

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
