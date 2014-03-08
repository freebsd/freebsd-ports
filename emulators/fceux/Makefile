# Created by: HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
# $FreeBSD$

PORTNAME=	fceux
PORTVERSION=	2.2.2
CATEGORIES=	emulators
MASTER_SITES=	SF/fceultra/Source%20Code/${PORTVERSION}%20src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable NES/Famicom emulator based on Bero's original FCE

LICENSE=	GPLv2

USES=		dos2unix pkgconfig scons
SCONS_BUILDENV=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
SCONS_ARGS+=	--prefix="${STAGEDIR}${PREFIX}"
USE_SDL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

RUN_DEPENDS+=	zenity:${PORTSDIR}/x11/zenity

OPTIONS_DEFINE=	FRAMESKIP OPENGL DEBUG LUA CREATE_AVI LOGO
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	GTK2 GTK3
OPTIONS_DEFAULT=	FRAMESKIP OPENGL LUA NEWPPU CREATE_AVI LOGO GTK2

FRAMESKIP_DESC=		Enable frameskipping
LUA_DESC=		Enable Lua support
CREATE_AVI_DESC=	Enable avi creation support (SDL)
LOGO_DESC=		Enable a logoscreen when creating avis (SDL)
GTK2_DESC=		Enable GTK2 GUI (SDL)
GTK3_DESC=		Enable GTK3 GUI (SDL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFRAMESKIP}
SCONS_ARGS+=	FRAMESKIP=1
.else
SCONS_ARGS+=	FRAMESKIP=0
.endif

.if ${PORT_OPTIONS:MGTK2}
SCONS_ARGS+=	GTK=1
USE_GNOME+=	gtk20
.else
SCONS_ARGS+=	GTK=0
.endif

.if ${PORT_OPTIONS:MGTK3}
SCONS_ARGS+=	GTK3=1
USE_GNOME+=	gtk30
.else
SCONS_ARGS+=	GTK3=0
.endif

.if ${PORT_OPTIONS:MLUA}
SCONS_ARGS+=	LUA=1 SYSTEM_LUA=1
USE_LUA=	yes
.else
SCONS_ARGS+=	LUA=0
.endif

.if ${PORT_OPTIONS:MLOGO}
SCONS_ARGS+=	LOGO=1 CREATE_AVI=1
LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd
.else
SCONS_ARG+=	LOGO=0
.endif

.if ${PORT_OPTIONS:MOPENGL}
SCONS_ARGS+=	OPENGL=1
USE_GL=		gl
.else
SCONS_ARGS+=	OPENGL=0
.endif

.if ${PORT_OPTIONS:MCREATE_AVI}
SCONS_ARGS+=	CREATE_AVI=1
.else
SCONS_ARGS+=	CREATE_AVI=0
.endif

.if ${PORT_OPTIONS:MDEBUG}
SCONS_ARGS+=	DEBUG=1
.else
SCONS_ARGS+=	DEBUG=0
.endif

# Go find a better compiler, base cc does not support mm3dnow.h,
# breaking the build:
#
# In file included from src/drivers/videolog/rgbtorgb.cpp:14:
# src/drivers/videolog/simd.h:13:56: error: mm3dnow.h: No such file or directory
#
# Use clang if in /usr/bin, else set USE_GCC:
#
.if (empty(CC:T:Mgcc4*) && empty(CC:T:Mclang*)) || (empty(CXX:T:Mg??4*) && empty(CXX:T:Mclang++*))
.if (${OSVERSION} >= 900014) && (exists(/usr/bin/clang++) && exists(/usr/bin/clang))
CC=		/usr/bin/clang
CXX=		/usr/bin/clang++
CPP=		/usr/bin/clang-cpp
.else
USE_GCC=	yes
.endif
.endif

post-extract:
	@${RM} ${WRKSRC}/output/*.dll ${WRKSRC}/output/*.chm

post-patch:
	${REINPLACE_CMD} -e 's|pkg-config|%%PKGCONFIG%%|g' \
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e 's|sdl-config|%%SDLCONFIG%%|g' \
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e 's|%%PKGCONFIG%%|${LOCALBASE}/bin/pkgconf|g' \
		-e 's|%%SDLCONFIG%%|${LOCALBASE}/bin/sdl-config|g' \
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e 's|usr|usr/local|g' ${WRKSRC}/fceux.desktop
	${REINPLACE_CMD} -e '107 s|Exit(1)|#Exit(1)|g' \
		${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e '194 s|/usr/local|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/SConstruct

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in TODO-PROJECT Videolog.txt cheat.html faq fcs.txt fm2.txt protocol.txt snes9x-lua.html
	@${CP} ${WRKSRC}/documentation/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MV} ${WRKSRC}/documentation/tech ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/fceux.desktop \
		${STAGEDIR}${PREFIX}/share/applications/fceux.desktop
	@${INSTALL_DATA} ${WRKSRC}/fceux.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/fceux.png
	@${INSTALL_MAN} ${WRKSRC}/documentation/fceux-net-server.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6
	@${INSTALL_MAN} ${WRKSRC}/documentation/fceux.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
