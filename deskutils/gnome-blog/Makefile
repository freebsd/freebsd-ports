# New ports collection makefile for:	gnomeblog
# Date created:				20 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeblog
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-blog/0.7
DISTNAME=	gnome-blog-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME app to post to blogs

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/libs"

.include <bsd.port.mk>
