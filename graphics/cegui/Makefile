# New ports collection makefile for:	cegui
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cegui
PORTVERSION=	0.6.2b
CATEGORIES=	graphics devel
MASTER_SITES=	SF/crayzedsgui/CEGUI%20Mk-2/0.6.2
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		pcre.0:${PORTSDIR}/devel/pcre \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${DISTNAME:S/2b/2/}
CONFIGURE_ARGS=	--enable-toluacegui --disable-irrlicht-renderer \
		--disable-corona --enable-devil --disable-freeimage --disable-silly \
		--disable-libxml --disable-xerces-c --disable-expat

CONFIGURE_ENV+=	Lua_LIBS="-L${LUA_LIBDIR} -llua -lm" \
		Lua_CFLAGS="-I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GL=		yes
USE_LUA=	5.1
USE_GNOME=	gnomehack

.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING AUTHORS ChangeLog TODO
.endif

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|"-lILU.*"|"-lm -L${LOCALBASE}/lib -lILU -lIL $$LIBS"|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|CEGUI_LUA_VER=..|CEGUI_LUA_VER=${USE_LUA:S/.//}|g; \
		s|DevIL_CFLAGS=.*|DevIL_CFLAGS="-DUSE_DEVIL_LIBRARY -I${LOCALBASE}/include"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SUBDIRS/ s| Samples||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|__linux__)|& \|\| defined(__FreeBSD__)|g' \
		${WRKSRC}/include/CEGUIDynamicModule.h \
		${WRKSRC}/src/CEGUIDynamicModule.cpp \
		${WRKSRC}/Samples/common/src/CEGuiSample.cpp \
		${WRKSRC}/src/CEGUISystem.cpp
	@${REINPLACE_CMD} -e 's|ILvoid|void|g' \
		${WRKSRC}/ImageCodecModules/DevILImageCodec/CEGUIDevILImageCodec.cpp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
