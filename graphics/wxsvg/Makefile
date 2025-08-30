PORTNAME=	wxsvg
DISTVERSION=	1.5.25
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	C++ library to create, manipulate, and render SVG files
WWW=		https://wxsvg.sourceforge.net/

LICENSE=	LGPL21+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libexpat.so:textproc/expat2 \
		libexif.so:graphics/libexif \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lib gettext-runtime gmake gnome libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo glib20 pango
USE_WX=		3.2+
WX_CONF_ARGS=	absolute
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-extract:
.for i in configure install-sh
	@${CHMOD} ${BINMODE} ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
