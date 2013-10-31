# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nvidia-texture-tools
DISTVERSION=	2.0.8-1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Texture Tools with support for DirectX 10 texture formats

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR

USES=		cmake
CMAKE_ARGS=	-DNVTT_SHARED=TRUE

CFLAGS+=	-fPIC -I${LOCALBASE}/include/libpng15
CXXFLAGS+=	-fPIC -I${LOCALBASE}/include/libpng15

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	NVIDIA_Texture_Tools_README.txt ChangeLog

OPTIONS_DEFINE=	COMPRESSUI DOCS
OPTIONS_DEFAULT=DOCS

COMPRESSUI_DESC=Build compressor UI (requires Qt4)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPRESSUI}
# *_build stuff is not really needed, but cmake's Qt finder won't work otherwise
USE_QT4=	qmake_build moc_build uic_build rcc_build corelib gui opengl
PLIST_SUB+=	COMPRESSUI=""
.else
PLIST_SUB+=	COMPRESSUI="@comment "
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e '/OPENEXR_LIBRARIES/ s|)$$| $${CMAKE_THREAD_LIBS_INIT}&|' \
		${WRKSRC}/src/nvimage/CMakeLists.txt
.if ${PORT_OPTIONS:MCOMPRESSUI}
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ s|)$$| REQUIRED&|' \
		${WRKSRC}/src/CMakeLists.txt
.else
	@${REINPLACE_CMD} -e '/FIND_PACKAGE.*Qt4/ d' \
		${WRKSRC}/src/CMakeLists.txt
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
