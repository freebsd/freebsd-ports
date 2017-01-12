# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47
PORTVERSION=	4.7.2
PORTREVISION=	3
CATEGORIES=	devel linux
MASTER_SITES=	https://www.mirrorservice.org/sites/dl.atrpms.net/el6-i386/atrpms/testing/ \
		https://www.mirrorservice.org/sites/dl.atrpms.net/el6-x86_64/atrpms/testing/ \
		LOCAL/xmj
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/atrpms/6

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 6)

RPMVERSION=	1_18.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png dbuslibs sqlite3 hicontheme openssl
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../qt4/pkg-descr
SRC_DISTFILES=	# no file available

.include <bsd.port.mk>
