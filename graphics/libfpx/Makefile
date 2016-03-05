# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	libfpx
DISTVERSION=	1.3.1-4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://imagemagick.mirrorcatalogs.com/delegates/	\
		http://www.imagemagick.org/download/delegates/	\
		ftp://mirror.aarnet.edu.au/pub/imagemagick/delegates/	\
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/delegates/ \
		http://servingzone.com/mirrors/ImageMagick/delegates/	\
		http://mirror.checkdomain.de/imagemagick/delegates/	\
		ftp://mirror.checkdomain.de/imagemagick/delegates/	\
		http://image_magick.veidrodis.com/image_magick/delegates/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library routines for working with Flashpix images

USES=		tar:xz uidfix

PLIST_FILES=	lib/libfpx.so.2 lib/libfpx.so lib/libfpx.a include/fpxlib.h
USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
post-patch:
	${SED} -i '' -e '/^#include "fpxlib-config.h"/d'	\
		${WRKSRC}/basics/filename.cpp	\
		${WRKSRC}/oless/h/owchar.h	\
		${WRKSRC}/ole/gen_guid.cpp	\
		${WRKSRC}/fpxlib.h

.include <bsd.port.mk>

# We want the port's Makefile to build compiler-flags from scratch
# (based on WARNS= in particular) instead of being influenced by
# the environment... There is no obvious way to prevent bsd.port.mk
# from adding CFLAGS and CXXFLAGS to the build environment, so we
# remove them here.
MAKE_ENV:=	${MAKE_ENV:NCFLAGS=*:NCXXFLAGS=*}
