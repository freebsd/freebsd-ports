# New ports collection makefile for:	aqualung
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqualung
DISTVERSION=	0.9beta6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Music player with rich features

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		FLAC.7:${PORTSDIR}/audio/flac \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		oggz.3:${PORTSDIR}/audio/liboggz \
		speex.3:${PORTSDIR}/audio/speex \
		mad.2:${PORTSDIR}/audio/libmad \
		modplug.0:${PORTSDIR}/audio/libmodplug \
		mpcdec.4:${PORTSDIR}/audio/libmpcdec \
		mac.2:${PORTSDIR}/audio/mac \
		tag.5:${PORTSDIR}/audio/taglib \
		lrdf.2:${PORTSDIR}/textproc/liblrdf \
		cddb.3:${PORTSDIR}/audio/libcddb

USE_GETTEXT=	yes
USE_GNOME=	pkgconfig gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --with-alsa=no --with-ifp=no --with-systray=no
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
PORTDOCS=	README manual.lyx manual.pdf
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/^docdir/s!=.*!= ${DOCSDIR}!' ${WRKSRC}/doc/Makefile.in
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/^install-data-am/s!install-docDATA!!' ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
