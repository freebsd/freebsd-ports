# Created by: bsam
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	7.2
PORTREVISION=	1
CATEGORIES=	graphics linux
BIN_DISTFILES=	Glide3-20050815-7.fc9${EXTRACT_SUFX} \
		freeglut-2.4.0-14.fc9${EXTRACT_SUFX} \
		libdrm-2.4.0-0.21.fc10${EXTRACT_SUFX} \
		mesa-dri-drivers-7.2-0.15.fc10${EXTRACT_SUFX} \
		mesa-libGL-7.2-0.15.fc10${EXTRACT_SUFX} \
		mesa-libGLU-7.2-0.15.fc10${EXTRACT_SUFX}
SRC_DISTFILES=	Glide3-20050815-7.fc9.src.rpm:SOURCE \
		freeglut-2.4.0-14.fc9.src.rpm:SOURCE \
		libdrm-2.4.0-0.21.fc10.src.rpm:SOURCE \
		mesa-7.2-0.15.fc10.src.rpm:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGL runtime libraries and DRI drivers (Linux Fedora 10)

CONFLICTS=	linux_dri-[0-9]* linux_dri-devel-[0-9]* linux-f8-dri-[0-9]* linux-dri-[0-9]*

USES=		linux:f10
USE_LINUX=	xorglibs
USE_LINUX_RPM=	nolib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
