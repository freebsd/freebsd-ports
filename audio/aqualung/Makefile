# New ports collection makefile for:	aqualung
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqualung
DISTVERSION=	0.9beta11
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
 		http://wickedmachine.net/mirror/

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Music player with rich features

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		FLAC.10:${PORTSDIR}/audio/flac \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		oggz.8:${PORTSDIR}/audio/liboggz \
		speex.1:${PORTSDIR}/audio/speex \
		mad.2:${PORTSDIR}/audio/libmad \
		modplug.1:${PORTSDIR}/audio/libmodplug \
		mpcdec.5:${PORTSDIR}/audio/libmpcdec \
		mac.2:${PORTSDIR}/audio/mac \
		tag.1:${PORTSDIR}/audio/taglib \
		lrdf.2:${PORTSDIR}/textproc/liblrdf \
		cdio.12:${PORTSDIR}/sysutils/libcdio \
		mp3lame.0:${PORTSDIR}/audio/lame \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		strfunc.9:${PORTSDIR}/devel/libstrfunc \
		wavpack.2:${PORTSDIR}/audio/wavpack \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		cddb.4:${PORTSDIR}/audio/libcddb \
		strfunc.9:${PORTSDIR}/devel/libstrfunc

USE_GETTEXT=	yes
USE_GNOME=	pkgconfig gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-alsa=no --with-ifp=no \
		--with-cdda=no
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lstrfunc
MAN1=		${PORTNAME}.1

OPTIONS=	JACK "Enable JACK low-latency audio server support" Off \
		PULSE "Enable PulseAudio sound server support" Off

.include <bsd.port.options.mk>

.if !defined(WITH_JACK)
CONFIGURE_ARGS+=	--with-jack=no
.else
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack=yes
.endif

.if !defined(WITH_PULSE)
CONFIGURE_ARGS+=	--with-pulse=no
.else
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulse=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^docdir/s!=.*!= ${DOCSDIR}!'\
		${WRKSRC}/doc/Makefile.in
#	@${REINPLACE_CMD} -e 's/libcdio_paranoia/libcdda_paranoia/g'\
#		${WRKSRC}/configure
	@${ECHO_CMD} "#include <sys/stat.h>" >> ${WRKSRC}/src/common.h
	@${ECHO_CMD} "#include <sys/types.h>" >> ${WRKSRC}/src/common.h
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/^install-data-am/s!install-docDATA!!'\
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
