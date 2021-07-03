PORTNAME=	pink-pony
PORTVERSION=	1.4.1
PORTREVISION=	32
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tron-like multiplayer racing game

LICENSE=	GPLv3+

LIB_DEPENDS=	libIL.so:graphics/devil \
		libprotobuf.so:devel/protobuf \
		libglfw.so.0:graphics/glfw2 \
		libftgl.so:graphics/ftgl \
		libsigc-2.0.so:devel/libsigc++20 \
		libImath.so:math/Imath

USE_GITHUB=	yes
GH_ACCOUNT=	ginkgo

USES=		pkgconfig scons compiler:c++11-lang gl sdl
USE_CXXSTD=	c++11
USE_GL=		gl glu
USE_SDL=	mixer
SUB_FILES=	pink-pony.sh

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -Ee 's,resources/,${DATADIR}/,' \
		${WRKSRC}/pony.options ${WRKSRC}/src/Config.cc
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/install/pink-pony.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pony ${STAGEDIR}${PREFIX}/libexec/
	cd ${WRKSRC}/resources && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pony.options ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/pink-pony.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.desktop ${STAGEDIR}${PREFIX}/share/applications/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
