PORTNAME=	uhexen
PORTVERSION=	0.601
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/U-hexen%20version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another port of Hexen, popular game from Raven Software
WWW=		http://uhexen.sourceforge.net/

LICENSE=	ACTIVISION
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_NAME=	Activision Software License Agreement
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		gmake sdl
USE_SDL=	mixer sdl
MAKE_ENV=	EXTRA_LIBS=-lm

PLIST_FILES=	bin/uhexen

OPTIONS_DEFINE=	MUSIC
OPTIONS_DEFAULT=	MUSIC
MUSIC_DESC=	In-game MIDI music support
MUSIC_RUN_DEPENDS=	${LOCALBASE}/lib/timidity/goemon.cfg:audio/timidity

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.post.mk>
