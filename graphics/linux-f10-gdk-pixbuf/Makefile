# Created by: bsam
# $FreeBSD$

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Image loading library for GTK+ (Linux Fedora 10)

CONFLICTS=	linux-gdk-pixbuf-[0-9]* linux-f8-gdk-pixbuf-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	36.fc9
USE_LDCONFIG=	yes

.include <bsd.port.mk>
