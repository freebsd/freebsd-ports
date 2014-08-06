# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47
PORTVERSION=	4.7.2
RPMVERSION=	1_18.el5
DIST_SUBDIR=    rpm/${LINUX_RPM_ARCH}/centos/c5
SRC_DISTFILES:=	# no file available, nowhere

CATEGORIES=	devel linux
MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 5)

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	xmj

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	fontconfig png dbuslibs sqlite3
USE_LINUX_RPM=	yes
LINUX_RPM_ARCH=	i386
USE_LDCONFIG=	yes
LINUX_DIST_VER=	5 # need centos 6 infrastructure, even though port is from centos 5
DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr

.include <bsd.port.mk>
