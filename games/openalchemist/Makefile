# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	openalchemist
PORTVERSION=	0.3
PORTREVISION=	21
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tetris-like game

LICENSE=	GPLv2+ CC-BY-SA-2.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libclanCore.so:devel/clanlib1 \
		libpng.so:graphics/png

USES=		autoreconf gl gmake gnome iconv jpeg pkgconfig python:2.7,run \
		sdl shebangfix xorg
USE_GNOME=	pygtk2
USE_XORG=	xxf86vm xi x11 xmu xext xdamage xfixes xau xdmcp xt sm ice
USE_GL=		gl glu
USE_SDL=	sdl gfx

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

SHEBANG_FILES=	openalchemist-config

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e 's|0.8|1.0|g' -e 's|^%|#|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e 's|0.8|1.0|g' ${WRKSRC}/build/Makefile.am
	@${REINPLACE_CMD} -E -e 's|^dist_pkgdata_DATA =.*|dist_pkgdata_DATA = data/* skins/aqua.zip skins/brushed.zip skins/vectoriel.zip|g' ${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
