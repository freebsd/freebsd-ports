PORTNAME=	concentration
PORTVERSION=	1.2
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.shiftygames.com/concentration/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Find all matching pairs of icons as fast as possible

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image ttf

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz
PORTDATA=	*

DESKTOP_ENTRIES="Concentration" \
		"" \
		"${DATADIR}/pics/cover.png" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

.include <bsd.port.mk>
