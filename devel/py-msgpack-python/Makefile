# Created by: Andrey Zonov <andrey@zonov.org>
# $FreeBSD$

PORTNAME=	msgpack-python
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	MessagePack (de)serializer for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/msgpack/_packer.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/msgpack/_unpacker.so

.include <bsd.port.mk>
