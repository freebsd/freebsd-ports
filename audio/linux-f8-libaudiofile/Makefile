# New ports collection makefile for:	audio/linux-f8-libaudiofile
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	lib${LINUX_NAME}
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	An implementation of the Audio File Library from SGI (Linux Fedora 8)

CONFLICTS=	linux-libaudiofile-[0-9]* linux-f10-libaudiofile-[0-9]*

USE_LINUX_RPM=	yes
LINUX_NAME=	audiofile
LINUX_DIST_VER=	8
RPMVERSION=	7.fc8
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
