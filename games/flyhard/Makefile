PORTNAME=	flyhard
PORTVERSION=	0.42
PORTREVISION=	21
CATEGORIES=	games
MASTER_SITES=	http://www.markboyd.me.uk/games/flyhard/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Game resembling Thrust, but with lots of shooting and puzzles
WWW=		https://www.markboyd.me.uk/games/flyhard/flyhard.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h
BROKEN_armv7=	dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h

LIB_DEPENDS=	libpng.so:graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

USES=		gmake localbase sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer

CXXFLAGS+=	-Wno-c++11-narrowing

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog README
PORTDATA=	*

DESKTOP_ENTRIES="Fly Hard" \
		"" \
		"${DATADIR}/images/ship.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} -type f -exec ${CHMOD} 644 {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
