PORTNAME=	libfpx
DISTVERSION=	1.3.1-10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.imagemagick.org/download/delegates/	\
		https://mirror.aarnet.edu.au/pub/imagemagick/delegates/ \
		https://mirror.checkdomain.de/imagemagick/delegates/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Library routines for working with Flashpix images
WWW=		https://github.com/ImageMagick/libfpx

USES=		cpe tar:xz uidfix

CPE_VENDOR=	libfpx_project

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
