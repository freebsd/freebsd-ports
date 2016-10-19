# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libGLU
PORTVERSION=	9.0.0
CATEGORIES=	graphics linux
DISTNAME=	mesa-${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa libGLU runtime libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-dri-[0-9]* linux-f10-${PORTNAME}-[0-9]* linux-c6-dri-[0-9]* linux-c7-dri-[0-9]*

RPMVERSION=	4.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
