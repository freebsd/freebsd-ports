PORTNAME=	glpng
PORTVERSION=	1.46
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://repo.or.cz/glpng.git/snapshot/ \
		https://mirror.amdmi3.ru/distfiles/${DIST_SUBDIR}/
DISTNAME=	1079563a36edfe10a5f5d79ad38fe465425b989e
DIST_SUBDIR=	glpng

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to easily load PNG files as an OpenGL textures

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/glpng-1079563

USES=		cmake gl zip
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
