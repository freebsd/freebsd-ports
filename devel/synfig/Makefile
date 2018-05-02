# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfig
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	devel graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}/source

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Vector based 2D animation package

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.2.1:devel/etl
LIB_DEPENDS=	libHalf.so:graphics/ilmbase \
		libIlmImf.so:graphics/OpenEXR \
		libMagickWand-6.so:graphics/ImageMagick \
		libavcodec.so:multimedia/ffmpeg \
		libboost_program_options.so:devel/boost-libs \
		libdv.so:multimedia/libdv \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libltdl.so:devel/libltdl \
		libmlt.so:multimedia/mlt \
		libmng.so:graphics/libmng \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang gmake iconv jpeg libtool localbase pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	cairo glibmm intltool libxml++26 pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} &&  ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
