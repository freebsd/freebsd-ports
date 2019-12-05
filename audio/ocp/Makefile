# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ocp
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Legendary Open Cubic Player

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis \
		libsidplay.so:audio/libsidplay \
		libogg.so:audio/libogg

USES=		gmake gnome iconv localbase:ldflags makeinfo ncurses pkgconfig \
		tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes

GH_ACCOUNT=	mywave82
GH_PROJECT=	opencubicplayer
GH_TUPLE=	mywave82:timidity:77cd92d:timidity/playgmi/timidity-git

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-dir-suffix="" \
		--libdir=${PREFIX}/lib
CONFIGURE_ENV=	SHARED_FLAGS="${LDFLAGS} -shared"

INFO=		ocp

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

OPTIONS_DEFINE=	ADPLUG ALSA FLAC MIDI OSS X11 SDL DOCS
OPTIONS_DEFAULT=ADPLUG ALSA FLAC MIDI OSS X11 SDL
OPTIONS_SUB=	yes

ADPLUG_DESC=	adplug support
MIDI_DESC=	timidity support

ADPLUG_CONFIGURE_WITH=	adplug
ADPLUG_LIB_DEPENDS=	libbinio.so:devel/libbinio \
			libadplug.so:audio/libadplug

ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

FLAC_CONFIGURE_WITH=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

MIDI_RUN_DEPENDS=	eawpats>0:audio/eawpats

OSS_CONFIGURE_WITH=	oss

SDL_CONFIGURE_WITH=	sdl2
SDL_PLIST_SUB=		DESKTOP=''
SDL_PLIST_SUB_OFF=	DESKTOP='@comment '
SDL_USE=		SDL=sdl2

X11_CONFIGURE_WITH=	x11
X11_PLIST_SUB=		XORG='' DESKTOP=''
X11_PLIST_SUB_OFF=	XORG='@comment ' DESKTOP='@comment '
X11_USE=		XORG=xxf86dga,xxf86vm,xpm,xext,x11

# needed despite stage-qa's warning
SDL_USES=	desktop-file-utils sdl
X11_USES=	desktop-file-utils xorg

LDFLAGS_i386=	-Wl,-z,notext

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/autoload/*.so

.include <bsd.port.mk>
