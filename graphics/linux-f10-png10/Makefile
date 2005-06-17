# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.16
PORTREVISION=	6
CATEGORIES=	graphics linux
MASTER_SITES=	http://mirrors.xmission.com/fedora/core/3/i386/os/Fedora/RPMS/ \
		http://fedora.cat.pdx.edu/linux/core/3/i386/os/Fedora/RPMS/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (old 1.0 version)

LATEST_LINK=	linux-png10

DIST_SUBDIR=	rpm/i386/fc3
ONLY_FOR_ARCHS=	i386
RPM_SET=	libpng10-${PORTVERSION}-1.i386.rpm

PLIST_FILES=	usr/lib/libpng.so.2.1.0.16 \
		usr/lib/libpng.so.2
DOCSDIR=	${PREFIX}/usr/share/doc/libpng10-1.0.16
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng.txt

.include "../../x11-toolkits/linux-gtk/Makefile"
