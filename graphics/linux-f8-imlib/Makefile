# New ports collection makefile for:	graphics/linux-f8-imlib
# Date created:				2008-03-28
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	imlib
PORTVERSION=	1.9.15
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of imlib (Linux Fedora 8)

CONFLICTS=	linux-imlib-[0-9]* linux-f10-imlib-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	6.fc8
BRANDELF_FILES=	usr/bin/imlib_config
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
