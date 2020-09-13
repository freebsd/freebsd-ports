# $FreeBSD$

PORTNAME=	dssim
DISTVERSION=	1.3.3-15
DISTVERSIONSUFFIX=	-gcb6b383
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image similarity comparison simulating human perception

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	kornelski

OPTIONS_DEFINE=	JPEG
OPTIONS_DEFAULT=JPEG

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} "/^[[:space:]]*version : /s/'.*'/'${PORTVERSION}'/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
