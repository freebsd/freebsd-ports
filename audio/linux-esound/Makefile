# New ports collection makefile for: linux-esound
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.36
PORTREVISION=	2
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-0.fc4.1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of esound

CONFLICTS=	linux-f8-esound-[0-9]* linux-f10-esound-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libaudiofile
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	ESOUND_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
