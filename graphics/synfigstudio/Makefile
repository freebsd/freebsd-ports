PORTNAME=	synfigstudio
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=v
CATEGORIES=	graphics multimedia

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Vector-based 2D animation software package

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.2.2:devel/etl \
		gsed:textproc/gsed
LIB_DEPENDS=	libImath.so:math/Imath \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libOpenEXR.so:graphics/openexr \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsynfig.so:graphics/synfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils

PORTSCOUT=	limitw:1,even

USES=		autoreconf compiler:c++11-lang desktop-file-utils \
		gmake gnome libtool localbase magick:6 mlt:6 pathfix pkgconfig \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
WRKSRC_SUBDIR=	synfig-studio
USE_CXXSTD=	c++11
USE_GNOME=	gdkpixbuf2 gtkmm30 intltool
GNU_CONFIGURE=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--disable-update-mimedb
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS JACK NLS
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
