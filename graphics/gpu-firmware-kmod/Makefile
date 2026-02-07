PORTNAME=	gpu-firmware-kmod
PORTVERSION=	20250109
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for the drm-kmod drivers
WWW=		https://github.com/freebsd/drm-kmod

USES=		metaport

RUN_DEPENDS=	gpu-firmware-radeon-kmod-aruba>0:graphics/gpu-firmware-radeon-kmod@aruba \
		gpu-firmware-radeon-kmod-barts>0:graphics/gpu-firmware-radeon-kmod@barts \
		gpu-firmware-radeon-kmod-bonaire>0:graphics/gpu-firmware-radeon-kmod@bonaire \
		gpu-firmware-radeon-kmod-btc>0:graphics/gpu-firmware-radeon-kmod@btc \
		gpu-firmware-radeon-kmod-caicos>0:graphics/gpu-firmware-radeon-kmod@caicos \
		gpu-firmware-radeon-kmod-cayman>0:graphics/gpu-firmware-radeon-kmod@cayman \
		gpu-firmware-radeon-kmod-cedar>0:graphics/gpu-firmware-radeon-kmod@cedar \
		gpu-firmware-radeon-kmod-cypress>0:graphics/gpu-firmware-radeon-kmod@cypress \
		gpu-firmware-radeon-kmod-hainan>0:graphics/gpu-firmware-radeon-kmod@hainan \
		gpu-firmware-radeon-kmod-hawaii>0:graphics/gpu-firmware-radeon-kmod@hawaii \
		gpu-firmware-radeon-kmod-juniper>0:graphics/gpu-firmware-radeon-kmod@juniper \
		gpu-firmware-radeon-kmod-kabini>0:graphics/gpu-firmware-radeon-kmod@kabini \
		gpu-firmware-radeon-kmod-kaveri>0:graphics/gpu-firmware-radeon-kmod@kaveri \
		gpu-firmware-radeon-kmod-mullins>0:graphics/gpu-firmware-radeon-kmod@mullins \
		gpu-firmware-radeon-kmod-oland>0:graphics/gpu-firmware-radeon-kmod@oland \
		gpu-firmware-radeon-kmod-palm>0:graphics/gpu-firmware-radeon-kmod@palm \
		gpu-firmware-radeon-kmod-pitcairn>0:graphics/gpu-firmware-radeon-kmod@pitcairn \
		gpu-firmware-radeon-kmod-r100>0:graphics/gpu-firmware-radeon-kmod@r100 \
		gpu-firmware-radeon-kmod-r200>0:graphics/gpu-firmware-radeon-kmod@r200 \
		gpu-firmware-radeon-kmod-r300>0:graphics/gpu-firmware-radeon-kmod@r300 \
		gpu-firmware-radeon-kmod-r420>0:graphics/gpu-firmware-radeon-kmod@r420 \
		gpu-firmware-radeon-kmod-r520>0:graphics/gpu-firmware-radeon-kmod@r520 \
		gpu-firmware-radeon-kmod-r600>0:graphics/gpu-firmware-radeon-kmod@r600 \
		gpu-firmware-radeon-kmod-r700>0:graphics/gpu-firmware-radeon-kmod@r700 \
		gpu-firmware-radeon-kmod-redwood>0:graphics/gpu-firmware-radeon-kmod@redwood \
		gpu-firmware-radeon-kmod-rs600>0:graphics/gpu-firmware-radeon-kmod@rs600 \
		gpu-firmware-radeon-kmod-rs690>0:graphics/gpu-firmware-radeon-kmod@rs690 \
		gpu-firmware-radeon-kmod-rs780>0:graphics/gpu-firmware-radeon-kmod@rs780 \
		gpu-firmware-radeon-kmod-rv610>0:graphics/gpu-firmware-radeon-kmod@rv610 \
		gpu-firmware-radeon-kmod-rv620>0:graphics/gpu-firmware-radeon-kmod@rv620 \
		gpu-firmware-radeon-kmod-rv630>0:graphics/gpu-firmware-radeon-kmod@rv630 \
		gpu-firmware-radeon-kmod-rv635>0:graphics/gpu-firmware-radeon-kmod@rv635 \
		gpu-firmware-radeon-kmod-rv670>0:graphics/gpu-firmware-radeon-kmod@rv670 \
		gpu-firmware-radeon-kmod-rv710>0:graphics/gpu-firmware-radeon-kmod@rv710 \
		gpu-firmware-radeon-kmod-rv730>0:graphics/gpu-firmware-radeon-kmod@rv730 \
		gpu-firmware-radeon-kmod-rv740>0:graphics/gpu-firmware-radeon-kmod@rv740 \
		gpu-firmware-radeon-kmod-rv770>0:graphics/gpu-firmware-radeon-kmod@rv770 \
		gpu-firmware-radeon-kmod-sumo>0:graphics/gpu-firmware-radeon-kmod@sumo \
		gpu-firmware-radeon-kmod-sumo2>0:graphics/gpu-firmware-radeon-kmod@sumo2 \
		gpu-firmware-radeon-kmod-tahiti>0:graphics/gpu-firmware-radeon-kmod@tahiti \
		gpu-firmware-radeon-kmod-turks>0:graphics/gpu-firmware-radeon-kmod@turks \
		gpu-firmware-radeon-kmod-verde>0:graphics/gpu-firmware-radeon-kmod@verde \
		gpu-firmware-amd-kmod-cyan-skillfish2>0:graphics/gpu-firmware-amd-kmod@cyan_skillfish2 \
		gpu-firmware-amd-kmod-dimgrey-cavefish>0:graphics/gpu-firmware-amd-kmod@dimgrey_cavefish \
		gpu-firmware-amd-kmod-green-sardine>0:graphics/gpu-firmware-amd-kmod@green_sardine \
		gpu-firmware-amd-kmod-navy-flounder>0:graphics/gpu-firmware-amd-kmod@navy_flounder \
		gpu-firmware-amd-kmod-sienna-cichlid>0:graphics/gpu-firmware-amd-kmod@sienna_cichlid \
		gpu-firmware-amd-kmod-vangogh>0:graphics/gpu-firmware-amd-kmod@vangogh

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
RUN_DEPENDS+=	gpu-firmware-intel-kmod-skylake>0:graphics/gpu-firmware-intel-kmod@skylake \
		gpu-firmware-intel-kmod-broxton>0:graphics/gpu-firmware-intel-kmod@broxton \
		gpu-firmware-intel-kmod-kabylake>0:graphics/gpu-firmware-intel-kmod@kabylake \
		gpu-firmware-intel-kmod-geminilake>0:graphics/gpu-firmware-intel-kmod@geminilake \
		gpu-firmware-intel-kmod-cannonlake>0:graphics/gpu-firmware-intel-kmod@cannonlake \
		gpu-firmware-intel-kmod-icelake>0:graphics/gpu-firmware-intel-kmod@icelake \
		gpu-firmware-intel-kmod-elkhartlake>0:graphics/gpu-firmware-intel-kmod@elkhartlake \
		gpu-firmware-intel-kmod-tigerlake>0:graphics/gpu-firmware-intel-kmod@tigerlake \
		gpu-firmware-intel-kmod-rocketlake>0:graphics/gpu-firmware-intel-kmod@rocketlake \
		gpu-firmware-intel-kmod-dg1>0:graphics/gpu-firmware-intel-kmod@dg1 \
		gpu-firmware-intel-kmod-dg2>0:graphics/gpu-firmware-intel-kmod@dg2 \
		gpu-firmware-intel-kmod-alderlake>0:graphics/gpu-firmware-intel-kmod@alderlake \
		gpu-firmware-intel-kmod-meteorlake>0:graphics/gpu-firmware-intel-kmod@meteorlake
