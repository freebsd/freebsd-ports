# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monkeytype
PORTVERSION=	20.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MonkeyType-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate type annotations from sampled production types

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst>=0.3.5:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0:devel/py-mypy_extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
