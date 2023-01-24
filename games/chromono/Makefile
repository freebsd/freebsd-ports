PORTNAME=	chromono
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	https://thp.io/2013/chromono/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Circular color puzzle
WWW=		https://thp.io/2013/chromono/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

USES=		compiler:c++11-lang cmake gl pkgconfig sdl python:build
USE_SDL=	sdl2
USE_GL=		gl glu opengl

.include <bsd.port.mk>
