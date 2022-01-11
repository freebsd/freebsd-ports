# Created by: Richard Gallamore <ultima@FreeBSD.org>

PORTNAME=	rjsmin
PORTVERSION=	1.2.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Fast javascript minifier for Python

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/_rjsmin.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
