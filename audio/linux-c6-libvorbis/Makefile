# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libvorbis
PORTVERSION=	1.2.3
PORTREVISION=	3
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libvorbis-[0-9]* linux-f10-libvorbis-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes
USE_LINUX=	libogg

RPMVERSION=	4.el6_2.1
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
