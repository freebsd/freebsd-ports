PORTNAME=	gpu-firmware-amd-kmod
PORTVERSION=	20250109
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
		arcturus \
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
		fiji \
		gc_9_4_3 \
		gc_10_3_6 \
		gc_10_3_7 \
		gc_11_0_0 \
		gc_11_0_1 \
		gc_11_0_2 \
		gc_11_0_3 \
		gc_11_0_4 \
		gc_11_5_0 \
		hainan \
		hawaii \
		kabini \
		kaveri \
		mullins \
		navi10 \
		navi12 \
		navi14 \
		oland \
		picasso \
		pitcairn \
		polaris10 \
		polaris11 \
		polaris12 \
		psp_13_0_0 \
		psp_13_0_4 \
		psp_13_0_5 \
		psp_13_0_6 \
		psp_13_0_7 \
		psp_13_0_8 \
		psp_13_0_10 \
		psp_13_0_11 \
		psp_14_0_0 \
		raven \
		raven2 \
		renoir \
		sdma_4_4_2 \
		sdma_5_2_6 \
		sdma_5_2_7 \
		sdma_6_0_0 \
		sdma_6_0_1 \
		sdma_6_0_2 \
		sdma_6_0_3 \
		sdma_6_1_0 \
		si58 \
		smu_13_0_0 \
		smu_13_0_6 \
		smu_13_0_7 \
		smu_13_0_10 \
		smu_14_0_2 \
		stoney \
		tahiti \
		tonga \
		topaz \
		vcn_3_1_2 \
		vcn_4_0_0 \
		vcn_4_0_2 \
		vcn_4_0_3 \
		vcn_4_0_4 \
		vcn_4_0_5 \
		vega10 \
		vega12 \
		vega20 \
		vegam \
		verde \
		vpe_6_1_0 \
		dimgrey_cavefish \
		green_sardine \
		navy_flounder \
		sienna_cichlid \
		vangogh \
		yellow_carp

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod-firmware
GH_TAGNAME=	20250109

MAKE_ENV=	KMODS="amdgpukmsfw"
MAKE_ENV+=	AMDGPUKMODS="${FLAVOR}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""

.include <bsd.port.post.mk>
