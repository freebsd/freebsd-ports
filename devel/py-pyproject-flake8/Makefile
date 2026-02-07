PORTNAME=	pyproject-flake8
PORTVERSION=	7.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyproject_flake8-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Monkey patching wrapper to connect flake8 with pyproject.toml configuration
WWW=		https://github.com/csachs/pyproject-flake8

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=7.0.0:devel/py-flake8@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
