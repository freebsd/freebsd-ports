PORTNAME=	bx-python
DISTVERSION=	0.13.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets
WWW=		https://github.com/bxlab/bx-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>0:lang/cython3@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler python
USE_PYTHON=	distutils autoplist

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bx -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
