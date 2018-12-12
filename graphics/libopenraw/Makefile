# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenraw
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs

USES=		compiler:c++11-lib jpeg libtool localbase pkgconfig tar:bz2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include \
		--disable-silent-rules
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		GNOME TEST
OPTIONS_DEFAULT=	GNOME
OPTIONS_SUB=		yes

GNOME_CONFIGURE_ENABLE=	gnome
GNOME_USES=		gettext-runtime
GNOME_USE=		GNOME=glib20,gdkpixbuf2

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|\{libdir\}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
		-e '/^(CFLAGS|CXXFLAGS)/s|-g||g' \
		${WRKSRC}/configure

post-patch-TEST-off:
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
