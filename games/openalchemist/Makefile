# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	openalchemist
PORTVERSION=	0.3
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tetris-like game

LICENSE=	GPLv2 CCbySA
LICENSE_COMB=	multi
LICENSE_NAME_CCbySA=	Creative Commons Attribution-ShareAlike
LICENSE_FILE_CCbySA=	${WRKSRC}/GRAPHICS-LICENSE
LICENSE_PERMS_CCbySA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libclanCore.so:devel/clanlib1 \
	libpng.so:graphics/png

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_GNOME=	pygtk2
USE_XORG=	xxf86vm xi x11 xmu xext xdamage xfixes xau xdmcp xt sm ice
USE_GL=		gl glu
USE_SDL=	sdl gfx
USES=		autoreconf gmake iconv jpeg pkgconfig shebangfix
SHEBANG_FILES=	openalchemist-config

PORTDOCS=	AUTHORS ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} -E -e 's|0.8|1.0|g' -e 's|^%|#|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e 's|0.8|1.0|g' ${WRKSRC}/build/Makefile.am
	@${REINPLACE_CMD} -E -e 's|^dist_pkgdata_DATA =.*|dist_pkgdata_DATA = data/* skins/aqua.zip skins/brushed.zip skins/vectoriel.zip|g' ${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
