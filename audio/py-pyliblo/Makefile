# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyliblo
DISTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the Liblo OSC Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblo.so:audio/liblo

USES=		localbase python
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/liblo.so

.include <bsd.port.mk>
