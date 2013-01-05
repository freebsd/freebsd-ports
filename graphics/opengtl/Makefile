# $FreeBSD$

PORTNAME=	opengtl
PORTVERSION=	0.9.17
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.${PORTNAME}.org/
DISTNAME=	OpenGTL-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Graphics Transformation Languages

LICENSE=	LGPL20

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/lib/libLLVM-3.1.so:${PORTSDIR}/devel/llvm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SHIVA
OPTIONS_DEFAULT=SHIVA

SHIVA_DESC=	Install filters and generators

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHIVA}
RUN_DEPENDS+=	${LOCALBASE}/share/OpenGTL/shiva/kernels/oilify.shiva:${PORTSDIR}/graphics/shiva-collections
.endif

post-patch:
	# Disable latex doc, it's not ready yet.
	${REINPLACE_CMD} -e '/add_subdirectory.*doc/d' \
		${PATCH_WRKSRC}/OpenShiva/CMakeLists.txt

pre-configure:
	${REINPLACE_CMD} -e 's|set(OPENGTL_LIB_SOVERSION.*|set(OPENGTL_LIB_SOVERSION "0")|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${PATCH_WRKSRC}/OpenCTL/OpenCTL/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenGTL/GTLCore/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenGTL/GTLImageIO/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenShiva/OpenShiva/CMakeLists.txt

.include <bsd.port.mk>
