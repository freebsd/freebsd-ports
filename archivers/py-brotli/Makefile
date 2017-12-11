# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brotli
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	autoplist concurrent distutils
USES=		compiler:c++0x python shebangfix

PLIST_FILES=	bin/brotli

GH_ACCOUNT=	google
USE_GITHUB=	yes

SHEBANG_FILES=	python/bro.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/python/bro.py ${STAGEDIR}${PREFIX}/bin/brotli
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_brotli.so

.include <bsd.port.mk>
