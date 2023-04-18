PORTNAME=	websockets
PORTVERSION=	11.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455 and 7692)
WWW=		https://pypi.org/project/websockets/

LICENSE=	BSD3CLAUSE

USES=		cpe python:3.7+
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/websockets/speedups*.so

.include <bsd.port.mk>
