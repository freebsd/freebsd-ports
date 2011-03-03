# New ports collection makefile for:	devel/linux-f10-libglade
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.17
CATEGORIES=	devel linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of libglade (Linux Fedora 10)

CONFLICTS=	linux-libglade-[0-9]* linux-f8-libglade-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	21.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libglade-gnome.so.0 usr/lib/libglade-gnome.so.0.4.2 \
		usr/lib/libglade.so.0 usr/lib/libglade.so.0.4.2
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
