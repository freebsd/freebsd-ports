PORTNAME=	Automat
DISTVERSION=	25.4.16
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	john@saltant.com
COMMENT=	Finite-state machines in Python
WWW=		https://github.com/glyph/Automat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=35.0.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}

# Officially: 3.9-3.13
USES=		python
USE_PYTHON=	autoplist concurrent pep517

# Note: We cannot include devel/py-twisted in *_DEPENDS because it depends
# on us for BUILD and RUN.

NO_ARCH=	yes

.include <bsd.port.mk>
