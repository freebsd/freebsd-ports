# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	11.0.7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the GLX utils (Linux CentOS ${LINUX_DIST_VER})

DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/centos/${LINUX_DIST_VER}

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	nolib
RPMVERSION=	4.el6
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NVIDIA_GL
NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver \
			linux-c6-libGLU>0:graphics/linux-c6-libGLU
NVIDIA_GL_USE_OFF=	linux_apps=dri

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
.endif

.include <bsd.port.mk>
