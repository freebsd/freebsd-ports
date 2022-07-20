PORTNAME=	dri
PORTVERSION=	18.3.4
DISTVERSIONSUFFIX=	-12.el7_9
PORTREVISION=	4
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libelf expat libdrm libglvnd wayland xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	freeglut-3.0.0-8.el7 \
		llvm-private-7.0.1-1.el7 \
		mesa-dri-drivers-${DISTVERSIONFULL} \
		mesa-libEGL-${DISTVERSIONFULL} \
		mesa-libGL-${DISTVERSIONFULL} \
		mesa-libGLES-${DISTVERSIONFULL} \
		mesa-libGLU-9.0.0-4.el7 \
		mesa-libOSMesa-${DISTVERSIONFULL} \
		mesa-libgbm-${DISTVERSIONFULL} \
		mesa-libglapi-${DISTVERSIONFULL} \
		mesa-vdpau-drivers-${DISTVERSIONFULL}

LIB_DISTNAMES_amd64=	mesa-vulkan-drivers-${DISTVERSIONFULL} \
		mesa-libxatracker-${DISTVERSIONFULL}

LIB_DISTNAMES_i386=	mesa-vulkan-drivers-${DISTVERSIONFULL} \
		mesa-libxatracker-${DISTVERSIONFULL}

SRC_DISTFILES=	freeglut-3.0.0-8.el7${SRC_SUFX}:SOURCE \
		llvm-private-7.0.1-1.el7${SRC_SUFX}:SOURCE \
		mesa-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \
		mesa-libGLU-9.0.0-4.el7${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${ARCH} == amd64  ||  ${ARCH} == i386
	${LN} -sf libGLX_mesa.so.0 \
		${STAGEDIR}${PREFIX}/usr/lib/libGLX_system.so.0
.endif
.if ${ARCH} == aarch64 || ${ARCH} == amd64
	${LN} -sf libGLX_mesa.so.0 \
		${STAGEDIR}${PREFIX}/usr/lib64/libGLX_system.so.0
.endif

.include <bsd.port.mk>
