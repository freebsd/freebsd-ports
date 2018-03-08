# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
PORTREVISION=	3
CATEGORIES=	devel pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

RUN_DEPENDS=	${PEARDIR}/Console/Table.php:devel/pear-Console_Table@${PHP_FLAVOR} \
		${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR} \
		${PEARDIR}/File/Find.php:sysutils/pear-File_Find@${PHP_FLAVOR} \
		${PEARDIR}/Event/Dispatcher.php:devel/pear-Event_Dispatcher@${PHP_FLAVOR}

PORTSCOUT=	skipv:1.9.0a1,1.9.0b1,1.9.0b2
USE_PHP=	tokenizer
USES=		dos2unix pear php

OPTIONS_DEFINE=	PEAR_XML_BEAUTIFIER PEAR_VAR_DUMP PHPUNIT PEAR_XML_UTIL PEAR_HTML_TABLE
OPTIONS_DEFAULT=	PHPUNIT PEAR_XML_UTIL
PEAR_XML_BEAUTIFIER_DESC=	PEAR::XML_Beautifier support
PEAR_VAR_DUMP_DESC=	PEAR::Var_Dump support
PHPUNIT_DESC=	PHPUnit support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table

PEAR_XML_BEAUTIFIER_RUN_DEPENDS=	${PEARDIR}/XML/Beautifier.php:textproc/pear-XML_Beautifier@${PHP_FLAVOR}
PEAR_VAR_DUMP_RUN_DEPENDS=	${PEARDIR}/Var/Dump.php:devel/pear-Var_Dump@${PHP_FLAVOR}
PHPUNIT_RUN_DEPENDS=	phpunit:devel/phpunit@${PHP_FLAVOR}
PEAR_XML_UTIL_RUN_DEPENDS=	${PEARDIR}/XML/Util.php:devel/pear-XML_Util@${PHP_FLAVOR}
PEAR_HTML_TABLE_RUN_DEPENDS=	${PEARDIR}/HTML/Table.php:devel/pear-HTML_Table@${PHP_FLAVOR}

.include <bsd.port.mk>
