# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wxsvg
PORTVERSION=	1.5.13
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

LICENSE=	LGPL21+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libexpat.so:textproc/expat2 \
		libexif.so:graphics/libexif

USES=		compiler:c++11-lib gettext-runtime gmake libtool pathfix pkgconfig tar:bzip2
USE_WX=		3.0
WX_CONF_ARGS=	absolute
USE_GNOME=	cairo glib20 pango
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBAV_CFLAGS="${LIBAV_CFLAGS}" LIBAV_LIBS="${LIBAV_LIBS}" \
		CXXFLAGS="${CXXFLAGS} -std=c++11"
MAKE_ENV=	AM_CPPFLAGS="${LIBAV_CFLAGS}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-extract:
.for i in configure install-sh
	@${CHMOD} ${BINMODE} ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
