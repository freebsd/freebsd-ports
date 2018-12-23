# $FreeBSD$

PORTNAME=	foo-yc20
DISTVERSION=	1.3.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Faust implementation of a 1969-designed Yamaha combo organ, the YC-20

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lang gmake gnome localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sampov2
USE_GNOME=	gtk20 gdkpixbuf2 cairo

post-patch:
	@${REINPLACE_CMD} -e 's|install -Dm|install -m|' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/lv2/foo-yc20.lv2/*.so

.include <bsd.port.mk>
