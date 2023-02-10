PORTNAME=	monkeytype
PORTVERSION=	22.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MonkeyType-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate type annotations from sampled production types
WWW=		https://github.com/Instagram/MonkeyType

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst03>=0.3.7:devel/py-libcst03@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0:devel/py-mypy_extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
