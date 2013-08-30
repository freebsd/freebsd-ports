# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jackit
PORTVERSION=	0.121.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://jackaudio.org/downloads/
DISTNAME=	jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Low latency audio server

LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio \
		sndfile:${PORTSDIR}/audio/libsndfile \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		celt0:${PORTSDIR}/audio/celt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--enable-portaudio \
		--with-default-tmpdir=/tmp
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LATEST_LINK=	jack

MAN1=		jackd.1 jackstart.1

OPTIONS_DEFINE=	ALSA DOXYGEN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOCS=""
.else
CONFIGURE_ENV+=	ac_cv_prog_HAVE_DOXYGEN="false"
PLIST_SUB+=	DOCS="@comment "
.endif

.if exists(${LOCALBASE}/lib/libreadline.so)
LIB_DEPENDS+=	readline:${PORTSDIR}/devel/readline
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=	--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|define USE_MLOCK|undef USE_MLOCK|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,-lpthread,-pthread," \
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

.include <bsd.port.mk>
