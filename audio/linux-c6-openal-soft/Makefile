# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.12.854
PORTREVISION=	2
CATEGORIES=	audio linux
MASTER_SITES=	EPEL

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib arts esound

RPMVERSION=	1.el6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
