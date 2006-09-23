# Ports collection makefile for:  pear-Config
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	Config
PORTVERSION=	1.10.6
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Your configurations swiss-army knife

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

FILES=		Config.php Config/Container.php Config/Container/Apache.php \
		Config/Container/GenericConf.php \
		Config/Container/IniCommented.php Config/Container/IniFile.php \
		Config/Container/PHPArray.php Config/Container/PHPConstants.php \
		Config/Container/XML.php
DOCS=		Apache.php IniCommented.php IniFromScratch.php
TESTS=		phpt_test.php.inc setup.php.inc bug2742.phpt bug2742.ini \
		bug2780.phpt bug3051.phpt bug3051.xml bug3137.phpt bug3298.phpt \
		bug3298.xml bug3398.phpt bug3398.ini bug3590.phpt \
		bug3590-input.php bug4623.phpt bug4623.conf bug6441.phpt \
		bug6441.ini
_TESTSDIR=	test

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
