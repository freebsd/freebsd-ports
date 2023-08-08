PORTNAME=	pyrsistent
PORTVERSION=	0.18.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Persistent/Functional/Immutable data structures
WWW=		https://github.com/tobgu/pyrsistent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.mit

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0<7:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pvectorc*.so

.include <bsd.port.mk>
