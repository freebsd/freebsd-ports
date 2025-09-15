PORTNAME=	nvidia-drm-61-kmod
PORTREVISION=	3
CATEGORIES=	graphics

BUILD_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-61-kmod
RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-61-kmod
CONFLICTS_INSTALL=	nvidia-drm-510-kmod* nvidia-drm-515-kmod* nvidia-drm-66-kmod*

.include "${.CURDIR}/../drm-61-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>
