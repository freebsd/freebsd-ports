# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	ocp
PORTVERSION=	0.1.20
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://stian.cubic.org/ocp/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	The legendary Open Cubic Player

LICENSE=	GPLv2

LIB_DEPENDS=	id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad \
		vorbis:${PORTSDIR}/audio/libvorbis \
		sidplay:${PORTSDIR}/audio/libsidplay

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
USES=		ncurses gmake pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes
WANT_GNOME=	desktopfileutils
USE_GCC=	any

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-L${LOCALBASE}/lib ${CPPFLAGS}
CXXFLAGS+=	-L${LOCALBASE}/lib ${CPPFLAGS}

CONFIGURE_ARGS=	--with-dir-suffix="" \
		--without-alsa \
		--libdir=${PREFIX}/lib

INFO=		ocp

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

PFILES=		configure cpiface/cpianal.c cpiface/cpidots.c \
		cpiface/cpiface.c cpiface/cpigraph.c cpiface/cpiinst.c \
		cpiface/cpikube.c cpiface/cpilinks.c cpiface/cpimsg.c \
		cpiface/cpiphase.c cpiface/cpiscope.c cpiface/cpitrack.c \
		cpiface/mcpedit.c cpiface/volctrl.c filesel/cphlpfs.c \
		filesel/pfilesel.c filesel/pfilesel.c.bak help/cphelper.c \
		medialib/medialib.c playcda/cdapplay.c stuff/poutput-curses.c \
		stuff/poutput-dga.c stuff/poutput-keyboard.c \
		stuff/poutput-vcsa.c stuff/poutput-x11.c

OPTIONS_DEFINE=	ADPLUG FLAC MIDI X11 SDL DOCS

ADPLUG_DESC=	adplug support
MIDI_DESC=	timidity support

OPTIONS_DEFAULT=ADPLUG FLAC MIDI X11 SDL

.include <bsd.port.options.mk>

.if exists(${TIMIDITY_CFG}) || ${PORT_OPTIONS:MMIDI}
RUN_DEPENDS+=	${TIMIDITY_CFG}:${PORTSDIR}/audio/eawpats
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		xxf86dga xxf86vm xpm
USE_GNOME=		desktopfileutils
CONFIGURE_ARGS+=	--with-x11=yes
PLIST_SUB+=		XORG=""
.else
CONFIGURE_ARGS+=	--without-x11
PLIST_SUB+=		XORG="@comment "
.endif

.if ${PORT_OPTIONS:MADPLUG}
LIB_DEPENDS+=		adplug:${PORTSDIR}/audio/libadplug
CONFIGURE_ARGS+=	--with-adplug
PLIST_SUB+=		ADPLUG=""
.else
PLIST_SUB+=		ADPLUG="@comment "
CONFIGURE_ARGS+=	--without-adplug
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=		sound
USE_GNOME+=		desktopfileutils
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
LIB_DEPENDS+=		FLAC:${PORTSDIR}/audio/flac
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

.include <bsd.port.mk>
