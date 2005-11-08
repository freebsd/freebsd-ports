# New ports collection makefile for:	linux-glib2
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	glib2
PORTVERSION=	2.2.3
CATEGORIES=	devel linux

MASTER_SITES=	\
		http://mirrors.kernel.org/fedora/core/1/i386/os/Fedora/RPMS/ \
		http://distro.ibilio.org/pub/linux/distributions/fedora/linux/core/1/i386/os/Fedora/RPMS/

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Version 2.X Linux/i386 binary port of GLib

ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
RESTRICTED=	"binary under GNU LGPL without accompanying source"
RPM_SET=	glib2-${PORTVERSION}-1.1.i386.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
