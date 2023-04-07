PORTNAME=	msgpack
PORTVERSION=	1.0.5 # WARNING: archivers/py-borgbackup pins the full version
# so if upgrading msgpack, archivers/py-borgbackup will break. We need to
# coordinate updates.
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MessagePack (de)serializer for Python
WWW=		https://msgpack.org/ \
		https://github.com/msgpack/msgpack-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
