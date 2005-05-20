# New ports collection makefile for:	libuta
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	wftk
PORTVERSION=	0.7.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.worldforge.org/pub/worldforge/libs/wftk/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A Graphical User Interface library for C++

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

OPTIONS=	SDL_MIXER	"music and sound support"	off

USE_FREETYPE=	yes
USE_INC_LIBTOOL_VER=15
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack
USE_GCC=	3.4+

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"
CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE}

WANT_SDL=	yes

SDL11_FILES=	configure wftk/sge_blib.h wftk/sge_blib.cpp wftk/sge_draw.h \
		wftk/sge_draw.cpp wftk/rotozoom.h wftk/surface.cpp \
		wftk/surface_io.cpp wftk/screensurface.cpp wftk/timer.cpp \
		wftk/poll.cpp wftk/sdlhandler.cpp wftk/rootwindow.cpp \
		wftk/mouse.cpp wftk/joystick.cpp wftk/mixer.cpp wftk/color.h \
		wftk/rect.h wftk/region.h wftk/keysym.h wftk/pixelformat.h \
		wftk/surface.h wftk/refobj.h wftk/focus.h wftk/application.h \
		wftk/mouse.h wftk/joystick.h wftk/sound.h wftk/mixer.h \
		wftk/mutex.h wftk/timer.h wftk/poll.h wftk/sdlhandler.h

.include <bsd.port.pre.mk>

.if ${HAVE_SDL:Mmixer}!=""
WITH_SDL_MIXER=	yes
.endif

.if defined(WITH_SDL_MIXER)
USE_SDL+=	mixer
.endif

post-patch:
.for i in ${SDL11_FILES}
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/$i
.endfor

.include <bsd.port.post.mk>
