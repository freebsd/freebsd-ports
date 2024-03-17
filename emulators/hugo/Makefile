PORTNAME=	hugo
PORTVERSION=	2.12
PORTREVISION=	18
CATEGORIES=	emulators
MASTER_SITES=	http://www.zeograd.com/download/ \
		http://www.sourcefiles.org/Emulators/Videogames/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PC Engine (TurboGrafx 16) emulator
WWW=		https://www.zeograd.com/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

DEPRECATED=	Unmaintained, last release in 2005 and uses deprecated gtk2 library
EXPIRATION_DATE=2024-04-17

LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		gmake localbase:ldflags pkgconfig sdl
USE_CSTD=	gnu89
USE_SDL=	sdl

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-return-type

CONFLICTS_INSTALL=	gohugo

OPTIONS_DEFINE=	GTK2 DOCS NETPLAY SDL_MIXER
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes

NETPLAY_DESC=	Netplay support
SDL_MIXER_DESC=	SDL_mixer support

GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
GTK2_USES=	gnome
GTK2_USE=	GNOME=gtk20 cairo gdkpixbuf2
GTK2_CONFIGURE_OFF=	--disable-gui --disable-gtktest
NETPLAY_IMPLIES=	GTK2
NETPLAY_USE=	SDL=net
NETPLAY_CONFIGURE_ENV_OFF=	ac_cv_lib_SDL_net_main=no
SDL_MIXER_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
SDL_MIXER_USE=	SDL=mixer
SDL_MIXER_CONFIGURE_ENV_OFF=	ac_cv_lib_SDL_mixer_main=no \
		ac_cv_lib_vorbis_main=no \
		ac_cv_lib_vorbisfile_main=no
SDL_MIXER_CFLAGS=	-DOGG_SUPPORT

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.if ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 )
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif
.endif

.include <bsd.port.post.mk>
