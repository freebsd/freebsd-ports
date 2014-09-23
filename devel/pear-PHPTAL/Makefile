# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	PHPTAL
PORTVERSION=	1.2.2
CATEGORIES=	devel www pear
MASTER_SITES=	http://phptal.org/files/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	PEAR PHPTAL is a XML/XHTML template library for PHP

OPTIONS_DEFINE=	GETTEXT SIMPLEXML JSON
GETTEXT_DESC=	Enable GetText Support
SIMPLEXML_DESC=	Enable SimpleXML Support
JSON_DESC=	Enable JSON Support

EXTRACT_SUFX=	.tar.gz
USES=	pear

USE_PHP=	ctype hash

GETTEXT_USE=	PHP=gettext
SIMPLEXML_USE=	PHP=simplexml
JSON_USE=	PHP=json

.include <bsd.port.mk>
