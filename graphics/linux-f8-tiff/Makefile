# New ports collection makefile for:	graphics/linux-f8-tiff
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	The TIFF library, Linux/i386 binary (Linux Fedora 8)

CONFLICTS=	linux-tiff-[0-9]* linux-f10-tiff-[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_NAME=	lib${PORTNAME}
LINUX_DIST_VER=	8
RPMVERSION=	9.fc8
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
