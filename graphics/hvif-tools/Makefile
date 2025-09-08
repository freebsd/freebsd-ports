PORTNAME=	hvif-tools
DISTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/threedeyes/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	hoanga@gmail.com
COMMENT=	Toolkit for converting HVIF icons to SVG and back
WWW=		https://github.com/threedeyes/hvif-tools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/nanosvg.h:graphics/nanosvg

USES=		cmake localbase

EXTRACT_AFTER_ARGS=	--exclude external \
			--no-same-owner --no-same-permissions

PLIST_FILES=	bin/hvif2svg \
		bin/svg2hvif

.include <bsd.port.mk>
