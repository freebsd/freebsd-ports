# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.9.5
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor

LICENSE=	GPLv3

USES=		iconv ncurses shebangfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no
CPPFLAGS+=	-I${LOCALBASE}/include -I${WRKDIR}/include
LDFLAGS+=	-L${LOCALBASE}/libs

INFO=		gtypist gtypist.cs gtypist.es

SHEBANG_FILES=	typefortune

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

# wide curses header expected at <ncursesw/ncurses.h>
pre-configure:
	@${MKDIR} ${WRKDIR}/include
	@${LN} -sf /usr/include ${WRKDIR}/include/ncursesw

.include <bsd.port.mk>
