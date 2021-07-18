# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	brotlicffi
PORTVERSION=	1.0.9.2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python CFFI bindings to the Brotli library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python:3.6+
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	USE_SHARED_BROTLI=1

post-patch:
	@${RM} -fr ${WRKSRC}/libbrotli/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/brotlicffi/_brotlicffi*.so

.include <bsd.port.mk>
