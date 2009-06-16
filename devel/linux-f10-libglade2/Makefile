# New ports collection makefile for:	devel/linux-f10-libglade2
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libglade2
PORTVERSION=	2.6.3
PORTREVISION=	1
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of libglade2 (Linux Fedora 10)

CONFLICTS=	linux-libglade2-[0-9]* linux-f8-libglade2-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	2.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libglade-2.0.so.0 usr/lib/libglade-2.0.so.0.0.7 \
		usr/share/xml/libglade/glade-2.0.dtd
PLIST_DIRS=	usr/share/xml/libglade usr/share/xml \
		usr/lib/libglade/2.0 usr/lib/libglade
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
