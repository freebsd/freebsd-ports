# New ports collection makefile for:   alsaplayer
# Date created:                18 June 2003
# Whom:                        Robin Schilham <co9@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	alsaplayer
PORTVERSION=	0.99.75
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/people/andy/ \
		http://www.alsaplayer.org/

MAINTAINER=	co9@xs4all.nl
COMMENT=	Audio player with pitch control and a GNOME GUI

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad \
		sndfile.1:${PORTSDIR}/audio/libsndfile

USE_REINPLACE=	yes
USE_GNOME=	glib12 gnomehack gnometarget
WANT_GNOME=	yes
USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=	13
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
	       	LDFLAGS="${LDFLAGS}"

MAN1=		alsaplayer.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!="" && !defined(WITHOUT_X11)
USE_XLIB=	yes
USE_GNOME+=	gtk12
CPPFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--disable-gtktest --disable-gtk
PLIST_SUB+=	GUI="@comment "
.endif

.if exists(${LOCALBASE}/lib/libaudiofile.so)
WITH_AUDIOFILE=	yes
.endif

.if ${HAVE_GNOME:Mesound}!=""
WITH_ESOUND=	yes
.endif

.if exists(${LOCALBASE}/lib/libFLAC.so)
WITH_FLAC=	yes
.endif

.if exists(${LOCALBASE}/lib/libmikmod.so)
WITH_MIKMOD=	yes
.endif

.if exists(${X11BASE}/lib/libaudio.so)
WITH_NAS=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.ifndef(WITH_AUDIOFILE)
CONFIGURE_ARGS+=	--disable-audiofile \
			--disable-audiofiletest
PLIST_SUB+=		AUDIOFILE="@comment "
.else
LIB_DEPENDS+=		audiofile.0:${PORTSDIR}/audio/libaudiofile
CONFIGURE_ARGS+=	--enable-audiofile \
			--with-audiofile-prefix=${LOCALBASE} \
			--with-audiofile-exec-prefix=${LOCALBASE}
PLIST_SUB+=		AUDIOFILE=""
.endif

.ifndef(WITH_ESOUND)
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=		ESD="@comment "
.else
USE_GNOME+=		esound
CONFIGURE_ARGS+=	--enable-esd \
			--with-esd-prefix=${LOCALBASE} \
			--with-esd-exec-prefix=${LOCALBASE}
PLIST_SUB+=		ESD=""
.endif

.ifndef(WITH_FLAC)
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=		FLAC="@comment "
.else
LIB_DEPENDS+=		FLAC.7:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--enable-flac
PLIST_SUB+=		FLAC=""
.endif

.ifndef(WITH_MIKMOD)
CONFIGURE_ARGS+=	--disable-mikmod \
			--disable-libmikmodtest
PLIST_SUB+=		MIKMOD="@comment "
.else
CONFIGURE_ARGS+=	--enable-mikmod \
			--with-libmikmod-prefix=${LOCALBASE} \
			--with-libmikmod-exec-prefix=${LOCALBASE}
LIB_DEPENDS+=		mikmod.2:${PORTSDIR}/audio/libmikmod
PLIST_SUB+=		MIKMOD=""
.endif

.ifndef(WITH_NAS)
CONFIGURE_ARGS+=	--disable-nas
PLIST_SUB+=		NAS="@comment "
.else
CONFIGURE_ARGS+=	--enable-nas
LIB_DEPENDS+=		audio.2:${PORTSDIR}/audio/nas
PLIST_SUB+=		NAS=""
.endif

.ifdef(WITHOUT_OSS)
CONFIGURE_ARGS+=	--disable-oss
PLIST_SUB+=		OSS="@comment "
.else
PLIST_SUB+=		OSS=""
.endif

.ifndef(WITH_VORBIS)
CONFIGURE_ARGS+=	--disable-oggvorbis \
			--disable-vorbistest \
			--disable-oggtest
PLIST_SUB+=		VORBIS="@comment "
.else
CONFIGURE_ARGS+=	--enable-oggvorbis \
			--with-vorbis-prefix=${LOCALBASE} \
			--with-ogg-prefix=${LOCALBASE}
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=		VORBIS=""
.endif

pre-everything::
.ifndef(WITH_AUDIOFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AUDIOFILE to enable audiofile plugin'
.endif
.ifndef(WITH_ESOUND)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ESOUND to enable esound Audio plugin'
.endif
.ifndef(WITH_FLAC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FLAC to enable flac Audio plugin'
.endif
.ifndef(WITH_MIKMOD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_MIKMOD to enable libmikmod Audio plugin'
.endif
.ifndef(WITH_NAS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_NAS to enable NAS Audio plugin'
.endif
.ifndef(WITHOUT_OSS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_OSS to disable OSS Audio plugin'
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_VORBIS to enable vorbis Audio plugin'
.endif
.ifndef(WITHOUT_X11)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_X11 to disable the Alsaplayer GUI'
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.c' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

post-configure:
	@${REINPLACE_CMD} -e "s|CPPFLAGS = -I/usr/local/include|CPPFLAGS = |g" \
		${WRKSRC}/app/Makefile

.include <bsd.port.post.mk>
