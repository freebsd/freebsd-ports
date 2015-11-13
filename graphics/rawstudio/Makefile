# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	rawstudio
PORTVERSION=	2.0
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://rawstudio.org/files/release/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Open-source program to read and manipulate RAW photo images

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		libflickcurl.so:${PORTSDIR}/www/flickcurl \
		libgphoto2.so:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3

USES=		desktop-file-utils gettext gmake jpeg libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libxml2 gconf2
USE_SQLITE=	3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		`pkg-config --libs gthread-2.0`

post-patch:
	@${REINPLACE_CMD} -e 's, libssl,,' ${WRKSRC}/configure
# lensfun 0.3.0 had removed support for LF_MODIFY_CCI
	@${REINPLACE_CMD} -e 's, | LF_MODIFY_CCI,,' \
		${WRKSRC}/plugins/lensfun/lensfun.c

.include <bsd.port.mk>
