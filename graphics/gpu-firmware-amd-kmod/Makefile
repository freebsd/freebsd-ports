PORTNAME=	gpu-firmware-amd-kmod
PORTVERSION=	20260519
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for ${FLAVOR} AMD GPUs
WWW=		https://github.com/freebsd/drm-kmod-firmware

LICENSE=	AMD
LICENSE_NAME=	AMD firmware license (amdgpu/radeon)
LICENSE_FILE=	${WRKSRC}/LICENSE.radeon
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	AMD GPUs are only available on aarch64, x86 and powerpc64le

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	aldebaran \
		aldebaran_ip_discovery \
		arcturus \
		arcturus_ip_discovery \
		banks \
		beige_goby \
		bonaire \
		carrizo \
		cyan_skillfish2 \
		dcn_3_1_4 \
		dcn_3_1_5 \
		dcn_3_1_6 \
		dcn_3_2_0 \
		dcn_3_2_1 \
		dcn_3_5 \
		dcn_3_5_1 \
		dcn_3_6 \
		dcn_4_0_1 \
		dimgrey_cavefish \
		fiji \
		gc_10_3_6 \
		gc_10_3_7 \
		gc_11_0_0 \
		gc_11_0_1 \
		gc_11_0_2 \
		gc_11_0_3 \
		gc_11_0_4 \
		gc_11_5_0 \
		gc_11_5_1 \
		gc_11_5_2 \
		gc_11_5_3 \
		gc_12_0_0 \
		gc_12_0_1 \
		gc_9_4_3 \
		gc_9_4_4 \
		gc_9_5_0 \
		green_sardine \
		hainan \
		hawaii \
		isp_4_1_1 \
		kabini \
		kaveri \
		mullins \
		navi10 \
		navi12 \
		navi14 \
		navy_flounder \
		oland \
		picasso \
		picasso_ip_discovery \
		pitcairn \
		polaris10 \
		polaris11 \
		polaris12 \
		psp_13_0_0 \
		psp_13_0_10 \
		psp_13_0_11 \
		psp_13_0_4 \
		psp_13_0_5 \
		psp_13_0_6 \
		psp_13_0_7 \
		psp_13_0_8 \
		psp_13_0_12 \
		psp_13_0_14 \
		psp_14_0_0 \
		psp_14_0_1 \
		psp_14_0_2 \
		psp_14_0_3 \
		psp_14_0_4 \
		psp_14_0_5 \
		raven \
		raven_ip_discovery \
		raven2 \
		raven2_ip_discovery \
		renoir \
		sdma_4_4_2 \
		sdma_4_4_4 \
		sdma_4_4_5 \
		sdma_5_2_6 \
		sdma_5_2_7 \
		sdma_6_0_0 \
		sdma_6_0_1 \
		sdma_6_0_2 \
		sdma_6_0_3 \
		sdma_6_1_0 \
		sdma_6_1_1 \
		sdma_6_1_2 \
		sdma_6_1_3 \
		sdma_7_0_0 \
		sdma_7_0_1 \
		si58 \
		sienna_cichlid \
		smu_13_0_0 \
		smu_13_0_10 \
		smu_13_0_6 \
		smu_13_0_7 \
		smu_13_0_14 \
		smu_14_0_2 \
		smu_14_0_3 \
		stoney \
		tahiti \
		tonga \
		topaz \
		umsch_mm_4_0_0 \
		vangogh \
		vcn_3_1_2 \
		vcn_4_0_0 \
		vcn_4_0_2 \
		vcn_4_0_3 \
		vcn_4_0_4 \
		vcn_4_0_5 \
		vcn_4_0_6 \
		vcn_4_0_6_1 \
		vcn_5_0_0 \
		vcn_5_0_1 \
		vega10 \
		vega10_ip_discovery \
		vega12 \
		vega12_ip_discovery \
		vega20 \
		vega20_ip_discovery \
		vegam \
		verde \
		vpe_6_1_0 \
		vpe_6_1_1 \
		vpe_6_1_3 \
		yellow_carp

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod-firmware
GH_TAGNAME=	20260519

MAKE_ENV=	KMODS="amdgpukmsfw"
MAKE_ENV+=	AMDGPUKMODS="${FLAVOR}"

.for flav in ${FLAVORS:O}
# Used to generate lines for graphics/gpu-firmware-kmod
DEPENDENCY_LINES+=	${PORTNAME}-${flav:C/_/-/g}>0:graphics/${PORTNAME}@${flav}
.endfor

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""

.include <bsd.port.post.mk>
