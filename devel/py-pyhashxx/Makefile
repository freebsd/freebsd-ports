PORTNAME=	pyhashxx
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for xxHash algorithm
WWW=		https://github.com/ewencp/pyhashxx

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -maxdepth 1 -name 'pyhashxx*.so' \
		-exec ${STRIP_CMD} {} +

pre-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_ext --inplace

.include <bsd.port.mk>
