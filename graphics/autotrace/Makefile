# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.27a
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://homepage.go.com/~martweb/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	jbig.1:${PORTSDIR}/graphics/jbigkit \
		df.1:${PORTSDIR}/graphics/hdf \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.7:${PORTSDIR}/print/freetype2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		ming.2:${PORTSDIR}/graphics/ming \
		wmf.1:${PORTSDIR}/graphics/libwmf \
		Magick.5:${PORTSDIR}/graphics/ImageMagick
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
USE_XLIB=	yes

pre-configure:
	@(cd ${WRKSRC} ; ${AUTOCONF})

do-configure:
	@(cd ${WRKSRC}/ ; set CPPFLAGS="-I${PREFIX}/include" ; \
	  set CFLAGS="-I${PREFIX}/include -L${PREFIX}/lib" ; ./configure )

.include <bsd.port.mk>
