# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/graphics/glitz/Makefile,v 1.8 2006/09/10 00:51:10 mezz Exp $

PORTNAME=	glitz
PORTVERSION=	0.5.6
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL image compositing library

USES=		libtool:keepla pathfix
USE_GL=		yes
USE_XORG=	xt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
