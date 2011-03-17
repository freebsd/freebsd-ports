# New ports collection makefile for:	Xfce Foundation Classes
# Date created:				1 Jun 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfc
PORTVERSION=	4.3.1
PORTREVISION=	9
CATEGORIES=	devel xfce
MASTER_SITES=	http://xfc.xfce.org/download/${PORTVERSION}/src/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Xfce Foundation Classes

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

BROKEN=		Does not compile with GCC 4.2
DEPRECATED=	does not compile on FreeBSD 7.x or newer
EXPIRATION_DATE=2011-04-17

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 gtk20 atk pango pkgconfig libglade2 gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
