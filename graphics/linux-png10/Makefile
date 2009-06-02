# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.18
PORTREVISION=	2
CATEGORIES=	graphics linux
DISTNAME=	libpng10-${PORTVERSION}-2

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (old 1.0 version)

CONFLICTS=	linux-f8-png10-[0-9]* linux-f10-png10-[0-9]*
LATEST_LINK=	linux-png10

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libpng.so.2.${PORTVERSION} \
		usr/lib/libpng.so.2
DOCSDIR=	${PREFIX}/usr/share/doc/libpng10-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng.txt

.include <bsd.port.mk>
