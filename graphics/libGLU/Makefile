# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGLU
PORTVERSION=	9.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/ \
		https://mesa.freedesktop.org/archive/glu/
DISTNAME=	glu-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library

USES=		gl libtool pathfix pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
USE_GL=		gl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
