# Created by: Hye-Shik Chang

PORTNAME=	lzma
PORTVERSION=	0.5.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python binding for the LZMA compression library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le
USES=		dos2unix python:3.6+
USE_PYTHON=	concurrent distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	USAGE.md

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/pylzma*.so

.include <bsd.port.mk>
