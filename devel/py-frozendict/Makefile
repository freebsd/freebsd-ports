PORTNAME=	frozendict
PORTVERSION=	2.4.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/Marco-Sulla/python-frozendict/releases/download/v${PORTVERSSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Immutable dictionary implementation for Python
WWW=		https://github.com/Marco-Sulla/python-frozendict

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31100
NO_ARCH=	yes
.else
MAKE_ARGS=	custom_arg=c

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +
.endif

.include <bsd.port.post.mk>
