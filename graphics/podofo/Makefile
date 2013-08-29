# Created by: stas
# $FreeBSD$

PORTNAME=	podofo
PORTVERSION=	0.9.2
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		cmake
CMAKE_ARGS=	-DPODOFO_BUILD_SHARED:BOOL=TRUE \
		-DPODOFO_BUILD_STATIC:BOOL=FALSE \
		-DOPENSSL_INCLUDE_DIR:PATH="${OPENSSLINC}" \
		-DOPENSSL_LIBRARIES:PATH="${OPENSSLDIR}"
USE_GCC=	any
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

MAN1=		podofobox.1 podofocountpages.1 podofocrop.1 \
		podofoencrypt.1 podofoimg2pdf.1 podofoimgextract.1 \
		podofoimpose.1 podofoincrementalupdates.1 podofomerge.1 \
		podofopages.1 podofopdfinfo.1 podofotxt2pdf.1 \
		podofotxtextract.1 podofouncompress.1 podofoxmp.1

OPTIONS_DEFINE=		IMPOSE JPEG PNG TIFF
OPTIONS_DEFAULT=	JPEG PNG TIFF
IMPOSE_DESC=		Build impose tool (needs Lua)

IMPOSE_CMAKE_ON=	-DWANT_LUA:BOOL=TRUE
IMPOSE_CXXFLAGS=	-I${LUA_INCDIR}
IMPOSE_LDFLAGS=		-L${LUA_LIBDIR}

JPEG_CMAKE_ON=		-DWANT_LIBJPEG:BOOL=TRUE
JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

PNG_CMAKE_ON=		-DWANT_PNG:BOOL=TRUE
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

TIFF_CMAKE_ON=		-DWANT_TIFF:BOOL=TRUE
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMPOSE}
USE_LUA=	5.1
.endif

.include <bsd.port.mk>
