# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHPLOC
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-SebastianBergmann_
DISTNAME=	phploc-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Tool for quickly measuring the size of a PHP project

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.0.4:${PORTSDIR}/devel/pear-SebastianBergmann_FinderFacade \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-File_Iterator>=1.3.0:${PORTSDIR}/devel/pear-File_Iterator \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-SebastianBergmann_FinderFacade>=1.0.4:${PORTSDIR}/devel/pear-SebastianBergmann_FinderFacade \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

USE_PHP=	tokenizer
PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
