# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aqualung
DISTVERSION=	0.9beta11
PORTREVISION=	21
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
 		http://wickedmachine.net/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music player with rich features

LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		liboggz.so:${PORTSDIR}/audio/liboggz \
		libspeex.so:${PORTSDIR}/audio/speex \
		libmad.so:${PORTSDIR}/audio/libmad \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpcdec.so:${PORTSDIR}/audio/musepack \
		libmac.so:${PORTSDIR}/audio/mac \
		libtag.so:${PORTSDIR}/audio/taglib \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf \
		libcdio.so:${PORTSDIR}/sysutils/libcdio \
		libmp3lame.so:${PORTSDIR}/audio/lame \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libwavpack.so:${PORTSDIR}/audio/wavpack \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libcddb.so:${PORTSDIR}/audio/libcddb \
		libstrfunc.so:${PORTSDIR}/devel/libstrfunc

USES=		gmake pkgconfig gettext compiler:nestedfct
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-alsa=no --with-ifp=no \
		--with-cdda=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lstrfunc

OPTIONS_DEFINE=	JACK PULSEAUDIO DOCS

JACK_CONFIGURE_OFF=	--with-jack=no
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ON=	--with-jack=yes

PULSEAUDIO_CONFIGURE_OFF=	--with-pulse=no
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pulse=yes

post-patch:
	@${REINPLACE_CMD} -e '/^docdir/s!=.*!= ${DOCSDIR}!'\
		${WRKSRC}/doc/Makefile.in
#	@${REINPLACE_CMD} -e 's/libcdio_paranoia/libcdda_paranoia/g'\
#		${WRKSRC}/configure
	@${ECHO_CMD} "#include <sys/stat.h>" >> ${WRKSRC}/src/common.h
	@${ECHO_CMD} "#include <sys/types.h>" >> ${WRKSRC}/src/common.h

.include <bsd.port.mk>
