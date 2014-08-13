# Created by: bsam
# $FreeBSD: head/graphics/linux-f10-tiff/Makefile 362312 2014-07-20 11:58:56Z rene $

PORTNAME=	tiff
PORTVERSION=	3.8.2
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary (Linux Fedora 10)

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=8816bf3a-7929-11df-bcce-0018f3e2eb82

CONFLICTS=	linux-tiff-[0-9]* linux-f8-tiff-[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_NAME=	lib${PORTNAME}
LINUX_DIST_VER=	10
RPMVERSION=	11.fc10
BRANDELF_DIRS=	usr/bin
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
