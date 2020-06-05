# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Off-Screen Mesa implementation of the OpenGL API

USES=		xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"


# Disable some options
MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers=swrast \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dgallium-vdpau=false \
		-Dgallium-omx=disabled \
		-Dgallium-va=false \
		-Dgallium-opencl=disabled \
		-Dgallium-xa=false \
		-Dgallium-xvmc=false \
		-Dgallium-nine=false \
		-Dgles1=false \
		-Dgles2=false \
		-Dopengl=false \
		-Dglx=disabled \
		-Degl=false \
		-Dgbm=false \
		-Dtools=""
LDFLAGS_i386=		-Wl,-znotext

.if ${ARCH} == sparc64
MESON_ARGS+=	-Dosmesa=classic
.else
MESON_ARGS+=	-Dosmesa=gallium
.endif

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.post.mk>
