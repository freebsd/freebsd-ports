# New ports collection makefile for:	ocp
# Date created:				22 April 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ocp
PORTVERSION=	0.1.13
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://stian.lunafish.org/ocp/ \
		CRITICAL

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

.include <bsd.port.pre.mk>

.if exists(${TIMIDITY_CFG}) || !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${TIMIDITY_CFG}:${PORTSDIR}/audio/eawpats
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11
.else
USE_XORG=	xxf86dga xxf86vm
CONFIGURE_ARGS+=	--with-x11=yes
.endif
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.endif
.if defined(WITH_ADPLUG)
LIB_DEPENDS+=		adplug-2.1:${PORTSDIR}/audio/libadplug
CONFIGURE_ARGS+=	--without-x11 --with-adplug
PLIST_SUB+=		ADPLUG=""
.else
PLIST_SUB+=		ADPLUG="@comment "
CONFIGURE_ARGS+=	--without-adplug
.endif

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

pre-everything::
.if !exists(${TIMIDITY_CFG}) && !defined(WITHOUT_MIDI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "In order to be able to play MIDI files, audio/eawpats will be installed."
	@${ECHO_MSG} "Define WITHOUT_MIDI if you do not want to install it."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_X11) && !defined(WITH_ADPLUG)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to compile without X11 support, hit Ctrl-C right now and"
	@${ECHO_MSG} "define WITHOUT_X11"
	@${ECHO_MSG} ""
.endif

# Hangs on exit
.if defined(WITH_ADPLUG) && !defined(WITHOUT_X11)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Disabling X11 support. X11 and libadplug usage cannot yet peacefully"
	@${ECHO_MSG} "coexist."
	@${ECHO_MSG} ""
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocp ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ocp.pak ${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/ocp.ini ${PREFIX}/etc/ocp.ini.default
.if !exists(${PREFIX}/etc/ocp.ini)
	${INSTALL_DATA} ${WRKSRC}/ocp.ini ${PREFIX}/etc
.endif

	${MKDIR} ${PREFIX}/lib/ocp
	${INSTALL_DATA} ${WRKSRC}/*.so ${PREFIX}/lib/ocp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS BUGS CREDITS Changelog KEYBOARD_REMAPS SUID TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
