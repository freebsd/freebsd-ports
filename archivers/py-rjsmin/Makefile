PORTNAME=	rjsmin
PORTVERSION=	1.2.5
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Fast javascript minifier for Python
WWW=		https://github.com/ndparker/rjsmin

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/_rjsmin.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
