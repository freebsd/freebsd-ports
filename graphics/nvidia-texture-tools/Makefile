# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-texture-tools
PORTVERSION=	2.0.8.1 # needed to not bump PORTEPOCH; remove on next update
PORTREVISION=	11
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Texture Tools with support for DirectX 10 texture formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/NVIDIA_Texture_Tools_LICENSE.txt

# see src/nvcore/nvcore.h
ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libIlmImf.so:graphics/openexr

USE_GITHUB=	yes
GH_ACCOUNT=	castano
GH_TAGNAME=	${PORTVERSION:R}

USES=		alias cmake compiler:c++11-lang jpeg
CMAKE_ARGS=	-DNVTT_SHARED=TRUE

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

PORTDOCS=	NVIDIA_Texture_Tools_README.txt ChangeLog

OPTIONS_DEFINE=	COMPRESSUI DOCS
OPTIONS_SUB=	yes

COMPRESSUI_DESC=Build compressor UI (requires Qt4)
COMPRESSUI_USES=	qt:4
COMPRESSUI_USE=	QT=qmake_build,moc_build,uic_build,rcc_build,corelib,gui,opengl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPRESSUI}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch-COMPRESSUI-on:
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ s|)$$| REQUIRED&|' \
		${WRKSRC}/src/CMakeLists.txt

post-patch-COMPRESSUI-off:
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ d' \
		${WRKSRC}/src/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
