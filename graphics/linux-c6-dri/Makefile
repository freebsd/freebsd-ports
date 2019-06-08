# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	11.0.7
DISTVERSIONSUFFIX=	-4.el6
PORTREVISION=	5
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	expat libelf libpciaccess xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	mesa-libGL-${DISTVERSIONFULL} \
		mesa-libGLU-${DISTVERSIONFULL} \
		mesa-dri-drivers-${DISTVERSIONFULL} \
		mesa-private-llvm-3.6.2-1.el6 \
		libdrm-2.4.65-2.el6 \
		freeglut-2.6.0-1.el6
SRC_DISTFILES=	mesa-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \
		mesa-private-llvm-3.6.2-1.el6${SRC_SUFX}:SOURCE \
		libdrm-2.4.65-2.el6${SRC_SUFX}:SOURCE \
		freeglut-2.6.0-1.el6${SRC_SUFX}:SOURCE

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1

.include <bsd.port.mk>
