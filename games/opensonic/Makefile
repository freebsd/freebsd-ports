PORTNAME=	opensonic
PORTVERSION=	0.1.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/opensnc/Open%20Sonic/${PORTVERSION} \
		LOCAL/tobik:loggcompat
DISTNAME=	opensnc-src-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		loggcompat-4.4.2${EXTRACT_SUFX}:loggcompat

MAINTAINER=	devel@stasyan.com
COMMENT=	Game based on the "Sonic the Hedgehog" universe
WWW=		https://opensnc.sourceforge.net

BUILD_DEPENDS=	alpng>=1.3:graphics/alpng
LIB_DEPENDS=	liballeg.so:devel/allegro \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis

DESKTOP_ENTRIES="${PORTNAME}" \
		"Sonic the Hedgehog" \
		"${PREFIX}/share/pixmaps/opensonic.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

USES=		cmake

CONFIGURE_ENV=	_ALLEGRO_LIBS="`allegro-config --libs`" \
		_ALLEGRO_VERSION="`allegro-config --version`"

CFLAGS+=	-I${LOCALBASE}/include -I${WRKDIR}/loggcompat-4.4.2

SUB_FILES=	opensonic

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${PREFIX}/bin,g' \
		-e 's,/usr/share,${PREFIX}/share,g' \
		${PATCH_WRKSRC}/src/core/global.h

post-install:
	${INSTALL_DATA}	${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/opensonic.png
	${INSTALL_SCRIPT} ${WRKDIR}/opensonic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
