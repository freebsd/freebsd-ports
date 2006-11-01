# Ports collection makefile for:  pear-Config
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	Config
PORTVERSION=	1.10.7
CATEGORIES=	devel www pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Your configurations swiss-army knife

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_XML_PARSER "PEAR::XML_Parser support" off \
		PEAR_XML_UTIL "PEAR::XML_Util support" off

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
		bug6441.ini bug7652.phpt bug7652.xml bug7544.ini \
		bug7544-inicommented.phpt bug7544-inifile.phpt bug8357.ini \
		bug8357-inicommented.phpt bug8357-inifile.phpt
_TESTSDIR=	test

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_XML_PARSER)
RUN_DEPENDS+=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
.endif

.if defined(WITH_PEAR_XML_UTIL)
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
