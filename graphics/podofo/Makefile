# New ports collection makefile for:	podofo
# Date created:		10/17/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	podofo
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	JPEG "Enable JPEG support" on \
		TIFF "Enable TIFF support" on \
		IMPOSE "Build impose tool (needs Lua)" off

USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DPODOFO_BUILD_SHARED:BOOL=TRUE \
		-DPODOFO_BUILD_STATIC:BOOL=FALSE

.include <bsd.port.pre.mk>

MAN1=		podofobox.1 podofoxmp.1 podofouncompress.1 podofomerge.1 \
		podofoimgextract.1 podofoimg2pdf.1 podofotxtextract.1 \
		podofoencrypt.1 podofocrop.1 podofopdfinfo.1 podofoimpose.1 \
		podofoincrementalupdates.1 podofocountpages.1 podofopages.1 \
		podofotxt2pdf.1

.if !defined(WITHOUT_JPEG) || exists(${LOCALBASE}/lib/libjpeg.so)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif
.if !defined(WITHOUT_TIFF) || exists(${LOCALBASE}/lib/libtiff.so)
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif
.if defined(WITH_IMPOSE) || exists(${LOCALBASE}/lib/lua51/liblua.so)
USE_LUA=	5.1
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.endif

.include <bsd.port.post.mk>
