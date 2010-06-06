# New ports collection makefile for: games/opensonic
# Date created:		27 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	opensonic
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/opensnc/Open%20Sonic/${PORTVERSION}
DISTNAME=	opensnc-src${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Game based on the "Sonic the Hedgehog" universe

DESKTOP_ENTRIES="${PORTNAME}" \
		"Sonic the Hedgehog" \
		"${DATADIR}/images/icon.png" \
		"${PORTNAME}_launcher" \
		"Game;KidsGame;" \
		"false"

USE_CMAKE=	yes
CMAKE_ENV+=	OPENSNC_ALLEGRO_LIBS="`allegro-config --libs`" OPENSNC_ALLEGRO_VERSION="`allegro-config --version`"

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CFLAGS="${CFLAGS}"

BUILD_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro \
		alpng>=1.3:${PORTSDIR}/graphics/alpng
RUN_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro \
		alpng>=1.3:${PORTSDIR}/graphics/alpng
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro \
		ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g' \
		${PATCH_WRKSRC}/CMakeLists.txt ${PATCH_WRKSRC}/src/global.h
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,g' \
		${PATCH_WRKSRC}/src/global.h
	@${REINPLACE_CMD} -e 's,%%GAME_DIR%%,${DATADIR},g' \
		${PATCH_WRKSRC}/src/misc/opensonic ${PATCH_WRKSRC}/src/misc/opensonic_launcher

.include <bsd.port.post.mk>
