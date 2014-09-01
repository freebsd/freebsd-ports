# Created by: bsam
# $FreeBSD$

PORTNAME=		arts
PORTVERSION=		1.5.10
PORTREVISION=		1
CATEGORIES=		audio kde linux
MASTER_SITES=		CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=		linux-f10-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux Fedora 10)

CONFLICTS=		linux-arts-[0-9]* linux-f8-arts-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
LINUX_DIST_VER=		10
RPMVERSION=		1.fc10
BRANDELF_DIRS=		usr/bin
USE_LDCONFIG=		yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/*.la

.include <bsd.port.mk>
