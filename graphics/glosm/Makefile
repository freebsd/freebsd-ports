PORTNAME=	glosm
PORTVERSION=	0.0.2
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	7
CATEGORIES=	graphics geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D OpenGL renderer for OpenStreetMap

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libexpat.so:textproc/expat2

USES=		cmake gl sdl tar:bzip2 xorg
USE_GL=		gl
USE_XORG=	x11
USE_SDL=	sdl
USE_CXXSTD=	c++98
USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
TEST_TARGET=	test

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
