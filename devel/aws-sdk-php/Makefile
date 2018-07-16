# $FreeBSD$

PORTNAME=	aws-sdk
PORTVERSION=	3.63.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/aws/${PORTNAME}-php/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTFILES=	aws.zip
DIST_SUBDIR=	${PORTNAME}-php-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php:flavors zip
USE_PHP=	curl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
