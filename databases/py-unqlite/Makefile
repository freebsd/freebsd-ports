PORTNAME=	unqlite
PORTVERSION=	0.9.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fast Python bindings for the UnQLite embedded NoSQL database
WWW=		https://github.com/coleifer/unqlite-python

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist cython

post-stage:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/unqlite*.so

.include <bsd.port.mk>