.endif

.if ${ARCH} != powerpc64
RUN_DEPENDS+=	gpu-firmware-amd-kmod-aldebaran>0:graphics/gpu-firmware-amd-kmod@aldebaran \
		gpu-firmware-amd-kmod-arcturus>0:graphics/gpu-firmware-amd-kmod@arcturus \
		gpu-firmware-amd-kmod-banks>0:graphics/gpu-firmware-amd-kmod@banks \
		gpu-firmware-amd-kmod-beige-goby>0:graphics/gpu-firmware-amd-kmod@beige_goby \
		gpu-firmware-amd-kmod-bonaire>0:graphics/gpu-firmware-amd-kmod@bonaire \
		gpu-firmware-amd-kmod-carrizo>0:graphics/gpu-firmware-amd-kmod@carrizo \
		gpu-firmware-amd-kmod-fiji>0:graphics/gpu-firmware-amd-kmod@fiji \
		gpu-firmware-amd-kmod-hainan>0:graphics/gpu-firmware-amd-kmod@hainan \
		gpu-firmware-amd-kmod-hawaii>0:graphics/gpu-firmware-amd-kmod@hawaii \
		gpu-firmware-amd-kmod-kabini>0:graphics/gpu-firmware-amd-kmod@kabini \
		gpu-firmware-amd-kmod-kaveri>0:graphics/gpu-firmware-amd-kmod@kaveri \
		gpu-firmware-amd-kmod-mullins>0:graphics/gpu-firmware-amd-kmod@mullins \
		gpu-firmware-amd-kmod-navi10>0:graphics/gpu-firmware-amd-kmod@navi10 \
		gpu-firmware-amd-kmod-navi12>0:graphics/gpu-firmware-amd-kmod@navi12 \
		gpu-firmware-amd-kmod-navi14>0:graphics/gpu-firmware-amd-kmod@navi14 \
		gpu-firmware-amd-kmod-oland>0:graphics/gpu-firmware-amd-kmod@oland \
		gpu-firmware-amd-kmod-picasso>0:graphics/gpu-firmware-amd-kmod@picasso \
		gpu-firmware-amd-kmod-pitcairn>0:graphics/gpu-firmware-amd-kmod@pitcairn \
		gpu-firmware-amd-kmod-polaris10>0:graphics/gpu-firmware-amd-kmod@polaris10 \
		gpu-firmware-amd-kmod-polaris11>0:graphics/gpu-firmware-amd-kmod@polaris11 \
		gpu-firmware-amd-kmod-polaris12>0:graphics/gpu-firmware-amd-kmod@polaris12 \
		gpu-firmware-amd-kmod-raven>0:graphics/gpu-firmware-amd-kmod@raven \
		gpu-firmware-amd-kmod-raven2>0:graphics/gpu-firmware-amd-kmod@raven2 \
		gpu-firmware-amd-kmod-renoir>0:graphics/gpu-firmware-amd-kmod@renoir \
		gpu-firmware-amd-kmod-si58>0:graphics/gpu-firmware-amd-kmod@si58 \
		gpu-firmware-amd-kmod-stoney>0:graphics/gpu-firmware-amd-kmod@stoney \
		gpu-firmware-amd-kmod-tahiti>0:graphics/gpu-firmware-amd-kmod@tahiti \
		gpu-firmware-amd-kmod-tonga>0:graphics/gpu-firmware-amd-kmod@tonga \
		gpu-firmware-amd-kmod-topaz>0:graphics/gpu-firmware-amd-kmod@topaz \
		gpu-firmware-amd-kmod-vega10>0:graphics/gpu-firmware-amd-kmod@vega10 \
		gpu-firmware-amd-kmod-vega12>0:graphics/gpu-firmware-amd-kmod@vega12 \
		gpu-firmware-amd-kmod-vega20>0:graphics/gpu-firmware-amd-kmod@vega20 \
		gpu-firmware-amd-kmod-vegam>0:graphics/gpu-firmware-amd-kmod@vegam \
		gpu-firmware-amd-kmod-verde>0:graphics/gpu-firmware-amd-kmod@verde \
		gpu-firmware-amd-kmod-yellow-carp>0:graphics/gpu-firmware-amd-kmod@yellow_carp \
		gpu-firmware-amd-kmod-dcn-3-1-4>0:graphics/gpu-firmware-amd-kmod@dcn_3_1_4 \
		gpu-firmware-amd-kmod-dcn-3-1-5>0:graphics/gpu-firmware-amd-kmod@dcn_3_1_5 \
		gpu-firmware-amd-kmod-dcn-3-1-6>0:graphics/gpu-firmware-amd-kmod@dcn_3_1_6 \
		gpu-firmware-amd-kmod-dcn-3-2-0>0:graphics/gpu-firmware-amd-kmod@dcn_3_2_0 \
		gpu-firmware-amd-kmod-dcn-3-2-1>0:graphics/gpu-firmware-amd-kmod@dcn_3_2_1 \
		gpu-firmware-amd-kmod-dcn-3-5>0:graphics/gpu-firmware-amd-kmod@dcn_3_5 \
		gpu-firmware-amd-kmod-gc-9-4-3>0:graphics/gpu-firmware-amd-kmod@gc_9_4_3 \
		gpu-firmware-amd-kmod-gc-10-3-6>0:graphics/gpu-firmware-amd-kmod@gc_10_3_6 \
		gpu-firmware-amd-kmod-gc-10-3-7>0:graphics/gpu-firmware-amd-kmod@gc_10_3_7 \
		gpu-firmware-amd-kmod-gc-11-0-0>0:graphics/gpu-firmware-amd-kmod@gc_11_0_0 \
		gpu-firmware-amd-kmod-gc-11-0-1>0:graphics/gpu-firmware-amd-kmod@gc_11_0_1 \
		gpu-firmware-amd-kmod-gc-11-0-2>0:graphics/gpu-firmware-amd-kmod@gc_11_0_2 \
		gpu-firmware-amd-kmod-gc-11-0-3>0:graphics/gpu-firmware-amd-kmod@gc_11_0_3 \
		gpu-firmware-amd-kmod-gc-11-0-4>0:graphics/gpu-firmware-amd-kmod@gc_11_0_4 \
		gpu-firmware-amd-kmod-gc-11-5-0>0:graphics/gpu-firmware-amd-kmod@gc_11_5_0 \
		gpu-firmware-amd-kmod-psp-13-0-0>0:graphics/gpu-firmware-amd-kmod@psp_13_0_0 \
		gpu-firmware-amd-kmod-psp-13-0-4>0:graphics/gpu-firmware-amd-kmod@psp_13_0_4 \
		gpu-firmware-amd-kmod-psp-13-0-5>0:graphics/gpu-firmware-amd-kmod@psp_13_0_5 \
		gpu-firmware-amd-kmod-psp-13-0-6>0:graphics/gpu-firmware-amd-kmod@psp_13_0_6 \
		gpu-firmware-amd-kmod-psp-13-0-7>0:graphics/gpu-firmware-amd-kmod@psp_13_0_7 \
		gpu-firmware-amd-kmod-psp-13-0-8>0:graphics/gpu-firmware-amd-kmod@psp_13_0_8 \
		gpu-firmware-amd-kmod-psp-13-0-10>0:graphics/gpu-firmware-amd-kmod@psp_13_0_10 \
		gpu-firmware-amd-kmod-psp-13-0-11>0:graphics/gpu-firmware-amd-kmod@psp_13_0_11 \
		gpu-firmware-amd-kmod-psp-14-0-0>0:graphics/gpu-firmware-amd-kmod@psp_14_0_0 \
		gpu-firmware-amd-kmod-sdma-4-4-2>0:graphics/gpu-firmware-amd-kmod@sdma_4_4_2 \
		gpu-firmware-amd-kmod-sdma-5-2-6>0:graphics/gpu-firmware-amd-kmod@sdma_5_2_6 \
		gpu-firmware-amd-kmod-sdma-5-2-7>0:graphics/gpu-firmware-amd-kmod@sdma_5_2_7 \
		gpu-firmware-amd-kmod-sdma-6-0-0>0:graphics/gpu-firmware-amd-kmod@sdma_6_0_0 \
		gpu-firmware-amd-kmod-sdma-6-0-1>0:graphics/gpu-firmware-amd-kmod@sdma_6_0_1 \
		gpu-firmware-amd-kmod-sdma-6-0-2>0:graphics/gpu-firmware-amd-kmod@sdma_6_0_2 \
		gpu-firmware-amd-kmod-sdma-6-0-3>0:graphics/gpu-firmware-amd-kmod@sdma_6_0_3 \
		gpu-firmware-amd-kmod-sdma-6-1-0>0:graphics/gpu-firmware-amd-kmod@sdma_6_1_0 \
		gpu-firmware-amd-kmod-smu-13-0-0>0:graphics/gpu-firmware-amd-kmod@smu_13_0_0 \
		gpu-firmware-amd-kmod-smu-13-0-6>0:graphics/gpu-firmware-amd-kmod@smu_13_0_6 \
		gpu-firmware-amd-kmod-smu-13-0-7>0:graphics/gpu-firmware-amd-kmod@smu_13_0_7 \
		gpu-firmware-amd-kmod-smu-13-0-10>0:graphics/gpu-firmware-amd-kmod@smu_13_0_10 \
		gpu-firmware-amd-kmod-smu-14-0-2>0:graphics/gpu-firmware-amd-kmod@smu_14_0_2 \
		gpu-firmware-amd-kmod-vcn-3-1-2>0:graphics/gpu-firmware-amd-kmod@vcn_3_1_2 \
		gpu-firmware-amd-kmod-vcn-4-0-0>0:graphics/gpu-firmware-amd-kmod@vcn_4_0_0 \
		gpu-firmware-amd-kmod-vcn-4-0-2>0:graphics/gpu-firmware-amd-kmod@vcn_4_0_2 \
		gpu-firmware-amd-kmod-vcn-4-0-3>0:graphics/gpu-firmware-amd-kmod@vcn_4_0_3 \
		gpu-firmware-amd-kmod-vcn-4-0-4>0:graphics/gpu-firmware-amd-kmod@vcn_4_0_4 \
		gpu-firmware-amd-kmod-vcn-4-0-5>0:graphics/gpu-firmware-amd-kmod@vcn_4_0_5 \
		gpu-firmware-amd-kmod-vpe-6-1-0>0:graphics/gpu-firmware-amd-kmod@vpe_6_1_0
.endif

.include <bsd.port.post.mk>
