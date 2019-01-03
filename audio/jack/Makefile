# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jackit
PORTVERSION=	0.125.0
PORTREVISION=	6
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Low latency audio server

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BROKEN_mips=		fails to link: undefined reference to '__sync_add_and_fetch_4'
BROKEN_mips64=		fails to link: undefined reference to '__sync_add_and_fetch_4'

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libcelt0.so:audio/celt

USES=		autoreconf compiler:c11 gmake pathfix pkgconfig libtool localbase bdb
USE_GITHUB=	yes

GH_ACCOUNT=	jackaudio
GH_PROJECT=	jack1
GH_TAGNAME=	90f9dd3
GH_TUPLE=	jackaudio:headers:07f1ecf:h/jack
GH_TUPLE+=	jackaudio:tools:8d13c31:t/tools
GH_TUPLE+=	jackaudio:example-clients:7fa0890:e/example-clients
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	jackd

CONFIGURE_ARGS=	--disable-portaudio \
		--enable-optimize \
		--enable-force-install \
		--with-default-tmpdir=/tmp

CFLAGS+=		-I${BDB_INCLUDE_DIR}
LIBS+=			-L${BDB_LIB_DIR}
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=		ALSA DOXYGEN READLINE SNDIO COOKEDMODE
OPTIONS_DEFINE_i386=	DYNSIMD
OPTIONS_DEFINE_amd64=	DYNSIMD
OPTIONS_DEFAULT=	READLINE COOKEDMODE
OPTIONS_DEFAULT_i386=	DYNSIMD
OPTIONS_DEFAULT_amd64=	DYNSIMD
OPTIONS_SUB=		yes
COOKEDMODE_DESC=	Use OSS COOKEDMODE (OSS driver is broken without it)
DYNSIMD_DESC=		Use dynamic SIMD selection (only i386/amd64)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa

READLINE_USES=		readline

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_HAVE_DOXYGEN="false"

READLINE_CONFIGURE_ENV_OFF=	ac_cv_lib_readline_readline=no \
		ac_cv_header_readline_chardefs_h=no

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

COOKEDMODE_CFLAGS=	-DOPTION_COOKEDMODE

DYNSIMD_CONFIGURE_ENABLE=dynsimd

post-patch:
	@${RM} ${WRKSRC}/doc/reference/html/*

post-build:
	@${RM} ${WRKSRC}/doc/reference/html/dir__2F*

.include <bsd.port.mk>
