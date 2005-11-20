# New ports collection makefile for:	linux-glib2
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	glib2
PORTVERSION=	2.4.8
PORTREVISION=	0
CATEGORIES=	devel linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	updates/3/i386

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Version 2.X Linux/i386 binary port of GLib

ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	glib2-${PORTVERSION}-1.fc3.i386.rpm

PLIST_SUB+=	LIBVERSION="400.8" PORTVERSION="${PORTVERSION}"

.include "../../x11-toolkits/linux-gtk/Makefile"
