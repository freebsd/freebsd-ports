# New ports collection makefile for:	libole2
# Date created:				20th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libole2
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libole2/0.2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Support library for OLE functions (MS-Excel) for gnumeric

USE_GMAKE=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
