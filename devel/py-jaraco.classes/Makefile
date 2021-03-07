# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.classes
PORTVERSION=	3.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python class routines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.1:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco>=0:devel/py-jaraco@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-black>=0.3.7:devel/py-pytest-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-enabler>=0:devel/py-pytest-enabler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>=0:devel/py-pytest-mypy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

POST_PLIST=	trim-jaraco-namespace

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__init__.py*
	-@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__/__init__.*
	-@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/jaraco/__pycache__

trim-jaraco-namespace:
	@${REINPLACE_CMD} '/jaraco\/__init__\./d; /jaraco\/__pycache__\/__init__\./d' ${TMPPLIST}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
