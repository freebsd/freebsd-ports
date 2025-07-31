PORTNAME=	burrtools
PORTVERSION=	0.6.3
PORTREVISION=	30
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Puzzle solver
WWW=		https://burrtools.sourceforge.net/

LICENSE=	GPLv2+ # COPYING is GPLv3

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk

USES=		gl gmake localbase lua:51
USE_CXXSTD=	c++14
USE_GL=		gl glu

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_ICE_IceConnectionNumber="no" \
		ac_cv_search_glutInit="none required"
MAKE_ARGS=	am_lua_liblua_a_OBJECTS='lua/luaclass.$$(OBJEXT)'

LDFLAGS+=	-Wl,--as-needed # fltk deps
LIBS+=		-llua-${LUA_VER}

DESKTOP_ENTRIES="BurrGui" "" "burricons" "burrGui" "Game;LogicGame;" ""

PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrGui \
		share/pixmaps/burricons.png
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e '/GL_X_LIBS/d' ${WRKSRC}/configure
	${REINPLACE_CMD} -e \
		's|g++ |$$(CXX) | ; \
		 s|-O2 |$$(CXXFLAGS) $$(LDFLAGS) |' ${WRKSRC}/src/Makefile.in

post-build:
	(cd ${WRKSRC} && uudecode ${FILESDIR}/burricons.png.uu)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/burrTxt ${WRKSRC}/src/burrTxt2 \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/gui/burrGui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/burricons.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
