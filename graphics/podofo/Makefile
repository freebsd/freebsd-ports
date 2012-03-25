# New ports collection makefile for:	podofo
# Date created:		10/17/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	podofo
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	JPEG "Enable JPEG support" on \
		TIFF "Enable TIFF support" on \
		PNG "Enable PNG support" on \
		IMPOSE "Build impose tool (needs Lua)" off

USE_CMAKE=	yes
CMAKE_ARGS=	-DPODOFO_BUILD_SHARED:BOOL=TRUE \
		-DPODOFO_BUILD_STATIC:BOOL=FALSE
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		podofobox.1 podofocountpages.1 podofocrop.1 \
		podofoencrypt.1 podofoimg2pdf.1 podofoimgextract.1 \
		podofoimpose.1 podofoincrementalupdates.1 podofomerge.1 \
		podofopages.1 podofopdfinfo.1 podofotxt2pdf.1 \
		podofotxtextract.1 podofouncompress.1 podofoxmp.1

.include <bsd.port.options.mk>

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CMAKE_ARGS+=	-DWANT_LIBJPEG:BOOL=TRUE
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWANT_TIFF:BOOL=TRUE
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DWANT_PNG:BOOL=TRUE
.endif

.if defined(WITH_IMPOSE)
USE_LUA=	5.1
CMAKE_ARGS+=	-DWANT_LUA:BOOL=TRUE
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.endif

.include <bsd.port.mk>
