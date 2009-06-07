# New ports collection makefile for:	exact-image
# Date created:		2 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exact-image
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://dl.exactcode.de/oss/${PORTNAME}/ CENKES

MAINTAINER=	bf1783@gmail.com
COMMENT=	Fast image processing library

BUILD_DEPENDS=	swig>=1.3.31:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	agg.2:${PORTSDIR}/graphics/agg \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		jasper.4:${PORTSDIR}/graphics/jasper \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		lcms.1:${PORTSDIR}/graphics/lcms

CFLAGS+=	-fPIC
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_XORG=	x11
USE_EFL=	evas
USE_EFL_EVAS_ENGINES=	x11 opengl
HAS_CONFIGURE=	yes
INSTALL_WRKSRC=	${WRKSRC}/objdir
BINS=	econvert edisplay edentify optimize2bw empty-page
PLIST_FILES=	${BINS:S|^|bin/|} %%SITE_PERL%%/ExactImage.so \
		%%SITE_PERL%%/ExactImage.pm
PORT_VERBS=	ExactImage ${BINS}

post-extract:
	@${RM} -rf ${WRKSRC}/agg-2.4/

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|;s|libpng|libpng12|;\
		/parse_options/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^Q =/d;s|$$[(]COMPILE.cc[)]|${CXX} $${CPPFLAGS} -c|;\
		s|$$[(]CXX[)]|${CXX}|;s|$$[(]COMPILE.c[)]|${CC} $${CPPFLAGS} -c|'\
			${WRKSRC}/build/bottom.make
	@${REINPLACE_CMD} -e '/^CFLAGS =/d;/^CXXFLAGS =/d;/march=/d;\
		/mtune=/d;/call cc-option/d;' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CFLAGS=/s|".*"|"${CFLAGS} -I${LOCALBASE}/include"|;\
		/LIBS=/s|".*"|"-L${LOCALBASE}/lib -lX11"|' ${WRKSRC}/config/pkgcheck-x11.c
	@${REINPLACE_CMD} -e 's|$$prg|$$prg -I${LOCALBASE}/include|;\
		/^var_remove/,/^}/d;/^parse_options/,/^}/d' ${WRKSRC}/config/functions

post-configure:
	@${REINPLACE_CMD} -e '/EVASGL/s|1|0|' ${WRKSRC}/config.h
	@${ECHO_CMD} '#define WITHLIBPNG 1' >> ${WRKSRC}/config.h
	@${ECHO_CMD} 'WITHLIBPNG = 1' >> ${WRKSRC}/config.make
	@${ECHO_CMD} 'EVASGL = 0' >> ${WRKSRC}/config.make

do-install:
	@cd ${INSTALL_WRKSRC}/&&for i in ${BINS};do\
		${INSTALL_PROGRAM} */$$i ${PREFIX}/bin/;done
	@cd ${INSTALL_WRKSRC}/api/&&\
		${INSTALL_PROGRAM} ExactImage.so ${SITE_PERL}/;\
		${INSTALL_DATA} ExactImage.pm ${SITE_PERL}/

.include <bsd.port.mk>
