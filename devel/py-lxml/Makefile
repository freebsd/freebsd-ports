# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	lxml
PORTVERSION=	4.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/licenses/BSD.txt

USES=		gnome python uniquefiles:dirs
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist concurrent distutils

LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib

DOCS_FILES=	CHANGES.txt CREDITS.txt TODO.txt README.rst
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
	-name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
