# Created by: ijliao
# $FreeBSD$

PORTNAME=	burrtools
PORTVERSION=	0.6.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle solver

LICENSE=	GPLv3

BUILD_DEPENDS=	netpbm>0:graphics/netpbm
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk

USES=		gmake localbase lua:51
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_ICE_IceConnectionNumber="no" \
		ac_cv_search_glutInit="none required"
CONFIGURE_ARGS=	--disable-silent-rules
MAKE_ARGS=	am_lua_liblua_a_OBJECTS='lua/luaclass.$$(OBJEXT)'

LDFLAGS+=	-Wl,--as-needed # fltk deps
LIBS+=		-llua-${LUA_VER} -lboost_system # _ZN5boost6system15system_categoryEv

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui \
		share/pixmaps/burricons.png

DESKTOP_ENTRIES="BurrGui" "" "burricons" "burrGui" "Game;LogicGame;" ""

OPTIONS_DEFINE=		DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/GL_X_LIBS/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|g++ |$$(CXX) | ; \
		 s|-O2 |$$(CXXFLAGS) $$(LDFLAGS) |' ${WRKSRC}/src/Makefile.in

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
