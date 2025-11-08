PORTNAME=	nvidia-drm-515-kmod
PORTREVISION=	0
CATEGORIES=	graphics

RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-515-kmod
CONFLICTS_INSTALL=	nvidia-drm-510-kmod* nvidia-drm-61-kmod* nvidia-drm-66-kmod*

.include "${.CURDIR}/../drm-515-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>
