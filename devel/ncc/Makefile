PORTNAME=	ncc
PORTVERSION=	2.8
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program analysis tool and call-graph navigator

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

ALL_TARGET=	# empty
MAKE_ARGS=	CC="${CXX}" LCFLAGS="${CFLAGS}"
USES=		compiler ncurses python:run shebangfix
SHEBANG_FILES=	scripts/*.py
# build ignores CXXFLAGS
CFLAGS+=	-DNOGNU='\"${PREFIX}/include/ncc/nognu\"' -fpermissive \
		${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/NOGNU/d' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e '/#include <alloca.h>/d' ${WRKSRC}/dbstree.h
	@${REINPLACE_CMD} -e 's|-lncurses|$$(CFLAGS) $$(LDFLAGS) -lncurses|' \
		${WRKSRC}/nccnav/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/ncc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gengraph.py \
		${STAGEDIR}${PREFIX}/bin/ncc-gengraph.py
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/nccstrip2.py \
		${STAGEDIR}${PREFIX}/bin/nccstrip2.py
	${INSTALL_PROGRAM} ${WRKSRC}/nccnav/nccnav ${STAGEDIR}${PREFIX}/bin
.for i in nccar nccld nccc++ nccg++
	${LN} -sf ncc ${STAGEDIR}${PREFIX}/bin/$i
.endfor
	${LN} -sf nccnav ${STAGEDIR}${PREFIX}/bin/nccnavi
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ncc
	${INSTALL_DATA}	${WRKSRC}/doc/nognu ${STAGEDIR}${PREFIX}/include/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
