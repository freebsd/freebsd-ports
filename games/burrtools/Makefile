# Created by: ijliao
# $FreeBSD$

PORTNAME=	burrtools
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle solver

LICENSE=	GPLv3

BUILD_DEPENDS=	netpbm>0:graphics/netpbm
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng.so:graphics/png \
		libxmlwrapp.so:textproc/xmlwrapp \
		libfltk.so:x11-toolkits/fltk

USES=		gmake
USE_XORG=	x11 xt xext xmu xi
USE_GL=		glu
USE_GCC=	yes # clang generates incorrect binaries: cause SIGILL
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lboost_system

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui \
		share/pixmaps/burricons.png

DESKTOP_ENTRIES="BurrGui" "" "${PREFIX}/pixmaps/burricons.png" "burrGui" "" ""

OPTIONS_DEFINE=		DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000024
LDFLAGS+=	-lc++
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++ |$$(CXX) | ; \
		 s|-O2 |$$(CXXFLAGS) |' ${WRKSRC}/src/Makefile.in

post-build:
	(cd ${WRKSRC} && ${CAT} burricons.ico | winicontoppm -bestqual | \
		pnmtopng -transparent=black > burricons.png)

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} burrTxt burrTxt2 \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/src/gui && ${INSTALL_PROGRAM} burrGui \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} burricons.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
