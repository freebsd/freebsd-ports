# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	debugpy
PORTVERSION=	1.4.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the Debug Adapter Protocol for Python

LICENSE=	EPL MIT
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		dos2unix python:3.6+ zip
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
