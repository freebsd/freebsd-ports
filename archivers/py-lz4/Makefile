# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	0.7.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python binding for the LZ4 compression library

LICENSE=	BSD3CLAUSE

USE_PYTHON=	autoplist distutils
USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lz4.so

.include <bsd.port.mk>
