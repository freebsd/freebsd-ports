# New ports collection makefile for:	exact-image
# Date created:		2 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exact-image
PORTVERSION=	0.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://dl.exactcode.de/oss/${PORTNAME}/

MAINTAINER=	bf1783@gmail.com
COMMENT=	Fast image processing library

BUILD_DEPENDS=	swig>=1.3.32:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	agg.2:${PORTSDIR}/graphics/agg \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.6:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		jasper.4:${PORTSDIR}/graphics/jasper \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		lcms.1:${PORTSDIR}/graphics/lcms \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

CFLAGS+=	-fPIC
#hack to get custom exactcode configure script to enable tiff support with
#broken headers on c++ in base system:
CPPFLAGS+=	-fpermissive
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_PYTHON=	2.5+
USE_XORG=	x11
USE_EFL=	evas
USE_EFL_EVAS_ENGINES=	x11 opengl
HAS_CONFIGURE=	yes
INSTALL_WRKSRC=	${WRKSRC}/objdir
BINS=	bardecode econvert edentify edisplay empty-page hocr2pdf optimize2bw
PLIST_FILES=	${BINS:S|^|bin/|} \
		%%SITE_PERL%%/ExactImage.so \
		%%SITE_PERL%%/ExactImage.pm \
		%%PYTHON_SITELIBDIR%%/ExactImage.py \
		%%PYTHON_SITELIBDIR%%/_ExactImage.so

post-extract:
	@${RM} -rf ${WRKSRC}/agg-2.4/

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|;s|/usr/local|${LOCALBASE}|;\
		/parse_options/d;s| cc | ${CC} |;s| c++ | ${CXX} |;\
		s|python -V|${PYTHON_CMD} -V|;\
		/PYTHONINCS/s|=.*$$|=-I${PYTHON_INCLUDEDIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^Q =/d;s|$$[(]COMPILE.cc[)]|${CXX} $${CPPFLAGS} -c|;\
		s|$$[(]CXX[)]|${CXX}|;s|$$[(]COMPILE.c[)]|${CC} $${CPPFLAGS} -c|'\
			${WRKSRC}/build/bottom.make
	@${REINPLACE_CMD} -e '/^CFLAGS =/d;/^CXXFLAGS =/d;/march=/d;\
		/mtune=/d;/call cc-option/d;' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CFLAGS=/s|".*"|"${CFLAGS} -I${LOCALBASE}/include"|;\
		/LIBS=/s|".*"|"-L${LOCALBASE}/lib -lX11"|' ${WRKSRC}/config/pkgcheck-x11.c
	@${REINPLACE_CMD} -e 's|$$prg|$$prg ${CPPFLAGS} -I${LOCALBASE}/include|;\
		s|/usr/local|${PREFIX}|;/^var_remove/,/^}/d;/^parse_options/,/^}/d' \
		 ${WRKSRC}/config/functions
	@${REINPLACE_CMD} -e 's|/usr/X11|${LOCALBASE}|' ${WRKSRC}/lib/vectorial.cc \
		${WRKSRC}/edisplay/edisplay.cc

do-install:
	@cd ${INSTALL_WRKSRC}/&&for i in ${BINS};do\
		${INSTALL_PROGRAM} */$$i ${PREFIX}/bin/;done
	@cd ${INSTALL_WRKSRC}/api/perl&&\
		${INSTALL_PROGRAM} ExactImage.so ${SITE_PERL}/;\
		${INSTALL_DATA} ExactImage.pm ${SITE_PERL}/
	@cd ${INSTALL_WRKSRC}/api/python&&\
		${INSTALL_SCRIPT} ExactImage.py ${PYTHONPREFIX_SITELIBDIR}/;\
		${INSTALL_PROGRAM} _ExactImage.so ${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.mk>
