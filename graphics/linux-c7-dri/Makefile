# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	17.0.1
CATEGORIES=	graphics linux
LIB_DISTNAMES=	mesa-libEGL-${DISTVERSIONFULL} \
		mesa-libGL-${DISTVERSIONFULL} \
		mesa-libGLU-9.0.0-4.el7 \
		mesa-libgbm-${DISTVERSIONFULL} \
		mesa-libglapi-${DISTVERSIONFULL} \
		mesa-dri-drivers-${DISTVERSIONFULL} \
		mesa-private-llvm-3.9.1-3.el7 \
		libdrm-2.4.74-1.el7 \
		freeglut-2.8.1-3.el7
SRC_DISTFILES=	mesa-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \
		mesa-libGLU-9.0.0-4.el7${SRC_SUFX}:SOURCE \
		mesa-private-llvm-3.9.1-3.el7${SRC_SUFX}:SOURCE \
		libdrm-2.4.74-1.el7${SRC_SUFX}:SOURCE \
		freeglut-2.8.1-3.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	6.20170307.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat libelf libpciaccess xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1

.include <bsd.port.mk>
