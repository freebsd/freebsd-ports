# New ports collection makefile for:	xmms-nebulus
# Date created:				3 Oct 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-nebulus
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://nebulus.tuxfamily.org/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS visualization plugin that uses SDL and OpenGL

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libnebulus.so
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOME=	gtk12
USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include"

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
MAKE_ENV+=	SDL_CONFIG=${SDL_CONFIG}

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|SDL/SDL.h|SDL11/SDL.h|; \
		s|SDL/SDL_opengl.h|SDL11/SDL_opengl.h|; \
		s|SDL/SDL_thread.h|SDL11/SDL_thread.h|' \
		${WRKSRC}/src/nebulus.h \
		${WRKSRC}/src/nebulus.c \
		${WRKSRC}/src/face_data.c \
		${WRKSRC}/src/child_data.c \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -e \
		's|-Wall||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
