# Created by: HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
# $FreeBSD$

PORTNAME=	fceux
PORTVERSION=	2.2.3
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	SF/fceultra/Source%20Code/${PORTVERSION}%20src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable NES/Famicom emulator based on Bero's original FCE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zenity:x11/zenity

USES=		compiler:c++0x desktop-file-utils dos2unix localbase:ldflags \
		pkgconfig scons sdl xorg
USE_SDL=	sdl
USE_XORG=	x11
USE_GNOME+=	gdkpixbuf2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

OPTIONS_DEFINE=		CREATE_AVI DEBUG DOCS FRAMESKIP LOGO LUA OPENGL
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 GTK3
OPTIONS_DEFAULT=	CREATE_AVI FRAMESKIP GTK2 LOGO LUA OPENGL

CREATE_AVI_DESC=	Enable avi creation support
CREATE_AVI_MAKE_ARGS=	CREATE_AVI=1
CREATE_AVI_MAKE_ARGS_OFF=	CREATE_AVI=0
DEBUG_MAKE_ARGS=	DEBUG=1
DEBUG_MAKE_ARGS_OFF=	DEBUG=0
FRAMESKIP_DESC=		Enable frameskipping
FRAMESKIP_MAKE_ARGS=	FRAMESKIP=1
FRAMESKIP_MAKE_ARGS_OFF=	FRAMESKIP=0
GTK2_USES=		gnome
GTK2_USE=		GNOME=gtk20
GTK2_MAKE_ARGS=		GTK=1
GTK2_MAKE_ARGS_OFF=	GTK=0
GTK3_USES=		gnome
GTK3_USE=		GNOME=gtk30
GTK3_MAKE_ARGS=		GTK3=1
GTK3_MAKE_ARGS_OFF=	GTK3=0
LOGO_DESC=		Enable a logoscreen when creating avis
LOGO_LIB_DEPENDS=	libgd.so:graphics/gd
LOGO_MAKE_ARGS=		LOGO=1
LOGO_MAKE_ARGS_OFF=	LOGO=0
LOGO_IMPLIES=		CREATE_AVI
LUA_USES=		lua:51
LUA_MAKE_ARGS=		LUA=1 SYSTEM_LUA=1
LUA_MAKE_ARGS_OFF=	LUA=0
OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_MAKE_ARGS=	OPENGL=1
OPENGL_MAKE_ARGS_OFF=	OPENGL=0

post-patch:
	@${REINPLACE_CMD} -e \
		'/PUBLIC/s|^|#| ; \
		 /CheckLib/s|lua5.1|lua-${LUA_VER}| ; \
		 /LINKFLAGS/s|lua5.1|lua-${LUA_VER}| ; \
		 s|"-ldl"|| ; \
		 s|/usr/include/lua5.1|${LUA_INCDIR}| ; \
		 s|-O2||' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		's|/usr/bin/|| ; \
		 s|/usr/share/|${PREFIX}/share/|' ${WRKSRC}/fceux.desktop

do-install:
.for i in fceux fceux-net-server
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/documentation/${i}.6 ${STAGEDIR}${MANPREFIX}/man/man6
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/*.lua ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/output && ${COPYTREE_SHARE} "luaScripts palettes tools" \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@(cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} "TODO-PROJECT Videolog.txt \
		cheat.html faq fcs.txt fm2.txt protocol.txt snes9x-lua.html tech" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
