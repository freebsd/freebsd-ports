# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brotli
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Brotli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	autoplist concurrent distutils
USES=		compiler:c++0x python zip

PLIST_FILES=	bin/brotli

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/python/bro.py ${STAGEDIR}${PREFIX}/bin/brotli
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/brotli.so

.include <bsd.port.mk>
