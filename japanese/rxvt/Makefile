# New ports collection Makefile for: rxvt
# Version required:	2.4.9
# Date created:         6th November 1998
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $Id$
#

DISTNAME=	rxvt-2.4.9
PKGNAME=	ja-rxvt-2.4.9
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
MAN1=		rxvt.1
CONFIGURE_ARGS=	--enable-xpm-background --enable-kanji --enable-menubar --enable-graphics --with-xpm --disable-backspace-key --disable-delete-key

DOCDIR=		${PREFIX}/share/doc/rxvt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/README.ja ${DOCDIR}
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
