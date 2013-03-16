# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
PORTREVISION=	2
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
OPTIONS_DEFINE=	PEAR_XML_BEAUTIFIER PEAR_VAR_DUMP PEAR_PHPUNIT PEAR_XML_UTIL PEAR_HTML_TABLE
OPTIONS_DEFAULT=	PEAR_PHPUNIT PEAR_XML_UTIL
PEAR_XML_BEAUTIFIER_DESC=	PEAR::XML_Beautifier support
PEAR_VAR_DUMP_DESC=	PEAR::Var_Dump support
PEAR_PHPUNIT_DESC=	PEAR::PHPUnit support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_XML_BEAUTIFIER}
RUN_DEPENDS+=	${PEARDIR}/XML/Beautifier.php:${PORTSDIR}/textproc/pear-XML_Beautifier
.endif

.if ${PORT_OPTIONS:MPEAR_VAR_DUMP}
RUN_DEPENDS+=	${PEARDIR}/Var/Dump.php:${PORTSDIR}/devel/pear-Var_Dump
.endif

.if ${PORT_OPTIONS:MPEAR_PHPUNIT}
RUN_DEPENDS+=	${PEARDIR}/PHPUnit/Autoload.php:${PORTSDIR}/devel/pear-PHPUnit3
.endif

.if ${PORT_OPTIONS:MPEAR_XML_UTIL}
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.if ${PORT_OPTIONS:MPEAR_HTML_TABLE}
RUN_DEPENDS+=${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
