# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugbuddy2
PORTVERSION=	2.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/2.6
DISTNAME=	bug-buddy-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	gnomeprefix gnomehack intlhack lthack gnomedesktop
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	bug-buddy.1

.include <bsd.port.mk>
