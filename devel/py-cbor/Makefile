# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbor
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RFC 7049 - Concise Binary Object Representation

LICENSE=	APACHE20

USE_PYTHON=	autoplist concurrent distutils
USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cbor/_cbor.so

.include <bsd.port.mk>
