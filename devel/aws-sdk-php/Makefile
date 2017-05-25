# $FreeBSD$

PORTNAME=	aws-sdk-php
PORTVERSION=	3.28.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	aws
USES=		php
USE_PHP=	curl
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
