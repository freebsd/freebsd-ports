# Created by: Stefan Sperling <stsp@stsp.in-berlin.de>
# $FreeBSD$

PORTNAME=	desmume
PORTVERSION=	0.9.11
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	Nintendo DS emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libSoundTouch.so:audio/soundtouch

USE_GL=		gl
USE_SDL=	sdl
USE_GNOME=	gtk20 intltool libglade2
USES=		autoreconf desktop-file-utils dos2unix gettext gmake pkgconfig
DOS2UNIX_FILES=	src/utils/task.cpp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt DATADIRNAME=share
CONFIGURE_ARGS=	--enable-glade

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -DGTKGLEXT_AVAILABLE \
		-DHAVE_LIBGDKGLEXT_X11_1_0 -DHAVE_GL_GL_H -DHAVE_GL_GLU_H
CXXFLAGS+=	${CFLAGS}

.include <bsd.port.mk>
