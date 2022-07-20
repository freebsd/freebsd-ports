PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.9.0
PORTREVISION=	5
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Console_Getargs>=1.3.3:devel/pear-Console_Getargs@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Console_Table>=1.1.1:devel/pear-Console_Table@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Event_Dispatcher>=1.0.0:devel/pear-Event_Dispatcher@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}File_Find>=1.3.0:sysutils/pear-File_Find@${PHP_FLAVOR}

USES=		dos2unix pear
USE_PHP=	pcre tokenizer

NO_ARCH=	yes

PORTSCOUT=	skipv:1.9.0a1,1.9.0b1,1.9.0b2

OPTIONS_DEFINE=	PEAR_HTML_TABLE PEAR_VAR_DUMP PEAR_XML_BEAUTIFIER PEAR_XML_UTIL PHPUNIT
OPTIONS_DEFAULT=PEAR_XML_UTIL PHPUNIT
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table
PEAR_VAR_DUMP_DESC=	PEAR::Var_Dump support
PEAR_XML_BEAUTIFIER_DESC=	PEAR::XML_Beautifier support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support
PHPUNIT_DESC=		PHPUnit support

PEAR_VAR_DUMP_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Var_Dump>=1.0.3:devel/pear-Var_Dump@${PHP_FLAVOR}
PEAR_XML_BEAUTIFIER_RUN_DEPENDS=${PEAR_PKGNAMEPREFIX}XML_Beautifier>=1.1:textproc/pear-XML_Beautifier@${PHP_FLAVOR}
PEAR_XML_UTIL_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}XML_Util>=1.1.4:devel/pear-XML_Util@${PHP_FLAVOR}
PHPUNIT_RUN_DEPENDS=	phpunit9${PHP_PKGNAMESUFFIX}>=3.2.0:devel/phpunit9@${PHP_FLAVOR}

.include <bsd.port.mk>
