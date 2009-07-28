# New ports collection makefile for:	devel/linux-f10-dbus-libs
# Date created:				2009-07-27
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	dbus-libs
PORTVERSION=	1.2.4
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux Fedora 10)

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	4.fc10
USE_LDCONFIG=	yes
SRC_DISTFILES=	dbus-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
DESCR=		${.CURDIR}/../dbus/pkg-descr

PLIST_FILES=	lib/libdbus-1.so.3 lib/libdbus-1.so.3.4.0

.include <bsd.port.mk>
