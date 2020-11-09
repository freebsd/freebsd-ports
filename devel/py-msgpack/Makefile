# Created by: Andrey Zonov <andrey@zonov.org>
# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MessagePack (de)serializer for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/msgpack/_cmsgpack.so
.endif

.include <bsd.port.post.mk>
