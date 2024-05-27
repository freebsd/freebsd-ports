PORTNAME=	meson-python
DISTVERSION=	0.14.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	meson_python-${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Meson Python build backend (PEP-517)
WWW=		https://github.com/mesonbuild/meson-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.7.1:devel/py-pyproject-metadata@${PY_FLAVOR}
RUN_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.7.1:devel/py-pyproject-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31200
BUILD_DEPENDS+=	${PY_SETUPTOOLS}
.endif
.if ${PYTHON_REL} < 31100
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.0.0:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.0.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
