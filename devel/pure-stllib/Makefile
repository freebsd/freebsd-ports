# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-stllib
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL map and vectors

LICENSE=	BSD3CLAUSE

USES=		pkgconfig pure

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.pdf

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS ?=|' \
		${WRKSRC}/Makefile ${WRKSRC}/pure-stlmap/Makefile ${WRKSRC}/pure-stlvec/Makefile
	@${MKDIR} ${WRKSRC}/examples/
	@${MV} ${WRKSRC}/pure-stlmap/examples/* \
		${WRKSRC}/pure-stlvec/examples/* ${WRKSRC}/examples/

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
