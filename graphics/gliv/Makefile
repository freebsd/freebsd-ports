# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer that uses Gdk-Pixbuf and OpenGL

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gnomehack gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		gliv.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
