# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	wxsvg
PORTVERSION=	1.5.23
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	C++ library to create, manipulate, and render SVG files

LICENSE=	LGPL21+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libexpat.so:textproc/expat2 \
		libexif.so:graphics/libexif \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lib gettext-runtime gmake gnome libtool pathfix pkgconfig tar:bzip2
USE_WX=		3.1
WX_CONF_ARGS=	absolute
USE_GNOME=	cairo glib20 pango
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBAV_CFLAGS="${LIBAV_CFLAGS}" LIBAV_LIBS="${LIBAV_LIBS}"
MAKE_ENV=	AM_CPPFLAGS="${LIBAV_CFLAGS}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-extract:
.for i in configure install-sh
	@${CHMOD} ${BINMODE} ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
