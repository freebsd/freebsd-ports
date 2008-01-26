# New ports collection makefile for:	pfstools
# Date created:		25 September 2007
# Whom:			Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	pfstools
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	darius@dons.net.au
COMMENT=	Tools for manipulating HDR images and video frames

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		Magick++:${PORTSDIR}/graphics/ImageMagick

BROKEN=		does not build

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	ltverhack
CONFIGURE_ARGS+=--disable-jpeghdr --disable-ppm
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
USE_GL=		glut

OPTIONS=	OCTAVE "Install Octave interface" on

MAN1=		pfsabsolute.1 pfscat.1 pfsclamp.1 pfscut.1 pfsextractchannels.1 \
		pfsflip.1 pfsgamma.1 pfsin.1 pfsindcraw.1 pfsinexr.1 \
		pfsinimgmagick.1 pfsinjpeghdr.1 pfsinmulti.1 pfsinpfm.1 pfsinppm.1 \
		pfsinrgbe.1 pfsintiff.1 pfsout.1 pfsoutexr.1 pfsoutffmpeg.1 \
		pfsoutimgmagick.1 pfsoutjpeghdr.1 pfsoutpfm.1 pfsoutppm.1 pfspad.1 \
		pfspanoramic.1 pfsrotate.1 pfssize.1 pfsstat.1 pfstag.1 pfsv.1 \
		pfsview.1
MLINKS=		pfsoutppm.1 pfsouttiff.1 \
		pfsoutppm.1 pfsoutrgbe.1

.include <bsd.port.pre.mk>

.if defined(WITH_OCTAVE)
USE_FORTRAN=	yes
BUILD_DEPENDS+=	octave:${PORTSDIR}/math/octave
RUN_DEPENDS+=	octave:${PORTSDIR}/math/octave
PLIST_SUB=	OCTAVE_VERSION="`${LOCALBASE}/bin/octave-config -v`" \
		GNU_HOST=${ARCH}-portbld-freebsd${OSREL} \
		OCTAVE_PLIST=
MAN1+=		pfsoctavelum.1 pfsoctavergb.1
.else
PLIST_SUB=	OCTAVE_PLIST=#
CONFIGURE_ARGS+=--disable-octave
.endif

pre-configure:
	${REINPLACE_CMD} -e "s,#!/bin/bash,#!${LOCALBASE}/bin/bash," \
		${WRKSRC}/src/fileformat/pfsin \
		${WRKSRC}/src/fileformat/pfsout \
		${WRKSRC}/src/fileformat/pfsinmulti \
		${WRKSRC}/src/fileformat/pfsindcraw \
		${WRKSRC}/src/pfsview/pfsv

.include <bsd.port.post.mk>
