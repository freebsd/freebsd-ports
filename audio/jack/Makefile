# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jackit
PORTVERSION=	0.124.1
CATEGORIES=	audio
MASTER_SITES=	http://jackaudio.org/downloads/
DISTNAME=	jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Low latency audio server

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libcelt0.so:${PORTSDIR}/audio/celt \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig libtool:keepla
USE_BDB=        48

CONFIGURE_ARGS=	--enable-portaudio \
		--with-default-tmpdir=/tmp

CFLAGS+=	-I${BDB_INCLUDE_DIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
INSTALL_TARGET=	install-strip

LATEST_LINK=	jack

OPTIONS_DEFINE=	ALSA DOCS READLINE
OPTIONS_DEFAULT=READLINE
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

READLINE_LIB_DEPENDS=	libreadline.so:${PORTSDIR}/devel/readline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ENV+=	ac_cv_prog_HAVE_DOXYGEN="false"
.endif

.if ! ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ENV+=	ac_cv_lib_readline_readline=no \
		ac_cv_header_readline_chardefs_h=no
.endif

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
	@${RM} -f ${WRKSRC}/doc/reference/html/*

post-build:
	@${RM} -f ${WRKSRC}/doc/reference/html/dir__2F*

.include <bsd.port.mk>
