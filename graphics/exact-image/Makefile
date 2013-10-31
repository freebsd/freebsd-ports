# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exact-image
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	graphics perl5 python
MASTER_SITES=	http://dl.exactcode.de/oss/${PORTNAME}/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast image processing library

LICENSE=	GPLv2

BUILD_DEPENDS=	swig>=1.3.32:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libagg.so:${PORTSDIR}/graphics/agg \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2

CFLAGS+=	-fPIC
#hack to get custom exactcode configure script to enable tiff support with
NO_STAGE=	yes
#broken headers on c++ in base system:
CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include/libpng15
USE_BZIP2=	yes
USES=		gmake perl5 pkgconfig
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
		s|libungif|giflib|; s|LIBUNGIF|GIFLIB|; \
		/parse_options/d;s| cc | ${CC} |;s| c++ | ${CXX} |;\
		s|python -V|${PYTHON_CMD} -V|;\
		/PYTHONINCS/s|=.*$$|=-I${PYTHON_INCLUDEDIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^Q =/d;s|$$[(]COMPILE.cc[)]|${CXX} $${CPPFLAGS} -c|;\
		s|$$[(]CXX[)]|${CXX}|;s|$$[(]COMPILE.c[)]|${CC} $${CPPFLAGS} -c|'\
		${WRKSRC}/build/bottom.make
	@${REINPLACE_CMD} -e '/^CFLAGS =/d;/^CXXFLAGS =/d;/march=/d;\
		/mtune=/d;/call cc-option/d;' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-lungif|-lgif|; s|LIBUNGIF|GIFLIB|' \
		${WRKSRC}/codecs/Makefile
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
		${MKDIR} ${PREFIX}/${SITE_PERL_REL}&&\
		${INSTALL_PROGRAM} ExactImage.so ${PREFIX}/${SITE_PERL_REL}/&&\
		${INSTALL_DATA} ExactImage.pm ${PREFIX}/${SITE_PERL_REL}/
	@cd ${INSTALL_WRKSRC}/api/python&&\
		${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/&&\
		${INSTALL_SCRIPT} ExactImage.py ${PYTHONPREFIX_SITELIBDIR}/&&\
		${INSTALL_PROGRAM} _ExactImage.so ${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.mk>
