# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47
PORTVERSION=	4.7.2
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	http://dl.atrpms.net/el6-${LINUX_REPO_ARCH}/atrpms/testing/ LOCAL/xmj
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/atrpms/6

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 6)

BROKEN=		unfetchable
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	fontconfig png dbuslibs sqlite3 hicontheme
USE_LINUX_RPM=	yes
RPMVERSION=	1_18.el6
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr

SRC_DISTFILES:=	# no file available

.include <bsd.port.mk>
