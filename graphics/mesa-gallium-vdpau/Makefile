PORTNAME=	mesa-gallium-vdpau
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Mesa Gallium VDPAU drivers
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=		aarch64 i386 amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	used only by AMD/Radeon hardware

BUILD_DEPENDS=	libvdpau>=0:multimedia/libvdpau
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libgallium-${MESAVERSION}.so:graphics/mesa-libs

USES=		llvm:lib,noexport xorg

USE_XORG=	xorgproto x11 xcb xdamage xext xfixes xshmfence xxf86vm xrandr

OPTIONS_GROUP=		GALLIUM
OPTIONS_SUB=		yes

OPTIONS_GROUP_GALLIUM=	radeonsi r600
GALLIUM_DESC=		Gallium Video Drivers
radeonsi_DESC=		AMD/ATI Southern Islands and newer
r600_DESC=		AMD/ATI R600, R700, Evergreen, Northern Islands
OPTIONS_EXCLUDE+=	${ARCH:Mi386:C/.+/radeonsi/}

MESON_ARGS+=		-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
. for _gd in ${OPTIONS_GROUP_GALLIUM}
OPTIONS_DEFAULT+=	${_gd}
${_gd}_VARS+=		GALLIUM_DRIVERS+=${_gd}
. endfor

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dvulkan-drivers="" \
		-Dandroid-libbacktrace=disabled \
		-Dgallium-va=disabled \
		-Dgbm=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dglvnd=disabled \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dvalgrind=disabled \
		-Dglx=disabled

LDFLAGS_i386=	-Wl,-znotext

MESON_ARGS+=	-Dplatforms="x11" \
		-Dgallium-vdpau=enabled

.if ${ARCH} != amd64
MESON_ARGS+=	-Dintel-rt=disabled # https://gitlab.freedesktop.org/mesa/mesa/-/issues/10629
.endif

.for _gd in ${OPTIONS_GROUP_GALLIUM}
. if defined(GALLIUM_DRIVERS) && ${GALLIUM_DRIVERS:M${_gd}}
PLIST_SUB+=	${_gd}=""
. else
PLIST_SUB+=	${_gd}="@comment "
. endif
.endfor

post-install:
# Mesa 25: libgallium-${MESAVERSION}.so is owned by graphics/mesa-libs.
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libgallium-${MESAVERSION}.so
	${RM} -f ${STAGEDIR}${PREFIX}/lib/dri/r300_dri.so
	${RM} -f ${STAGEDIR}${PREFIX}/lib/dri/r600_dri.so
	${RM} -f ${STAGEDIR}${PREFIX}/lib/dri/radeonsi_dri.so

.include <bsd.port.post.mk>
