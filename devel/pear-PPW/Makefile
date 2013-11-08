# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PPW
PORTVERSION=	1.0.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-
DISTNAME=	ppw-${DISTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Project Wizard

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-Text_Template>=1.1.0:${PORTSDIR}/textproc/pear-Text_Template
RUN_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-ezc_ConsoleTools>=1.6:${PORTSDIR}/devel/pear-ezc_ConsoleTools \
		pear-Text_Template>=1.1.0:${PORTSDIR}/textproc/pear-Text_Template

PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes
IGNORE_WITH_PHP=52

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
