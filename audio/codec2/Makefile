PORTNAME=	codec2
DISTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	audio hamradio
MASTER_SITES=	https://hobbes1069.fedorapeople.org/freetel/codec2/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Low bit rate codec

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp

CONFLICTS=	libcodec2-[0-9]*
USES=		cmake pathfix pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SUB=	yes
EXAMPLES_CMAKE_ON=	-DINSTALL_EXAMPLES=ON
TEST_CMAKE_ON=		-DUNITTEST=ON

TEST_SRCFILES=	cohpsk_ch cohpsk_demod cohpsk_get_test_bits cohpsk_mod\
		cohpsk_put_test_bits fdmdv_channel freedv_rx freedv_tx\
		generate_codebook
TEST_UNITTESTFILES=	c2validate create_interleaver de extract fdmdv_mem\
			genlsp genres polar2rect\
			pre raw2h scalarlsptest speexnoisesup t16_8\
			t16_8_short tcohpsk test_cohpsk_ch tfdmdv tfifo\
			tnlp tprede vq_train_jvm\
			vqtrain

SHEBANG_FILES=	${WRKSRC}/octave/fsk_horus_stream.m\
		${WRKSRC}/script/menu.sh
SHEBANG_LANG=		octave

TEST_RUN_DEPENDS=	octave:math/octave
TEST_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

PORTEXAMPLES=	*

pre-patch-TEST-on:
	${REINPLACE_CMD} 's|%ld|%u|' ${WRKSRC}/unittest/fdmdv_mem.c

post-install-TEST-on:
.for a in ${TEST_SRCFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/src/${a} ${STAGEDIR}${PREFIX}/bin
.endfor
.for a in ${TEST_UNITTESTFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/unittest/${a} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
