# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libpciaccess
PORTVERSION=	0.13.4
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Generic PCI access library (CentOS ${LINUX_DIST_VER})

# LICENSE=	Various GNU

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
RPMVERSION=	1.el6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESC=	${.CURDIR}/../${PORTNAME}/pkg-descr

PLIST_SUB+=	NLS=""

.include <bsd.port.mk>
