# New ports collection makefile for:	bugbuddy
# Date created:				23rd February 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugbuddy
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/2.0
DISTNAME=	bug-buddy-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gnomevfs
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
