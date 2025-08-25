PORTNAME=	bx-python
DISTVERSION=	0.14.0
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
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}

USES=		compiler python
USE_PYTHON=	pep517 cython3 autoplist

post-patch:
	# force cythonization, compilation fails otherwise for some reason
	@${TOUCH} `${FIND} ${WRKSRC} -name "*.pyx" -o -name "*.pxd"`

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bx -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
