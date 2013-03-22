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

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	JPEG TIFF PNG IMPOSE
OPTIONS_DEFAULT=	JPEG TIFF PNG
IMPOSE_DESC=	Build impose tool (needs Lua)

USES=		cmake
CMAKE_ARGS=	-DPODOFO_BUILD_SHARED:BOOL=TRUE \
		-DPODOFO_BUILD_STATIC:BOOL=FALSE \
		-DOPENSSL_INCLUDE_DIR:PATH="${OPENSSLINC}" \
		-DOPENSSL_LIBRARIES:PATH="${OPENSSLDIR}"
USE_GCC=	any
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		podofobox.1 podofocountpages.1 podofocrop.1 \
		podofoencrypt.1 podofoimg2pdf.1 podofoimgextract.1 \
		podofoimpose.1 podofoincrementalupdates.1 podofomerge.1 \
		podofopages.1 podofopdfinfo.1 podofotxt2pdf.1 \
		podofotxtextract.1 podofouncompress.1 podofoxmp.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CMAKE_ARGS+=	-DWANT_LIBJPEG:BOOL=TRUE
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWANT_TIFF:BOOL=TRUE
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DWANT_PNG:BOOL=TRUE
.endif

.if ${PORT_OPTIONS:MIMPOSE}
USE_LUA=	5.1
CMAKE_ARGS+=	-DWANT_LUA:BOOL=TRUE
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.endif

.include <bsd.port.mk>
