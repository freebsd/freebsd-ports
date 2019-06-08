# $FreeBSD$

PORTNAME=	libglvnd
PORTVERSION=	1.0.1
DISTVERSIONSUFFIX=	-0.8.git5baa1e5.el7
CATEGORIES=	graphics linux
LIB_DISTNAMES=	libglvnd-${DISTVERSIONFULL} \
		libglvnd-egl-${DISTVERSIONFULL} \
		libglvnd-gles-${DISTVERSIONFULL} \
		libglvnd-glx-${DISTVERSIONFULL} \
		libglvnd-opengl-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GL Vendor-Neutral Dispatch library (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1

.include <bsd.port.mk>
