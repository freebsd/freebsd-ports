# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-crc32c
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper of the C library Google CRC32C

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libcrc32c.so:devel/crc32c
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/google_crc32c/_crc32c_cffi*.so

.include <bsd.port.mk>
