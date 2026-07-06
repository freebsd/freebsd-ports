PORTNAME=	nvidia-drm-66-kmod
PORTREVISION=	1
CATEGORIES=	graphics

RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-66-kmod
CONFLICTS_INSTALL=	nvidia-drm-515-kmod* nvidia-drm-61-kmod* nvidia-drm-612-kmod* nvidia-drm-latest-kmod*

.include "${.CURDIR}/../drm-66-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>
