# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aqualung
DISTVERSION=	0.9beta11
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
 		http://wickedmachine.net/mirror/

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Music player with rich features

LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		FLAC:${PORTSDIR}/audio/flac \
		vorbis:${PORTSDIR}/audio/libvorbis \
		oggz:${PORTSDIR}/audio/liboggz \
		speex:${PORTSDIR}/audio/speex \
		mad:${PORTSDIR}/audio/libmad \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpcdec:${PORTSDIR}/audio/musepack \
		mac:${PORTSDIR}/audio/mac \
		tag:${PORTSDIR}/audio/taglib \
		lrdf:${PORTSDIR}/textproc/liblrdf \
		cdio:${PORTSDIR}/sysutils/libcdio \
		mp3lame:${PORTSDIR}/audio/lame \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		strfunc:${PORTSDIR}/devel/libstrfunc \
		wavpack:${PORTSDIR}/audio/wavpack \
		xslt:${PORTSDIR}/textproc/libxslt \
		cddb:${PORTSDIR}/audio/libcddb \
		strfunc:${PORTSDIR}/devel/libstrfunc

USES=		gmake pkgconfig gettext
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-alsa=no --with-ifp=no \
		--with-cdda=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lstrfunc
MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	JACK PULSEAUDIO DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK}
CONFIGURE_ARGS+=	--with-jack=no
.else
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack=yes
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=	--with-pulse=no
.else
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulse=yes
.endif
post-patch:
	@${REINPLACE_CMD} -e '/^docdir/s!=.*!= ${DOCSDIR}!'\
		${WRKSRC}/doc/Makefile.in
#	@${REINPLACE_CMD} -e 's/libcdio_paranoia/libcdda_paranoia/g'\
#		${WRKSRC}/configure
	@${ECHO_CMD} "#include <sys/stat.h>" >> ${WRKSRC}/src/common.h
	@${ECHO_CMD} "#include <sys/types.h>" >> ${WRKSRC}/src/common.h
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am/s!install-docDATA!!'\
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
