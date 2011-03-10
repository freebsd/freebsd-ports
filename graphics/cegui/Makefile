# New ports collection makefile for:	cegui
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cegui
PORTVERSION=	0.7.5
CATEGORIES=	graphics devel
MASTER_SITES=	SF/crayzedsgui/CEGUI%20Mk-2/0.7.5
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		pcre.0:${PORTSDIR}/devel/pcre \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.2:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.2:${PORTSDIR}/graphics/ogre3d

WRKSRC=		${WRKDIR}/${DISTNAME:S/2b/2/}
CONFIGURE_ARGS=	--disable-toluacegui --disable-irrlicht-renderer \
		--disable-corona --enable-devil --disable-freeimage --disable-silly \
		--disable-libxml --disable-xerces-c --disable-expat --disable-samples

CONFIGURE_ENV+=	Lua_LIBS="-L${LUA_LIBDIR} -llua -lm" \
		Lua_CFLAGS="-I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GL=		yes
USE_LUA=	5.1
LUA_COMPS=	toluaxx
USE_PYTHON=	2.6+
USE_GNOME=	gnomehack
PLIST_SUB+=	WITH_OGRE=""

.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING
.endif

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|"-lILU.*"|"-lm -L${LOCALBASE}/lib -lILU -lIL $$LIBS"|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|CEGUI_LUA_VER=..|CEGUI_LUA_VER=${USE_LUA:S/.//}|g; \
		s|DevIL_CFLAGS=.*|DevIL_CFLAGS="-DUSE_DEVIL_LIBRARY -I${LOCALBASE}/include"|g; \
		s|-release $$cegui_lib_version_suffix|-release ${PORTVERSION:C/\.[0-9]$//g} -version-number ${PORTVERSION:C/^[0-9]\.[0-9]\.//g}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS = tolua\+\+|SUBDIRS =|g' \
		${WRKSRC}/cegui/include/ScriptingModules/LuaScriptModule/support/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
