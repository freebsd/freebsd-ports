# New ports collection makefile for: linux-libglade2
# Date created:		2007.09.02
# Whom:			Artem Naluzhnyy <tut@nhamon.com.ua>
#
# $FreeBSD$
#

PORTNAME=	libglade2
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	devel linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	RPM of libglade2

CONFLICTS=	linux-f8-libglade2-[0-9]* linux-f10-libglade2-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=	LIBVERSION="0.0.7" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
