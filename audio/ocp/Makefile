# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ocp
PORTVERSION=	0.1.21
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF/opencubicplayer/${DISTNAME} \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Legendary Open Cubic Player

LICENSE=	GPLv2

LIB_DEPENDS=	libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis \
		libsidplay.so:audio/libsidplay \
		libogg.so:audio/libogg

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
USES=		ncurses gmake pkgconfig makeinfo tar:xz iconv
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-L${LOCALBASE}/lib ${CPPFLAGS}
CXXFLAGS+=	-L${LOCALBASE}/lib ${CPPFLAGS}

CONFIGURE_ARGS=	--with-dir-suffix="" \
		--without-alsa \
		--libdir=${PREFIX}/lib

INFO=		ocp

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

OPTIONS_DEFINE=	ADPLUG FLAC MIDI X11 SDL DOCS

ADPLUG_DESC=	adplug support
MIDI_DESC=	timidity support

OPTIONS_DEFAULT=ADPLUG FLAC MIDI X11 SDL

ADPLUG_LIB_DEPENDS=	libbinio.so:devel/libbinio \
			libadplug.so:audio/libadplug

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

# needed despite stage-qa's warning
X11_USES=	desktop-file-utils
SDL_USES=	desktop-file-utils

.include <bsd.port.options.mk>

.if exists(${TIMIDITY_CFG}) || ${PORT_OPTIONS:MMIDI}
RUN_DEPENDS+=	eawpats>0:audio/eawpats
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		xxf86dga xxf86vm xpm xext x11
CONFIGURE_ARGS+=	--with-x11=yes
PLIST_SUB+=		XORG=""
.else
CONFIGURE_ARGS+=	--without-x11
PLIST_SUB+=		XORG="@comment "
.endif

.if ${PORT_OPTIONS:MADPLUG}
CONFIGURE_ARGS+=	--with-adplug
PLIST_SUB+=		ADPLUG=""
.else
PLIST_SUB+=		ADPLUG="@comment "
CONFIGURE_ARGS+=	--without-adplug
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=		sdl
CONFIGURE_ARGS+=	--with-sdl=yes
PLIST_SUB+=		SDL=""
.else
CONFIGURE_ARGS+=	--with-sdl=no
PLIST_SUB+=		SDL="@comment "
.endif

.if ${PORT_OPTIONS:MSDL} || ${PORT_OPTIONS:MX11}
PLIST_SUB+=		DESKTOP=""
.else
PLIST_SUB+=		DESKTOP="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
CONFIGURE_ARGS+=	--with-flac
PLIST_SUB+=		FLAC=""
.else
PLIST_SUB+=		FLAC="@comment "
CONFIGURE_ARGS+=	--without-flac
.endif

.if empty(PORT_OPTIONS:MDOCS)
MAKE_ENV+=	DOCS="\#"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/.*\.cfg|${TIMIDITY_CFG}|' \
		${WRKSRC}/playgmi/gmitimidity.c
# conflicts with fnmatch.h from security/heimdal
	@${REINPLACE_CMD} -e 's|<\(fnmatch.h\)>|"/usr/include/\1"|' \
		${WRKSRC}/filesel/adb.c \
		${WRKSRC}/filesel/pfilesel.c
	@${REINPLACE_CMD} -e '1s|bash|sh|' ${WRKSRC}/ultrafix.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ocp
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocp/autoload/*.so

.include <bsd.port.mk>
