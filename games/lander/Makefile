PORTNAME=	lander
DISTVERSIONPREFIX=	r
DISTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone
WWW=		https://www.doof.me.uk/lunar-lander/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		compiler:c++17-lang display:test gettext gl meson sdl pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	nickg
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
