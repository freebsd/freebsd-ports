# $FreeBSD$

PORTNAME=	mesa
DISTVERSION=	20.1-branchpoint-1696
DISTVERSIONSUFFIX=	-g67ad75a282d
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
PATCHFILES+=	614e5280165b.patch:-p1
PATCHFILES+=	15057d74fdb9.patch:-p1
PATCHFILES+=	4902067868ea.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bleeding edge Mesa drivers (OpenGL, Vulkan)

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	Limited scope: no old drivers and no software rendering. \
			See also https://mesamatrix.net/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2
.if !exists(/usr/lib/libelf.so)
# DragonFly doesn't install it yet
LIB_DEPENDS+=	libelf.so:devel/libelf
.endif

USES=		bison compiler:c++11-lib meson pkgconfig python:3.6+,build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mesa3d
USE_LDCONFIG=	yes
BINARY_ALIAS=	python=${PYTHON_CMD}
SHEBANG_FILES=	src/vulkan/overlay-layer/${PORTNAME}-overlay-control.py
PLATFORMS=	${PORT_OPTIONS:MX11:tl} ${PORT_OPTIONS:MWAYLAND:tl} drm surfaceless
MESON_ARGS=	-Dgallium-omx=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-xvmc=disabled \
		-Dplatforms=${PLATFORMS:ts,} \
		${BINARY_ALIAS:D--native-file=binary_alias.ini} \
		${NULL}
PLIST_SUB=	ARCH=${ARCH:S/amd/x86_/}

.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --build-id isn't supported by old GNU ld.bfd in base
LDFLAGS+=	-fuse-ld=lld
.endif

OPTIONS_DEFINE=		${OPTIONS_MULTI} LIBUNWIND LLVM NLS VAAPI VDPAU WAYLAND X11 ZSTD
OPTIONS_DEFAULT=	${OPTIONS_MULTI} LIBUNWIND LLVM VAAPI VDPAU WAYLAND X11 ZSTD
OPTIONS_MULTI=		DRI GALLIUM VULKAN
OPTIONS_MULTI_DRI=	i965
OPTIONS_MULTI_GALLIUM=	iris r600 radeonsi
OPTIONS_MULTI_VULKAN=	anv radv
OPTIONS_EXCLUDE_DragonFly=	LIBUNWIND anv
OPTIONS_EXCLUDE+=	${ARCH:Namd64:Ni386:C/.+/anv i965 iris/}
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:Namd64:Ni386:C/.+/LIBUNWIND/}
OPTIONS_EXCLUDE+=	${"${GL_DEFAULT:S/,/ /g:[-1]}"==${.CURDIR:T}:?COINST:}
OPTIONS_EXCLUDE+=	${"${GL_DEFAULT:S/,/ /g:[1]}"!=libglvnd:?GLVND:}
OPTIONS_SLAVE+=		${"${GL_DEFAULT:S/,/ /g:[-1]}"!=${.CURDIR:T}:?COINST:}
OPTIONS_SLAVE+=		${"${GL_DEFAULT:S/,/ /g:[1]}"==libglvnd:?GLVND:}
OPTIONS_SUB=		yes

# Convert options to -D<type>-drivers=<driver1,driver2,etc>
.for i in ${OPTIONS_MULTI}
MESON_ARGS+=		-D${i:tl}-drivers=${${i}_DRIVERS:ts,}
. for j in ${OPTIONS_MULTI_${i}}
OPTIONS_DEFAULT+=	${j}
${j}_VARS+=		${i}_DRIVERS+=${j:S/anv/intel/:S/radv/amd/}
. endfor
.endfor

DRI_DESC=		Classic OpenGL drivers
i965_DESC=		GMA 3000 (Gen4) and newer

GALLIUM_DESC=		Unified OpenGL drivers
iris_DESC=		Broadwell and newer
r600_DESC=		R600, R700, Evergreen, Northern Islands
radeonsi_DESC=		Southern Islands and newer

COINST_DESC=		Allow co-installation with another Mesa port
COINST_MESON_ON=	-Degl-lib-suffix=${PKGNAMESUFFIX}
COINST_PLIST_SUB=	SUFFIX=${PKGNAMESUFFIX}
COINST_SUB_FILES=	libmap.conf
COINST_SUB_LIST=	SUFFIX=${PKGNAMESUFFIX}
COINST_PLIST_SUB_OFF=	SUFFIX=

GLVND_DESC=		GL Vendor-Neutral Dispatch support
GLVND_BUILD_DEPENDS=	libglvnd>0:graphics/libglvnd
GLVND_MESON_TRUE=	glvnd

LIBUNWIND_DESC=		Use libunwind for stacktraces
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_ENABLED=	libunwind

LLVM_DESC=		Build with LLVM support
LLVM_LIB_DEPENDS=	libLLVM-${LLVM_DEFAULT:C/^([6-9])0/\1/:S/-devel/11/}.so:devel/llvm${LLVM_DEFAULT}
LLVM_MESON_ENABLED=	llvm
LLVM_BINARY_ALIAS=	llvm-config=llvm-config${LLVM_DEFAULT}
.for i in r600 radeonsi radv
${i}_IMPLIES+=		LLVM
.endfor

NLS_USES=		gettext-tools

VAAPI_BUILD_DEPENDS=	libva>0:multimedia/libva
VAAPI_MESON_ENABLED=	gallium-va

VDPAU_BUILD_DEPENDS=	libvdpau>0:multimedia/libvdpau
VDPAU_MESON_ENABLED=	gallium-vdpau

VULKAN_DESC=		Vulkan drivers and layers
VULKAN_BUILD_DEPENDS=	glslangValidator:devel/glslang
VULKAN_MESON_TRUE=	vulkan-device-select-layer vulkan-overlay-layer
anv_DESC=		Haswell and newer
radv_DESC=		Southern Islands and newer

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xcb,xdamage,xext,xfixes,xorgproto,xrandr,xshmfence,xxf86vm
X11_MESON_OFF=		-Dglx=disabled

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	zstd

post-extract:
# Work around Meson lookup order e.g., llvm-config
.if defined(BINARY_ALIAS)
	@${ECHO_CMD} '[binaries]' >${WRKSRC}/binary_alias.ini
	@for f in ${BINARY_ALIAS}; do \
		${ECHO_CMD} "$${f%%=*} = '$${f#*=}'"; \
	done >>${WRKSRC}/binary_alias.ini
.endif

post-patch:
# Extract (snapshot) version from the port instead of empty string
	@${REINPLACE_CMD} '/MESA_GIT_SHA1/s/""/" (git-${DISTVERSIONSUFFIX:C/.*-g//})"/' \
		${WRKSRC}/bin/git_sha1_gen.py

post-patch-COINST-on:
	@${MV} ${WRKSRC}/src/util/00-${PORTNAME}-defaults.conf \
		${WRKSRC}/src/util/00-${PKGBASE}-defaults.conf

pre-build-NLS-on:
# Meson doesn't automatically generate translations
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} xmlpool-gmo

post-install-COINST-on:
	@${INSTALL_DATA} ${WRKDIR}/libmap.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/${PKGBASE}.conf.sample

.include <bsd.port.mk>
