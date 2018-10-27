# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	ioflo
PORTVERSION=	1.7.5
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Automated Reasoning Engine and Flow Based Programming Framework

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=1.1:devel/py-setuptools-git@${PY_FLAVOR}

USES=		python:2.7 shebangfix

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

SHEBANG_FILES=	scripts/ioflo

.include <bsd.port.mk>
