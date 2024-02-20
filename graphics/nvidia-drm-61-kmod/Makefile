PORTNAME=	nvidia-drm-61-kmod
PORTVERSION=	${NVIDIA_DISTVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-61-kmod
CONFLICTS_INSTALL=	nvidia-drm-510-kmod nvidia-drm-515-kmod

.include "${.CURDIR}/../drm-61-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>
