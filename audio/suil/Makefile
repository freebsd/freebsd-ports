# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	suil
PORTVERSION=	0.8.2
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Suil is a C library for loading and wrapping LV2 plugin UIs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libQtCore.so:devel/qt4-corelib \
		libQtGui.so:x11-toolkits/qt4-gui \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig python:build tar:bzip2 waf

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango

USE_LDCONFIG=	yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsuil-0.so.0.8.2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_gtk2_in_qt4.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_qt4_in_gtk2.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_x11_in_gtk2.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_x11_in_qt4.so

.include <bsd.port.mk>
