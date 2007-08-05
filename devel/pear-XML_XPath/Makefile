# Ports collection makefile for:  pear-XML_XPath
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_XPath
PORTVERSION=	1.2.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class provided an XPath/DOM XML manipulation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(PACKAGE_BUILDING)
IGNORE=		No package building: The default libraries in the PHP package do not support domxml by default.
.endif

DEFAULT_PHP_VER=	4
IGNORE_WITH_PHP=	5
USE_PHP=	domxml

CATEGORY=	XML
FILES=		XPath.php XPath/common.php XPath/error.php XPath/result.php
EXAMPLES=	XML_XPath_example.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
