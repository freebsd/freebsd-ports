# Created by: Peter Dunning
# $FreeBSD$

PORTNAME=	etracer
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/extremetuxracer/releases/${PORTVERSION}
DISTNAME=	etr-${PORTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Extreme Tux Racer

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		compiler gmake localbase pkgconfig tar:xz tcl
USE_SDL=	mixer sdl image
USE_GL=		gl glu

GNU_CONFIGURE=	yes

CXXFLAGS+=      ${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang= -Wno-c++11-narrowing

.include <bsd.port.mk>
