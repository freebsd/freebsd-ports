# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	PHPTAL
PORTVERSION=	1.2.2
CATEGORIES=	devel www pear
MASTER_SITES=	http://phptal.org/files/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	PEAR PHPTAL is a XML/XHTML template library for PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

OPTIONS_DEFINE=	GETTEXT SIMPLEXML JSON
GETTEXT_DESC=	"Enable GetText Support"
SIMPLEXML_DESC=	"Enable SimpleXML Support"
JSON_DESC=	"Enable JSON Support"

.include <bsd.port.options.mk>

USE_PHP=	ctype hash

.if ${PORT_OPTIONS:MGETTEXT}
USE_PHP+=	gettext
.endif

.if ${PORT_OPTIONS:MSIMPLEXML}
USE_PHP+=	simplexml
.endif

.if ${PORT_OPTIONS:MJSON}
USE_PHP+=	json
.endif

PEAR_DIST_SUFX=	.tar.gz
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
