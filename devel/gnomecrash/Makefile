# New ports collection makefile for:	gnomecrash
# Date created:				3rd November 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomecrash
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-crash/0.0
DISTNAME=	gnome-crash-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small coredump analysis tool for GNOME

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gnomeprint
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
