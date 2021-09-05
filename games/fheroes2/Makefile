PORTNAME=	fheroes2
PORTVERSION=	0.9.7
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free implementation of Heroes of Might and Magic II engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake gettext-tools iconv localbase:ldflags pkgconfig sdl \
		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ihhub
USE_SDL=	image2 mixer2 sdl2 ttf2
SHEBANG_FILES=	script/demo/demo_unix.sh

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/files/data/resurrection.h2d
PORTDOCS=	LICENSE \
		README.txt \
		changelog.txt \
		demo/demo_unix.sh

.include <bsd.port.mk>
