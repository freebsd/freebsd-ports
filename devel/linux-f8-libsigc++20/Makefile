# New ports collection makefile for:	devel/linux-f8-libsigc++20
# Date created:				2008-04-02
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		libsigc++20
PORTVERSION=		2.0.18
PORTREVISION=		1
CATEGORIES=		devel linux
PKGNAMEPREFIX=		linux-f8-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Callback Framework for C++ (Linux Fedora 8)

CONFLICTS=		linux-libsigc++20-[0-9]* linux-f10-libsigc++20-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
LINUX_DIST_VER=		8
RPMVERSION=		1
USE_LDCONFIG=		yes

PLIST_FILES=		usr/lib/libsigc-2.0.so.0 usr/lib/libsigc-2.0.so.0.0.0
DOCSDIR=		usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
