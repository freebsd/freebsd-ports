PORTNAME=	synfig
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4
PORTREVISION=	8
CATEGORIES=	graphics devel multimedia

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Vector based 2D animation package
WWW=		https://www.synfig.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.2.2:devel/etl \
		gsed:textproc/gsed
LIB_DEPENDS=	libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libavcodec.so:multimedia/ffmpeg \
		libboost_program_options.so:devel/boost-libs \
		libdv.so:multimedia/libdv \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libltdl.so:devel/libltdl \
		libmng.so:graphics/libmng \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		autoreconf compiler:c++11-lang gmake gnome iconv jpeg \
		libtool localbase magick:7 mlt:7 pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GITHUB=	yes
USE_GNOME=	cairo glibmm intltool libxml++26 pango
USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
WRKSRC_SUBDIR=	synfig-core

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

CONFIGURE_ENV+=	ac_cv_path_SED=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README TODO
	(cd ${WRKSRC} &&  ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
