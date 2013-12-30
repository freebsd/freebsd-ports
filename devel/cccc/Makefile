# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cccc
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	devel textproc www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C and C++ Code Counter

LICENSE=	GPLv2 # (or later)

USES=		gmake
MAKEFILE=	makefile
MAKE_ENV=	CCC="${CXX}" LD="${CXX}" CFLAGS_DEBUG="${CXXFLAGS}"
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	readme.txt changes.txt
PLIST_FILES=	bin/cccc

post-patch:
	@${REINPLACE_CMD} -e \
		'/^all/s|install|| ; \
		 s| make| $$(MAKE)| ; \
		 s|su root -c|| ; \
		 s|"make|"$$(MAKE)|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|^CCC=|CCC?=| ; \
		 s|^LD=|LD?=|' ${WRKSRC}/cccc/posixgcc.mak
	@${REINPLACE_CMD} -e \
		's| make| $$(MAKE)|' ${WRKSRC}/pccts/makefile
.for i in antlr dlg
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS= -O |CFLAGS +=|' ${WRKSRC}/pccts/${i}/makefile
.endfor

do-install:
	(cd ${WRKSRC}/cccc && ${INSTALL_PROGRAM} cccc ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
