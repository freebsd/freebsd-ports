# $FreeBSD$

PORTNAME=	aws-sdk-php
PORTVERSION=	3.28.3
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
	${MKDIR} ${STAGEDIR}${WWWDIR}/${PORTNAME}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/${PORTNAME}

.include <bsd.port.mk>
