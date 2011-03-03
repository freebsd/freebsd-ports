# New ports collection makefile for: linux-libglade
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	devel linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-16

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of libglade

CONFLICTS=	linux-f8-libglade-[0-9]* linux-f10-libglade-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=	LIBVERSION="0.4.2" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
