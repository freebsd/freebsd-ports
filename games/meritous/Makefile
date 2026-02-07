PORTNAME=	meritous
PORTVERSION=	1.5
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Action-adventure dungeon crawl game
WWW=		https://www.asceai.net/meritous/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome sdl
USE_GNOME=	intltool
USE_GITLAB=	yes
GL_TAGNAME=	a754f33ae35f47b98cc1aa7fe8de43ed24662d11
USE_SDL=	sdl mixer image

LDFLAGS+=	${LOCALBASE}/lib/libintl.so

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
