# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exact-image
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	graphics perl5 python
MASTER_SITES=	https://dl.exactcode.de/oss/exact-image/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast image processing library

LICENSE=	GPLv2

BROKEN_armv6=		fails to configure: C++ compiler is not installed or does not work correctly
BROKEN_armv7=		fails to configure: C++ compiler is not installed or does not work correctly

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libagg.so:graphics/agg \
		libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libjasper.so:graphics/jasper \
		libImath-2_3.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		liblcms.so:graphics/lcms \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

#hack to get custom exactcode configure script to enable tiff support with
#broken headers on c++ in base system:
CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include
USES=		gmake jpeg perl5 pkgconfig python:2.7 tar:bzip2 xorg
USE_CXXSTD=	c++03
USE_XORG=	x11
HAS_CONFIGURE=	yes
INSTALL_WRKSRC=	${WRKSRC}/objdir
BINS=		bardecode econvert edentify empty-page hocr2pdf optimize2bw
PLIST_FILES=	${BINS:S|^|bin/|} \
		%%SITE_PERL%%/ExactImage.so \
		%%SITE_PERL%%/ExactImage.pm \
		%%PYTHON_SITELIBDIR%%/ExactImage.py \
		%%PYTHON_SITELIBDIR%%/_ExactImage.so
BINARY_ALIAS=	swig=swig3.0

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|;s|/usr/local|${LOCALBASE}|;\
		/parse_options/d;s| cc | ${CC} |;s| c++ | ${CXX} |;\
		s|python -V|${PYTHON_CMD} -V|;\
		/PYTHONINCS/s|=.*$$|=-I${PYTHON_INCLUDEDIR}|; \
		s|pkg-config EVAS atleast 0.9.9|pkg-config EVAS equals 1.7.9|; \
		s|php -config PHP atleast 5.2.0|php -config PHP atleast 15.2.0|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^Q =/d;s|$$[(]COMPILE.cc[)]|${CXX} $${CPPFLAGS} -c|;\
		s|$$[(]CXX[)]|${CXX}|;s|$$[(]COMPILE.c[)]|${CC} $${CPPFLAGS} -c|'\
		${WRKSRC}/build/bottom.make
	@${REINPLACE_CMD} -e '/CFLAGS=/s|".*"|"${CFLAGS} -I${LOCALBASE}/include"|;\
		/LIBS=/s|".*"|"-L${LOCALBASE}/lib -lX11"|' ${WRKSRC}/config/pkgcheck-x11.c
	@${REINPLACE_CMD} -e 's|$$prg|$$prg ${CPPFLAGS} -I${LOCALBASE}/include|;\
		s|/usr/local|${PREFIX}|;/^var_remove/,/^}/d;/^parse_options/,/^}/d; \
		s| ++errors | errors+=1 |g' \
		${WRKSRC}/config/functions
	@${REINPLACE_CMD} -e 's|/usr/X11|${LOCALBASE}|' \
		${WRKSRC}/image/vectorial.cc \
		${WRKSRC}/edisplay/edisplay.cc
	@${REINPLACE_CMD} -e 's| = {}||g' ${WRKSRC}/image/Colorspace.cc

do-install:
	@cd ${INSTALL_WRKSRC}/&&for i in ${BINS};do\
		${INSTALL_PROGRAM} */$$i ${STAGEDIR}${PREFIX}/bin/;done
	@cd ${INSTALL_WRKSRC}/api/perl&&\
		${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}&&\
		${INSTALL_PROGRAM} ExactImage.so ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/&&\
		${INSTALL_DATA} ExactImage.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/
	@cd ${INSTALL_WRKSRC}/api/python&&\
		${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/&&\
		${INSTALL_SCRIPT} ExactImage.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/&&\
		${INSTALL_PROGRAM} _ExactImage.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.mk>
