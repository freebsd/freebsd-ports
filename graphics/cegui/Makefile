# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cegui
PORTVERSION=	0.7.9
#PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/crayzedsgui/CEGUI%20Mk-2/${PORTVERSION}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		pcre.3:${PORTSDIR}/devel/pcre \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d

WRKSRC=		${WRKDIR}/${DISTNAME:S/2b/2/}
CONFIGURE_ARGS=	--disable-toluacegui --disable-irrlicht-renderer \
		--disable-corona --enable-devil --disable-freeimage --disable-silly \
		--disable-libxml --disable-xerces-c --disable-expat --disable-samples \
		--enable-null-renderer --disable-external-tinyxml

CONFIGURE_ENV+=	Lua_LIBS="-L${LUA_LIBDIR} -llua -lm" \
		Lua_CFLAGS="-I${LUA_INCDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GL=		yes
USE_LUA=	5.1
LUA_COMPS=	toluaxx
USE_PYTHON=	yes
USES=		pathfix pkgconfig
PLIST_SUB+=	WITH_OGRE=""

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README COPYING
.endif

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|"-lILU.*"|"-lm -L${LOCALBASE}/lib -lILU -lIL $$LIBS"|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|CEGUI_LUA_VER=..|CEGUI_LUA_VER=${USE_LUA:S/.//}|g; \
		s|DevIL_CFLAGS=.*|DevIL_CFLAGS="-DUSE_DEVIL_LIBRARY -I${LOCALBASE}/include"|g; \
		s|-release $$cegui_lib_version_suffix|& -version-number 0|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS = tolua\+\+|SUBDIRS =|g' \
		${WRKSRC}/cegui/include/ScriptingModules/LuaScriptModule/support/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
