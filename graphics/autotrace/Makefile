# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.28
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} 
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	jbig.1:${PORTSDIR}/graphics/jbigkit \
		df.1:${PORTSDIR}/graphics/hdf \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.8:${PORTSDIR}/print/freetype2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ming.3:${PORTSDIR}/graphics/ming \
		wmf.2:${PORTSDIR}/graphics/libwmf \
		Magick.5:${PORTSDIR}/graphics/ImageMagick
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_XLIB=	yes

pre-install:
	@(cd ${WRKSRC} ; perl -p -i.bak -e s/\\@OBJEXT\\@/o/ Makefile)	

.include <bsd.port.mk>
