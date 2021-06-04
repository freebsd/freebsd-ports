PORTNAME=	fheroes2
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free implementation of Heroes of Might and Magic II engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake gettext-tools iconv localbase:ldflags pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ihhub
USE_SDL=	image2 mixer2 sdl2 ttf2

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.txt \
		changelog.txt

.include <bsd.port.mk>
