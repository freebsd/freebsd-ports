# Created by: bsam
# $FreeBSD$

PORTNAME=		libsigc++20
PORTVERSION=		2.2.2
PORTREVISION=	1
CATEGORIES=		devel linux

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Callback Framework for C++ (Linux Fedora 10)

CONFLICTS=		linux-libsigc++20-[0-9]* linux-f8-libsigc++20-[0-9]*

USES=			linux:f10
USE_LINUX_RPM=		yes

RPMVERSION=		1.fc9
USE_LDCONFIG=		yes

PLIST_FILES=		usr/lib/libsigc-2.0.so.0 usr/lib/libsigc-2.0.so.0.0.0
PORTDOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
DESCR=			${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
