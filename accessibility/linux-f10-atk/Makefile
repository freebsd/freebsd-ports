# Created by: bsam
# $FreeBSD: head/accessibility/linux-f10-atk/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	atk
PORTVERSION=	1.24.0
PORTREVISION=	1
CATEGORIES=	accessibility linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary (Linux Fedora 10)

CONFLICTS=	linux-atk-[0-9]* linux-f8-atk-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

.include <bsd.port.mk>
