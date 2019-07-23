# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	lzma
PORTVERSION=	0.4.9
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python binding for the LZMA compression library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64
USES=		dos2unix python
USE_PYTHON=	concurrent distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	USAGE.md

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/pylzma.so

.include <bsd.port.mk>
