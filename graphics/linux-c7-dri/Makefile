# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	10.6.5
PORTREVISION=	5
CATEGORIES=	graphics linux
LIB_DISTFILES=	mesa-libEGL-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		mesa-libGL-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		mesa-libGLU-9.0.0-4.el7${EXTRACT_SUFX} \
		mesa-libgbm-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		mesa-libglapi-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		mesa-dri-drivers-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		mesa-private-llvm-3.6.2-2.el7${EXTRACT_SUFX} \
		libdrm-2.4.60-3.el7${EXTRACT_SUFX} \
		freeglut-2.8.1-3.el7${EXTRACT_SUFX}
SRC_DISTFILES=	mesa-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE \
		mesa-private-llvm-3.6.2-2.el7${SRC_SUFX}:SOURCE \
		libdrm-2.4.60-3.el7${SRC_SUFX}:SOURCE \
		freeglut-2.8.1-3.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	3.20150824.el7
USES=		linux:c7
USE_LINUX=	expat libelf libpciaccess xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libEGL.so.1
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib64/libGL.so.1

.include <bsd.port.mk>
