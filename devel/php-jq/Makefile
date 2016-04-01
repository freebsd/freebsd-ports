# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	0.0.1
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Jq shared extension for php

LICENSE=	MIT

LIB_DEPENDS=	libjq.so:textproc/jq

USE_GITHUB=	yes
GH_ACCOUNT=	kjdev
GH_PROJECT=	php-ext-jq

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70
USES=		tar:tgz

JQ_CMD=		${LOCALBASE}/bin/jq

pre-build:
	(${JQ_CMD} -V | ${SED} 's,jq-\(.*\),#define JQ_VERSION "\1",' >> ${WRKSRC}/version.h)

.include <bsd.port.mk>
