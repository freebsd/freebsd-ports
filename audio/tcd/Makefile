PORTNAME=	tcd
PORTVERSION=	2.2.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, user-friendly ncurses-based CD player
WWW=		https://www.nongnu.org/tcd/

LICENSE=	GPLv2

USES=		ncurses sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/tcd \
		share/man/man1/tcd.1.gz

.include <bsd.port.mk>
