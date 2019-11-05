# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.1.2
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/arx/ \
		http://arx-libertatis.org/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/ARX_PUBLIC_LICENSE.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/foreach.hpp:devel/boost-libs

USES=		cmake gl openal sdl tar:xz
USE_SDL=	sdl
USE_GL=		gl glew
LLD_UNSAFE=	yes
CMAKE_ARGS=	-DDATA_DIR=arx \
		-DSTRICT_USE=ON \
		-DBUILD_CRASHREPORTER=OFF
CFLAGS_powerpc64+=	-mminimal-toc

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
