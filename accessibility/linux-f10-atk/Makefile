# New ports collection makefile for:	linux-atk
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	accessibility

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${PKGDIR}/pkg-plist
RPM_SET=	atk-1.2.0-2.i386.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
