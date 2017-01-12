# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	11.0.7
PORTREVISION=	4
CATEGORIES=	graphics linux
LIB_DISTFILES=	mesa-libGL-${PORTVERSION}-4.el6${EXTRACT_SUFX} \
		mesa-libGLU-${PORTVERSION}-4.el6${EXTRACT_SUFX} \
		mesa-dri-drivers-${PORTVERSION}-4.el6${EXTRACT_SUFX} \
		mesa-private-llvm-3.6.2-1.el6${EXTRACT_SUFX} \
		libdrm-2.4.65-2.el6${EXTRACT_SUFX} \
		freeglut-2.6.0-1.el6${EXTRACT_SUFX}
SRC_DISTFILES=	mesa-${PORTVERSION}-4.el6.src.rpm:SOURCE \
		mesa-private-llvm-3.6.2-1.el6.src.rpm:SOURCE \
		libdrm-2.4.65-2.el6.src.rpm:SOURCE \
		freeglut-2.6.0-1.el6.src.rpm:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f10-dri-[0-9]* linux-dri-[0-9]*

USES=		linux:c6
USE_LINUX=	expat libelf libpciaccess xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1

.include <bsd.port.mk>
