PORTNAME=	pymongo
PORTVERSION=	3.12.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python driver for MongoDB

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py[0-9][0-9]-pymongo28

post-install:
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bson/_cbson${PYTHON_EXT_SUFFIX}.so
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pymongo/_cmessage${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
