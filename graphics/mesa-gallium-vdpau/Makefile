PORTNAME=	mesa-gallium-vdpau
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	Mesa Gallium VDPAU drivers

LIB_DEPENDS=	libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libzstd.so:archivers/zstd

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
X11_DESC=		Enable X11 support
X11_USES=		xorg
X11_USE=		xorg=xorgproto,x11,xcb,xdamage,xext,xfixes,xshmfence,xxf86vm,xrandr

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ONLY_FOR_ARCHS=		i386 amd64 aarch64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Used only by amd/radeon hardware

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers="r300,r600,radeonsi" \
		-Dvulkan-drivers="" \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-xvmc=disabled \
		-Dgallium-nine=false \
		-Dgbm=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dosmesa=none \
		-Dglx=disabled \
		-Ddri3=disabled

LDFLAGS_i386=	-Wl,-znotext

MESON_ARGS+=	-Dgallium-vdpau=enabled

.if ${PORT_OPTIONS:MX11}
MESON_ARGS+=	-Dplatforms="x11"
.else
MESON_ARGS+=	-Dglx=disabled \
		-Degl=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled
.endif

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
