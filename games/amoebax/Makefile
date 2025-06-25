PORTNAME=	amoebax
PORTVERSION=	0.2.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.emma-soft.com/games/amoebax/download/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cute and addictive Puyo Puyo like game
WWW=		https://www.emma-soft.com/games/amoebax/

LICENSE=	GPLv2 FAL
LICENSE_COMB=	dual
LICENSE_NAME_FAL=	Free Art License, version 1.2
LICENSE_FILE_FAL=	${WRKSRC}/COPYING.LAL
LICENSE_PERMS_FAL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake sdl tar:bzip2
USE_CXXSTD=	c++14
USE_SDL=	sdl mixer image

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/amoebax \
		share/applications/amoebax.desktop \
		share/man/man6/amoebax.6.gz \
		share/pixmaps/amoebax.svg
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|datarootdir|datadir|' \
		${WRKSRC}/data/Makefile.in ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
