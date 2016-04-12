# Created by: HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
# $FreeBSD$

PORTNAME=	fceux
PORTVERSION=	2.2.2
DISTVERSIONSUFFIX=	.src
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/fceultra/Source%20Code/${PORTVERSION}%20src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable NES/Famicom emulator based on Bero's original FCE

LICENSE=	GPLv2

RUN_DEPENDS=	zenity:x11/zenity

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++0x desktop-file-utils dos2unix pkgconfig scons
USE_SDL=	sdl

LDFLAGS+=	-L${LOCALBASE}/lib

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
GTK2_USE=		GNOME=gtk20
GTK2_MAKE_ARGS=		GTK=1
GTK2_MAKE_ARGS_OFF=	GTK=0
GTK3_USE=		GNOME=gtk30
GTK3_MAKE_ARGS=		GTK3=1
GTK3_MAKE_ARGS_OFF=	GTK3=0
LOGO_DESC=		Enable a logoscreen when creating avis
LOGO_LIB_DEPENDS=	libgd.so:graphics/gd
LOGO_MAKE_ARGS=		LOGO=1
LOGO_MAKE_ARG_OFF=	LOGO=0
LUA_USES=		lua:51
LUA_MAKE_ARGS=		LUA=1 SYSTEM_LUA=1
LUA_MAKE_ARGS_OFF=	LUA=0
OPENGL_USE=		GL=gl
OPENGL_MAKE_ARGS=	OPENGL=1
OPENGL_MAKE_ARGS_OFF=	OPENGL=0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOGO} && empty(PORT_OPTIONS:MCREATE_AVI)
IGNORE=		LOGO support requires CREATE_AVI support
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/PUBLIC/s|^|#| ; \
		 /CheckLib/s|lua5.1|lua-${LUA_VER}| ; \
		 /LINKFLAGS/s|"-ldl",|| ; \
		 /LINKFLAGS/s|lua5.1|lua-${LUA_VER}| ; \
		 s|/usr/include/lua5.1|${LUA_INCDIR}| ; \
		 s|-O2||' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		's|/usr/bin/|| ; \
		 s|/usr/share/|${PREFIX}/share/|' ${WRKSRC}/fceux.desktop

do-install:
.for i in fceux fceux-net-server
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/documentation && ${INSTALL_MAN} ${i}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/bin && ${INSTALL_DATA} *.lua \
		${STAGEDIR}${DATADIR})
.for i in luaScripts palettes tools
	@(cd ${WRKSRC}/output && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${DATADIR})
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} *.desktop \
		${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} *.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in TODO-PROJECT Videolog.txt cheat.html faq fcs.txt fm2.txt \
	protocol.txt snes9x-lua.html
	(cd ${WRKSRC}/documentation && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@(cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} tech \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
