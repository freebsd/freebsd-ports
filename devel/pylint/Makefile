# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pylint
PORTVERSION=	2.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=2.2.0:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.5:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.6:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
USE_PYTHON=	distutils py3kplist

NO_ARCH=	yes

SHEBANG_FILES=	pylint/test/data/ascript

.include <bsd.port.mk>
