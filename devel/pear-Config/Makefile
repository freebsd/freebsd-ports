# Ports collection makefile for:  pear-Config
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	Config
PORTVERSION=	1.10.4
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Your configurations swiss-army knife

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

FILES=		Config.php Config/Container.php Config/Container/Apache.php \
		Config/Container/GenericConf.php Config/Container/IniCommented.php \
		Config/Container/IniFile.php Config/Container/PHPArray.php \
		Config/Container/XML.php
DOCS=		Apache.php IniCommented.php IniFromScratch.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
