# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.12.854
PORTREVISION=	4
CATEGORIES=	audio linux
MASTER_SITES=	EPEL

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LINUX_RPM=	yes
USE_LINUX=	alsalib arts esound

RPMVERSION=	1.el6
USE_LDCONFIG=	yes

PORTDOCS=	COPYING
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
