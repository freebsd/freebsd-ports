# New ports collection makefile for:	linux-atk
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	accessibility
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS \
			3/SRPMS

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2

ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${PKGDIR}/pkg-plist
RPM_SET=	atk-${PORTVERSION}-2.i386.rpm
PLIST_SUB+=	LIBVERSION="800.0" PORTVERSION="${PORTVERSION}"

.include "../../x11-toolkits/linux-gtk/Makefile"

.if defined(PACKAGE_BUILDING)
DISTFILES+=	atk-1.8.0-2.src.rpm
ALWAYS_KEEP_DISTFILES=	yes
.endif
