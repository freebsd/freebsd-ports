# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	pfstools
PORTVERSION=	1.6.4
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	darius@dons.net.au
COMMENT=	Tools for manipulating HDR images and video frames

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib
PFS_BUILD=	${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_SUB+=	PFS_BASE=${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	${PFS_BUILD}
CONFIGURE_ARGS=	--disable-jpeghdr --disable-matlab \
		--with-bash=${LOCALBASE}/bin/bash
CONFIGURE_ENV=	PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
CPPFLAGS+=	${PFS_CPPFLAGS}
LDFLAGS+=	${PFS_LDFLAGS}
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USES=	pkgconfig

OPTIONS_DEFINE=	NETPBM OPENEXR TIFF IMAGEMAGICK OCTAVE OPENGL
OCTAVE_DESC=	Compile octave interface functions

OPTIONS_DEFAULT=	TIFF

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETPBM}
CONFIGURE_ARGS+=--enable-ppm
LIB_DEPENDS+=	netpbm.1:${PORTSDIR}/graphics/netpbm
PLIST_SUB+=	PPM=""
.else
CONFIGURE_ARGS+=--disable-ppm
PLIST_SUB+=	PPM="@comment "
.endif

.if ${PORT_OPTIONS:MOPENEXR}
PFS_CPPFLAGS+=	${PTHREAD_CFLAGS}
PFS_LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS+=--enable-openexr --with-exrdir=${LOCALBASE}/include/OpenEXR
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	EXR=""
.else
CONFIGURE_ARGS+=--disable-openexr
PLIST_SUB+=	EXR="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
CONFIGURE_ARGS+=--enable-tiff
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--disable-tiff
PLIST_SUB+=	TIFF="@comment "
.endif

CONFIGURE_ARGS+=--disable-qt
PLIST_SUB+=	QT="@comment "

.if ${PORT_OPTIONS:MIMAGEMAGICK}
CONFIGURE_ARGS+=--enable-imagemagick
LIB_DEPENDS+=	Magick++.5:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IM=""
.else
CONFIGURE_ARGS+=--disable-imagemagick
PLIST_SUB+=	IM="@comment "
.endif

.if ${PORT_OPTIONS:MOCTAVE}
CONFIGURE_ARGS+=--enable-octave
USE_FORTRAN=	yes

# need to determine which octave installed which patching
PATCH_DEPENDS+=	mkoctfile:${PORTSDIR}/math/octave
BUILD_DEPENDS+=	mkoctfile:${PORTSDIR}/math/octave
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave

OCTAVE_BASE?=	${LOCALBASE}
OCTAVE_VERSION!=${OCTAVE_BASE}/bin/octave-config -v 2>&1 || ${ECHO} "0"
PLIST_SUB+=	OCTAVE="" \
		OCTAVE_VERSION=${OCTAVE_VERSION} \
		OCTAVE_BASE=${OCTAVE_BASE} \
		BUILD=${PFS_BUILD}
.if (!empty(OCTAVE_VERSION:M[3-9].*))
EXTRA_PATCHES+=	${PATCHDIR}/epatch-src-octave-pfsopen.cpp
.endif
MAN1+=		pfsoctavelum.1 \
		pfsoctavergb.1 \
		pfsstat.1
.else
CONFIGURE_ARGS+=--disable-octave
PLIST_SUB+=	OCTAVE="@comment "
.endif

.if ${PORT_OPTIONS:MOPENGL}
CONFIGURE_ARGS+=--enable-opengl
USE_GL=		glut
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	GL="@comment "
.endif

.if ${PORT_OPTIONS:MOCTAVE}
pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/octave|${LOCALBASE}/bin/octave|' \
		${WRKSRC}/src/octave/*
.endif

.include <bsd.port.mk>
