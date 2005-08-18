# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.7
PORTREVISION=	6
CATEGORIES=	graphics linux
MASTER_SITES=	http://mirrors.xmission.com/fedora/core/3/i386/os/Fedora/RPMS/ \
		http://fedora.cat.pdx.edu/linux/core/3/i386/os/Fedora/RPMS/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib

DIST_SUBDIR=	rpm/i386/fc3
# no alpha rpm is available
ONLY_FOR_ARCHS=	i386 amd64
RPM_SET=	libpng-${PORTVERSION}-1.i386.rpm

PLIST_FILES=	\
		usr/lib/libpng.so.3 \
		usr/lib/libpng.so.3.${PORTVERSION} \
		usr/lib/libpng12.so.0 \
		usr/lib/libpng12.so.0.${PORTVERSION} \
		usr/share/man/man5/png.5.gz
DOCSDIR=	${PREFIX}/usr/share/doc/libpng-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng.txt

.include "../../x11-toolkits/linux-gtk/Makefile"
