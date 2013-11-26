# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libGLU
PORTVERSION=	9.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glu/
DISTNAME=	glu-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library

USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libGLU.so.1

.include <bsd.port.mk>
