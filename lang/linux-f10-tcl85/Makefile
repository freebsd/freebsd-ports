# Created by: bsam
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.3
PORTREVISION=	2
CATEGORIES=	lang linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool Command Language (Linux Fedora 10)

CONFLICTS=	linux-f8-tcl84-[0-9]* linux-c6-tcl85-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes
RPMVERSION=	1.fc10
BRANDELF_FILES=	usr/bin/tclsh8.5
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
