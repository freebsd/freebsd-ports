PORTNAME=	libglvnd
PORTVERSION=	1.0.1
DISTVERSIONSUFFIX=	-0.8.git5baa1e5.el7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GL Vendor-Neutral Dispatch library (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

CONFLICTS_INSTALL=	linux-nvidia-libs linux-nvidia-libs-*

LIB_DISTNAMES=	libglvnd-${DISTVERSIONFULL} \
		libglvnd-egl-${DISTVERSIONFULL} \
		libglvnd-gles-${DISTVERSIONFULL} \
		libglvnd-glx-${DISTVERSIONFULL} \
		libglvnd-opengl-${DISTVERSIONFULL}

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGLESv1_CM.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGLESv2.so.2
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGLX.so.0
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGLdispatch.so.0
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libOpenGL.so.0
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGLESv1_CM.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGLESv2.so.2
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGLX.so.0
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGLdispatch.so.0
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libOpenGL.so.0

.include <bsd.port.mk>
