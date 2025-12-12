PORTNAME=	libdrm
PORTVERSION=	2.4.131
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://dri.freedesktop.org/libdrm/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Direct Rendering Manager library and headers
WWW=		https://dri.freedesktop.org/

LICENSE=	MIT

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

USES=		gnome meson pkgconfig tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Dvalgrind=disabled

OPTIONS_DEFINE=	TESTS
OPTIONS_SUB=	yes

TESTS_DESC=	Build and install test programs

TESTS_MESON_TRUE=	install-test-programs

# avoid circular dependency in case cairo supports OpenGL (cairo->mesa-libs->libdrm->cairo)
CONFIGURE_ARGS+=	-Dcairo-tests=disabled

# Disable some targets known to not work on FreeBSD
MESON_ARGS+=	-Domap=disabled \
		-Dexynos=disabled \
		-Dfreedreno=disabled \
		-Dfreedreno-kgsl=false \
		-Dvc4=disabled \
		-Detnaviv=disabled \
		-Dnouveau=disabled

MESON_ARGS+=	-Dman-pages=enabled

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MESON_ARGS+=	-Dvmwgfx=enabled \
		-Dintel=enabled
.else
MESON_ARGS+=	-Dvmwgfx=disabled \
		-Dintel=disabled
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	AMD_DRIVERS=""
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	VMWGFX_DRIVERS=""
.elif ${ARCH:Mpowerpc*}
PLIST_SUB+=	AMD_DRIVERS=""
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	VMWGFX_DRIVERS="@comment "
.elif ${ARCH} == aarch64
PLIST_SUB+=	AMD_DRIVERS=""
PLIST_SUB+=	ARM_DRIVERS=""
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	VMWGFX_DRIVERS="@comment "
.elif ${ARCH:Marm*}
PLIST_SUB+=	AMD_DRIVERS=""
PLIST_SUB+=	ARM_DRIVERS=""
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	VMWGFX_DRIVERS="@comment "
.elif ${ARCH} == riscv64
PLIST_SUB+=	AMD_DRIVERS=""
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	VMWGFX_DRIVERS="@comment "
.else
PLIST_SUB+=	AMD_DRIVERS="@comment "
PLIST_SUB+=	ARM_DRIVERS="@comment "
PLIST_SUB+=	INTEL_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
PLIST_SUB+=	VMWGFX_DRIVERS="@comment "
.endif

.include <bsd.port.mk>
