# $FreeBSD$

PORTNAME=	aiortc
PORTVERSION=	0.9.15
CATEGORIES=	devel multimedia python www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	WebRTC and ORTC in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopus.so:audio/opus \
		libvpx.so:multimedia/libvpx
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}aioice>=0.6.7:devel/py-aioice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}av>=6.1.0:multimedia/py-av@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>0:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyee>0:devel/py-pyee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylibsrtp>=0.5.6:devel/py-pylibsrtp@${PY_FLAVOR}

USES=		localbase python:3.5+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
