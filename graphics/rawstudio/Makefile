# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	rawstudio
PORTVERSION=	2.0
PORTREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	http://rawstudio.org/files/release/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Open-source program to read and manipulate RAW photo images

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblcms.so:graphics/lcms \
		libexiv2.so:graphics/exiv2 \
		libdbus-1.so:devel/dbus \
		libfftw3f.so:math/fftw3-float \
		liblensfun.so:graphics/lensfun \
		libflickcurl.so:www/flickcurl \
		libgphoto2.so:graphics/libgphoto2
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3

BROKEN_powerpc64=	fails to link: libicuuc.so. undefined reference to __cxa_throw_bad_array_new_length

USES=		compiler:c++11-lang desktop-file-utils gettext gmake \
		gnome jpeg libtool localbase pathfix pkgconfig sqlite
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libxml2 gconf2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CXXFLAGS+=	-Wno-c++11-narrowing

post-patch:
	@${REINPLACE_CMD} -e '/^pkg_modules=/s,libssl,gthread-2.0,' \
		${WRKSRC}/configure
# lensfun 0.3.0 had removed support for LF_MODIFY_CCI
	@${REINPLACE_CMD} -e 's, | LF_MODIFY_CCI,,' \
		${WRKSRC}/plugins/lensfun/lensfun.c

.include <bsd.port.mk>
