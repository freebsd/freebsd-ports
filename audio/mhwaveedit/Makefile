# ex:ts=8
# Ports collection makefile for:	mhWaveEdit
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mhwaveedit
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mtek.chalmers.se/~hjormagn/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A graphical program for editing sound files

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-portaudio --disable-gtk2

.if defined(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CFLAGS =.*$$|CFLAGS = \@CFLAGS\@|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mhwaveedit ${PREFIX}/bin

.include <bsd.port.mk>
