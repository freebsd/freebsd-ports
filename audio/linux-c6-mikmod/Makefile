# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	mikmod
PORTVERSION=	3.2.0
PORTREVISION=	3
CATEGORIES=	audio linux
MASTER_SITES=	EPEL
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	MikMod Sound Library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-mikmod-[0-9]* linux-f8-mikmod-[0-9]*

LINUX_NAME=	lib${PORTNAME}
RPMVERSION=	10.beta2.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LESSER COPYING.LIB NEWS README TODO

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
