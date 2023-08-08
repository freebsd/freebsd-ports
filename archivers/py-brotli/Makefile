PORTNAME=	brotli
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Brotli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm
WWW=		https://github.com/google/brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli>=${PORTVERSION}:archivers/brotli
LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli

USES=		compiler:c++0x cpe pkgconfig python shebangfix zip
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	google

SHEBANG_FILES=	python/bro.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py
	@${MKDIR} ${WRKSRC}/common/
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/c/

pre-configure:
	@${PRINTF} "#define BROTLI_VERSION 0x%x%03x%03x\n" `pkgconf --modversion libbrotlicommon | sed 's|\.| |g'` > ${WRKSRC}/common/version.h

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
