# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	hugo
PORTVERSION=	2.12
PORTREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	http://www.zeograd.com/download/ \
		http://www.sourcefiles.org/Emulators/Videogames/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC Engine (TurboGrafx 16) emulator

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libargp.so:devel/argp-standalone

OPTIONS_DEFINE=	GTK2 DOCS NETPLAY SDL_MIXER
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes
NETPLAY_DESC=	Netplay support
SDL_MIXER_DESC=	SDL_mixer support

USES=		gmake pkgconfig
USE_SDL=	sdl
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MGTK2) && ${PORT_OPTIONS:MNETPLAY}
IGNORE=	NETPLAY support requires GTK2 support
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=	--disable-gui --disable-gtktest
.endif

.if ${PORT_OPTIONS:MNETPLAY}
USE_SDL+=	net
.else
CONFIGURE_ENV+=	ac_cv_lib_SDL_net_main=no
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
USE_SDL+=	mixer
CFLAGS+=	-DOGG_SUPPORT
.else
CONFIGURE_ENV+=	ac_cv_lib_SDL_mixer_main=no \
		ac_cv_lib_vorbis_main=no \
		ac_cv_lib_vorbisfile_main=no
.endif

.include <bsd.port.mk>
