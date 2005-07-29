# New ports collection makefile for:   ocp
# Date created:		22 April 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ocp
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://labs.nixia.no/ \
		http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	The legendary Open Cubic Player

LIB_DEPENDS=	id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GCC=	3.4+

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CXXFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-dir-suffix="" \
		--libdir=${LOCALBASE}/lib

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
PLIST_SUB+=	LIBSIDPLAY=""
.else
PLIST_SUB+=	LIBSIDPLAY="@comment "
.endif

.if exists(${TIMIDITY_CFG}) || !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${TIMIDITY_CFG}:${PORTSDIR}/audio/eawpats
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x11=yes
.endif
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.endif
.if defined(WITH_ADPLUG)
LIB_DEPENDS+=		adplug-1.5.1:${PORTSDIR}/audio/libadplug
CONFIGURE_ARGS+=	--without-x11
PLIST_SUB+=		ADPLUG=""
.else
PLIST_SUB+=		ADPLUG="@comment "
CONFIGURE_ARGS+=	--without-adplug
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocp ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cp.pak ${DATADIR}

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
