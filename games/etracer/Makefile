# Created by: Peter Dunning
# $FreeBSD$

PORTNAME=	etracer
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/extremetuxracer/releases/${PORTVERSION}
DISTNAME=	etr-${PORTVERSION}

MAINTAINER=	peter_dunning@dsl.pipex.com
COMMENT=	Latest and greatest fork of the classic Tux Racer

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USE_SDL=	mixer sdl image
USE_GCC=	yes
USE_GL=		gl glu
USES=		gmake pkgconfig tar:xz tcl
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
