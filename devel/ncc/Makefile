# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ncc
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program analysis tool and call-graph navigator

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

ALL_TARGET=	# empty
MAKE_ARGS+=	CC="${CXX}" LCFLAGS="${CFLAGS}"
USES=		ncurses python:run
CFLAGS+=	-DNOGNU='\"${PREFIX}/include/ncc/nognu\"' -fpermissive

PLIST_FILES=	bin/ncc bin/nccnav bin/nccnavi bin/ncc-gengraph.py \
		${LINKS:S+^+bin/+} include/ncc/nognu bin/nccstrip2.py \
		man/man1/ncc.1.gz
PORTDOCS=	*

LINKS=		nccar nccld nccc++ nccg++

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
.for i in ${LINKS}
	${LN} -sf ${PREFIX}/bin/ncc ${STAGEDIR}${PREFIX}/bin/$i
.endfor
	${LN} -sf ${PREFIX}/bin/nccnav ${STAGEDIR}${PREFIX}/bin/nccnavi
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ncc
	${INSTALL_DATA}	${WRKSRC}/doc/nognu ${STAGEDIR}${PREFIX}/include/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
