PORTNAME=	armagetronad
DISTVERSION=	0.2.8.3.5
DISTVERSIONSUFFIX=	.src
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/stable/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tron clone in 3D
WWW=		http://www.armagetronad.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Fails to build with libxml2 2.14, error: indirection requires pointer operand ('std::nullptr_t' invalid)

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf desktop-file-utils gl gmake gnome jpeg sdl
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_GNOME=	libxml2
USE_SDL=	image mixer sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-etc --disable-games --enable-music
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}"

BINARY_ALIAS=	sdl11-config=sdl-config

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/desktop/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop
.for SZ in 16 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
.endfor
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/small/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/${PORTNAME}.png
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/medium/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/${PORTNAME}.png
	@${MV} ${STAGEDIR}${DATADIR}/desktop/icons/large/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	@${RM} -r ${STAGEDIR}${DATADIR}/desktop

.include <bsd.port.mk>
