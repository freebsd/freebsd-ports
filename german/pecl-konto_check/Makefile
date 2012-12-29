# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	konto_check
PORTVERSION=	2.98
CATEGORIES=	german
MASTER_SITES=	SF/kontocheck/konto_check-de/${PORTVERSION}
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP module to check German and Austrian Bank Account Numbers

USE_ZIP=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}
DEFAULT_PHP_VER=53

WRKSRC=	${WRKDIR}/php

.include <bsd.port.pre.mk>

post-extract:
	@${UNZIP_CMD} -q -d ${WRKDIR} ${WRKDIR}/php.zip

post-patch:
	@${REINPLACE_CMD} -e "s|\"/etc|\"${ETCDIR}|g;" ${WRKSRC}/konto_check.c ${WRKSRC}/konto_check.lxx

post-install:
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKDIR}/blz.lut ${ETCDIR}
	@${INSTALL_DATA} ${WRKDIR}/blz.lut2 ${ETCDIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/00liesmich.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
