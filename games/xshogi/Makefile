PORTNAME=	xshogi
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU/gnushogi

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Japanese chess-like game for X Window System
WWW=		https://www.gnu.org/software/gnushogi/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/share/fonts/100dpi/helvR12.pcf.gz:x11-fonts/font-adobe-100dpi \
		gnushogi:games/gnushogi

USES=		localbase xorg
USE_XORG=	x11 xaw xext xmu xt
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xshogi share/man/man6/xshogi.6.gz
PORTDOCS=	BUGS README.xboard

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
