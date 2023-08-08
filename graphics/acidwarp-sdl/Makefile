PORTNAME=	acidwarp-sdl
PORTVERSION=	g2022112701
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Eye candy program which displays various patterns
WWW=		https://github.com/dreamlayers/acidwarp

USES=		cmake magick:7,build sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	dreamlayers
GH_PROJECT=	acidwarp
GH_TAGNAME=	c48e1e2

# Fix build on recent current (clang11)
CFLAGS+=	-fcommon

PORTSCOUT=	skipv:svgalib-port,original,old-sdl-port

PLIST_FILES=	bin/acidwarp \
		share/applications/acidwarp.desktop \
		share/pixmaps/acidwarp.png

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/acidwarp.desktop

do-install:
	${STRIP_CMD} ${WRKSRC}/bin/acidwarp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/acidwarp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/acidwarp.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/acidwarp.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
