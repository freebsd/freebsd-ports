# New ports collection Makefile for: rxvt
# Version required:	2.6PRE2
# Date created:         28 January 1999
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $Id: Makefile,v 1.6 1998/12/10 01:32:07 flathill Exp $
#

DISTNAME=	rxvt-2.6.PRE2
PKGNAME=	ja-rxvt-2.6p2
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
MAN1=		rxvt.1
CONFIGURE_ARGS=	--enable-xpm-background --enable-xim --enable-kanji --enable-menubar --enable-graphics --disable-backspace-key --disable-delete-key

DOCDIR=		${PREFIX}/share/doc/ja/rxvt
RXVTLIB=	${PREFIX}/lib/X11/rxvt

pre-install:
	@${MKDIR} ${DOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/README.ja ${DOCDIR}
	@${MKDIR} ${RXVTLIB}
	@${INSTALL_MAN} ${FILESDIR}/ja.menu ${RXVTLIB}
	@${INSTALL_MAN} ${FILESDIR}/terminal.menu ${RXVTLIB}

.include <bsd.port.mk>
