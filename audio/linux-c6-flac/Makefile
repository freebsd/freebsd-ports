# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Free lossless audio codec (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-flac-[0-9]* linux-f10-flac-[0-9]*

RPMVERSION=	7.el6_6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	libogg
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
