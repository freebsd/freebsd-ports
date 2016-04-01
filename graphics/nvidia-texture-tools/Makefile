# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-texture-tools
DISTVERSION=	2.0.8-1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Texture Tools with support for DirectX 10 texture formats

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libIlmImf.so:graphics/OpenEXR

BROKEN_ia64=	does not build
BROKEN_powerpc=	does not build
BROKEN_sparc64=	does not build

USES=		alias cmake jpeg
CMAKE_ARGS=	-DNVTT_SHARED=TRUE

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	NVIDIA_Texture_Tools_README.txt ChangeLog

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64 # see src/nvcore/nvcore.h

OPTIONS_DEFINE=	COMPRESSUI DOCS
OPTIONS_SUB=	yes

COMPRESSUI_DESC=Build compressor UI (requires Qt4)
COMPRESSUI_USE=	QT4=qmake_build,moc_build,uic_build,rcc_build,corelib,gui,opengl

post-patch-COMPRESSUI-on:
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ s|)$$| REQUIRED&|' \
		${WRKSRC}/src/CMakeLists.txt

post-patch-COMPRESSUI-off:
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ d' \
		${WRKSRC}/src/CMakeLists.txt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
