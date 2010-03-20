# New ports collection Makefile for: ja-rxvt
# Date created:         11 May 1999
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	rxvt
PORTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xterm replacement that supports pixmap background and Japanese

USE_XORG=	x11 ice xt xpm
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN1=		rxvt.1 rclock.1
CONFIGURE_ARGS=	--enable-xpm-background --enable-transparency \
		--enable-menubar --enable-graphics --enable-xim \
		--enable-languages --with-encoding=eucj \
		--disable-backspace-key --disable-delete-key \
		--enable-utmp --enable-wtmp \
		--with-xpm --with-xpm-includes=${LOCALBASE}/include/X11 \
		--with-xpm-library=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCDIR=		${PREFIX}/share/doc/ja/rxvt
RXVTLIB=	${PREFIX}/lib/X11/rxvt

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

pre-install:
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/README.ja ${DOCDIR}
	@${MKDIR} ${RXVTLIB}
	@${INSTALL_DATA} ${FILESDIR}/ja.menu ${RXVTLIB}
	@${INSTALL_DATA} ${FILESDIR}/terminal.menu ${RXVTLIB}

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.post.mk>
