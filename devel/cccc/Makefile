# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cccc
PORTVERSION=	3.1.4
PORTREVISION=	2
CATEGORIES=	devel textproc www
MASTER_SITES=	SF

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	C and C++ Code Counter

LICENSE=	GPLv2+

USES=		gmake
MAKEFILE=	makefile
MAKE_ENV=	CCC="${CXX}" LD="${CXX}" CFLAGS_DEBUG="${CXXFLAGS}"
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	readme.txt changes.txt
PLIST_FILES=	bin/cccc

OPTIONS_DEFINE=	DOCS DEBUG

DEBUG_MAKE_ENV=	DEBUG="true"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^all/s|install|| ; \
		 s| make| $$(MAKE)| ; \
		 s|su root -c|| ; \
		 s|"make|"$$(MAKE)|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|^CCC=|CCC?=| ; \
		s|^CFLAGS=|CFLAGS+=| ; \
		s|^LD=|LD?=|' ${WRKSRC}/cccc/posixgcc.mak
	@${REINPLACE_CMD} -e \
		's| make| $$(MAKE)|' ${WRKSRC}/pccts/makefile
.for i in antlr dlg
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS= -O |CFLAGS +=|' ${WRKSRC}/pccts/${i}/makefile
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cccc/cccc ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
