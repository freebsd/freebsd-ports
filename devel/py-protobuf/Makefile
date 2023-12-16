PORTNAME=	protobuf
PORTVERSION=	4.25.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf \
		https://github.com/protocolbuffers/protobuf/tree/main/python

LICENSE=	BSD3CLAUSE

USES=		cpe python
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	google

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
