# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.7
PORTREVISION=	1
CATEGORIES=	lang linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool Command Language (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-tcl85-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes
RPMVERSION=	6.el6
BRANDELF_FILES=	usr/bin/tclsh usr/bin/tclsh8.5
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
