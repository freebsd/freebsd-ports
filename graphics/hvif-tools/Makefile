PORTNAME=	hvif-tools
DISTVERSION=	2.1.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/threedeyes/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	hoanga@gmail.com
COMMENT=	Toolkit for converting HVIF icons to SVG and back
WWW=		https://github.com/threedeyes/hvif-tools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/nanosvg.h:graphics/nanosvg \
		${LOCALBASE}/include/stb:devel/stb

USES=		cmake localbase

EXTRACT_AFTER_ARGS=	--exclude external \
			--no-same-owner --no-same-permissions

post-extract:
	@${MKDIR} ${WRKSRC}/external/nanosvg_ext/src
	@${LN} -sf ${LOCALBASE}/include/nanosvg.h \
		${WRKSRC}/external/nanosvg_ext/src
	@${LN} -sf ${LOCALBASE}/include/stb \
		${WRKSRC}/external
	@${TOUCH} ${WRKSRC}/external/CMakeLists.txt

.include <bsd.port.mk>
