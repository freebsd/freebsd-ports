# New ports collection makefile for:	linux-glib2
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	glib2
PORTVERSION=	2.4.8
PORTREVISION=	2
CATEGORIES=	devel linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.fc3

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Version 2.X Linux/i386 binary port of GLib

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	LIBVERSION="400.8" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
