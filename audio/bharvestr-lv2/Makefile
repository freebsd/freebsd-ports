# $FreeBSD$

PORTNAME=	bharvestr
DISTVERSIONPREFIX=	v
DISTVERSION=	g20200413
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Granular synthesizer LV2 plugin

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BHarvestr
GH_TAGNAME=	f07ec1e68337960860d06cac7a84a92d456e7f56
USE_GNOME=	cairo
USE_XORG=	x11

MAKEFILE=	makefile

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/lv2/BHarvestr.lv2/LICENSE
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BHarvestr.lv2/BHarvestr*.so

.include <bsd.port.mk>
