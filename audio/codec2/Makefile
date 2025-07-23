PORTNAME=	codec2
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	audio hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Low bit rate codec
WWW=		https://www.rowetel.com/?page_id=452

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp

USES=		cmake pkgconfig python shebangfix tar:xz

GH_ACCOUNT=	drowe67
GH_PROJECT=	codec2

USE_LDCONFIG=	yes
USE_GITHUB=		yes

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SUB=	yes
EXAMPLES_CMAKE_ON=	-DINSTALL_EXAMPLES=ON
TEST_CMAKE_ON=		-DUNITTEST=ON

TEST_SRCFILES=	cohpsk_ch cohpsk_demod cohpsk_get_test_bits cohpsk_mod\
		cohpsk_put_test_bits fdmdv_channel freedv_rx freedv_tx\
		generate_codebook
TEST_UNITTESTFILES=	compare_ints fdmdv_mem ofdm_mem ofdm_stack \
					t16_8 t16_8_short tcohpsk tdeframer tesno_est \
					test_phi0 tfdmdv tfifo tfmfsk tfreedv_2400A_rawdata \
					tfreedv_2400B_rawdata tfreedv_800XA_rawdata \
					tfreedv_data_channel tfsk tfsk_llr thash tnewamp1 \
					tofdm tofdm_acq tqam16 tst_codec2_fft_init tvq_mbest

SHEBANG_FILES=	${WRKSRC}/script/separate_all.sh \
				${WRKSRC}/demo/freedv_700d_rx.py \
				${WRKSRC}/script/gen_phi0 \
				${WRKSRC}/script/phi0_plot.py \
				${WRKSRC}/script/subsetvq.sh \
				${WRKSRC}/script/train_700c_quant.sh \
				${WRKSRC}/script/ofdm_stack_use.py \
				${WRKSRC}/script/train_sub_quant.sh \
				${WRKSRC}/unittest/*.sh \
				${WRKSRC}/octave/fsk_demod_BER_test.py \
				${WRKSRC}/octave/fskdemodgui.py \
				${WRKSRC}/octave/plot_fsk_demod_stats.py

#TEST_RUN_DEPENDS=	octave:math/octave
#TEST_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

PORTEXAMPLES=	*

post-install-TEST-on:
.for a in ${TEST_SRCFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/src/${a} ${STAGEDIR}${PREFIX}/bin
.endfor
.for a in ${TEST_UNITTESTFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/.build/unittest/${a} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
