PORTNAME=	Automat
DISTVERSION=	24.8.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	john@saltant.com
COMMENT=	Finite-state machines in Python
WWW=		https://github.com/glyph/Automat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm7>0:devel/py-setuptools_scm7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=35.0.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR}

# Officially: 3.8-3.12
USES=		python
USE_PYTHON=	autoplist concurrent pep517

# Note: We cannot include devel/py-twisted in *_DEPENDS because it depends
# on us for BUILD and RUN.

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
