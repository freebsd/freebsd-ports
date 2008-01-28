# New ports collection makefile for:	pfstools
# Date created:		25 September 2007
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	pfstools
PORTVERSION=	1.6.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	darius@dons.net.au
COMMENT=	Tools for manipulating HDR images and video frames

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_TARGET:=	--build=${CONFIGURE_TARGET}
CONFIGURE_ARGS=	--disable-jpeghdr --disable-matlab
CONFIGURE_ENV=	CPPFLAGS="${PFS_CPPFLAGS}" \
		LDFLAGS="${PFS_LDFLAGS}" \
		PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GL=		glut

USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig

# on TIFF
		EXR "Compile programs that use OpenEXR library" off \
		TIFF "Compile programs that use TIFF library" on \
		QT "Compile programs that use QT library" off \
		IM "Compile programs that use ImageMagick library" off \
		OCTAVE "Compile octave interface functioffs" off \
		GL "Compile opengl code (pfsglview)" off

MAN1=		pfsin.1 \
		pfsout.1 \
		pfsinppm.1 \
		pfsinexr.1 \
		pfsinrgbe.1 \
		pfsintiff.1 \
		pfsoutppm.1 \
		pfsoutexr.1 \
		pfsoutffmpeg.1 \
		pfsinpfm.1 \
		pfsoutpfm.1 \
		pfsinmulti.1 \
		pfsinimgmagick.1 \
		pfsoutimgmagick.1 \
		pfsinjpeghdr.1 \
		pfsoutjpeghdr.1 \
		pfsindcraw.1 \
		pfsgamma.1 \
		pfsclamp.1 \
		pfstag.1 \
		pfssize.1 \
		pfsextractchannels.1 \
		pfspanoramic.1 \
		pfsrotate.1 \
		pfsflip.1 \
		pfscut.1 \
		pfspad.1 \
		pfscat.1 \
		pfsabsolute.1

MLINKS=		pfsoutppm.1 \
		pfsouttiff.1 \
		pfsoutppm.1 \
		pfsoutrgbe.1

.include <bsd.port.pre.mk>

.if defined(WITH_PPM)
CONFIGURE_ARGS+=--enable-ppm
LIB_DEPENDS+=	netpbm.1:${PORTSDIR}/graphics/netpbm
PLIST_SUB+=	PPM=""
.else
CONFIGURE_ARGS+=--disable-ppm
PLIST_SUB+=	PPM="@comment "
.endif

.if defined(WITH_EXR)
PFS_CPPFLAGS+=	${PTHREAD_CFLAGS}
PFS_LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS+=--enable-openexr --with-exrdir=${LOCALBASE}/include/OpenEXR
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	EXR=""
.else
CONFIGURE_ARGS+=--disable-openexr
PLIST_SUB+=	EXR="@comment "
.endif

.if defined(WITH_TIFF)
CONFIGURE_ARGS+=--enable-tiff
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--disable-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

.if defined(WITH_QT)
CONFIGURE_ARGS+=--enable-qt
USE_QT_VER=	3
LIB_DEPENDS+=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt33
PLIST_SUB+=	QT=""
MAN1+=		pfsview.1 \
		pfsv.1
.else
CONFIGURE_ARGS+=--disable-qt
PLIST_SUB+=	QT="@comment "
.endif

.if defined(WITH_IM)
CONFIGURE_ARGS+=--enable-imagemagick
LIB_DEPENDS+=	Magick++.10:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IM=""
.else
CONFIGURE_ARGS+=--disable-imagemagick
PLIST_SUB+=	IM="@comment "
.endif

.if defined(WITH_OCTAVE)
CONFIGURE_ARGS+=--enable-octave
USE_FORTRAN=	yes
BUILD_DEPENDS+=	mkoctfile:${PORTSDIR}/math/octave
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave
PLIST_SUB+=	OCTAVE="" \
		OCTAVE_VERSION="`${LOCALBASE}/bin/octave-config -v`" \
		BUILD=${CONFIGURE_TARGET:S/--build//}
MAN1+=		pfsoctavelum.1 \
		pfsoctavergb.1 \
		pfsstat.1
.else
CONFIGURE_ARGS+=--disable-octave
PLIST_SUB+=	OCTAVE="@comment "
.endif

.if defined(WITH_GL)
PFS_CPPFLAGS+=	-I${X11BASE}/include
PFS_LDFLAGS+=	-L${X11BASE}/lib
CONFIGURE_ARGS+=--enable-opengl
LIB_DEPENDS+=	glut.4:${PORTSDIR}/graphics/libglut
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	GL="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s,#!/bin/bash,#!${LOCALBASE}/bin/bash," \
		${WRKSRC}/src/fileformat/pfsin \
		${WRKSRC}/src/fileformat/pfsout \
		${WRKSRC}/src/fileformat/pfsinmulti \
		${WRKSRC}/src/fileformat/pfsindcraw \
		${WRKSRC}/src/pfsview/pfsv
.if defined(WITH_OCT)
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/octave|${LOCALBASE}/bin/octave|' \
		${WRKSRC}/src/octave/*
.endif

.include <bsd.port.post.mk>
