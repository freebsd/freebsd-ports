# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	darts
PORTVERSION=	0.32
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/darts/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ template library that implements Double-Array

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES=	darts.cpp mkdarts.cpp
DOCS=		AUTHORS ChangeLog README doc

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.mk>
