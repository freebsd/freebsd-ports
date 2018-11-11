# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	PHPTAL
PORTVERSION=	1.3.0
CATEGORIES=	devel www pear
MASTER_SITES=	https://phptal.org/files/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML/XHTML template library for PHP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pear php
USE_PHP=	ctype hash

NO_ARCH=	yes

OPTIONS_DEFINE=	GETTEXT JSON SIMPLEXML
GETTEXT_DESC=	Enable GetText support
JSON_DESC=	Enable JSON support
SIMPLEXML_DESC=	Enable SimpleXML support

GETTEXT_USE=	PHP=gettext
JSON_USE=	PHP=json
SIMPLEXML_USE=	PHP=simplexml

.include <bsd.port.mk>
