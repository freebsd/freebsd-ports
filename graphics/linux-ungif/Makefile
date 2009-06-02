# New ports collection makefile for: linux-ungif
# Date created:         22 November 2002
# Whom:                 Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	ungif
PORTVERSION=	4.1.3
PORTREVISION=	3
CATEGORIES=	graphics linux
DISTNAME=	libungif-${PORTVERSION}-3.fc4.2

MAINTAINER=	maho@FreeBSD.org
COMMENT=	RPM of the ungif lib

CONFLICTS=	linux-f8-ungif-[0-9]* linux-f10-ungif-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
