# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PPW
PORTVERSION=	1.0.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-
DISTNAME=	ppw-${DISTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PHP Project Wizard

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pear>=1.9.4:devel/pear \
		pear-ezc_ConsoleTools>=1.6:devel/pear-ezc_ConsoleTools \
		pear-Text_Template>=1.1.0:textproc/pear-Text_Template
RUN_DEPENDS=	pear>=1.9.4:devel/pear \
		pear-ezc_ConsoleTools>=1.6:devel/pear-ezc_ConsoleTools \
		pear-Text_Template>=1.1.0:textproc/pear-Text_Template

PEAR_CHANNEL=	phpunit
USES=	pear

.include <bsd.port.mk>
