PORTNAME=	nvidia-drm-latest-kmod
PORTREVISION=	1
CATEGORIES=	graphics

RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-latest-kmod
CONFLICTS_INSTALL=	nvidia-drm-510-kmod* nvidia-drm-515-kmod* nvidia-drm-61-kmod* nvidia-drm-66-kmod*

.include "${.CURDIR}/../drm-latest-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>
