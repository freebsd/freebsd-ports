# New ports collection makefile for: linux-libaudiofile
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.2.6
PORTREVISION=	2
CATEGORIES=	audio linux
DISTNAME=	audiofile-${PORTVERSION}-2

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of audiofile

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	LIBAUDIOFILE_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
