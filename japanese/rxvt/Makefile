# New ports collection Makefile for: ja-rxvt
# Version required:	2.6.1
# Date created:         11 May 1999
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	rxvt-2.6.1
PKGNAME=	ja-rxvt-2.6.1
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN1=		rxvt.1
CONFIGURE_ARGS+=--enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--enable-kanji --disable-backspace-key --disable-delete-key

DOCDIR=		${PREFIX}/share/doc/ja/rxvt
RXVTLIB=	${PREFIX}/lib/X11/rxvt

pre-install:
	@${MKDIR} ${DOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/README.ja ${DOCDIR}
	@${MKDIR} ${RXVTLIB}
	@${INSTALL_MAN} ${FILESDIR}/ja.menu ${RXVTLIB}
	@${INSTALL_MAN} ${FILESDIR}/terminal.menu ${RXVTLIB}

.include <bsd.port.mk>
