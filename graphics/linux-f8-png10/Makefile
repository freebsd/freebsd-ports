# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.16
PORTREVISION=	7
CATEGORIES=	graphics linux
DISTNAME=	libpng10-${PORTVERSION}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (old 1.0 version)

LATEST_LINK=	linux-png10

ONLY_FOR_ARCHS=	i386
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes

PLIST_FILES=	usr/lib/libpng.so.2.1.0.16 \
		usr/lib/libpng.so.2
DOCSDIR=	${PREFIX}/usr/share/doc/libpng10-1.0.16
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng.txt

.include <bsd.port.mk>
