# New ports collection makefile for: linux-ungif
# Date created:         22 November 2002
# Whom:                 Nakata Maho <maho@FreeBSD.org>
# $FreeBSD$
#
PORTNAME=	ungif
PORTVERSION=	4.1.3
CATEGORIES=	graphics linux
DISTNAME=	libungif-${PORTVERSION}-1

MAINTAINTER=	maho@FreeBSD.org
COMMENT=	RPM of the ungif lib

NOT_FOR_ARCHS=	amd64

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
