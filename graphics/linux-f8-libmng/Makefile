# New ports collection makefile for:	graphics/linux-f8-libmng
# Date created:				2008-03-28
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		libmng
PORTVERSION=		1.0.9
PORTREVISION=		1
CATEGORIES=		graphics linux
PKGNAMEPREFIX=		linux-f8-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		RPM of libmng (Linux Fedora 8)

CONFLICTS=	linux-libmng-[0-9]* linux-f10-libmng-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_DIST_VER=	8
RPMVERSION=	5.1
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libmng.so.1 usr/lib/libmng.so.1.0.0

.include <bsd.port.mk>
