# New ports collection Makefile for: rxvt
# Version required:	2.4.11
# Date created:         23 November 1998
# Whom:                 HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $Id: Makefile,v 1.4 1998/11/09 01:24:12 steve Exp $
#

DISTNAME=	rxvt-2.4.11
PKGNAME=	ja-rxvt-2.4.11
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://mason.primenet.com.au/pub/rxvt/

.if !defined(NOXIMSUPPORT)
PATCH_SITES=	http://www.kashio.info.mie-u.ac.jp/~honda/rxvt/
PATCHFILES=	rxvt-2.4.10-JP-XIM.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	honda@kashio.info.mie-u.ac.jp

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
MAN1=		rxvt.1
CONFIGURE_ARGS=	--enable-xpm-background --enable-kanji --enable-menubar --enable-graphics --disable-backspace-key --disable-delete-key

DOCDIR=		${PREFIX}/share/doc/ja/rxvt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/README.ja ${DOCDIR}
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
