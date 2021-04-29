# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	brotli
PORTVERSION=	1.0.9
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Brotli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++0x python:3.6+ shebangfix zip
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	python/bro.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_brotli*.so

.include <bsd.port.mk>
