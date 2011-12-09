# New ports collection Makefile for: 	jackit
# Date created:			14 May 2002
# Whom:				arved
#
# $FreeBSD$
#

PORTNAME=	jackit
PORTVERSION=	0.121.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://jackaudio.org/downloads/
DISTNAME=	jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A low-latency audio server

LIB_DEPENDS=	portaudio.0:${PORTSDIR}/audio/portaudio \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		celt0.2:${PORTSDIR}/audio/celt

LATEST_LINK=	jack
LIBS+=		${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="${LIBS}"
CONFIGURE_ARGS+=--enable-portaudio \
		--with-default-tmpdir=/tmp
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig gnomehack

MAN1=		jackd.1 jackstart.1

OPTIONS=	ALSA "Build with ALSA compatibility library" off \
		DOCS "Build documentation" off

.include <bsd.port.pre.mk>

.if defined(WITH_DOCS) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOCS=""
.else
CONFIGURE_ENV+=	ac_cv_prog_HAVE_DOXYGEN="false"
PLIST_SUB+=	DOCS="@comment "
.endif

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|define USE_MLOCK|undef USE_MLOCK|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},"  \
		${WRKSRC}/configure ${WRKSRC}/libjack/Makefile.in \
		${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in ${WRKSRC}/jack.pc.in
	@${REINPLACE_CMD} -e "s,-lrt,," ${WRKSRC}/libjack/Makefile.in \
		${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in
	@${REINPLACE_CMD} -e "s,-ldl,," ${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in
	@${REINPLACE_CMD} -e 's|md5sum|md5 -q|g' \
		${WRKSRC}/jackd/Makefile.in
	@${RM} -f ${WRKSRC}/doc/reference/html/*

post-build:
	@${RM} -f ${WRKSRC}/doc/reference/html/dir__2F*

.include <bsd.port.post.mk>
