# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeBrowser
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Code browser that augments the code with information

BUILD_DEPENDS=	pear>=1.8.1:${PORTSDIR}/devel/pear \
		pear-Console_CommandLine>=1.1.3:${PORTSDIR}/devel/pear-Console_CommandLine \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-Log>=1.2.1:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	pear>=1.8.1:${PORTSDIR}/devel/pear \
		pear-Console_CommandLine>=1.1.3:${PORTSDIR}/devel/pear-Console_CommandLine \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-Log>=1.2.1:${PORTSDIR}/sysutils/pear-Log

USE_PHP=	dom
PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
