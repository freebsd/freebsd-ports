PORTNAME=	gpu-firmware-amd-kmod
PORTVERSION=	20230625
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
		fiji \
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
		raven \
		raven2 \
		renoir \
		si58 \
		stoney \
		tahiti \
		tonga \
		topaz \
		vega10 \
		vega12 \
		vega20 \
		vegam \
		verde \
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
GH_TAGNAME=	20230625_4

MAKE_ENV=	KMODS="amdgpukmsfw"
MAKE_ENV+=	AMDGPUKMODS="${FLAVOR}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""

.include <bsd.port.post.mk>
