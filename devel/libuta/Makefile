# New ports collection makefile for:	libuta
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	libuta
PORTVERSION=	0.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		SDL-1.1.4:${PORTSDIR}/devel/sdl12

USE_FREETYPE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config" \
		LIBS="-L${LOCALBASE}/lib"

SDL11_FILES=	configure uta/color.h uta/event.h uta/keysym.h uta/mutex.h \
		uta/pixelformat.h uta/rect.h uta/sge_blib.cc uta/sge_blib.h \
		uta/sge_draw.cc uta/sge_draw.h uta/sound.h uta/surface_io.cc \
		uta/surface.h uta/timer.cc

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libSDL_mixer.so.2)
WITH_SDL_MIXER=	yes
.endif

.if defined(WITH_SDL_MIXER)
LIB_DEPENDS+=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer
.endif


pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_SDL_MIXER=yes   Enable music and sound support"
	@${ECHO} ""

post-patch:
.for i in ${SDL11_FILES}
	${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/$i
.endfor

pre-configure:
	${REINPLACE_CMD} -e 's|<freetype/freetype.h>|<freetype1/freetype/freetype.h>|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
