# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Jq shared extension for php

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjq.so:textproc/jq

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-jq

IGNORE_WITH_PHP=	70 71 72
USES=		php:ext

JQ_CMD=		${LOCALBASE}/bin/jq

pre-build:
	(${JQ_CMD} -V | ${SED} 's,jq-\(.*\),#define JQ_VERSION "\1",' >> ${WRKSRC}/version.h)

.include <bsd.port.mk>
