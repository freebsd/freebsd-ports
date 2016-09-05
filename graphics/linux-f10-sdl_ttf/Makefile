# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.8
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to use TrueType fonts in SDL applications (Linux version)

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	sdl12
USE_LDCONFIG=	yes
DIST_SUBDIR=	rpm
PLIST_SUB+=	SDLTTFVER=${PORTVERSION}

.include <bsd.port.mk>
