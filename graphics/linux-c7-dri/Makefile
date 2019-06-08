# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	18.0.5
DISTVERSIONSUFFIX=	-4.el7_6
CATEGORIES=	graphics linux
LIB_DISTNAMES=	freeglut-3.0.0-8.el7 \
		libdrm-2.4.91-3.el7 \
		llvm-private-6.0.1-2.el7 \
		mesa-dri-drivers-${DISTVERSIONFULL} \
		mesa-libEGL-${DISTVERSIONFULL} \
		mesa-libGL-${DISTVERSIONFULL} \
		mesa-libGLES-${DISTVERSIONFULL} \
		mesa-libGLU-9.0.0-4.el7 \
		mesa-libOSMesa-${DISTVERSIONFULL} \
		mesa-libgbm-${DISTVERSIONFULL} \
		mesa-libglapi-${DISTVERSIONFULL} \
		mesa-libxatracker-${DISTVERSIONFULL} \
		mesa-vdpau-drivers-${DISTVERSIONFULL}
DISTFILES_amd64=${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
		mesa-vulkan-drivers-${DISTVERSIONFULL}${EXTRACT_SUFX_amd64}:amd64
SRC_DISTFILES=	freeglut-3.0.0-8.el7${SRC_SUFX}:SOURCE \
		libdrm-2.4.91-3.el7${SRC_SUFX}:SOURCE \
		llvm-private-6.0.1-2.el7${SRC_SUFX}:SOURCE \
		mesa-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \
		mesa-libGLU-9.0.0-4.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat libelf libglvnd libpciaccess wayland xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-install:
	${LN} -sf libGLX_mesa.so.0 \
		${STAGEDIR}${PREFIX}/usr/lib/libGLX_system.so.0
.if ${LINUX_ARCH} == x86_64
	${LN} -sf libGLX_mesa.so.0 \
		${STAGEDIR}${PREFIX}/usr/lib64/libGLX_system.so.0
.endif

.include <bsd.port.post.mk>
