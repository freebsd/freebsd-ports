PORTNAME=	burr-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
base_COMMENT=	Puzzle solver (GUI)
python_COMMENT=	Puzzle solver (Python bindings)
COMMENT=	${FLAVOR}_COMMENT
WWW=		https://burrtools.sourceforge.net/

LICENSE=	GPLv2+ # COPYING is GPLv3

FLAVORS=	base python
FLAVOR?=	${FLAVORS:[1]}
python_PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

python_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pybind11.pc:devel/pybind11
BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${LOCALBASE}/share/pkgconfig/nlohmann_json.pc:devel/nlohmann-json
LIB_DEPENDS=	libpng.so:graphics/png \
		libfltk.so:x11-toolkits/fltk \
		libmanifold.so:math/manifold \
		libCatch2.so:devel/catch2

USES=		cmake:indirect compiler:c++20-lang gl localbase:ldflags \
		lua:51 meson pkgconfig
.if ${FLAVOR} == python
USES+=		python
.endif
USE_CXXSTD=	c++20
USE_GITHUB=	yes
USE_GL=		gl glu

# for std::stop_source, can be removed once we move to LLVM 20
CXXFLAGS+=	-fexperimental-library
.if ${FLAVOR} == python
MESON_ARGS+=	-Dpython=enabled
ALL_TARGET=	burrtools${PYTHON_SOABI}.so
.else
MESON_ARGS+=	-Dpython=disabled
.endif

.if ${FLAVOR} == base
DESKTOP_ENTRIES=	"Burr Tools" "" "burricons" "burrtools" "Game;LogicGame;" ""
OPTIONS_DEFINE=	EXAMPLES
PORTEXAMPLES=	*
.endif

PLIST_FILES=	${${FLAVOR}_PLIST_FILES}
base_PLIST_FILES=	bin/burrTxt bin/burrTxt2 bin/burrtools \
			share/pixmaps/burricons.png
python_PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR}/burrtools/burrtools${PYTHON_SOABI}.so

# delete bundled lua 5.1
post-extract:
	${GREP} -L 'Burr Solver' ${WRKSRC}/src/lua/* | ${XARGS} ${RM}
	${RM} ${WRKSRC}/subprojects/*.wrap

pre-configure:
	${REINPLACE_CMD} -e 's/%%PKGVERSION%%/${PKGVERSION}/' \
		-e 's/%%PYTHON_VERSION%%/${PYTHON_VERSION}/' ${WRKSRC}/meson.build

post-build:
	(cd ${WRKSRC} && uudecode ${FILESDIR}/burricons.png.uu)

do-install:
.if ${FLAVOR} == base
	(cd ${INSTALL_WRKSRC} && ${INSTALL_PROGRAM} burrTxt burrTxt2 burrtools \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/burricons.png ${STAGEDIR}${PREFIX}/share/pixmaps
.else
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/burrtools
	${INSTALL_LIB} ${INSTALL_WRKSRC}/burrtools${PYTHON_SOABI}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/burrtools/
.endif

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
