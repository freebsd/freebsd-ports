# Created by: ijliao
# $FreeBSD$

PORTNAME=	libqrencode
DISTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding data in a QR Code symbol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	fukuchi

USES=		cmake iconv pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON
PLIST_FILES=	bin/qrencode \
		include/qrencode.h \
		lib/libqrencode.so \
		lib/libqrencode.so.4 \
		lib/libqrencode.so.4.0.0 \
		libdata/pkgconfig/libqrencode.pc \
		man/man1/qrencode.1.gz

post-patch:
	@${SED} -i -e 's|share\/man\/man1|man\/man1|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
