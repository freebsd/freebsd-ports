# Created by: bsam
# $FreeBSD$

PORTNAME=	libglade2
PORTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=	devel linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of libglade2 (Linux Fedora 10)

CONFLICTS=	linux-libglade2-[0-9]* linux-f8-libglade2-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	2.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libglade-2.0.so.0 usr/lib/libglade-2.0.so.0.0.7 \
		usr/share/xml/libglade/glade-2.0.dtd
PLIST_DIRS=	usr/lib/libglade/2.0
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
