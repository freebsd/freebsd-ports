# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yabause
PORTVERSION=	0.9.14
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Saturn system emulator

LICENSE=	GPLv2+

USES=		cmake dos2unix openal:soft pkgconfig
DOS2UNIX_FILES=	src/qt/YabauseThread.cpp
USE_XORG=	xmu xrandr
USE_GL=		gl glu glut

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		SDL2
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4 QT5
OPTIONS_DEFAULT=	QT4

GTK2_LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
GTK2_USE=		gnome=gtk20
GTK2_CMAKE_ON=		-DYAB_PORTS:STRING=gtk
GTK2_CMAKE_OFF=		-DYAB_PORTS:STRING=qt
QT4_USE=		qt4=corelib,gui,opengl \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CMAKE_ON=		-DQt5_FOUND:BOOL=OFF
QT5_USE=		qt5=core,gui,opengl \
			qt5=buildtools_build,qmake_build
SDL2_DESC=		SDL2 libraries support
SDL2_USE=		sdl=sdl2
SDL2_USE_OFF=		sdl=sdl

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MSDL2)
	@${REINPLACE_CMD} -e \
		's|SDL2 |SDL | ; \
		 s|SDL2_|SDL_|' ${WRKSRC}/src/CMakeLists.txt
.endif

.include <bsd.port.mk>
