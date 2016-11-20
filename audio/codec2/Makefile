# $FreeBSD$

PORTNAME=	codec2
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio hamradio
MASTER_SITES=	http://files.freedv.org/codec2/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Low bit rate codec

LICENSE=	LGPL21
CONFLICTS=	libcodec2-*

LIB_DEPENDS=	libspeex.so:audio/speex

BROKEN_powerpc64=	Does not build

USES=		cmake:outsource compiler:c11 tar:xz
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SUB=	yes
EXAMPLES_CMAKE_ON=	-DINSTALL_EXAMPLES=ON
TEST_CMAKE_ON=		-DUNITTEST=ON

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

TEST_SRCFILES=	cohpsk_ch cohpsk_demod cohpsk_get_test_bits cohpsk_mod\
		cohpsk_put_test_bits fdmdv_channel freedv_rx freedv_tx\
		generate_codebook genlspdtcb
TEST_UNITTESTFILES=	c2validate create_interleaver de extract fdmdv_mem\
			genampdata genlsp genphdata genres lspsync polar2rect\
			pre raw2h scalarlsptest speexnoisesup t16_8\
			t16_8_short tcohpsk test_cohpsk_ch tfdmdv tfifo\
			tinterp tlspsens tnlp tprede tquant vq_train_jvm\
			vqtrain vqtrainjnd vqtrainph vqtrainsp

pre-patch-TEST-on:
	${REINPLACE_CMD} 's|speex/speex.h|speex/speex_preprocess.h|;\
		s|"_FLAGS"|_FLAGS|' ${WRKSRC}/CMakeLists.txt

post-install-TEST-on:
.for a in ${TEST_SRCFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/src/${a} ${STAGEDIR}${PREFIX}/bin
.endfor
.for a in ${TEST_UNITTESTFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/unittest/${a} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
