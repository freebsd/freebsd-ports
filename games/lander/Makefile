PORTNAME=	lander
PORTVERSION=	0.7.2
CATEGORIES=	games
MASTER_SITES=	https://www.nickg.me.uk/files/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		compiler:c++17-lang gettext gl meson sdl pkgconfig tar:xz
USE_SDL=	sdl2 image2 mixer2
USE_GL=		gl glew

LDFLAGS+=	${LOCALBASE}/lib/libintl.so

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
