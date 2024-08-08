PORTNAME=	pyscaffold
PORTVERSION=	4.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyScaffold-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template tool for putting up the scaffold of a Python project
WWW=		https://github.com/pyscaffold/pyscaffold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=46.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=5:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configupdater>=3.0<4:devel/py-configupdater@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.7:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=5:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.7.0<2:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
