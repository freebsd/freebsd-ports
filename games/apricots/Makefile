PORTNAME=	apricots
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.8
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fly a little plane around and shoot things and drop bombs
WWW=		https://github.com/moggers87/apricots

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libalure.so:audio/alure

USES=		autoreconf compiler:c++17-lang gmake openal:al sdl
USE_GITHUB=	yes
GH_ACCOUNT=	moggers87
GNU_CONFIGURE=	yes
USE_SDL=	sdl2

LDFLAGS_i386=	-Wl,-znotext

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/apricots.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/contrib/desktop-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/apricots.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS NEWS README.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
