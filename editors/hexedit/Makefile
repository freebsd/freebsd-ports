# New ports collection makefile for:	hexedit
# Version required:			0.9.3
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/08/20 09:39:06 asami Exp $
#

DISTNAME=	hexedit-0.9.3
CATEGORIES=	editors
MASTER_SITES=	http://www.chez.com/prigaux/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses

MANUAL_PACKAGE_BUILD=	depends on ncurses

ALL_TARGET=
WRKSRC=		${WRKDIR}/hexedit

MAN1=		hexedit.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor
.endif

.include <bsd.port.mk>
