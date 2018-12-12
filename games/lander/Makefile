# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lander
PORTVERSION=	0.6.6
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to configure: error: Could not link against boost_filesystem-boost_filesystem

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libboost_filesystem.so:devel/boost-libs \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gettext localbase pkgconfig
USE_SDL=	sdl image mixer
USE_GL=		gl glu

CONFIGURE_ARGS=	--with-boost="${LOCALBASE}" \
		--with-boost-filesystem=boost_filesystem

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Lunar Lander" \
		"Lunar Lander clone" \
		"${DATADIR}/images/ship.png" \
		"lander" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-R$$found_dir||g' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
