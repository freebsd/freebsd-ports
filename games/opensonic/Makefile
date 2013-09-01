# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	opensonic
PORTVERSION=	0.1.4
CATEGORIES=	games
MASTER_SITES=	SF/opensnc/Open%20Sonic/${PORTVERSION}
DISTNAME=	opensnc-src-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Game based on the "Sonic the Hedgehog" universe

DESKTOP_ENTRIES="${PORTNAME}" \
		"Sonic the Hedgehog" \
		"${DATADIR}/images/icon.png" \
		"${PORTNAME}_launcher" \
		"Game;KidsGame;" \
		"false"

USES=		cmake
CMAKE_ENV+=	_ALLEGRO_LIBS="`allegro-config --libs`" _ALLEGRO_VERSION="`allegro-config --version`"

CFLAGS+=	-I${LOCALBASE}/include

BUILD_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro \
		alpng>=1.3:${PORTSDIR}/graphics/alpng
RUN_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro \
		alpng>=1.3:${PORTSDIR}/graphics/alpng
LIB_DEPENDS+=	liballeg.so:${PORTSDIR}/devel/allegro \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g' \
		${PATCH_WRKSRC}/CMakeLists.txt ${PATCH_WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,g' \
		${PATCH_WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -e 's,%%GAME_DIR%%,${DATADIR},g' -e 's,opensonic_bin,opensonic,g' -e 's,/bin/bash,/bin/sh,g' \
		${PATCH_WRKSRC}/src/misc/opensonic

post-install:
	@${INSTALL_SCRIPT} ${PATCH_WRKSRC}/src/misc/opensonic ${LOCALBASE}/bin/opensonic

.include <bsd.port.post.mk>
