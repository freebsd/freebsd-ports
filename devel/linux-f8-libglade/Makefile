# New ports collection makefile for:	devel/linux-f8-libglade
# Date created:				2008-04-02
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of libglade (Linux Fedora 8)

CONFLICTS=	linux-libglade-[0-9]* linux-f10-libglade-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	20.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libglade-gnome.so.0 usr/lib/libglade-gnome.so.0.4.2 \
		usr/lib/libglade.so.0 usr/lib/libglade.so.0.4.2
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
