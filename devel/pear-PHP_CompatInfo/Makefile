# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	devel pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class to find out the minimum version and extensions required

RUN_DEPENDS=	${PEARDIR}/Console/Table.php:devel/pear-Console_Table \
		${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs \
		${PEARDIR}/File/Find.php:sysutils/pear-File_Find \
		${PEARDIR}/Event/Dispatcher.php:devel/pear-Event_Dispatcher

PORTSCOUT=	skipv:1.9.0a1,1.9.0b1,1.9.0b2
USE_PHP=	tokenizer
USES=		dos2unix pear

OPTIONS_DEFINE=	PEAR_XML_BEAUTIFIER PEAR_VAR_DUMP PEAR_PHPUNIT PEAR_XML_UTIL PEAR_HTML_TABLE
OPTIONS_DEFAULT=	PEAR_PHPUNIT PEAR_XML_UTIL
PEAR_XML_BEAUTIFIER_DESC=	PEAR::XML_Beautifier support
PEAR_VAR_DUMP_DESC=	PEAR::Var_Dump support
PEAR_PHPUNIT_DESC=	PEAR::PHPUnit support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table

PEAR_XML_BEAUTIFIER_RUN_DEPENDS=	${PEARDIR}/XML/Beautifier.php:textproc/pear-XML_Beautifier
PEAR_VAR_DUMP_RUN_DEPENDS=	${PEARDIR}/Var/Dump.php:devel/pear-Var_Dump
PEAR_PHPUNIT_RUN_DEPENDS=	${PEARDIR}/PHPUnit/Autoload.php:devel/pear-PHPUnit3
PEAR_XML_UTIL_RUN_DEPENDS=	${PEARDIR}/XML/Util.php:devel/pear-XML_Util
PEAR_HTML_TABLE_RUN_DEPENDS=	${PEARDIR}/HTML/Table.php:devel/pear-HTML_Table

.include <bsd.port.mk>
