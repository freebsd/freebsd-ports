# New ports collection makefile for:	cegui
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cegui
PORTVERSION=	0.5.0b
PORTREVISION=	0
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=crayzedsgui
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.1:${PORTSDIR}/graphics/devil \
		pcre.0:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/${DISTNAME:S/0b/0/}
CONFIGURE_ARGS=	--without-xerces-c --enable-toluacegui
CONFIGURE_ENV+=	Lua_LIBS="-L${PREFIX}/lib/lua50 -llua -llualib -lm" \
		Lua_CFLAGS="-I${PREFIX}/include/lua50"
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GL=		YES
USE_LUA=	5.0
USE_XLIB=	YES
USE_GNOME=	gnomehack

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|"-lILU.*"|"-lm -L${LOCALBASE}/lib -lILU -lIL $$LIBS"|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|DevIL_CFLAGS=.*|DevIL_CFLAGS="-DUSE_DEVIL_LIBRARY -I${LOCALBASE}/include"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SUBDIRS/ s| Samples||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|__linux__)|& \|\| defined(__FreeBSD__)|g' \
		${WRKSRC}/include/CEGUIDynamicModule.h \
		${WRKSRC}/src/CEGUIDynamicModule.cpp
	@${REINPLACE_CMD} -e 's|(linux)|& \|\| defined(__FreeBSD__)|g' \
		${WRKSRC}/Samples/common/src/CEGuiSample.cpp
	@${REINPLACE_CMD} -e 's|INCLUDES = |&-I${LOCALBASE}/include/lua50 |' \
		${WRKSRC}/ScriptingModules/CEGUILua/tolua++bin/Makefile.in \
		${WRKSRC}/ScriptingModules/CEGUILua/LuaScriptModule/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
