PORTNAME=	bsd
PORTVERSION=	1.0.20170329
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python wrappers for various BSD libc and system calls

LICENSE=	BSD3CLAUSE

BROKEN_FreeBSD_13=	does not build: use of undeclared identifier 'PS_FST_TYPE_CRYPTO'
BROKEN_FreeBSD_14=	does not build: use of undeclared identifier 'PS_FST_TYPE_CRYPTO'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils cython

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-bsd
GH_TAGNAME=	6d148fa

.include <bsd.port.mk>
