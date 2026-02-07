PORTNAME=	coolreader
DISTVERSIONPREFIX=	cr
DISTVERSION=	3.2.59
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	mistresssilvara@hotmail.com
COMMENT=	E-book reader
WWW=		https://github.com/buggins/coolreader

LICENSE=	GPLv2 LGPL21+ BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libfribidi.so:converters/fribidi \
		libunibreak.so:textproc/libunibreak \
		libfontconfig.so:x11-fonts/fontconfig \
		libzstd.so:archivers/zstd

USES=		qt:5 cmake:noninja pkgconfig desktop-file-utils jpeg

USE_GITHUB=	yes
GH_ACCOUNT=	buggins

USE_QT=		core buildtools:build gui qmake:build widgets linguisttools:build

CMAKE_ARGS=	-D GUI=QT5 -D MAX_IMAGE_SCALE_MUL=2 \
		-D DOC_DATA_COMPRESSION_LEVEL=3 -D DOC_BUFFER_SIZE=0x1400000
CXXFLAGS+=	-D CR_EMULATE_GETTEXT=1 \
		-I${WRKSRC}/thirdparty_unman/nanosvg/src

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
