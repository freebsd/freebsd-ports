# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.9.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor

USES=		iconv tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no
CPPFLAGS+=	-I${WRKDIR}/include

INFO=		gtypist gtypist.cs gtypist.es

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

# wide curses header expected at <ncursesw/ncurses.h>
pre-configure:
	@${MKDIR} ${WRKDIR}/include
	@${LN} -sf /usr/include ${WRKDIR}/include/ncursesw

.include <bsd.port.mk>
