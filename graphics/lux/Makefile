PORTNAME=	lux
PORTVERSION=	1.1.8
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/kfj/pv/get/
PKGNAMESUFFIX=	-pv	# distinguish from www/lux
DISTNAME=	${COMMIT}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Panorama and image viewer
WWW=		https://bitbucket.org/kfj/pv

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	address space exhaustion in compiler

LIB_DEPENDS=	libhwy.so:devel/highway \
		libsfml-window.so:devel/sfml \
		libexiv2.so:graphics/exiv2 \
		libvigraimpex.so:graphics/vigra
RUN_DEPENDS=	${GUIFONT}:x11-fonts/noto-basic
GUIFONT=	${LOCALBASE}/share/fonts/noto/NotoSans-Regular.ttf

USES=		cmake desktop-file-utils dos2unix pkgconfig tar:bz2
DOS2UNIX_FILES=	tinyfiledialogs.c
CMAKE_ON=	USE_HWY_LIBRARY
CXXFLAGS+=	-Wno-deprecated-declarations
CONFLICTS=	lux

WRKSRC=		${WRKDIR}/kfj-pv-${COMMIT}
COMMIT=		15b1fd742285
OPTIONS_DEFINE_amd64=	SSSE3 SSE42 AVX AVX2 AVX512
OPTIONS_DEFINE_i386=	SSE2 SSSE3 SSE42 AVX AVX2 AVX512
OPTIONS_DEFAULT_amd64=	SSSE3 SSE42 AVX AVX2 AVX512
OPTIONS_DEFAULT_i386=	SSSE3 SSE42 AVX AVX2 AVX512

SSE2_DESC=	build port for Pentium 4 or newer
SSSE3_DESC=	support SSSE3 flavor
SSE42_DESC=	support SSE4.2 flavor
AVX_DESC=	support AVX flavor
AVX2_DESC=	support AVX2 flavor
AVX512_DESC=	support AVX-512F flavor

SSE2_CXXFLAGS_OFF=	-march=i686
SSE2_CXXFLAGS=		-march=pentium4
SSSE3_CMAKE_BOOL=	FLV_SSSE3
SSE42_CMAKE_BOOL=	FLV_SSE42
AVX_CMAKE_BOOL=		FLV_AVX
AVX2_CMAKE_BOOL=	FLV_AVX2
AVX512_CMAKE_BOOL=	FLV_AVX512f

.include <bsd.port.pre.mk>

# cannot use CMAKE_ON after bsd.port.pre.mk
# this disables the flavor dispatch code on non-x86
.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DFLV_NATIVE=ON
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,%%GUIFONT%%,${GUIFONT},' ${WRKSRC}/options.h

.include <bsd.port.post.mk>
