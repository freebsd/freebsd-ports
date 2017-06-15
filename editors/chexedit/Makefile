# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	chexedit
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.rogoyski.com/adam/programs/hexedit/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	hexedit-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Full screen text mode Hex editor using the [n]curses library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_ncurses_h=yes
PLIST_FILES=	bin/chexedit \
		man/man1/chexedit.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hexedit ${STAGEDIR}${PREFIX}/bin/chexedit
	${INSTALL_MAN} ${WRKSRC}/docs/hexedit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/chexedit.1

.include <bsd.port.mk>
