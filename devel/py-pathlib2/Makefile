PORTNAME=	pathlib2
PORTVERSION=	2.3.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Object-oriented filesystem paths

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} test_pathlib2.py && \
		${PYTHON_CMD} test_pathlib2_with_py2_unicode_literals.py)

.include <bsd.port.mk>
