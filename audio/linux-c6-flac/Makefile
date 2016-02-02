# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=		flac
PORTVERSION=		1.2.1
PORTREVISION=		3
CATEGORIES=		audio linux
MASTER_SITES=		CENTOS_LINUX

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Free lossless audio codec (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=		linux-flac-[0-9]* linux-f10-flac-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		c6
USE_LINUX_APPS=		libogg
USE_LINUX_RPM=		yes

RPMVERSION=		7.el6_6
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes

DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
