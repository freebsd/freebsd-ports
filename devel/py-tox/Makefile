# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	tox
PORTVERSION=	3.24.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Virtualenv-based automation of test activities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=3.0.0,<4:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=0.12.0,<1:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.17,<2:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0,<2:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.9.4:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=16.0.0:devel/py-virtualenv@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flaky>=3.4.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0.3.11,<1:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10.0,<2:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.22.2,<2:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.0.0,<5:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.8
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.12:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

# tox.ini clobbers our pytest arguments
post-extract:
	${RM} ${WRKSRC}/tox.ini

do-test:
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC}/src ${PYTHON_CMD} -m pytest -v -rs -n ${MAKE_JOBS_NUMBER}

.include <bsd.port.post.mk>
