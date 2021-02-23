# $FreeBSD$

PORTNAME=	fheroes2
PORTVERSION=	0.9
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free implementation of Heroes of Might and Magic II engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USES=		gettext-tools gmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ihhub
USE_SDL=	image2 mixer2 sdl2 ttf2

LDFLAGS+=	-ltinyxml
MAKE_ENV=	WITHOUT_BUNDLED_LIBS=1

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
