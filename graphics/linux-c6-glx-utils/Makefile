# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	glx-utils
PORTVERSION=	10.1.2
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the GLX utils (Linux CentOS ${LINUX_DIST_VER})

DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/centos/${LINUX_DIST_VER}

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	2.el6
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NVIDIA_GL
NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
			linux-c6-libGLU>0:${PORTSDIR}/graphics/linux-c6-libGLU
NVIDIA_GL_USE_OFF=	linux_apps=dri

PLIST_FILES=	usr/bin/glxgears usr/bin/glxinfo \
		usr/bin/xdriinfo usr/share/man/man1/xdriinfo.1.gz

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	mesa-10.1.2-2.el6.src.rpm
.endif

.include <bsd.port.mk>
