PORTNAME=	synfig
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.5
PORTREVISION=	7
CATEGORIES=	graphics devel multimedia

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Vector based 2D animation package
WWW=		https://www.synfig.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.4.5:devel/etl \
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

USES=		autoreconf compiler:c++14-lang gmake gnome iconv jpeg \
		libtool localbase magick:7 mlt:7 pathfix pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
USE_GNOME=	cairo glibmm intltool libxml++26 pango
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
CONFIGURE_ENV+=	ac_cv_path_SED=${LOCALBASE}/bin/gsed

INSTALL_TARGET=	install-strip
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	synfig-core

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
