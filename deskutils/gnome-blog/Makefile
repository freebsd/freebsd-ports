# New ports collection makefile for:	gnomeblog
# Date created:				20 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeblog
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-blog/0.8
DISTNAME=	gnome-blog-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME app to post to blogs

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2 intlhack
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/libs"

GCONF_SCHEMAS=	gnomeblog.schemas

.include <bsd.port.mk>
