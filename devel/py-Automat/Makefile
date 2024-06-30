PORTNAME=	Automat
PORTVERSION=	22.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/glyph/Automat/commit/
PATCHFILES=	033cb4e0a41c.patch:-p1  # https://github.com/glyph/automat/pull/150

MAINTAINER=	john@saltant.com
COMMENT=	Finite-state machines in Python
WWW=		https://github.com/glyph/Automat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm7>0:devel/py-setuptools_scm7@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

# Officially: 2.7, 3.5-3.8
USES=		python
USE_PYTHON=	autoplist concurrent distutils

# Note: We cannot include devel/py-twisted in *_DEPENDS because it depends
# on us for BUILD and RUN.

NO_ARCH=	yes

.include <bsd.port.mk>
