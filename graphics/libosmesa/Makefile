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
		-Dgallium-drivers="swrast" \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-va=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-xvmc=disabled \
		-Dgallium-nine=false \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dopengl=true \
		-Dglx=disabled \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dtools="" \
		-Dzstd=disabled
LDFLAGS_i386=		-Wl,-znotext

MESON_ARGS+=	-Dosmesa=true

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.post.mk>
