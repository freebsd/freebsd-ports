# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	10.6.5
PORTREVISION=	2
CATEGORIES=	graphics linux
LIB_DISTFILES=	mesa-libGL-${PORTVERSION}-3.20150824.el7${EXTRACT_SUFX} \
		mesa-libGLU-9.0.0-4.el7${EXTRACT_SUFX} \
		mesa-dri-drivers-${PORTVERSION}-3.20150824.el7${EXTRACT_SUFX} \
		libdrm-2.4.60-3.el7${EXTRACT_SUFX} \
		freeglut-2.8.1-3.el7${EXTRACT_SUFX}
SRC_DISTFILES=	mesa-${PORTVERSION}-3.20150824.el7${SRC_SUFX}:SOURCE \
		libdrm-2.4.60-3.el7${SRC_SUFX}:SOURCE \
		freeglut-2.8.1-3.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

USES=		linux:c7
USE_LINUX=	libpciaccess xorglibs
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/usr/lib/libGL.so.1

.include <bsd.port.mk>
