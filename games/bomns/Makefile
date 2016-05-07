# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	bomns
PORTVERSION=	0.99.3
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Best old-school Deathmatch game ever (only for two players)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_ACCOUNT=	keithfancher
GH_PROJECT=	Bomns-for-Linux
GH_TAGNAME=	113be27

USES=		cmake
USE_SDL=	mixer sdl
USE_GNOME=	gtk20
CMAKE_ARGS+=	-Wno-dev
USE_CSTD=	gnu89
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LIBS=-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=	DOCS

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
