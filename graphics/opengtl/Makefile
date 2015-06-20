# $FreeBSD$

PORTNAME=	opengtl
PORTVERSION=	0.9.18
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.${PORTNAME}.org/
DISTNAME=	OpenGTL-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Graphics Transformation Languages

LICENSE=	LGPL20

BROKEN=		Depends on deleted devel/llvm32
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-07-21

#LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
#		libLLVM-3.2.so:${PORTSDIR}/devel/llvm32

USES=		cmake perl5 tar:bzip2
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config32

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	SHIVA
OPTIONS_DEFAULT=SHIVA

SHIVA_DESC=	Install filters and generators
SHIVA_RUN_DEPENDS=${LOCALBASE}/share/OpenGTL/shiva/kernels/oilify.shiva:${PORTSDIR}/graphics/shiva-collections

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
