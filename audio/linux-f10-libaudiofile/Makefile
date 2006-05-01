# New ports collection makefile for: linux-libaudiofile
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	audio linux
DISTNAME=	audiofile-${PORTVERSION}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of audiofile

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
