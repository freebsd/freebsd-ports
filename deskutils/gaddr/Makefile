# New ports collection makefile for:	gaddr
# Date created:			8 August 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaddr
PORTVERSION=	1.1.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.cse.unl.edu/~cluening/gaddr/

MAINTAINER=	jim@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+= --enable-gnome
.endif

.include <bsd.port.post.mk>
