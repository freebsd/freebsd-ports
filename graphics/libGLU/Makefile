# Created by: Eric Anholt <anholt@FreeBSD.org>

PORTNAME=	libGLU
PORTVERSION=	9.0.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/ \
		https://mesa.freedesktop.org/archive/glu/
DISTNAME=	glu-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library

USES=		gl libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-libglvnd
INSTALL_TARGET=	install-strip
USE_GL=		opengl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
