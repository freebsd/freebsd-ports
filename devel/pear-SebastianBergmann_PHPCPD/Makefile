# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPCPD
PORTVERSION=	1.4.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-SebastianBergmann_
DISTNAME=	phpcpd-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Copy/Paste Detector (CPD) for PHP code

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.0.4:${PORTSDIR}/devel/pear-SebastianBergmann_FinderFacade \
		pear-PHP_Timer>=1.0.4:${PORTSDIR}/devel/pear-PHP_Timer \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.0.4:${PORTSDIR}/devel/pear-SebastianBergmann_FinderFacade \
		pear-PHP_Timer>=1.0.4:${PORTSDIR}/devel/pear-PHP_Timer \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

USE_PHP=	tokenizer
PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
