PORTNAME=	ocp
PORTVERSION=	0.2.109
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	https://stian.cubic.org/ocp/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Legendary Open Cubic Player
WWW=		https://stian.cubic.org/project-ocp.php

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	xa65:devel/xa65
LIB_DEPENDS=	libancient.so:archivers/ancient \
		libcjson.so:devel/libcjson \
		libdiscid.so:audio/libdiscid \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis

USES=		compiler:c11 dos2unix gmake gnome iconv jpeg localbase:ldflags \
		makeinfo ncurses pkgconfig shared-mime-info tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib \
		--with-dir-suffix="" \
		--without-sdl \
		--without-update-desktop-database
CONFIGURE_ENV=	SHARED_FLAGS="${LDFLAGS} -shared" \
		XA=${PREFIX}/bin/xa65

MAKE_JOBS_UNSAFE=	yes

LDFLAGS_i386=	-Wl,-z,notext

CONFLICTS_INSTALL=	alliance # man/man1/ocp.1.gz

INFO=		ocp

OPTIONS_DEFINE=		ADPLUG ALSA DOCS FLAC GME MIDI OSS SDL X11
OPTIONS_DEFAULT=	ADPLUG ALSA FLAC GME MIDI OSS SDL X11
OPTIONS_SUB=		yes

ADPLUG_DESC=	adplug support
GME_DESC=	libgme support for additional video game music support
MIDI_DESC=	timidity support

ADPLUG_LIB_DEPENDS=	libadplug.so:audio/libadplug \
			libbinio.so:devel/libbinio
ADPLUG_CONFIGURE_WITH=	adplug

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_WITH=	alsa

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_WITH=	flac

GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_WITH=	libgme

MIDI_RUN_DEPENDS=	eawpats>0:audio/eawpats

OSS_CONFIGURE_WITH=	oss

SDL_IMPLIES=		X11
SDL_BUILD_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont-otf/unifont.otf:x11-fonts/gnu-unifont-otf
SDL_LIB_DEPENDS=	libfreetype.so:print/freetype2
SDL_RUN_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont-otf/unifont.otf:x11-fonts/gnu-unifont-otf
SDL_USES=		desktop-file-utils sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_WITH=	sdl2 \
			unifontdir=${LOCALBASE}/share/fonts/gnu-unifont-otf
SDL_PLIST_SUB=		DESKTOP=''
SDL_PLIST_SUB_OFF=	DESKTOP='@comment '

X11_BUILD_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont-otf/unifont.otf:x11-fonts/gnu-unifont-otf
X11_LIB_DEPENDS=	libfreetype.so:print/freetype2
X11_RUN_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont-otf/unifont.otf:x11-fonts/gnu-unifont-otf
X11_USES=		desktop-file-utils xorg
X11_USE=		XORG=x11,xext,xpm,xxf86dga,xxf86vm
X11_CONFIGURE_WITH=	unifontdir-otf=${LOCALBASE}/share/fonts/gnu-unifont-otf \
			x11
X11_PLIST_SUB=		DESKTOP='' \
			XORG=''
X11_PLIST_SUB_OFF=	DESKTOP='@comment ' \
			XORG='@comment '

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/autoload/*.so

.include <bsd.port.post.mk>
