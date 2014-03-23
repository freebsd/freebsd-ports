# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cegui
PORTVERSION=	0.8.3
CATEGORIES=	graphics devel
MASTER_SITES=	SF/crayzedsgui/CEGUI%20Mk-2/0.8

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		pcre.3:${PORTSDIR}/devel/pcre \
		freetype.9:${PORTSDIR}/print/freetype2 \
		execinfo:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.9.0:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.9.0:${PORTSDIR}/graphics/ogre3d

WRKSRC=		${WRKDIR}/${DISTNAME:S/2b/2/}
CXXFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
## VERRIFY IF STILL NEEDED INCL. PATCH if CPPFLAGS IS SET AS ABOVE
CMAKE_ENV+=	TOLUA_INC="${LUA_INCDIR}"
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GL=		gl glew
USE_LUA=	5.1
LUA_COMPS=	toluaxx
USE_PYTHON=	2.6+
USES=		cmake pathfix pkgconfig compiler:c++11-lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README COPYING
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$${CEGUI_LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
