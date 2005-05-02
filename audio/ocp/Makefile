# New ports collection makefile for:   ocp
# Date created:		22 April 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ocp
PORTVERSION=	0.1.6
CATEGORIES=	audio
MASTER_SITES=	http://labs.nixia.no/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	The legendary Open Cubic Player

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		vorbis.3:${PORTSDIR}/audio/libvorbis

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GCC=	3.4+

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-dir-suffix=""

TIMIDITY_CFG=	${LOCALBASE}/share/timidity/timidity.cfg

.include <bsd.port.pre.mk>

.if exists(${TIMIDITY_CFG}) || !defined(WITHOUT_MIDI)
RUN_DEPENDS=	${TIMIDITY_CFG}:${PORTSDIR}/audio/eawpats
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x11=yes
.endif

pre-everything::
.if !exists(${TIMIDITY_CFG}) && !defined(WITHOUT_MIDI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "In order to be able to play MIDI files, audio/eawpats will be installed."
	@${ECHO_MSG} "Define WITHOUT_MIDI if you do not want to install it."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to compile without X11 support, hit Ctrl-C right now and"
	@${ECHO_MSG} "define WITHOUT_X11"
	@${ECHO_MSG} ""
.endif

post-patch:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|/\*\ \(#define\ .*DEBUG\ 1\)\ \*/|\1|' \
		${WRKSRC}/config.h.in
.endif
	@${REINPLACE_CMD} -e 's|@LIBDIR@|${PREFIX}/lib/ocp|' \
		${WRKSRC}/Rules.make.in
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes\.h|' ${WRKSRC}/types.h
	@${REINPLACE_CMD} -e 's|\(-shared\)|-L${LOCALBASE}/lib -L${X11BASE}/lib \1|' \
		${WRKSRC}/playmp2/Makefile \
		${WRKSRC}/playogg/Makefile \
		${WRKSRC}/playsid/Makefile
	@${REINPLACE_CMD} -e 's|/etc/.*\.cfg|${TIMIDITY_CFG}|' \
		${WRKSRC}/playgmi/gmitimidity.c

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
