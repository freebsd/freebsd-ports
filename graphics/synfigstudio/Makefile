PORTNAME=	synfigstudio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.5
PORTREVISION=	4
CATEGORIES=	graphics multimedia

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Vector-based 2D animation software package
WWW=		https://www.synfig.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.4.5:devel/etl \
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

USES=		autoreconf compiler:c++11-lang desktop-file-utils gmake \
		gnome libtool localbase magick:7 mlt:7 pathfix pkgconfig \
		shared-mime-info
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
USE_GNOME=	gdkpixbuf gtkmm30 intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb
INSTALL_TARGET=	install-strip

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PORTSCOUT=	limitw:1,even

WRKSRC_SUBDIR=	synfig-studio

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
