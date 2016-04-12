# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	opensonic
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/opensnc/Open%20Sonic/${PORTVERSION}
DISTNAME=	opensnc-src-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Game based on the "Sonic the Hedgehog" universe

BUILD_DEPENDS=	alpng>=1.3:graphics/alpng
LIB_DEPENDS=	liballeg.so:devel/allegro \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

DESKTOP_ENTRIES="${PORTNAME}" \
		"Sonic the Hedgehog" \
		"${PREFIX}/share/pixmaps/opensonic.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

USES=		cmake
CONFIGURE_ENV+=	_ALLEGRO_LIBS="`allegro-config --libs`" \
		_ALLEGRO_VERSION="`allegro-config --version`"

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${PREFIX}/bin,g' \
		-e 's,/usr/share,${PREFIX}/share,g' \
		${PATCH_WRKSRC}/src/core/global.h

post-install:
	${INSTALL_DATA}	${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/opensonic.png
	${LN} -s ${DATADIR}/opensonic ${STAGEDIR}${PREFIX}/bin/opensonic

.include <bsd.port.mk>
