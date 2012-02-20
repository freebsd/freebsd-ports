# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table \
		${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs \
		${PEARDIR}/File/Find.php:${PORTSDIR}/sysutils/pear-File_Find \
		${PEARDIR}/Event/Dispatcher.php:${PORTSDIR}/devel/pear-Event_Dispatcher

PORTSCOUT=	skipv:1.9.0a1,1.9.0b1,1.9.0b2
USE_PHP=	tokenizer
USE_DOS2UNIX=	yes
PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_XML_BEAUTIFIER "PEAR::XML_Beautifier support" off \
		PEAR_VAR_DUMP "PEAR::Var_Dump support" off \
		PEAR_PHPUNIT "PEAR::PHPUnit support" on \
		PEAR_XML_UTIL "PEAR::XML_Util support" on \
		PEAR_HTML_TABLE "PEAR::HTML_Table" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_XML_BEAUTIFIER)
RUN_DEPENDS+=	${PEARDIR}/XML/Beautifier.php:${PORTSDIR}/textproc/pear-XML_Beautifier
.endif

.if defined(WITH_PEAR_VAR_DUMP)
RUN_DEPENDS+=	${PEARDIR}/Var/Dump.php:${PORTSDIR}/devel/pear-Var_Dump
.endif

.if defined(WITH_PEAR_PHPUNIT)
RUN_DEPENDS+=	${PEARDIR}/PHPUnit/Framework.php:${PORTSDIR}/devel/pear-PHPUnit3
.endif

.if defined(WITH_PEAR_XML_UTIL)
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.if defined(WITH_PEAR_HTML_TABLE)
RUN_DEPENDS+=${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
