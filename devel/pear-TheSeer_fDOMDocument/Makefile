# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	fDOMDocument
PORTVERSION=	1.6.6
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-TheSeer_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Extension to PHP standard DOM

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-channel-theseer>=20120501:devel/pear-channel-theseer
RUN_DEPENDS=	pear-channel-theseer>=20120501:devel/pear-channel-theseer

USE_GITHUB=	yes
GH_ACCOUNT=	theseer
GH_PROJECT=	fDOMDocument

USE_PHP=	dom xml
PEAR_CHANNEL=	theseer

NO_BUILD=	yes

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/fDOMDocument.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/fDOMDocument.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
