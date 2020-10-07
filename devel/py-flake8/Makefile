# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	3.8.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0:devel/py-pyflakes@${PY_FLAVOR} \
		${PY_TYPING}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
