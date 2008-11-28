# New ports collection makefile for:	linux-glib2
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	glib2
PORTVERSION=	2.6.6
PORTREVISION=	1
CATEGORIES=	devel linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Version 2.X Linux/i386 binary port of GLib

CONFLICTS=	linux_base-fc6-* linux_base-f7-* linux_base-f8-*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	LIBVERSION="600.6" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
