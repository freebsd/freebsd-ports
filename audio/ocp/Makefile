# New ports collection makefile for:	ocp
# Date created:				22 April 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ocp
PORTVERSION=	0.1.17
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	The legendary Open Cubic Player

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		sidplay.1:${PORTSDIR}/audio/libsidplay

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-L${LOCALBASE}/lib
CXXFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-dir-suffix="" \
		--libdir=${LOCALBASE}/lib

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

OPTIONS=	ADPLUG "Build with adplug support" on \
		FLAC   "Build with FLAC support" on \
		MIDI   "Build with timidity support" on \
		X11    "Build with X11 support" on

.include <bsd.port.pre.mk>

.if exists(${TIMIDITY_CFG}) || !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${TIMIDITY_CFG}:${PORTSDIR}/audio/eawpats
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11
PLIST_SUB+=		XORG="@comment "
.else
USE_XORG=	xxf86dga xxf86vm xpm
CONFIGURE_ARGS+=	--with-x11=yes
PLIST_SUB+=		XORG=""
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
EXTRA_PATCHES+=		${PATCHDIR}/extrapatch-*
.endif

.if defined(WITH_ADPLUG)
LIB_DEPENDS+=		adplug-2.1:${PORTSDIR}/audio/libadplug
CONFIGURE_ARGS+=	--with-adplug
PLIST_SUB+=		ADPLUG=""
.else
PLIST_SUB+=		ADPLUG="@comment "
CONFIGURE_ARGS+=	--without-adplug
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=		FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--with-flac
PLIST_SUB+=		FLAC=""
.else
PLIST_SUB+=		FLAC="@comment "
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	DOCS="\#"
.endif

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|/\*\ \(#define\ LD_DEBUG\ 1\)\ \*/|\1|' \
		${WRKSRC}/config.h.in
.endif
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes\.h|' ${WRKSRC}/types.h
	@${REINPLACE_CMD} -e 's|/etc/.*\.cfg|${TIMIDITY_CFG}|' \
		${WRKSRC}/playgmi/gmitimidity.c
# conflicts with fnmatch.h from security/heimdal
	@${REINPLACE_CMD} -e 's|<\(fnmatch.h\)>|"/usr/include/\1"|' \
		${WRKSRC}/filesel/adb.c \
		${WRKSRC}/filesel/pfilesel.c

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
# use ncursesw from ports
	@${REINPLACE_CMD} -e 's|-l\(curses\)|-ln\1w|' ${WRKSRC}/stuff/Makefile
.for f in ${PFILES}
	@${REINPLACE_CMD} -e \
		's|#include.*<curses\.h.*|#include <ncurses/ncurses.h>|' \
			${WRKSRC}/${f}
.endfor
.endif

.include <bsd.port.post.mk>
