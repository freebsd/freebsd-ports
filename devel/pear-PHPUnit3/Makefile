# Created by: Gerrit Beine (<gerrit.beine@gmx.de>)
# $FreeBSD$

PORTNAME=	PHPUnit
PORTVERSION=	3.7.6
PORTREVISION=	1
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-
PKGNAMESUFFIX=	3

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR regression testing framework for unit tests

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-File_Iterator>=1.3.1:devel/pear-File_Iterator \
		pear-Text_Template>=1.1.1:textproc/pear-Text_Template \
		pear-PHP_CodeCoverage>=1.2.1:devel/pear-PHP_CodeCoverage \
		pear-PHP_Timer>=1.0.2:devel/pear-PHP_Timer \
		pear-PHPUnit_MockObject>=1.2.0:devel/pear-PHPUnit_MockObject \
		pear-Symfony_Component_Yaml>=2.1.0:textproc/pear-Symfony_Component_Yaml \
		${PEARDIR}/.channels/pear.phpunit.de.reg:devel/pear-channel-phpunit
RUN_DEPENDS=	pear-File_Iterator>=1.3.1:devel/pear-File_Iterator \
		pear-Text_Template>=1.1.1:textproc/pear-Text_Template \
		pear-PHP_CodeCoverage>=1.2.1:devel/pear-PHP_CodeCoverage \
		pear-PHP_Timer>=1.0.2:devel/pear-PHP_Timer \
		pear-PHPUnit_MockObject>=1.2.0:devel/pear-PHPUnit_MockObject \
		pear-Symfony_Component_Yaml>=2.1.0:textproc/pear-Symfony_Component_Yaml \
		${PEARDIR}/.channels/pear.phpunit.de.reg:devel/pear-channel-phpunit

CONFLICTS=	pear-PHPUnit-[12]*

USES=		pear
PEAR_CHANNEL=	phpunit

OPTIONS_DEFINE=	JSON SIMPLEXML TOKENIZER
JSON_DESC=	Enable JSON support
SIMPLEXML_DESC=	Enable SIMPLEXML support
TOKENIZER_DESC=	Enable Tokenizer support

USE_PHP=	dom spl pcre

JSON_USE=	PHP=json
SIMPLEXML_USE=	PHP=simplexml
TOKENIZER_USE=	PHP=tokenizer

.include <bsd.port.mk>
