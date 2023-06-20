PORTNAME=	aws-sdk
PORTVERSION=	3.273.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/aws/${PORTNAME}-php/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTFILES=	aws.zip
DIST_SUBDIR=	${PORTNAME}-php-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP interface for Amazon Web Services (AWS)
WWW=		https://github.com/aws/aws-sdk-php

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors zip
USE_PHP=	filter mbstring simplexml

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
