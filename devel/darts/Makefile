PORTNAME=	darts
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/darts/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ template library that implements Double-Array
WWW=		http://www.chasen.org/~taku/software/darts/

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LGPL

USES=		autoreconf

GNU_CONFIGURE=	yes

PLIST_FILES=	include/darts.h \
		libexec/darts/darts \
		libexec/darts/mkdarts
PORTDOCS=	AUTHORS ChangeLog README doc
PORTEXAMPLES=	darts.cpp mkdarts.cpp

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=  -Dregister=
.endif

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
