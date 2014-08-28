# Created by: bsam
# $FreeBSD: head/graphics/linux-f10-png/Makefile 362312 2014-07-20 11:58:56Z rene $

PORTNAME=	png
PORTVERSION=	1.2.37
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (Linux Fedora 10)

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=262b92fe-81c8-11e1-8899-001ec9578670

CONFLICTS=	linux-png-[0-9]* linux-f8-png-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	libpng
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libpng.so.3 \
		usr/lib/libpng.so.3.37.0 \
		usr/lib/libpng12.so.0 \
		usr/lib/libpng12.so.0.37.0 \
		usr/share/man/man5/png.5.gz
DOCSDIR=	${PREFIX}/usr/share/doc/libpng-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng-1.2.37.txt
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
