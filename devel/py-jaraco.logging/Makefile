# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.logging
PORTVERSION=	3.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional facilities to supplement Python stdlib logging module

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco>=0:devel/py-jaraco@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-black-multipy>=0:devel/py-pytest-black-multipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR}

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
