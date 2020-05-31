# $FreeBSD$

PORTNAME=	mesa
DISTVERSION=	20.1-branchpoint-1310
DISTVERSIONSUFFIX=	-gaaec065f03e
CATEGORIES=	graphics
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ee5c7790fa93.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	9f52b5177728.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	cefdea8105bf.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	55822330540d.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	f6c7569ad9ea.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	c7a2ab64144b.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	f3b7aba7ed39.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	23df7d9971dd.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1598
PATCHFILES+=	ec60ac47860a.patch:-p1
PATCHFILES+=	807ae077ab19.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/3568
PATCHFILES+=	1b10b42fe65e.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/1619
PATCHFILES+=	9291544ca0bd.patch:-p1
PATCHFILES+=	700efacda59c.patch:-p1
PATCHFILES+=	227ebbd9e837.patch:-p1
PATCHFILES+=	de60a36d5836.patch:-p1
PATCHFILES+=	0a500a8f4648.patch:-p1
PATCHFILES+=	15057d74fdb9.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bleeding edge Mesa drivers (OpenGL, Vulkan)

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Limited scope: no old drivers and no software rendering. \
			See also https://mesamatrix.net/
BROKEN_DragonFly=	requires making Vulkan support conditional

BUILD_DEPENDS=	glslangValidator:devel/glslang \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libLLVM-${LLVM_DEFAULT:C/^([6-9])0/\1/:S/-devel/11/}.so:devel/llvm${LLVM_DEFAULT} \
		libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2

USES=		bison compiler:c++11-lib meson pkgconfig python:3.6+,build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mesa3d
USE_LDCONFIG=	yes
BINARY_ALIAS=	llvm-config=llvm-config${LLVM_DEFAULT} python=${PYTHON_CMD}
SHEBANG_FILES=	src/vulkan/overlay-layer/${PORTNAME}-overlay-control.py
PLATFORMS=	${PORT_OPTIONS:MX11:tl} ${PORT_OPTIONS:MWAYLAND:tl} drm surfaceless
MESON_ARGS=	-Ddri-drivers=i965 \
		-Dgallium-drivers=iris,r600,radeonsi \
		-Dgallium-omx=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-va=false \
		-Dgallium-vdpau=false \
		-Dgallium-xa=false \
		-Dgallium-xvmc=false \
		-Dplatforms=${PLATFORMS:ts,} \
		-Dvulkan-device-select-layer=true \
		-Dvulkan-overlay-layer=true \
		${PKGNAMESUFFIX:S/^/-Degl-lib-suffix=/} \
		${NULL}
SUB_FILES=	libmap.conf
SUB_LIST=	PKGNAMESUFFIX=${PKGNAMESUFFIX}
PLIST_SUB=	ARCH=${ARCH:S/amd/x86_/} PKGNAMESUFFIX=${PKGNAMESUFFIX}

.if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --build-id isn't supported by old GNU ld.bfd in base
LDFLAGS+=	-fuse-ld=lld
.endif

OPTIONS_DEFINE=		LIBUNWIND VAAPI VDPAU WAYLAND X11 ZSTD
OPTIONS_DEFAULT=	LIBUNWIND VAAPI VDPAU WAYLAND X11 ZSTD
OPTIONS_SUB=		yes

LIBUNWIND_DESC=		Use libunwind for stacktraces
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_TRUE=	libunwind

VAAPI_BUILD_DEPENDS=	libva>0:multimedia/libva
VAAPI_MESON_TRUE=	gallium-va

VDPAU_BUILD_DEPENDS=	libvdpau>0:multimedia/libvdpau
VDPAU_MESON_TRUE=	gallium-vdpau

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xcb,xdamage,xext,xfixes,xorgproto,xrandr,xshmfence,xxf86vm
X11_MESON_OFF=		-Dglx=disabled

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_TRUE=	zstd

post-patch:
# Extract (snapshot) version from the port instead of empty string
	@${REINPLACE_CMD} '/MESA_GIT_SHA1/s/""/" (git-${DISTVERSIONSUFFIX:C/.*-g//})"/' \
		${WRKSRC}/bin/git_sha1_gen.py
.if defined(PKGNAMESUFFIX)
	@${MV} ${WRKSRC}/src/egl/main/50_${PORTNAME}.json \
		${WRKSRC}/src/egl/main/50_${PKGBASE}.json
	@${MV} ${WRKSRC}/src/util/00-${PORTNAME}-defaults.conf \
		${WRKSRC}/src/util/00-${PKGBASE}-defaults.conf
.endif

post-install:
.if defined(PKGNAMESUFFIX)
	@${INSTALL_DATA} ${WRKDIR}/libmap.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/${PKGBASE}.conf.sample
.endif

.include <bsd.port.mk>
