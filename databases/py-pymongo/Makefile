PORTNAME=	pymongo
PORTVERSION=	3.13.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python driver for MongoDB
WWW=		https://github.com/mongodb/mongo-python-driver

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py[0-9][0-9]-pymongo28

post-install:
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bson/_cbson${PYTHON_TAG}.so
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pymongo/_cmessage${PYTHON_TAG}.so

.include <bsd.port.mk>
