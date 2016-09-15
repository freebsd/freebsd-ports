# Created by: bsam
# $FreeBSD$

PORTNAME=	dbus-libs
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux Fedora 10)

USES=		linux:f10
USE_LINUX_RPM=	yes

RPMVERSION=	4.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	dbus-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
DESCR=		${.CURDIR}/../dbus/pkg-descr

PLIST_FILES=	lib/libdbus-1.so.3 lib/libdbus-1.so.3.4.0

.include <bsd.port.mk>
