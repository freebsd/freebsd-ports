# New ports collection makefile for: linux-libaudiofile
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.2.6
PORTREVISION=	4
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	audiofile-${PORTVERSION}-2

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of audiofile

CONFLICTS=	linux-f8-libaudiofile-[0-9]* linux-f10-libaudiofile-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	LIBAUDIOFILE_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
