PORTNAME=	starfighter
PORTVERSION=	2.4
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	alfix86@gmail.com
COMMENT=	Liberate the universe from the evil company WEAPCO
WWW=		https://pr-starfighter.github.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext gnome iconv pkgconfig python:build sdl
USE_SDL=	sdl2 image2 mixer2 ttf2
USE_GNOME=	pango
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	pr-starfighter

LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS

pre-build:
	@cd ${WRKSRC}/locale && ${PYTHON_CMD} build.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
