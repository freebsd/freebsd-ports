PORTNAME=	glpng
PORTVERSION=	1.47
CATEGORIES=	graphics
MASTER_SITES=	https://repo.or.cz/glpng.git/snapshot/
DISTNAME=	2266ea17d0df15619e6c6e21611aa7a34f5f6833
DIST_SUBDIR=	glpng

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to easily load PNG files as an OpenGL textures
WWW=		https://repo.or.cz/glpng.git

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake cpe gl zip
USE_GL=		gl
WRKSRC=		${WRKDIR}/glpng-${DISTNAME:C/^(.......).*/\1/}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
