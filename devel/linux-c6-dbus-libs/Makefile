# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dbus-libs
PORTVERSION=	1.2.24
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	7.el6_3
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../dbus/pkg-descr

PLIST_FILES=	lib/libdbus-1.so.3 lib/libdbus-1.so.3.4.0

CONFLICTS=	linux-dbus-libs-[0-9]*  linux-f10-dbus-libs-[0-9]*

SRC_DISTFILES=	dbus-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}

.include <bsd.port.mk>
