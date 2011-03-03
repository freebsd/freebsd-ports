# New ports collection makefile for:	audio/linux-f10-libaudiofile
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	lib${LINUX_NAME}
PORTVERSION=	0.2.6
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	An implementation of the Audio File Library from SGI (Linux Fedora 10)

CONTFLICTS=	linux-libaudiofile-[0-9]* linux-f8-libaudiofile-[0-9]*

USE_LINUX_RPM=	yes
LINUX_NAME=	audiofile
LINUX_DIST_VER=	10
RPMVERSION=	9.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
