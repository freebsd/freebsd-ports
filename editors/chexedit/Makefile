# New ports collection makefile for:	chexedit
# Date Created:				8 Jul 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	chexedit
PORTVERSION=	0.9.7
CATEGORIES=	editors
MASTER_SITES=	http://www.rogoyski.com/adam/programs/hexedit/
DISTNAME=	hexedit-${PORTVERSION}

MAINTAINER=	ports@oven.org
COMMENT=	Full screen text mode Hex editor using the [n]curses library

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/chexedit

MAN1=		chexedit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hexedit ${PREFIX}/bin/chexedit
	${INSTALL_MAN} ${WRKSRC}/docs/hexedit.1 ${PREFIX}/man/man1/chexedit.1

.include <bsd.port.mk>
