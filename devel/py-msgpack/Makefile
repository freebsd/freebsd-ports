# Created by: Andrey Zonov <andrey@zonov.org>

PORTNAME=	msgpack
PORTVERSION=	1.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MessagePack (de)serializer for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
