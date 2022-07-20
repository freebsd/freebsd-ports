PORTNAME=	gpu-firmware-radeon-kmod
PORTVERSION=	20220511
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Firmware modules for ${FLAVOR} Radeon GPUs

LICENSE=	RADEON
LICENSE_NAME=	Radeon firmware license (i915)
LICENSE_FILE=	${WRKSRC}/LICENSE.radeon
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Radeon GPUs are only available on aarch64, x86 and powerpc64

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	aruba \
		barts \
		bonaire \
		btc \
		caicos \
		cayman \
		cedar \
		cypress \
		hainan \
		hawaii \
		juniper \
		kabini \
		kaveri \
		mullins \
		oland \
		palm \
		pitcairn \
		r100 \
		r200 \
		r300 \
		r420 \
		r520 \
		r600 \
		r700 \
		redwood \
		rs600 \
		rs690 \
		rs780 \
		rv610 \
		rv620 \
		rv630 \
		rv635 \
		rv670 \
		rv710 \
		rv730 \
		rv740 \
		rv770 \
		sumo \
		sumo2 \
		tahiti \
		turks \
		verde

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod-firmware
GH_TAGNAME=	20220511

MAKE_ENV=	KMODS="radeonkmsfw"
MAKE_ENV+=	RADEONKMODS="${FLAVOR}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	${FLAVORS:N${FLAVOR}:@v@${v:tu}="\@comment "@}
PLIST_SUB+=	${FLAVOR:tu}=""

.include <bsd.port.post.mk>
