# New ports collection makefile for:	graphics/linux-f10-libmng
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		libmng
PORTVERSION=		1.0.9
CATEGORIES=		graphics linux
PKGNAMEPREFIX=		linux-f10-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		RPM of libmng (Linux Fedora 10)

CONFLICTS=		linux-libmng-[0-9]* linux-f8-libmng-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_DIST_VER=	10
RPMVERSION=	7
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libmng.so.1 usr/lib/libmng.so.1.0.0

.include <bsd.port.mk>
