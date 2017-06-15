# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	lxml
PORTVERSION=	3.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/licenses/BSD.txt

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt

USES+=		python uniquefiles:dirs
USE_PYTHON=	autoplist concurrent distutils

LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib

DOCS_FILES=	CHANGES.txt CREDITS.txt TODO.txt README.rst
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DOCS_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
