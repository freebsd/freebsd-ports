# $FreeBSD$

PORTNAME=	aws-sdk-php
PORTVERSION=	3.29.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/aws/${PORTNAME}/releases/download/${PORTVERSION}/
DISTFILES=	aws.zip
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php zip
USE_PHP=	curl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
