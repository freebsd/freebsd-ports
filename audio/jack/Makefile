# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jackit
PORTVERSION=	0.125.0
CATEGORIES=	audio
MASTER_SITES=	http://jackaudio.org/downloads/
DISTNAME=	jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Low latency audio server

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libcelt0.so:audio/celt \
		libuuid.so:misc/e2fsprogs-libuuid

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig libtool localbase bdb
USE_RC_SUBR=	jackd

CONFIGURE_ARGS=	--disable-portaudio \
		--enable-force-install \
		--with-default-tmpdir=/tmp

CFLAGS+=	-I${BDB_INCLUDE_DIR}
LIBS+=	-L${BDB_LIB_DIR}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ALSA DOXYGEN READLINE SNDIO
OPTIONS_DEFAULT=READLINE
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

READLINE_USES=		readline

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_HAVE_DOXYGEN="false"

READLINE_CONFIGURE_ENV_OFF=	ac_cv_lib_readline_readline=no \
		ac_cv_header_readline_chardefs_h=no

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

post-patch:
	@${REINPLACE_CMD} -e 's|define USE_MLOCK|undef USE_MLOCK|' \
		-e 's|alloca.h||' \
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
	@${RM} ${WRKSRC}/doc/reference/html/*

post-build:
	@${RM} ${WRKSRC}/doc/reference/html/dir__2F*

.include <bsd.port.mk>
