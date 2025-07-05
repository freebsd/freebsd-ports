PORTNAME=	rawstudio
PORTVERSION=	2.0
PORTREVISION=	27
CATEGORIES=	graphics
MASTER_SITES=	http://rawstudio.org/files/release/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source program to read and manipulate RAW photo images
WWW=		https://rawstudio.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblcms.so:graphics/lcms \
		libexiv2.so:graphics/exiv2 \
		libdbus-1.so:devel/dbus \
		libfftw3f.so:math/fftw3-float \
		libflickcurl.so:www/flickcurl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgphoto2.so:graphics/libgphoto2 \
		libharfbuzz.so:print/harfbuzz \
		liblensfun.so:graphics/lensfun \
		libpng.so:graphics/png \
		libraptor2.so:textproc/raptor2 \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang cpe desktop-file-utils gmake gnome \
		jpeg libtool localbase pathfix pkgconfig sqlite xorg
USE_GNOME=	cairo gconf2 gdkpixbuf gtk20 libxml2
USE_LDCONFIG=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CXXFLAGS+=	-Wno-c++11-narrowing

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e '/^pkg_modules=/s,libssl,gthread-2.0,' \
		${WRKSRC}/configure
# lensfun 0.3.0 had removed support for LF_MODIFY_CCI
	@${REINPLACE_CMD} -e 's, | LF_MODIFY_CCI,,' \
		${WRKSRC}/plugins/lensfun/lensfun.c

.include <bsd.port.mk>
