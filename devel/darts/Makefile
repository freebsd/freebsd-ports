# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	darts
PORTVERSION=	0.32
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/darts/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ template library that implements Double-Array

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LGPL

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTEXAMPLES=	darts.cpp mkdarts.cpp
PORTDOCS=	AUTHORS ChangeLog README doc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.mk>
