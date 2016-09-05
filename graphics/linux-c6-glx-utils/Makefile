# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	11.0.7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the GLX utils (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LINUX_RPM=	nolib
RPMVERSION=	4.el6
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NVIDIA_GL
NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver \
			linux-c6-libGLU>0:graphics/linux-c6-libGLU
NVIDIA_GL_USE_OFF=	LINUX=dri

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
.endif

.include <bsd.port.mk>
