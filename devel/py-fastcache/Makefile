PORTNAME=	fastcache
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C implementation of Python 3 functools.lru_cache
WWW=		https://github.com/pbrady/fastcache

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fastcache/_lrucache*.so

.include <bsd.port.mk>
