# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cccc
DISTVERSION=	3.1.5
CATEGORIES=	devel textproc www

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	C and C++ Code Counter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/cccc/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sarnold

PORTSCOUT=	limit:^[0-9].*$$

MAKEFILE=	makefile
MAKE_ENV=	CCC="${CXX}" LD="${CXX}" CFLAGS_DEBUG="${CXXFLAGS}"
ALL_TARGET=	cccc
MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	README.md CHANGELOG.md
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
