# $FreeBSD$

PORTNAME=	path.py
PORTVERSION=	11.5.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Module wrapper for os.path

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.5:devel/py-importlib-metadata@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>0:devel/py-pytest-flake8@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
GH_ACCOUNT=	jaraco
PORTSCOUT=	limit:^11\. # ignore py3-only for now

post-patch:
	@${REINPLACE_CMD} -e '/setuptools_scm/d' \
		-e 's/use_scm_version=True/version="${PORTVERSION}"/' \
		${WRKSRC}/setup.*

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
