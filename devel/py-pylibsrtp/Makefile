PORTNAME=	pylibsrtp
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python wrapper around libsrtp
WWW=		https://github.com/aiortc/pylibsrtp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
