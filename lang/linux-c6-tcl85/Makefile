# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.7
PORTREVISION=	2
CATEGORIES=	lang linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool Command Language (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-tcl85-[0-9]*

RPMVERSION=	6.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes

DATADIR=	${PREFIX}/usr/share/tcl${PORTVERSION:R}
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
