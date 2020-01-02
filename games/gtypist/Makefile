# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.9.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor

LICENSE=	GPLv3

USES=		iconv ncurses shebangfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no \
		ac_cv_header_ncursesw_ncurses_h=yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${WRKDIR}/include
CPPFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${LOCALBASE}/libs

INFO=		gtypist gtypist.cs gtypist.es

SHEBANG_FILES=	typefortune

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -e 's|<ncursesw/ncurses.h>|<ncurses.h>|' \
		${WRKSRC}/src/error.c \
		${WRKSRC}/src/cursmenu.c \
		${WRKSRC}/src/script.c \
		${WRKSRC}/src/gtypist.c \
		${WRKSRC}/src/utf8.c
	${REINPLACE_CMD} -e 's/-lncursesw/-l${NCURSES_IMPL}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
