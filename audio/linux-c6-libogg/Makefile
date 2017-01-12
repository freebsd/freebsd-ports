# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libogg
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Ogg bitstream library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libogg-[0-9]* linux-f10-libogg-[0-9]*

USES=		linux:c6
USE_LINUX_RPM=	yes

RPMVERSION=	2.1.el6
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
