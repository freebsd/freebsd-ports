# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dbus-libs
PORTVERSION=	1.2.24
PORTREVISION=	5
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux CentOS ${LINUX_DIST_VER})


USES=		linux:c6
USE_LINUX_RPM=	yes
RPMVERSION=	8.el6_6
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../dbus/pkg-descr

CONFLICTS=	linux-dbus-libs-[0-9]*  linux-f10-dbus-libs-[0-9]*

SRC_DISTFILES=	dbus-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
