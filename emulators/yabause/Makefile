# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yabause
PORTVERSION=	0.9.13.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Saturn system emulator

LICENSE=	GPLv2 # (or later)

USES=		cmake openal:soft pkgconfig
USE_XORG=	xmu xrandr
USE_GL=		gl glu glut
USE_SDL=	sdl

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	QT4

GTK2_LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
GTK2_USE=		gnome=gtk20
GTK2_CMAKE_ON=		-DYAB_PORTS:STRING=gtk
QT4_USE=		qt4=corelib,gui,opengl \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CMAKE_ON=		-DYAB_PORTS:STRING=qt

.include <bsd.port.mk>
