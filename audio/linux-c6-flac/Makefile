# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=		flac
PORTVERSION=		1.2.1
CATEGORIES=		audio linux

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=		linux-arts-[0-9]* linux-f10-arts-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		c6
USE_LINUX_RPM=		yes

RPMVERSION=		6.1.el6
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes

DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
