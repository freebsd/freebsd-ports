# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47
PORTVERSION=	4.7.2
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	LOCAL/xmj
DIST_SUBDIR=    rpm/${LINUX_RPM_ARCH}/centos/c5

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 5)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	fontconfig png dbuslibs sqlite3 hicontheme
USE_LINUX_RPM=	yes
RPMVERSION=	1_18.el5
LINUX_RPM_ARCH=	i386
USE_LDCONFIG=	yes
LINUX_DIST_VER=	5 # need centos 6 infrastructure, even though port is from centos 5
DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr

SRC_DISTFILES:=	# no file available, nowhere

.include <bsd.port.mk>
