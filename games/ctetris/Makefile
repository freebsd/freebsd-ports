# New ports collection makefile for:	ctetris
# Date created:			14 Aug 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	ctetris
PORTVERSION=	0.30
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tlp@liquidx.org
COMMENT=	Beautiful tetris clone written in C using the ncurses library

USE_BZIP2=	yes
USE_REINPLACE=	yes

MAN1=		ctetris.1
PLIST_FILES=	bin/ctetris

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|termio.h|termios.h|' ${WRKSRC}/ctetris.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/ctetris.1 ${PREFIX}/man/man1/ctetris.1
	${INSTALL_PROGRAM} ${WRKSRC}/ctetris ${PREFIX}/bin/ctetris

.include <bsd.port.mk>
