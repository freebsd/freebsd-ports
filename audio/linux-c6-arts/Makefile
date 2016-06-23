# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=		arts
PORTVERSION=		1.5.10
PORTREVISION=		1
CATEGORIES=		audio kde linux

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=		linux-arts-[0-9]* linux-f8-arts-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		c6
USE_LINUX_RPM=		yes

RPMVERSION=			10.el6
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/*.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib64/*.la

.include <bsd.port.mk>
