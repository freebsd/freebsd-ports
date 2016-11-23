# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lander
PORTVERSION=	0.6.6
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lunar Lander clone

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libboost_filesystem.so:devel/boost-libs

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig
USE_SDL=	sdl image mixer
USE_GL=		gl glu

CONFIGURE_ARGS=	--with-boost="${LOCALBASE}" \
		--with-boost-filesystem=boost_filesystem
LDFLAGS=	-L${LOCALBASE}/lib

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

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
