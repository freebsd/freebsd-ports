PORTNAME=	toycars
PORTVERSION=	0.3.10
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Physics-based 2D racing game

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		gl gmake localbase sdl
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes
USE_SDL=	image sdl
USE_GL=		gl glu

PLIST_FILES=	bin/toycars \
		bin/toycars_track_editor \
		bin/toycars_vehicle_editor
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/data/.*Store

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
