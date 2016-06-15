# Created by: Johannes Jost Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	pyganim
PORTVERSION=	0.9.2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyganim-${PORTVERSION}

MAINTAINER=	johannes@perceivon.net
COMMENT=	Sprite animation module for Pygame

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python zip
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
