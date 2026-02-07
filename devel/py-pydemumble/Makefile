PORTNAME=	pydemumble
PORTVERSION=	0.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for demumble: C++, Rust, and Swift symbol demangler
WWW=		https://github.com/angr/pydemumble \
		https://pypi.org/project/pydemumble/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>=1.3.2:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
