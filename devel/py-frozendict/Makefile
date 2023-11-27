PORTNAME=	frozendict
PORTVERSION=	2.3.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/Marco-Sulla/python-frozendict/releases/download/v${PORTVERSSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Immutable dictionary implementation for Python
WWW=		https://github.com/Marco-Sulla/python-frozendict

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

MAKE_ARGS=	custom_arg=c

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.pre.mk>

# There is no C implementation for Python 3.11+ yet.
# Check src/frozendict/c_src for details.
.if ${PYTHON_REL} >= 31100
MAKE_ENV+=	FROZENDICT_PURE_PY=1
.endif

.include <bsd.port.post.mk>
