# New ports collection makefile for: linux-png
# Date created:		28 September 2000
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.8
PORTREVISION=	5
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	libpng-${PORTVERSION}-2

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib

CONFLICTS=	linux-f8-png-[0-9]* linux-f10-png-[0-9]*

# no alpha rpm is available
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes

PLIST_FILES=	\
		usr/lib/libpng.so.3 \
		usr/lib/libpng.so.3.${PORTVERSION} \
		usr/lib/libpng12.so.0 \
		usr/lib/libpng12.so.0.${PORTVERSION} \
		usr/share/man/man5/png.5.gz
DOCSDIR=	${PREFIX}/usr/share/doc/libpng-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng.txt

.include <bsd.port.mk>
