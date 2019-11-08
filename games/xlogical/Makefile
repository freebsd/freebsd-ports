# Created by: Aaron Baugher
# $FreeBSD$

PORTNAME=	xlogical
DISTVERSION=	1.0-8
CATEGORIES=	games
MASTER_SITES=	https://changeling.ixionstudios.com/xlogical/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	aaron@baugher.biz
COMMENT=	Remake of the classic puzzle game Logical

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="/var/games"
USES=		autoreconf dos2unix gmake sdl tar:bzip2
DOS2UNIX_FILES=	*.h *.cpp
USE_SDL=	sdl image mixer

DESKTOP_ENTRIES="XLogical" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
